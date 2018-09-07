package com.yjyz.iot.stats.service.impl;

import java.util.List;
import java.util.Map;

import javax.annotation.Resource;

import org.springframework.stereotype.Service;

import com.yjyz.iot.stats.dao.QueryMapper;
import com.yjyz.iot.stats.entity.QueryParm;
import com.yjyz.iot.stats.service.IQueryService;

@Service("queryService")
public class QueryServiceImpl implements IQueryService {
	@Resource
	QueryMapper queryDao;
	
	@Override
	public List<Map<String, Object>> consumeDetailQuery(QueryParm parm) throws Exception {
		if (parm.getMerchantCode()== null|| parm.getMerchantCode()=="") {
			parm.setMerchantCode("all");
		} 
		return this.queryDao.consumeDetailQuery(parm);
	}


	@Override
	public List<Map<String, Object>> consumeMerchantQuery(QueryParm parm) throws Exception {
		if (parm.getMerchantCode()== null || parm.getMerchantCode()=="") {
			parm.setMerchantCode("all");
		} 
		return this.queryDao.consumeMerchantQuery(parm);
	}


	@Override
	public List<Map<String, Object>> qnrQuery(QueryParm parm) throws Exception {
		return this.queryDao.qnrQuery(parm);
	}
	
}