package com.yjyz.iot.device.service;

import java.util.List;

import com.yjyz.iot.comm.GISQuery;
import com.yjyz.iot.device.dto.DevCommDto;
import com.yjyz.iot.device.entity.DevAccount;
import com.yjyz.iot.device.entity.DevAccountMini;
import com.yjyz.iot.device.entity.DevConsume;
import com.yjyz.iot.device.entity.DeviceInfo;
import com.yjyz.iot.dict.entity.DictCharge;

public interface IDeviceService {

	DeviceInfo getDevInfo(String deviceId) throws Exception;

	DeviceInfo getDevInfoByMac(String deviceMac) throws Exception;

	DeviceInfo getDevInfoByOrderNo(String orderNo) throws Exception;

	DevAccount getDevAccount(String deviceId) throws Exception;

	List<DevAccount> getDevAccountByOwnerCode(String merchantCode) throws Exception;

	List<DictCharge> getDevChargeInfo(String deviceId);

	List<DevConsume> getConsume(String deviceId) throws Exception;

	boolean sendCommand(DevCommDto dto, String clientId) throws Exception;

	boolean updateDevAccount(DevAccount devAccount, String userId) throws Exception;

	List<DevAccountMini> selectByGISRect(GISQuery gisQuery) throws Exception;

	boolean updateDevAccount(DevCommDto devAccount) throws Exception;

	public boolean delDevAccount(DevCommDto dto, String userId) throws Exception;
}
