package com.yjyz.iot.share.service.impl;

import java.util.Date;
import java.util.List;
import java.util.UUID;

import javax.annotation.Resource;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;

import com.yjyz.iot.device.dao.DevAccountMapper;
import com.yjyz.iot.device.dao.DevConsumeMapper;
import com.yjyz.iot.device.dao.DevControlMapper;
import com.yjyz.iot.device.dao.DevRelationMapper;
import com.yjyz.iot.device.dao.DeviceInfoMapper;
import com.yjyz.iot.device.entity.DevAccount;
import com.yjyz.iot.device.entity.DevConsume;
import com.yjyz.iot.device.entity.DevControl;
import com.yjyz.iot.device.entity.DevRelation;
import com.yjyz.iot.device.entity.DeviceInfo;
import com.yjyz.iot.ota.dao.OTAFileInfoMapper;
import com.yjyz.iot.ota.dao.OTAUpdateLogMapper;
import com.yjyz.iot.ota.entity.OTAFileInfo;
import com.yjyz.iot.ota.entity.OTAUpdateLog;
import com.yjyz.iot.product.dao.ProdInfoMapper;
import com.yjyz.iot.product.entity.ProdInfo;
import com.yjyz.iot.security.dao.PowAppInfoMapper;
import com.yjyz.iot.security.entity.PowAppInfo;
import com.yjyz.iot.share.dto.ActivateDto;
import com.yjyz.iot.share.service.IMX3165Service;

/**
 * @class :MX3165ServiceImpl
 * @TODO :
 * @author:Herolizhen
 * @date :2017年10月31日上午9:47:58
 */
@Service("mx3165Service")
public class MX3165ServiceImpl implements IMX3165Service {
	@Resource
	PowAppInfoMapper appInfoDao;
	@Resource
	ProdInfoMapper prodInfoDao;
	@Resource
	DeviceInfoMapper deviceInfoDao;
	@Resource
	DevAccountMapper devAccountDao;
	@Resource
	DevControlMapper devControlDao;
	@Resource
	OTAFileInfoMapper otaFileInfoDao;
	@Resource
	OTAUpdateLogMapper otaUpdateLogDao;
	@Resource
	DevConsumeMapper devConsumeDao;
	@Resource
	DevRelationMapper devRelationDao;

	@Value("${cfg.sys.device.owner_code}")
	private String OWNER_CODE;
	@Value("${cfg.sys.device.owner_type}")
	private String ONWER_TYPE;
	@Value("${cfg.sys.device.owner_name}")
	private String OWNER_NAME;
	@Value("${cfg.sys.device.latitude}")
	private Double LATITUDE;
	@Value("${cfg.sys.device.longitude}")
	private Double LONGITUDE;

	@Override
	public DeviceInfo activate(ActivateDto dto) throws Exception {

		ProdInfo prodInfo = this.prodInfoDao.selectByPrimaryKey(dto.getProduct_id());
		PowAppInfo appInfo = this.appInfoDao.selectByPrimaryKey(prodInfo.getAppId());
		DeviceInfo devInfo = this.deviceInfoDao.selectByMAC(dto.getMac());

		if (devInfo == null) {
			devInfo = new DeviceInfo();
			devInfo.setDeviceId(UUID.randomUUID().toString());
			devInfo.setModuleName(dto.getMxchipsn());
			devInfo.setDevicePw(dto.getDevicepw());
			devInfo.setDeviceMac(dto.getMac());
			devInfo.setProductId(dto.getProduct_id());
			devInfo.setIsActivate(true);
			devInfo.setRegIp(dto.getRegIp());
			devInfo.setDeviceName(prodInfo.getName());
			// 超级用户，用来判断重新绑定
			devInfo.setIsRecovery(false);
			this.deviceInfoDao.insertSelective(devInfo);
		} else {
			devInfo.setModuleName(dto.getMxchipsn());
			devInfo.setDevicePw(dto.getDevicepw());
			devInfo.setDeviceMac(dto.getMac());
			devInfo.setProductId(dto.getProduct_id());
			devInfo.setIsActivate(true);
			devInfo.setRegIp(dto.getRegIp());
			this.deviceInfoDao.updateByPrimaryKeySelective(devInfo);
		}
		// 生成设备台账
		DevAccount devAccount = this.devAccountDao.selectByPrimaryKey(devInfo.getDeviceId());
		if (devAccount == null) {
			devAccount = new DevAccount();
			devAccount.setDeviceId(devInfo.getDeviceId());
			devAccount.setOwnerCode(appInfo.getFirmCreditCode());
			devAccount.setOwnerType(ONWER_TYPE);
			devAccount.setOwnerName(appInfo.getFirmName());
			devAccount.setLatitude(appInfo.getFirmLatitude());
			devAccount.setLongitude(appInfo.getFirmLongitude());
			this.devAccountDao.insertSelective(devAccount);
		}
		return devInfo;
	}

