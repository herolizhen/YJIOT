package com.yjyz.iot.stats.action;

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
import com.yjyz.iot.stats.service.IAccountQueryService;

@RestController
@RequestMapping("/query")
public class AccountQueryController {
	@Autowired
	private IAccountQueryService accountQueryService;
	@Autowired
	ClientJwtUtil jwtUtil;
	private static Log log = LogFactory.getLog(AccountQueryController.class);

	@Transactional
	@RequestMapping(value = "/deviceAccountQuery", method = RequestMethod.POST)
	public RetInfoDto deviceAccountQuery(@RequestBody QueryParm dto, @RequestHeader String Authorization) {

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
			dto.setAppId(jwtToken.getApp_id());
			List<Map<String, Object>> data = this.accountQueryService.deviceAccountQuery(dto);
			if (data.size() == 0) {
				info.meta.put("message", "no data for deviceAccountQuery stats.");
				info.meta.put("code", ConstParm.SUCESS_CODE);
			} else {
				info.meta.put("code", ConstParm.SUCESS_CODE);
				info.data.put("data", data);
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "Stats deviceAccountQuery Fail.");
			info.meta.put("code", ConstParm.ERR_QUERY_DEVICEACCOUNTQUERY);
		}
		return info;
	}
	
	@Transactional
	@RequestMapping(value = "/deviceOfferMonthQuery", method = RequestMethod.POST)
	public RetInfoDto deviceOfferMonthQuery(@RequestBody QueryParm dto, @RequestHeader String Authorization) {

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
			dto.setAppId(jwtToken.getApp_id());
			List<Map<String, Object>> data = this.accountQueryService.deviceOfferMonthQuery(dto);
			if (data.size() == 0) {
				info.meta.put("message", "no data for deviceOfferMonthQuery stats.");
				info.meta.put("code", ConstParm.SUCESS_CODE);
			} else {
				info.meta.put("code", ConstParm.SUCESS_CODE);
				info.data.put("data", data);
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "Stats deviceFundMonthQuery Fail.");
			info.meta.put("code", ConstParm.ERR_QUERY_DEVICEOFFERMONTHQUERY);
		}
		return info;
	}

	@Transactional
	@RequestMapping(value = "/deviceOfferWeekQuery", method = RequestMethod.POST)
	public RetInfoDto deviceOfferWeekQuery(@RequestBody QueryParm dto, @RequestHeader String Authorization) {
	
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
			dto.setAppId(jwtToken.getApp_id());
			List<Map<String, Object>> data = this.accountQueryService.deviceOfferWeekQuery(dto);
			if (data.size() == 0) {
				info.meta.put("message", "no data for deviceOfferWeekQuery stats.");
				info.meta.put("code", ConstParm.SUCESS_CODE);
			} else {
				info.meta.put("code", ConstParm.SUCESS_CODE);
				info.data.put("data", data);
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "Stats deviceOfferWeekQuery Fail.");
			info.meta.put("code", ConstParm.ERR_QUERY_DEVICEOFFERWEEKQUERY);
		}
		return info;
	}

	@Transactional
	@RequestMapping(value = "/merchantAccountQuery", method = RequestMethod.POST)
	public RetInfoDto merchantAccountQuery(@RequestBody QueryParm dto, @RequestHeader String Authorization) {
	
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
			dto.setAppId(jwtToken.getApp_id());
			List<Map<String, Object>> data = this.accountQueryService.merchantAccountQuery(dto);
			if (data.size() == 0) {
				info.meta.put("message", "no data for merchantAccountQuery stats.");
				info.meta.put("code", ConstParm.SUCESS_CODE);
			} else {
				info.meta.put("code", ConstParm.SUCESS_CODE);
				info.data.put("data", data);
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "Stats merchantAccountQuery Fail.");
			info.meta.put("code", ConstParm.ERR_QUERY_MERCHANTACCOUNTQUERY);
		}
		return info;
	}

	@Transactional
	@RequestMapping(value = "/merchantOfferMonthQuery", method = RequestMethod.POST)
	public RetInfoDto merchantOfferMonthQuery(@RequestBody QueryParm dto, @RequestHeader String Authorization) {

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
			dto.setAppId(jwtToken.getApp_id());
			List<Map<String, Object>> data = this.accountQueryService.merchantOfferMonthQuery(dto);
			if (data.size() == 0) {
				info.meta.put("message", "no data for merChantFundMonthQuery stats.");
				info.meta.put("code", ConstParm.SUCESS_CODE);
			} else {
				info.meta.put("code", ConstParm.SUCESS_CODE);
				info.data.put("data", data);
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "Stats merchantOfferMonthQuery Fail.");
			info.meta.put("code", ConstParm.ERR_QUERY_MERCHANTOFFERMONTHQUERY);
		}
		return info;
	}
	
	@Transactional
	@RequestMapping(value = "/merchantOfferWeekQuery", method = RequestMethod.POST)
	public RetInfoDto merchantOfferWeekQuery(@RequestBody QueryParm dto, @RequestHeader String Authorization) {

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
			dto.setAppId(jwtToken.getApp_id());
			List<Map<String, Object>> data = this.accountQueryService.merchantOfferWeekQuery(dto);
			if (data.size() == 0) {
				info.meta.put("message", "no data for merchantOfferWeekQuery stats.");
				info.meta.put("code", ConstParm.SUCESS_CODE);
			} else {
				info.meta.put("code", ConstParm.SUCESS_CODE);
				info.data.put("data", data);
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "Stats merchantOfferWeekQuery Fail.");
			info.meta.put("code", ConstParm.ERR_QUERY_MERCHANTOFFERWEEKQUERY);
		}
		return info;
	}
}
