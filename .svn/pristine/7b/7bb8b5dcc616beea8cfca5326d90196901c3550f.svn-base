package com.yjyz.iot.dict.dao;

import java.util.List;

import com.yjyz.iot.comm.PCAQuery;
import com.yjyz.iot.dict.entity.DictRegion;

public interface DictRegionMapper {
	int deleteByPrimaryKey(String id);

	int insert(DictRegion record);

	int insertSelective(DictRegion record);

	DictRegion selectByPrimaryKey(String id);

	int updateByPrimaryKeySelective(DictRegion record);

	int updateByPrimaryKey(DictRegion record);

	List<DictRegion> selectByPCA(PCAQuery query);

	List<DictRegion> selectByPCAFree(PCAQuery query);
}