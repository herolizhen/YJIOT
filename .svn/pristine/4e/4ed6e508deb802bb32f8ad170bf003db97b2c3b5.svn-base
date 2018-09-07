package com.yjyz.iot.device.dao;

import java.util.List;

import com.yjyz.iot.comm.GISQuery;
import com.yjyz.iot.device.entity.DevAccount;
import com.yjyz.iot.device.entity.DevAccountMini;

public interface DevAccountMapper {
	int deleteByPrimaryKey(String deviceId);

	int insert(DevAccount record);

	int insertSelective(DevAccount record);

	DevAccount selectByPrimaryKey(String deviceId);

	int updateByPrimaryKeySelective(DevAccount record);

	int updateByPrimaryKey(DevAccount record);

	List<DevAccount> selectByMerchantCode(String ownerCode);

	List<DevAccountMini> selectByGISRect(GISQuery gisQuery);

	int updateMqttDevOnlineState(List<String> deviceIds);
}