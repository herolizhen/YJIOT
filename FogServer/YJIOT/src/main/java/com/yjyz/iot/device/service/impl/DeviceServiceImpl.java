package com.yjyz.iot.device.service.impl;

import java.util.Date;
import java.util.List;
import java.util.UUID;

import javax.annotation.Resource;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;

import com.alibaba.fastjson.JSONObject;
import com.yjyz.iot.comm.GISQuery;
import com.yjyz.iot.comm.PCAQuery;
import com.yjyz.iot.device.dao.DevAccountHisMapper;
import com.yjyz.iot.device.dao.DevAccountMapper;
import com.yjyz.iot.device.dao.DevConsumeMapper;
import com.yjyz.iot.device.dao.DevControlMapper;
import com.yjyz.iot.device.dao.DeviceInfoMapper;
import com.yjyz.iot.device.dto.DevCommDto;
import com.yjyz.iot.device.entity.DevAccount;
import com.yjyz.iot.device.entity.DevAccountHis;
import com.yjyz.iot.device.entity.DevAccountMini;
import com.yjyz.iot.device.entity.DevConsume;
import com.yjyz.iot.device.entity.DevControl;
import com.yjyz.iot.device.entity.DeviceInfo;
import com.yjyz.iot.device.service.IDeviceService;
import com.yjyz.iot.dict.dao.DictChargeMapper;
import com.yjyz.iot.dict.dao.DictRegionMapper;
import com.yjyz.iot.dict.entity.DictCharge;
import com.yjyz.iot.dict.entity.DictRegion;
import com.yjyz.iot.mq.producer.topic.TopicSender;

/**
 * @class :DeviceServiceImpl
 * @TODO :
 * @author:Herolizhen
 * @date :2017年11月7日下午4:50:16
 */
@Service("deviceService")
public class DeviceServiceImpl implements IDeviceService {
	private static Log log = LogFactory.getLog(DeviceServiceImpl.class);
	@Resource
	DictChargeMapper dictChargeDao;
	@Resource
	DictRegionMapper dictRegionDao;
	@Resource
	DevConsumeMapper devConsumeDao;
	@Autowired
	DeviceInfoMapper deviceInfoDao;
	@Resource
	DevAccountMapper devAccountDao;
	@Resource
	DevControlMapper devControlDao;
	@Resource
	DevAccountHisMapper devAccountHisDao;
	@Autowired
	private TopicSender topicSender;

	@Value("${cfg.sys.device_ttl}")
	private long DEV_TTL;

	@Override
	public DeviceInfo getDevInfo(String deviceId) throws Exception {
		return this.deviceInfoDao.selectByPrimaryKey(deviceId);
	}

	@Override
	public DevAccount getDevAccount(String deviceId) throws Exception {
		DevAccount devAccount = this.devAccountDao.selectByPrimaryKey(deviceId);
		if (devAccount != null) {
			long lastTime = devAccount.getLastTime().getTime();
			long nowTime = System.currentTimeMillis();
			if (lastTime + DEV_TTL <= nowTime) {
				devAccount.setIsOnline(false);
			}
		}
		return devAccount;
	}

	@Override
	public List<DictCharge> getDevChargeInfo(String deviceId) {
		return this.dictChargeDao.selectByDeviceId(deviceId);
	}

	@Override
	public List<DevConsume> getConsume(String deviceId) throws Exception {
		return this.devConsumeDao.selectByDeviceID(deviceId);
	}

	@Override
	public DeviceInfo getDevInfoByMac(String deviceMac) throws Exception {
		return this.deviceInfoDao.selectByMAC(deviceMac);
	}

	@Override
	public DeviceInfo getDevInfoByOrderNo(String orderNo) throws Exception {
		DevConsume devConsume = this.devConsumeDao.selectByOrderNo(orderNo);
		return this.deviceInfoDao.selectByPrimaryKey(devConsume.getDeviceId());
	}

	@Override
	public boolean sendCommand(DevCommDto dto, String clientId) throws Exception {
		if (dto.getFlag() == 1) {
			try {
				JSONObject obj = JSONObject.parseObject(dto.getPayload());
				for (String key : obj.keySet()) {
					DevControl record = new DevControl();
					record.setId(UUID.randomUUID().toString());
					record.setCmd(key);
					record.setDeviceId(dto.getDeviceId());
					record.setOpUser(clientId);
					record.setParm(String.valueOf(obj.get(key)));
					int ret = this.devControlDao.insertSelective(record);
					if (ret != 1) {
						return false;
					}
				}
			} catch (Exception e) {
				System.out.println("ESHARE Alert Save SendCommand Fail, Payload Syntax Error:" + dto.getPayload());
				log.error(e);
			}
		}
		topicSender.send("c2d." + dto.getDeviceId() + ".commands", dto.getPayload());
		return true;

	}

