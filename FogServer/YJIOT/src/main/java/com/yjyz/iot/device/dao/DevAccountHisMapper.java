package com.yjyz.iot.device.dao;

import com.yjyz.iot.device.entity.DevAccountHis;

public interface DevAccountHisMapper {
	int insert(DevAccountHis record);
	int insertSelective(DevAccountHis record);
}