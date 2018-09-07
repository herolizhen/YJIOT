package com.yjyz.iot.device.dao;

import com.yjyz.iot.device.entity.DevRelation;
import com.yjyz.iot.device.entity.DevRelationKey;

public interface DevRelationMapper {
    int deleteByPrimaryKey(DevRelationKey key);

    int insert(DevRelation record);

    int insertSelective(DevRelation record);

    DevRelation selectByPrimaryKey(DevRelationKey key);

    int updateByPrimaryKeySelective(DevRelation record);

    int updateByPrimaryKey(DevRelation record);
}