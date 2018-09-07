package com.yjyz.iot.notice.service.impl;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;

import com.yjyz.iot.push.ISendPush;
import com.yjyz.iot.push.PushResult;
import com.yjyz.iot.security.dao.PowUserDevMapper;
import com.yjyz.iot.security.entity.PowClientUserQuery;
import com.yjyz.iot.notice.dao.NoticeConfigMapper;
import com.yjyz.iot.notice.dao.NoticeMapper;
import com.yjyz.iot.notice.dao.NoticePushMapper;
import com.yjyz.iot.notice.dao.NoticeRuleMapper;
import com.yjyz.iot.notice.entity.Notice;
import com.yjyz.iot.notice.entity.NoticeConfig;
import com.yjyz.iot.notice.entity.NoticePush;
import com.yjyz.iot.notice.entity.NoticePushKey;
import com.yjyz.iot.notice.entity.NoticeRule;
import com.yjyz.iot.notice.service.INoticeService;
import com.yjyz.iot.sms.ISendSMS;
import com.yjyz.iot.sms.SMSResult;

/**
 * 推送通知服务
 * 
 * @class :PushServiceImpl
 * @TODO :
 * @author:HeroLizhen
 * @date :2018年5月12日下午4:05:45
 */
@Service("noticeService")
public class NoticeServiceImpl implements INoticeService {
	@Autowired
	private NoticeConfigMapper noticeConfigDao;
	@Autowired
	private NoticeRuleMapper noticeRuleDao;
	@Autowired
	private NoticePushMapper noticePushDao;
	@Autowired
	private PowUserDevMapper powUserDevDao;
	@Autowired
	private NoticeMapper noticeDao;
	@Autowired
	private ISendSMS sendSMS;
	@Autowired
	private ISendPush sendPush;

	@Value("${sms.ytx.appid}")
	private String SMS_YTX_APPID;
	@Value("${sms.ytx.verCodeTemplateCode}")
	private String SMS_YTX_VERCODETEMPLATECODE;
	@Value("${sms.ytx.alermTemplateCode}")
	private String SMS_YTX_ALERMTEMPLATECODE;
	@Value("${sms.ytx.verCodeTemplate}")
	private String SMS_YTX_VERCODETEMPLATE;
	@Value("${sms.ytx.alermTemplate}")
	private String SMS_YTX_ALERMTEMPLATE;
	@Value("${push.apicloud.alermTemplate}")
	private String PUSH_APICLOUD_ALERMTEMPLATE;

	@Override
	public boolean delNoticeConfig(String appId) throws Exception {
		int ret = this.noticeConfigDao.deleteByPrimaryKey(appId);
		if (ret == 1) {
			return true;
		} else {
			return false;
		}
	}

	@Override
	public boolean insNoticeConfig(NoticeConfig record) throws Exception {
		int ret = this.noticeConfigDao.insertSelective(record);
		if (ret == 1) {
			return true;
		} else {
			return false;
		}
	}

	@Override
	public NoticeConfig selNoticeConfig(String appId) throws Exception {
		NoticeConfig noticeConfig = this.noticeConfigDao.selectByPrimaryKey(appId);
		if (noticeConfig == null) {
			noticeConfig = new NoticeConfig();
			noticeConfig.setYtxAppid(SMS_YTX_APPID);
			noticeConfig.setVerTemplate(SMS_YTX_VERCODETEMPLATE);
			noticeConfig.setVerTemplateId(SMS_YTX_VERCODETEMPLATECODE);
			noticeConfig.setMesTemplate(SMS_YTX_ALERMTEMPLATE);
			noticeConfig.setMesTemplateId(SMS_YTX_ALERMTEMPLATECODE);
			noticeConfig.setApiTemplate(PUSH_APICLOUD_ALERMTEMPLATE);

		}
		return noticeConfig;
	}

	@Override
	public boolean updNoticeConfig(NoticeConfig record) throws Exception {
		int ret = this.noticeConfigDao.updateByPrimaryKeySelective(record);
		if (ret == 1) {
			return true;
		} else {
			return false;
		}
	}

	@Override
	public boolean delNoticeRule(String productId) throws Exception {
		int ret = this.noticeRuleDao.deleteByPrimaryKey(productId);
		if (ret == 1) {
			return true;
		} else {
			return false;
		}
	}

	@Override
	public boolean insNoticeRule(NoticeRule record) throws Exception {
		int ret = this.noticeRuleDao.insertSelective(record);
		if (ret == 1) {
			return true;
		} else {
			return false;
		}
	}

	@Override
	public NoticeRule selNoticeRule(String productId) throws Exception {
		return this.noticeRuleDao.selectByPrimaryKey(productId);
	}

	@Override
	public boolean updNoticeRule(NoticeRule record) throws Exception {
		int ret = this.noticeRuleDao.updateByPrimaryKeySelective(record);
		if (ret == 1) {
			return true;
		} else {
			return false;
		}
	}

	@Override
	public boolean delNoticePush(String productId, int pushNo) throws Exception {
		NoticePushKey key = new NoticePushKey();
		key.setProductId(productId);
		key.setPushNo(pushNo);
		int ret = this.noticePushDao.deleteByPrimaryKey(key);
		if (ret == 1) {
			return true;
		} else {
			return false;
		}
	}

	@Override
	public boolean insNoticePush(NoticePush record) throws Exception {
		int ret = this.noticePushDao.insertSelective(record);
		if (ret == 1) {
			return true;
		} else {
			return false;
		}
	}

