package com.yjyz.iot.device.dao;

import java.util.List;

import com.yjyz.iot.device.entity.DevControl;

public interface DevControlMapper {
	int deleteByPrimaryKey(String id);

	int insert(DevControl record);

	int insertSelective(DevControl record);

	DevControl selectByPrimaryKey(String id);

	int updateByPrimaryKeySelective(DevControl record);

	int updateByPrimaryKey(DevControl record);

	List<DevControl> selectLastStatusByDid(String deviceId);

	int updateStatusByDid(String deviceId);
}