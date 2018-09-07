package com.yjyz.iot.device.service;

import java.util.List;
import java.util.Map;

public interface IDevRealTimeService {
	int createNewTable(String tableName);

	int createTable(String tableName, String jsonString);

	int existTable(String tableName);

	int dropTable(String tableName);

	int insertData(String tableName, String jsonString) throws Exception;

	Map<String, Object> selectLast(String tableName) throws Exception;

	List<Map<String, Object>> getLastDayStats(String tableName, String type) throws Exception;

	List<Map<String, Object>> getLastWeekStats(String tableName, String type) throws Exception;

	List<Map<String, Object>> getLastMonthStats(String tableName, String type) throws Exception;

	List<Map<String, Object>> getLastYearStats(String tableName, String type) throws Exception;

}
