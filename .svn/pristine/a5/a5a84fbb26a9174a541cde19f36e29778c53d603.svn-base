package com.yjyz.iot.device.dao;

import com.yjyz.iot.device.entity.DeviceInfo;

public interface DeviceInfoMapper {
	int deleteByPrimaryKey(String deviceId);

	int insert(DeviceInfo record);

	int insertSelective(DeviceInfo record);

	DeviceInfo selectByPrimaryKey(String deviceId);

	int updateByPrimaryKeySelective(DeviceInfo record);

	int updateByPrimaryKey(DeviceInfo record);

	DeviceInfo selectByMAC(String deviceMac);
}