package com.yjyz.iot.security.dao;

import java.util.List;

import com.yjyz.iot.security.entity.PowAppInfo;
import com.yjyz.iot.security.entity.PowResource;
import com.yjyz.iot.security.entity.PowSysUser;
import com.yjyz.iot.security.entity.PowSysUserKey;

public interface PowSysUserMapper {
	int deleteByPrimaryKey(PowSysUserKey key);

	int insert(PowSysUser record);

	int insertSelective(PowSysUser record);

	PowSysUser selectByPrimaryKey(PowSysUserKey key);

	int updateByPrimaryKeySelective(PowSysUser record);

	int updateByPrimaryKey(PowSysUser record);

	List<PowSysUser> selectByAppId(PowSysUserKey key);

	List<PowResource> selectResourceByUser(PowSysUserKey key);

	List<PowAppInfo> userLogin(PowSysUser record);
	PowSysUser isAppAdmin(PowSysUser record);
}