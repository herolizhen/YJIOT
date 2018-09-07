package com.yjyz.iot.stats.dao;

import java.util.List;
import java.util.Map;

import com.yjyz.iot.stats.entity.QueryParm;

public interface QueryMapper {
	List<Map<String, Object>> consumeDetailQuery(QueryParm parm);

	List<Map<String, Object>> consumeMerchantQuery(QueryParm parm);

	List<Map<String, Object>> deviceAccountQuery(QueryParm parm);

	List<Map<String, Object>> deviceFundMonthQuery(QueryParm parm);

	List<Map<String, Object>> merchantAccountQuery(QueryParm parm);

	List<Map<String, Object>> merchantFundMonthQuery(QueryParm parm);

	List<Map<String, Object>> qnrQuery(QueryParm parm);

}