	@Override
	public DeviceInfo recoverydevicegrant(String deviceId) throws Exception {
		DeviceInfo devInfo = this.deviceInfoDao.selectByPrimaryKey(deviceId);
		if (devInfo == null) {
			return null;
		} else {
			devInfo.setIsRecovery(false);
			this.deviceInfoDao.updateByPrimaryKey(devInfo);
		}
		return devInfo;
	}

	@Override
	public boolean checkdevicesuperuser(String deviceId) throws Exception {
		DeviceInfo devInfo = this.deviceInfoDao.selectByPrimaryKey(deviceId);
		if (devInfo == null) {
			return false;
		} else {
			return devInfo.getIsRecovery();
		}
	}

	@Override
	public DeviceInfo getDeviceByID(String deviceId) throws Exception {
		return this.deviceInfoDao.selectByPrimaryKey(deviceId);
	}

	@Override
	public int updateDeviceInfo(DeviceInfo devInfo) throws Exception {
		return this.deviceInfoDao.updateByPrimaryKeySelective(devInfo);
	}

	@Override
	public OTAFileInfo selectByOTACheck(OTAFileInfo otaCheck) throws Exception {
		return this.otaFileInfoDao.selectByOTACheck(otaCheck);
	}

	@Override
	public int saveOTAUpdateLog(OTAUpdateLog log) throws Exception {
		log.setId(UUID.randomUUID().toString());
		return this.otaUpdateLogDao.insert(log);
	}

	@Override
	public int updateDevAccount(DevAccount record) throws Exception {
		return this.devAccountDao.updateByPrimaryKeySelective(record);
	}

	@Override
	public boolean chipsConfirm(String orderNo) throws Exception {
		DevConsume devConsume = this.devConsumeDao.selectByOrderNo(orderNo);
		if (devConsume == null) {
			return false;
		}

		long curr_ts = System.currentTimeMillis();
		devConsume.setBillBeing(new Date(curr_ts));
		devConsume.setBillExport(new Date(curr_ts + devConsume.getChips() * 60 * 1000));
		devConsume.setStatus("2");

		int ret = this.devConsumeDao.updateByPrimaryKeySelective(devConsume);
		if (ret == 1) {
			return true;
		} else {
			return false;
		}
	}

	@Override
	public DevConsume getUnConOrder(String deviceId) throws Exception {
		return this.devConsumeDao.selectUnConOrder(deviceId);
	}

	@Override
	public List<DevControl> getDeviceLastStatus(String deviceId) throws Exception {
		List<DevControl> conList = this.devControlDao.selectLastStatusByDid(deviceId);
		this.devControlDao.updateStatusByDid(deviceId);
		return conList;
	}
	@Override
	public boolean devRelationAdd(List<DevRelation> dataList) throws Exception {
		boolean retState = true;
		for (int i = 0; i < dataList.size(); i++) {
			int ret = this.devRelationDao.insertSelective(dataList.get(i));
			if (ret != 1) {
				retState = false;
			}
		}
		return retState;
	}
}
