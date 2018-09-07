package com.yjyz.iot.dict.action;

import java.util.List;

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
import com.yjyz.iot.comm.PCAQuery;
import com.yjyz.iot.comm.RetInfoDto;
import com.yjyz.iot.dict.entity.DictRegion;
import com.yjyz.iot.dict.service.IDictService;
import com.yjyz.iot.security.utils.ClientJwtUtil;

/**
 * 
 * @class :ChargeController
 * @TODO :
 * @author:Herolizhen
 * @date :2017年11月7日下午5:35:35
 */
@RestController
@RequestMapping("/dict")
public class RegionController {
	private static Log log = LogFactory.getLog(RegionController.class);
	@Autowired
	private IDictService dictService;
	@Autowired
	ClientJwtUtil jwtUtil;

	@Transactional
	@RequestMapping(value = "/selRegionByPCA", method = RequestMethod.POST)
	public RetInfoDto selRegionByPCA(@RequestBody PCAQuery dto, @RequestHeader String Authorization) {

		RetInfoDto info = new RetInfoDto();
		try {
			jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}
		if (dto.getProvName() == null || dto.getCityName() == null || dto.getAreaName() == null) {
			info.meta.put("message", "parma  is wrong!");
			info.meta.put("code", ConstParm.ERR_SELECT);
			return info;
		}
		try {
			List<DictRegion> regList = this.dictService.selectByPCA(dto);
			info.meta.put("code", ConstParm.SUCESS_CODE);
			info.data.put("data", regList);
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "selectByPCA fail.");
			info.meta.put("code", ConstParm.ERR_SELECT);
		}
		return info;
	}

	@Transactional
	@RequestMapping(value = "/selRegionByPCAFree", method = RequestMethod.POST)
	public RetInfoDto selRegionByPCAFree(@RequestBody PCAQuery dto, @RequestHeader String Authorization) {

		RetInfoDto info = new RetInfoDto();
		try {
			jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}
	
		try {
			List<DictRegion> regList = this.dictService.selectByPCAFree(dto);
			info.meta.put("code", ConstParm.SUCESS_CODE);
			info.data.put("data", regList);
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "selectByPCA fail.");
			info.meta.put("code", ConstParm.ERR_SELECT);
		}
		return info;
	}
}
