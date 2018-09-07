package com.yjyz.iot.exam.dao;

import java.util.List;

import com.yjyz.iot.exam.entity.DevExamMain;

public interface DevExamMainMapper {
	int deleteByPrimaryKey(String examId);

	int insert(DevExamMain record);

	int insertSelective(DevExamMain record);

	DevExamMain selectByPrimaryKey(String examId);

	int updateByPrimaryKeySelective(DevExamMain record);

	int updateByPrimaryKey(DevExamMain record);

	List<DevExamMain> selectByDeviceId(String deviceId);
}