	@Override
	public boolean updateDevAccount(DevAccount devAccount, String userId) throws Exception {
		DevAccount oldData = this.devAccountDao.selectByPrimaryKey(devAccount.getDeviceId());
		DevAccountHis accountHis = new DevAccountHis();
		accountHis.setGuid(UUID.randomUUID().toString());
		accountHis.setDeviceId(oldData.getDeviceId());
		accountHis.setInstallDate(oldData.getInstallDate());
		accountHis.setInstaller(oldData.getInstaller());
		accountHis.setLatitude(oldData.getLatitude());
		accountHis.setLongitude(oldData.getLongitude());
		accountHis.setManager(oldData.getManager());
		accountHis.setOwnerCode(oldData.getOwnerCode());
		accountHis.setOwnerName(oldData.getOwnerName());
		accountHis.setOwnerType(oldData.getOwnerType());
		accountHis.setPosition(oldData.getPosition());
		accountHis.setRegCode(oldData.getRegCode());
		accountHis.setRemoveDate(new Date());
		accountHis.setRemover(userId);
		accountHis.setTel(oldData.getTel());

		int ret = this.devAccountHisDao.insertSelective(accountHis);
		if (ret == 1) {
			devAccount.setInstaller(userId);
			devAccount.setInstallDate(new Date());
			ret = this.devAccountDao.updateByPrimaryKeySelective(devAccount);
			if (ret == 1) {
				return true;
			}
		}
		return false;
	}

	@Override
	public List<DevAccount> getDevAccountByOwnerCode(String merchantCode) throws Exception {

		List<DevAccount> devList = this.devAccountDao.selectByMerchantCode(merchantCode);
		long nowTime = System.currentTimeMillis();
		for (int i = 0; i < devList.size(); i++) {
			DevAccount devAccount = devList.get(i);
			long lastTime = devAccount.getLastTime().getTime();
			if (lastTime + DEV_TTL <= nowTime) {
				devAccount.setIsOnline(false);
			}
		}

		return devList;
	}

	@Override
	public List<DevAccountMini> selectByGISRect(GISQuery gisQuery) throws Exception {
		List<DevAccountMini> devList = this.devAccountDao.selectByGISRect(gisQuery);
		long nowTime = System.currentTimeMillis();
		for (int i = 0; i < devList.size(); i++) {
			DevAccountMini devAccount = devList.get(i);
			if (devAccount.getLastTime() == null) {
				devAccount.setIsOnline(false);
			} else {
				long lastTime = devAccount.getLastTime().getTime();
				if (lastTime + DEV_TTL <= nowTime) {
					devAccount.setIsOnline(false);
				}
			}
		}
		return devList;

	}

	@Override
	public boolean updateDevAccount(DevCommDto dto) throws Exception {
		DevAccount devAccount = this.devAccountDao.selectByPrimaryKey(dto.getDeviceId());
		PCAQuery query = new PCAQuery();
		query.setProvName(dto.getProvName());
		query.setCityName(dto.getCityName());
		query.setAreaName(dto.getAreaName());

		String[] reg = { "省", "市", "区", "县" };
		for (int i = 0; i < reg.length; i++) {
			if (query.getProvName().endsWith(reg[i])) {
				query.setProvName(query.getProvName().replace(reg[i], ""));
			}
			if (query.getCityName().endsWith(reg[i])) {
				query.setCityName(query.getCityName().replace(reg[i], ""));
			}
			if (query.getAreaName().endsWith(reg[i])) {
				query.setAreaName(query.getAreaName().replace(reg[i], ""));
			}
		}
		query.setProvName(query.getProvName() + "%");
		query.setCityName(query.getCityName() + "%");
		query.setAreaName(query.getAreaName() + "%");

		List<DictRegion> regList = this.dictRegionDao.selectByPCA(query);
		if (regList.size() > 0) {
			devAccount.setRegCode(regList.get(0).getAreaCode());
			int ret = this.devAccountDao.updateByPrimaryKeySelective(devAccount);
			if (ret == 1) {
				return true;
			}
		}
		return false;
	}

	@Override
	public boolean delDevAccount(DevCommDto dto, String userId) throws Exception {
		DevAccount oldData = this.devAccountDao.selectByPrimaryKey(dto.getDeviceId());
		DevAccountHis accountHis = new DevAccountHis();
		accountHis.setGuid(UUID.randomUUID().toString());
		accountHis.setDeviceId(oldData.getDeviceId());
		accountHis.setInstallDate(oldData.getInstallDate());
		accountHis.setInstaller(oldData.getInstaller());
		accountHis.setLatitude(oldData.getLatitude());
		accountHis.setLongitude(oldData.getLongitude());
		accountHis.setManager(oldData.getManager());
		accountHis.setOwnerCode(oldData.getOwnerCode());
		accountHis.setOwnerName(oldData.getOwnerName());
		accountHis.setOwnerType(oldData.getOwnerType());
		accountHis.setPosition(oldData.getPosition());
		accountHis.setRegCode(oldData.getRegCode());
		accountHis.setRemoveDate(new Date());
		accountHis.setRemover(userId);
		accountHis.setTel(oldData.getTel());

		int ret = this.devAccountHisDao.insertSelective(accountHis);
		if (ret == 1) {
			ret = this.devAccountDao.deleteByPrimaryKey(dto.getDeviceId());
			if (ret == 1) {
				ret = this.deviceInfoDao.deleteByPrimaryKey(dto.getDeviceId());
			}
		}
		if (ret == 1) {
			return true;
		} else {
			return false;
		}
	}
}
