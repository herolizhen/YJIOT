package com.yjyz.iot.security.dao;

import java.util.List;

import com.yjyz.iot.security.entity.PowResource;
import com.yjyz.iot.security.entity.PowRole;
import com.yjyz.iot.security.entity.PowRoleResourceKey;

public interface PowRoleResourceMapper {
	int deleteByPrimaryKey(PowRoleResourceKey key);

	int insert(PowRoleResourceKey record);

	int insertSelective(PowRoleResourceKey record);

	List<PowResource> selectRoleResource(PowRole record);

	List<PowRole> selectResourceRole(PowResource record);

	int deleteByResId(String resId);

	int deleteByRoleId(String roleId);

}