package com.yjyz.iot.device.dao;

import java.util.List;

import com.yjyz.iot.device.entity.DevConsume;
import com.yjyz.iot.device.entity.DevConsumeKey;

public interface DevConsumeMapper {
	int deleteByPrimaryKey(DevConsumeKey key);

	int insert(DevConsume record);

	int insertSelective(DevConsume record);

	DevConsume selectByPrimaryKey(DevConsumeKey key);

	DevConsume selectUnConOrder(String deviceId);

	int updateByPrimaryKeySelective(DevConsume record);

	int updateByPrimaryKey(DevConsume record);

	List<DevConsume> selectByClientId(String clientId);

	List<DevConsume> selectHistory(DevConsumeKey key);

	DevConsume selectByOrderNo(String orderNo);

	List<DevConsume> selectByDeviceID(String deviceId);

}