package com.yjyz.iot.security.dao;

import java.util.List;

import com.yjyz.iot.security.entity.PowAppInfo;

public interface PowAppInfoMapper {
	int deleteByPrimaryKey(String appId);

	int insert(PowAppInfo record);

	int insertSelective(PowAppInfo record);

	PowAppInfo selectByPrimaryKey(String appId);

	int updateByPrimaryKeySelective(PowAppInfo record);

	int updateByPrimaryKey(PowAppInfo record);

	List<PowAppInfo> selectAll();
}