package com.yjyz.iot.security.dao;

import java.util.List;

import com.yjyz.iot.security.entity.PowRole;
import com.yjyz.iot.security.entity.PowRoleKey;

public interface PowRoleMapper {
	int deleteByPrimaryKey(PowRoleKey key);

	int insert(PowRole record);

	int insertSelective(PowRole record);

	PowRole selectByPrimaryKey(PowRoleKey key);

	int updateByPrimaryKeySelective(PowRole record);

	int updateByPrimaryKey(PowRole record);

	List<PowRole> selectByAppId(PowRoleKey key);

}