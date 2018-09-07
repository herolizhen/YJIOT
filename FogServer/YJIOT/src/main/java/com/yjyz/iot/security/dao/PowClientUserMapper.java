package com.yjyz.iot.security.dao;

import com.yjyz.iot.security.entity.PowClientUser;

public interface PowClientUserMapper {
	int deleteByPrimaryKey(String openid);

	int insert(PowClientUser record);

	int insertSelective(PowClientUser record);

	PowClientUser selectByPrimaryKey(String openid);

	int updateByPrimaryKeySelective(PowClientUser record);

	int updateByClientIdSelective(PowClientUser record);

	int updateByPrimaryKey(PowClientUser record);

	PowClientUser findUserByTel(String tel);

	PowClientUser selectByClientId(String clientId);
}