package com.yjyz.iot.stats.action;

import java.util.Calendar;
import java.util.List;
import java.util.Map;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestHeader;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import com.yjyz.iot.comm.ConstParm;
import com.yjyz.iot.comm.RetInfoDto;
import com.yjyz.iot.security.utils.ClientJwtToken;
import com.yjyz.iot.security.utils.ClientJwtUtil;
import com.yjyz.iot.stats.entity.QueryParm;
import com.yjyz.iot.stats.service.IQueryService;

@RestController
@RequestMapping("/query")
public class QueryController {
	@Autowired
	private IQueryService queryService;
	@Autowired
	ClientJwtUtil jwtUtil;
	private static Log log = LogFactory.getLog(QueryController.class);

	@Transactional
	@RequestMapping(value = "/consumeDetailQuery", method = RequestMethod.POST)
	public RetInfoDto consumeDetailQuery(@RequestBody QueryParm dto, @RequestHeader String Authorization) {

		RetInfoDto info = new RetInfoDto();
		ClientJwtToken jwtToken;
		try {
			jwtToken = jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}
		try {
			Calendar c = Calendar.getInstance();
			c.setTime(dto.getEndDate());
			c.add(Calendar.DATE, 1);
			dto.setEndDate(c.getTime());
			dto.setAppId(jwtToken.getApp_id());
			List<Map<String, Object>> data = this.queryService.consumeDetailQuery(dto);
			if (data.size() == 0) {
				info.meta.put("message", "no data for consumeDetailQuery stats.");
				info.meta.put("code", ConstParm.SUCESS_CODE);
			} else {
				info.meta.put("code", ConstParm.SUCESS_CODE);
				info.data.put("data", data);
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "Stats consumeDetailQuery Fail.");
			info.meta.put("code", ConstParm.ERR_QUERY_CONSUMEDETAILQUERY);
		}
		return info;
	}

	@Transactional
	@RequestMapping(value = "/consumeMerchantQuery", method = RequestMethod.POST)
	public RetInfoDto consumeMerchantQuery(@RequestBody QueryParm dto, @RequestHeader String Authorization) {

		RetInfoDto info = new RetInfoDto();
		ClientJwtToken jwtToken;
		try {
			jwtToken = jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}
		try {
			Calendar c = Calendar.getInstance();
			c.setTime(dto.getEndDate());
			c.add(Calendar.DATE, 1);
			dto.setEndDate(c.getTime());
			dto.setAppId(jwtToken.getApp_id());
			List<Map<String, Object>> data = this.queryService.consumeMerchantQuery(dto);
			if (data.size() == 0) {
				info.meta.put("message", "no data for consumeDetailQuery stats.");
				info.meta.put("code", ConstParm.SUCESS_CODE);
			} else {
				info.meta.put("code", ConstParm.SUCESS_CODE);
				info.data.put("data", data);
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "Stats consumeMerchantQuery Fail.");
			info.meta.put("code", ConstParm.ERR_QUERY_CONSUMEMERCHANTQUERY);
		}
		return info;
	}

	@Transactional
	@RequestMapping(value = "/qnrQuery", method = RequestMethod.POST)
	public RetInfoDto qnrQuery(@RequestHeader String Authorization) {

		RetInfoDto info = new RetInfoDto();
		ClientJwtToken jwtToken;
		try {
			jwtToken = jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}
		try {
			QueryParm parm = new QueryParm();
			parm.setAppId(jwtToken.getApp_id());
			List<Map<String, Object>> data = this.queryService.qnrQuery(parm);
			if (data.size() == 0) {
				info.meta.put("message", "no data for qnrQuery stats.");
				info.meta.put("code", ConstParm.SUCESS_CODE);
			} else {
				info.meta.put("code", ConstParm.SUCESS_CODE);
				info.data.put("data", data);
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "Stats qnrQuery Fail.");
			info.meta.put("code", ConstParm.ERR_QUERY_QNRQUERY);
		}
		return info;
	}
}
