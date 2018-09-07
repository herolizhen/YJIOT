package com.yjyz.iot.device.service.impl;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.annotation.Resource;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.springframework.stereotype.Service;

import com.alibaba.fastjson.JSONObject;
import com.yjyz.iot.device.dao.DevRealTimeMapper;
import com.yjyz.iot.device.entity.DevRealTime;
import com.yjyz.iot.device.service.IDevRealTimeService;

/**
 * @class :DevRealTimeServiceImpl
 * @TODO :
 * @author:Herolizhen
 * @date :2017年11月7日下午4:50:49
 */
@Service("devRealTimeService")
public class DevRealTimeServiceImpl implements IDevRealTimeService {
	private static Log log = LogFactory.getLog(DevRealTimeServiceImpl.class);
	@Resource
	DevRealTimeMapper devRealTimeDao;

	@Override
	public int createNewTable(String tableName) {
		String colDefString = "dtime datetime not null DEFAULT CURRENT_TIMESTAMP,keyvalue decimal(10,4),device_id varchar(36),keyname varchar(36) not null,primary key (dtime, keyname)";
		DevRealTime drt = new DevRealTime();
		drt.setColDefString(colDefString);
		tableName = "T_RT_" + tableName.replaceAll("\\-", "");
		drt.setTableName(tableName);
		return this.devRealTimeDao.createTable(drt);
	}

	@Override
	public int existTable(String tableName) {
		tableName = "T_RT_" + tableName.replaceAll("\\-", "");
		return this.devRealTimeDao.existTable(tableName);
	}

	@Override
	public int dropTable(String tableName) {
		DevRealTime drt = new DevRealTime();
		tableName = "T_RT_" + tableName.replaceAll("\\-", "");
		drt.setTableName(tableName);
		return this.devRealTimeDao.dropTable(drt);
	}

	@Override
	public int createTable(String tableName, String jsonString) {
		try {
			JSONObject obj = JSONObject.parseObject(jsonString);
			StringBuffer colDefBuffer = new StringBuffer();
			colDefBuffer.append("dtime timestamp(3) not null DEFAULT CURRENT_TIMESTAMP(3),device_id varchar(36),");
			for (String key : obj.keySet()) {
				colDefBuffer.append("col_" + key.toLowerCase() + " decimal(10,4),");
			}
			colDefBuffer.append("primary key (dtime)");
			DevRealTime drt = new DevRealTime();
			drt.setColDefString(colDefBuffer.toString());
			tableName = "T_RT_" + tableName.replaceAll("\\-", "");
			drt.setTableName(tableName);
			this.devRealTimeDao.createTable(drt);
		} catch (Exception e) {
			System.out.println("ESHARE Alert createTable  Fail, Payload Syntax Error:" + jsonString);
			log.error(e);
			return 0;
		}
		return 1;
	}

	@Override
	public int insertData(String tableName, String jsonString) {
		try {
			JSONObject obj = JSONObject.parseObject(jsonString);
			StringBuffer insertBuffer = new StringBuffer();
			insertBuffer.append("(");
			for (String key : obj.keySet()) {
				insertBuffer.append("col_" + key.toLowerCase() + ",");
			}
			insertBuffer.append("device_id) values(");
			for (String key : obj.keySet()) {
				insertBuffer.append(obj.get(key) + ",");
			}
			insertBuffer.append("'" + tableName + "') ");
			DevRealTime drt = new DevRealTime();
			drt.setInsertString(insertBuffer.toString());
			tableName = "T_RT_" + tableName.replaceAll("\\-", "");
			drt.setTableName(tableName);
			this.devRealTimeDao.insertData(drt);
		} catch (Exception e) {
			System.out.println("ESHARE Alert insertData  Fail, Payload Syntax Error:" + jsonString);
			System.out.println("ESHARE Alert insertData  Fail :" + e.getMessage());
			log.error(e);
			return 0;
		}
		return 1;
	}

	@Override
	public Map<String, Object> selectLast(String tableName) {
		DevRealTime drt = new DevRealTime();
		tableName = "T_RT_" + tableName.replaceAll("\\-", "");
		drt.setTableName(tableName);
		Map<String, Object> lastDateSet = this.devRealTimeDao.selectLast(drt);
		if (lastDateSet != null) {
			Map<String, Object> set = new HashMap<String, Object>();
			for (String key : lastDateSet.keySet()) {
				if (key.toUpperCase().indexOf("COL_") == 0) {
					set.put(key.split("_")[1], lastDateSet.get(key));
				} else if (key.equalsIgnoreCase("dtime")) {
					set.put(key, lastDateSet.get(key));
				}
			}
			return set;
		}
		return null;
	}

	@Override
	public List<Map<String, Object>> getLastDayStats(String tableName, String type) throws Exception {
		DevRealTime drt = this.getStatsStru(tableName, type);
		return this.devRealTimeDao.getDayStats(drt);
	}

	@Override
	public List<Map<String, Object>> getLastWeekStats(String tableName, String type) throws Exception {
		DevRealTime drt = this.getStatsStru(tableName, type);
		return this.devRealTimeDao.getWeekStats(drt);
	}

	@Override
	public List<Map<String, Object>> getLastMonthStats(String tableName, String type) throws Exception {
		DevRealTime drt = this.getStatsStru(tableName, type);
		return this.devRealTimeDao.getMonthStats(drt);
	}

	@Override
	public List<Map<String, Object>> getLastYearStats(String tableName, String type) throws Exception {
		DevRealTime drt = this.getStatsStru(tableName, type);
		return this.devRealTimeDao.getYearStats(drt);
	}

	private DevRealTime getStatsStru(String tableName, String type) {
		DevRealTime drt = new DevRealTime();
		tableName = "T_RT_" + tableName.replaceAll("\\-", "");
		drt.setTableName(tableName);
		List<DevRealTime> tableStru = this.devRealTimeDao.getTableCols(drt);
		List<String> colsList = this.getColsFromStru(tableStru);
		String colDefString = this.getArithCol(colsList, type);
		drt.setColDefString(colDefString);
		return drt;
	}

	private String getArithCol(List<String> cols, String type) {
		StringBuffer sb = new StringBuffer();
		for (String col : cols) {
			sb.append(type);
			sb.append("(");
			sb.append(col);
			sb.append(") as ");
			sb.append(col.split("_")[1]);
			sb.append(",");
		}
		return sb.toString();
	}

	private List<String> getColsFromStru(List<DevRealTime> tableStru) {
		List<String> ret = new ArrayList<String>();
		for (DevRealTime col : tableStru) {
			if (col.getColField().indexOf("col_") == 0) {
				ret.add(col.getColField());
			}
		}
		return ret;
	}

}