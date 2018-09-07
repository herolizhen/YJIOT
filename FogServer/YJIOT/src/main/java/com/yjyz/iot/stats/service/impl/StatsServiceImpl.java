package com.yjyz.iot.stats.service.impl;

import java.util.List;
import java.util.Map;

import javax.annotation.Resource;

import org.springframework.stereotype.Service;

import com.yjyz.iot.stats.dao.StatsMapper;
import com.yjyz.iot.stats.entity.StatsParm;
import com.yjyz.iot.stats.service.IStatsService;

@Service("statsService")
public class StatsServiceImpl implements IStatsService {
	@Resource
	StatsMapper statsDao;

	@Override
	public List<Map<String, Object>> devStateType(StatsParm parm) throws Exception {
		return this.statsDao.devStateType(parm);
	}

	@Override
	public List<Map<String, Object>> userRegMonth(StatsParm parm) throws Exception {
		return this.statsDao.userRegMonth(parm);
	}

	@Override
	public List<Map<String, Object>> fundMonth(StatsParm parm) throws Exception {
		return this.statsDao.fundMonth(parm);
	}

	@Override
	public List<Map<String, Object>> fundMerChantDay(StatsParm parm) throws Exception {
		return this.statsDao.fundMerChantDay(parm);
	}

	@Override
	public List<Map<String, Object>> fundMerChantWeek(StatsParm parm) throws Exception {
		return this.statsDao.fundMerChantWeek(parm);
	}

	@Override
	public List<Map<String, Object>> fundTimesDay(StatsParm parm) throws Exception {
		return this.statsDao.fundTimesDay(parm);
	}

	@Override
	public List<Map<String, Object>> fundTimesWeek(StatsParm parm) throws Exception {
		return this.statsDao.fundTimesWeek(parm);
	}

	@Override
	public List<Map<String, Object>> devSeller(StatsParm parm) throws Exception {
		return this.statsDao.devSeller(parm);
	}

	@Override
	public List<Map<String, Object>> devOnlineState(StatsParm parm) throws Exception {
		return this.statsDao.devOnlineState(parm);
	}

	@Override
	public List<Map<String, Object>> fundSellerWeek(StatsParm parm) throws Exception {
		return this.statsDao.fundSellerWeek(parm);
	}

	@Override
	public List<Map<String, Object>> fundDevTop15(StatsParm parm) throws Exception {
		return this.statsDao.fundDevTop15(parm);
	}

	@Override
	public List<Map<String, Object>> fundUserTop10(StatsParm parm) throws Exception {
		return this.statsDao.fundUserTop10(parm);
	}

	@Override
	public List<Map<String, Object>> userRegTypeWeek(StatsParm parm) throws Exception {
		return this.statsDao.userRegTypeWeek(parm);
	}

	@Override
	public List<Map<String, Object>> devExamMain(StatsParm parm) throws Exception {
		return this.statsDao.devExamMain(parm);
	}

	@Override
	public List<Map<String, Object>> devExamItem(StatsParm parm) throws Exception {
		return this.statsDao.devExamItem(parm);
	}

}
