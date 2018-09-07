package com.yjyz.iot.product.dao;

import java.util.List;

import com.yjyz.iot.product.entity.ProdInfo;

public interface ProdInfoMapper {
	int deleteByPrimaryKey(String productId);

	int insert(ProdInfo record);

	int insertSelective(ProdInfo record);

	ProdInfo selectByPrimaryKey(String productId);
	
	List<ProdInfo> selectByAppId(String appId);

	int updateByPrimaryKeySelective(ProdInfo record);

	int updateByPrimaryKey(ProdInfo record);
}