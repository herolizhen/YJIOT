package com.yjyz.iot.security.dao;

import java.util.List;

import com.yjyz.iot.security.entity.PowResource;
import com.yjyz.iot.security.entity.PowSysUser;

public interface PowResourceMapper {
	int deleteByPrimaryKey(String resId);

	int insert(PowResource record);

	int insertSelective(PowResource record);

	PowResource selectByPrimaryKey(String resId);

	int updateByPrimaryKeySelective(PowResource record);

	int updateByPrimaryKey(PowResource record);

	List<PowResource> selectByAppId(String appId);

	List<PowSysUser> selectUserByResource(PowResource record);
}