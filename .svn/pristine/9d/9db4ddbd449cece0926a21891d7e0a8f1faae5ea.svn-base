package com.yjyz.iot.dict.dao;

import java.util.List;

import org.apache.ibatis.annotations.Param;

import com.yjyz.iot.dict.entity.DictCharge;
import com.yjyz.iot.dict.entity.DictChargeKey;

public interface DictChargeMapper {
	int deleteByPrimaryKey(DictChargeKey key);

	int insert(DictCharge record);

	int insertSelective(DictCharge record);

	DictCharge selectByPrimaryKey(DictChargeKey key);

	int updateByPrimaryKeySelective(DictCharge record);

	int updateByPrimaryKey(DictCharge record);

	List<DictCharge> selectByDeviceId(String deviceId);

	List<DictCharge> selectByType(@Param(value="chargeType")String chargeType,@Param(value="appId")String appId);

	List<DictCharge> selectAll(String appId);
}