	@Override
	public NoticePush selNoticePush(String productId, int pushNo) throws Exception {
		NoticePushKey key = new NoticePushKey();
		key.setProductId(productId);
		key.setPushNo(pushNo);
		return this.noticePushDao.selectByPrimaryKey(key);
	}

	@Override
	public boolean updNoticePush(NoticePush record) throws Exception {
		int ret = this.noticePushDao.updateByPrimaryKeySelective(record);
		if (ret == 1) {
			return true;
		} else {
			return false;
		}
	}

	@Override
	public List<NoticePush> selNoticePushAll(String productId) {
		return this.noticePushDao.selectByProductId(productId);
	}

	@Override
	@SuppressWarnings("deprecation")
	public boolean noticeSend(String deviceId, int noticeType, int pushNo) throws Exception {
		Notice notice = this.noticeDao.selectByDeviceId(deviceId);
		if (notice == null || notice.getNoticeOpen() == false) {
			return false;
		}

		List<PowClientUserQuery> userList = this.powUserDevDao.selectDevUser(deviceId);

		if (userList.size() == 0) {
			return false;
		}

		String tels = "";
		for (int i = 0; i < userList.size(); i++) {
			tels += ((PowClientUserQuery) userList.get(i)).getTel();
			if (i != userList.size() - 1) {
				tels += ",";
			}
		}

		if (notice.getTimeOpen()) {
			try {
				DateFormat df = new SimpleDateFormat("HH:mm");
				Date dateStart = df.parse(notice.getTimeStart());
				Date dateStop = df.parse(notice.getTimeStop());
				Date date = new Date();
				Date dateNow = df.parse(date.getHours() + ":" + date.getMinutes());
				if (!(dateStop.getTime() > dateNow.getTime() && dateNow.getTime() > dateStart.getTime())) {
					return false;
				}
			} catch (ParseException e) {
				return false;
			}
		}
		if (noticeType == 2 || noticeType == 3) {
			if (notice.getSmsOpen()) {
				this.sendSMS.sendAlerm(notice.getYtxAppid(), notice.getMesTemplateId(), tels, notice.getDeviceName(),
						notice.getSign());
			}
		}

		if (noticeType == 1 || noticeType == 3) {
			if (notice.getPushOpen()) {
				String content;
				if (pushNo == 0) {
					content = notice.getApiTemplate();
				} else {
					NoticePush push = this.selNoticePush(notice.getProductId(), pushNo);
					content = push.getPushInfo();
				}
				if (notice.getSign() != null) {
					content = content.replace("{sign}", notice.getSign());
				} else {
					System.out.println(notice.getSign());
				}
				this.sendPush.send(notice.getApiAppid(), notice.getApiAppkey(), tels, notice.getDeviceName(), content);
			}
		}
		return true;
	}

	@Override
	public boolean noticeTest(String appId, String tel, int type) throws Exception {
		NoticeConfig noticeConfig = this.noticeConfigDao.selectByPrimaryKey(appId);
		SMSResult rst;
		// 验证码
		if (type == 1) {
			if (noticeConfig == null) {
				rst = this.sendSMS.sendVerCode(tel, "0000");
				if (rst.getCode().equals("0")) {
					return true;
				} else {
					return false;
				}
			} else {
				rst = this.sendSMS.sendVerCode(noticeConfig.getYtxAppid(), noticeConfig.getVerTemplateId(), tel,
						"0000");
				if (rst.getCode().equals("0")) {
					return true;
				} else {
					return false;
				}
			}
		}
		if (noticeConfig == null) {
			return false;
		}
		// 短信通知
		if (type == 2) {
			rst = this.sendSMS.sendAlerm(noticeConfig.getYtxAppid(), noticeConfig.getMesTemplateId(), tel, "XXX",
					noticeConfig.getSign());
			if (rst.getCode().equals("0")) {
				return true;
			} else {
				return false;
			}
		}

		// 消息通知
		if (type == 3) {
			String content = noticeConfig.getApiTemplate();
			if (noticeConfig.getSign() != null) {
				content = content.replace("{sign}", noticeConfig.getSign());
			} else {
				System.out.println(noticeConfig.getSign());
			}
			PushResult pst = this.sendPush.send(noticeConfig.getApiAppid(), noticeConfig.getApiAppkey(), tel,
					"Device Name", content.replace("{sign}", noticeConfig.getSign()));
			if (pst.getStatus() == 1) {
				return true;

			} else {
				return false;
			}
		}
		return true;
	}

	@Override
	public boolean pushTest(String appId, String tel, String produceId, int pushNo) throws Exception {
		NoticeConfig noticeConfig = this.noticeConfigDao.selectByPrimaryKey(appId);
		if (noticeConfig == null) {
			return false;
		}

		NoticePush push = this.selNoticePush(produceId, pushNo);
		if (push == null) {
			return false;
		}
		String content = push.getPushInfo();
		if (noticeConfig.getSign() != null) {
			content = content.replace("{sign}", noticeConfig.getSign());
		} else {
			System.out.println(noticeConfig.getSign());
		}
		PushResult pst = this.sendPush.send(noticeConfig.getApiAppid(), noticeConfig.getApiAppkey(), tel, "Device Name",
				content);
		if (pst.getStatus() == 1) {
			return true;

		} else {
			return false;
		}
	}
}