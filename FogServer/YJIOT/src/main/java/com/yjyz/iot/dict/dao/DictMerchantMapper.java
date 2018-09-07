package com.yjyz.iot.dict.dao;

import java.util.List;

import org.apache.ibatis.annotations.Param;

import com.yjyz.iot.comm.GISQuery;
import com.yjyz.iot.dict.entity.DictMerchant;

public interface DictMerchantMapper {
	int deleteByPrimaryKey(String merchantCode);

	int insert(DictMerchant record);

	int insertSelective(DictMerchant record);

	DictMerchant selectByPrimaryKey(String merchantCode);

	int updateByPrimaryKeySelective(DictMerchant record);

	int updateByPrimaryKey(DictMerchant record);

	List<DictMerchant> selectAll(String appId);

	List<DictMerchant> selectByName(@Param(value="name")String name,@Param(value="appId")String appId);

	List<DictMerchant> selectByGISRect(GISQuery gisQuery);
	
	int updateDevAccountOwnerName(DictMerchant record);

}