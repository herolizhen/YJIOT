package com.yjyz.iot.device.dao;

import java.util.List;
import java.util.Map;

import com.yjyz.iot.device.entity.DevRealTime;

public interface DevRealTimeMapper {
	int createTable(DevRealTime devRealTime);

	int existTable(String tableName);

	int dropTable(DevRealTime devRealTime);

	List<DevRealTime> getTableCols(DevRealTime devRealTime);

	Map<String, Object> selectLast(DevRealTime devRealTime);

	int insertData(DevRealTime DevRealTime);

	List<Map<String, Object>> getDayStats(DevRealTime DevRealTime);

	List<Map<String, Object>> getWeekStats(DevRealTime devRealTime);

	List<Map<String, Object>> getMonthStats(DevRealTime devRealTime);

	List<Map<String, Object>> getYearStats(DevRealTime devRealTime);
}