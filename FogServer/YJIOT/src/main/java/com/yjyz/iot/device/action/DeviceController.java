package com.yjyz.iot.device.action;

import java.util.List;
import java.util.Map;

import javax.annotation.Resource;

import org.apache.commons.lang3.ArrayUtils;
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
import com.yjyz.iot.comm.GISQuery;
import com.yjyz.iot.comm.RetInfoDto;
import com.yjyz.iot.device.dto.DevCommDto;
import com.yjyz.iot.device.entity.DevAccount;
import com.yjyz.iot.device.entity.DevAccountMini;
import com.yjyz.iot.device.entity.DevConsume;
import com.yjyz.iot.device.entity.DeviceInfo;
import com.yjyz.iot.device.service.IDevRealTimeService;
import com.yjyz.iot.device.service.IDeviceService;
import com.yjyz.iot.dict.entity.DictCharge;
import com.yjyz.iot.mq.producer.topic.TopicSender;
import com.yjyz.iot.security.utils.BASE64Util;
import com.yjyz.iot.security.utils.ClientJwtToken;
import com.yjyz.iot.security.utils.ClientJwtUtil;
import com.yjyz.iot.security.utils.MD5Util;

/**
 * @class :DeviceController
 * @TODO :
 * @author:Herolizhen
 * @date :2017年11月7日下午4:50:35
 */
@RestController
@RequestMapping("/device")
public class DeviceController {

	@Autowired
	private IDeviceService deviceService;
	@Autowired
	private IDevRealTimeService devRealTimeService;
	@Autowired
	MD5Util md5Util;
	@Autowired
	BASE64Util base64Util;
	@Resource
	@Autowired
	private TopicSender topicSender;

	private static Log log = LogFactory.getLog(DeviceController.class);

	@Autowired
	ClientJwtUtil jwtUtil;

	@Transactional
	@RequestMapping(value = "/getLastDayHourStats", method = RequestMethod.POST)
	public RetInfoDto getLastDayMaxHour(@RequestBody DevCommDto dto, @RequestHeader String Authorization) {
		RetInfoDto info = new RetInfoDto();
		try {
			jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}

		if (!ArrayUtils.contains(ConstParm.STATS_TYPE, dto.getType().toLowerCase())) {
			info.meta.put("message", "stats method is wrong!");
			info.meta.put("code", ConstParm.ERR_DEVICE_STATS_METHOD);
			return info;
		}

		try {
			List<Map<String, Object>> data = this.devRealTimeService.getLastDayStats(dto.getDeviceId(), dto.getType());
			if (data.size() == 0) {
				info.meta.put("message", "no data for this stats.");
				info.meta.put("code", ConstParm.ERR_NO_STATS);
			} else {
				info.meta.put("code", ConstParm.SUCESS_CODE);
				info.data.put("data", data);
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "Stats Last Day By Hour Fail.");
			info.meta.put("code", ConstParm.ERR_DEVICE_DAYSTATS);
		}
		return info;
	}

	@Transactional
	@RequestMapping(value = "/getLastWeekDayStats", method = RequestMethod.POST)
	public RetInfoDto getLastWeekDayStats(@RequestBody DevCommDto dto, @RequestHeader String Authorization) {
		RetInfoDto info = new RetInfoDto();
		try {
			jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}

		if (!ArrayUtils.contains(ConstParm.STATS_TYPE, dto.getType().toLowerCase())) {
			info.meta.put("message", "stats method is wrong!");
			info.meta.put("code", ConstParm.ERR_DEVICE_STATS_METHOD);
			return info;
		}

		try {
			List<Map<String, Object>> data = this.devRealTimeService.getLastWeekStats(dto.getDeviceId(), dto.getType());
			if (data.size() == 0) {
				info.meta.put("message", "no data for this stats.");
				info.meta.put("code", ConstParm.ERR_NO_STATS);
			} else {
				info.meta.put("code", ConstParm.SUCESS_CODE);
				info.data.put("data", data);
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "Stats Last Day By Hour Fail.");
			info.meta.put("code", ConstParm.ERR_DEVICE_WEEKSTATS);
		}
		return info;
	}

	@Transactional
	@RequestMapping(value = "/getLastMonthDayStats", method = RequestMethod.POST)
	public RetInfoDto getLastMonthDayStats(@RequestBody DevCommDto dto, @RequestHeader String Authorization) {
		RetInfoDto info = new RetInfoDto();
		try {
			jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}

		if (!ArrayUtils.contains(ConstParm.STATS_TYPE, dto.getType().toLowerCase())) {
			info.meta.put("message", "stats method is wrong!");
			info.meta.put("code", ConstParm.ERR_DEVICE_STATS_METHOD);
			return info;
		}

		try {
			List<Map<String, Object>> data = this.devRealTimeService.getLastMonthStats(dto.getDeviceId(),
					dto.getType());
			if (data.size() == 0) {
				info.meta.put("message", "no data for this stats.");
				info.meta.put("code", ConstParm.ERR_NO_STATS);
			} else {
				info.meta.put("code", ConstParm.SUCESS_CODE);
				info.data.put("data", data);
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "Stats Last Day By Hour Fail.");
			info.meta.put("code", ConstParm.ERR_DEVICE_MONTHSTATS);
		}
		return info;
	}

	@Transactional
	@RequestMapping(value = "/getLastYearMonthStats", method = RequestMethod.POST)
	public RetInfoDto getLastYearMonthStats(@RequestBody DevCommDto dto, @RequestHeader String Authorization) {
		RetInfoDto info = new RetInfoDto();
		try {
			jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}

		if (!ArrayUtils.contains(ConstParm.STATS_TYPE, dto.getType().toLowerCase())) {
			info.meta.put("message", "stats method is wrong!");
			info.meta.put("code", ConstParm.ERR_DEVICE_STATS_METHOD);
			return info;
		}

		try {
			List<Map<String, Object>> data = this.devRealTimeService.getLastYearStats(dto.getDeviceId(), dto.getType());
			if (data.size() == 0) {
				info.meta.put("message", "no data for this stats.");
				info.meta.put("code", ConstParm.ERR_NO_STATS);
			} else {
				info.meta.put("code", ConstParm.SUCESS_CODE);
				info.data.put("data", data);
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "Stats Last Day By Hour Fail.");
			info.meta.put("code", ConstParm.ERR_DEVICE_YEARSTATS);
		}
		return info;
	}

	@Transactional
	@RequestMapping(value = "/getDevChargeInfo", method = RequestMethod.POST)
	public RetInfoDto getDevChargeInfo(@RequestBody DevCommDto dto, @RequestHeader String Authorization) {
		RetInfoDto info = new RetInfoDto();
		try {
			jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}

		try {
			List<DictCharge> chargeList = this.deviceService.getDevChargeInfo(dto.getDeviceId());
			if (chargeList.size() == 0) {
				info.meta.put("message", "no data for this stats.");
				info.meta.put("code", ConstParm.ERR_NO_DEVINFO);
			} else {
				info.meta.put("code", ConstParm.SUCESS_CODE);
				info.data.put("data", chargeList);
			}

		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "getDevChargeInfo fail.");
			info.meta.put("code", ConstParm.ERR_DEVICE_GETDEVCHARGEINFO);
		}
		return info;
	}

	@Transactional
	@RequestMapping(value = "/getDevInfoById", method = RequestMethod.POST)
	public RetInfoDto getDevInfoById(@RequestBody DevCommDto dto, @RequestHeader String Authorization) {
		RetInfoDto info = new RetInfoDto();
		try {
			jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}

		try {
			DeviceInfo devInfo = this.deviceService.getDevInfo(dto.getDeviceId());
			if (devInfo == null) {
				info.meta.put("message", "no dvice for this id.");
				info.meta.put("code", ConstParm.ERR_NO_DEVINFO);
			} else {
				info.meta.put("code", ConstParm.SUCESS_CODE);
				info.data.put("devInfo", devInfo);
			}

		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "getDevInfoById fail.");
			info.meta.put("code", ConstParm.ERR_DEVICE_GETDEVINFOBYID);
		}
		return info;
	}

	@Transactional
	@RequestMapping(value = "/getDevInfoByMac", method = RequestMethod.POST)
	public RetInfoDto getDevInfoByMac(@RequestBody DevCommDto dto, @RequestHeader String Authorization) {
		RetInfoDto info = new RetInfoDto();
		try {
			jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}

		try {
			DeviceInfo devInfo = this.deviceService.getDevInfoByMac(dto.getDeviceMac());
			if (devInfo == null) {
				info.meta.put("message", "no device for this mac.");
				info.meta.put("code", ConstParm.ERR_NO_DEVINFO);
			} else {
				info.meta.put("code", ConstParm.SUCESS_CODE);
				info.data.put("devInfo", devInfo);
			}

		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "getDevInfoByMac fail.");
			info.meta.put("code", ConstParm.ERR_DEVICE_GETDEVINFOBYMAC);
		}
		return info;
	}

	/**
	 * @name:getDevInfoByOrderNo
	 * @TODO:根据订单号获取设备信息
	 * @date:2017年12月25日 上午9:40:55
	 * @param dto
	 * @param Authorization
	 * @return RetInfoDto
	 */
	@Transactional
	@RequestMapping(value = "/getDevInfoByOrderNo", method = RequestMethod.POST)
	public RetInfoDto getDevInfoByOrderNo(@RequestBody DevCommDto dto, @RequestHeader String Authorization) {
		RetInfoDto info = new RetInfoDto();
		try {
			jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}

		try {
			DeviceInfo devInfo = this.deviceService.getDevInfoByOrderNo(dto.getOrderNo());
			if (devInfo == null) {
				info.meta.put("message", "no device for this orderno.");
				info.meta.put("code", ConstParm.ERR_NO_DEVINFO);
			} else {
				info.meta.put("code", ConstParm.SUCESS_CODE);
				info.data.put("devInfo", devInfo);
			}

		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "getDevInfoByOrderNo fail.");
			info.meta.put("code", ConstParm.ERR_DEVICE_GETDEVINFOBYORDERNO);
		}
		return info;
	}

	/**
	 * @name:getDevAccount
	 * @TODO:获取设备台账信息
	 * @date:2017年12月25日 上午9:40:40
	 * @param dto
	 * @param Authorization
	 * @return RetInfoDto
	 */
	@Transactional
	@RequestMapping(value = "/getDevAccount", method = RequestMethod.POST)
	public RetInfoDto getDevAccount(@RequestBody DevCommDto dto, @RequestHeader String Authorization) {
		RetInfoDto info = new RetInfoDto();
		try {
			jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}

		try {
			DevAccount devAccount = this.deviceService.getDevAccount(dto.getDeviceId());
			if (devAccount == null) {
				info.meta.put("message", "no device  account for this id.");
				info.meta.put("code", ConstParm.ERR_NO_DEVINFO);
			} else {
				info.meta.put("code", ConstParm.SUCESS_CODE);
				info.data.put("devAccount", devAccount);
			}

		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "getDevAccount fail.");
			info.meta.put("code", ConstParm.ERR_DEVICE_GETDEVACCOUNT);
		}
		return info;
	}

	/**
	 * @name:getDevAccountByOwnerCode
	 * @TODO:获取设备台账信息
	 * @date:2017年12月25日 上午9:40:22
	 * @param dto
	 * @param Authorization
	 * @return RetInfoDto
	 */
	@Transactional
	@RequestMapping(value = "/getDevAccountByOwnerCode", method = RequestMethod.POST)
	public RetInfoDto getDevAccountByOwnerCode(@RequestBody DevCommDto dto, @RequestHeader String Authorization) {
		RetInfoDto info = new RetInfoDto();
		try {
			jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}

		try {
			List<DevAccount> devAccountList = this.deviceService.getDevAccountByOwnerCode(dto.getOwnerCode());
			if (devAccountList == null) {
				info.meta.put("message", "no device  account for this MerchantCode.");
				info.meta.put("code", ConstParm.ERR_NO_DEVINFO);
			} else {
				info.meta.put("code", ConstParm.SUCESS_CODE);
				info.data.put("devAccountList", devAccountList);
			}

		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "getDevAccountByOwnerCode fail.");
			info.meta.put("code", ConstParm.ERR_DEVICE_GETDEVACCOUNT);
		}
		return info;
	}

	/**
	 * @name:getDevConsume
	 * @TODO:获取设备的消费清单
	 * @date:2017年12月25日 上午9:39:47
	 * @param dto
	 * @param Authorization
	 * @return RetInfoDto
	 */
	@Transactional
	@RequestMapping(value = "/getDevConsume", method = RequestMethod.POST)
	public RetInfoDto getDevConsume(@RequestBody DevCommDto dto, @RequestHeader String Authorization) {
		RetInfoDto info = new RetInfoDto();
		try {
			jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}

		try {
			List<DevConsume> data = this.deviceService.getConsume(dto.getDeviceId());
			if (data.size() == 0) {
				info.meta.put("message", "no data for this stats.");
				info.meta.put("code", ConstParm.ERR_NO_CONSUME);
			} else {
				info.meta.put("code", ConstParm.SUCESS_CODE);
				info.data.put("data", data);
			}

		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "getDevConsume fail.");
			info.meta.put("code", ConstParm.ERR_DEVICE_GETDEVCONSUME);
		}
		return info;
	}

	/**
	 * @name:sendCommand
	 * @TODO:控制设备
	 * @date:2017年12月25日 上午9:39:34
	 * @param dto
	 * @param Authorization
	 * @return RetInfoDto
	 */
	@Transactional
	@RequestMapping(value = "/sendCommand", method = RequestMethod.POST)
	public RetInfoDto sendCommand(@RequestBody DevCommDto dto, @RequestHeader String Authorization) {
		RetInfoDto info = new RetInfoDto();
		ClientJwtToken jwtToken;
		try {
			jwtToken = jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}

		String validSend = dto.getPayload().toString().toUpperCase();

		if (validSend.contains("CHIPS") || (validSend.contains("TYPE") && !validSend.contains("EXAMTYPE"))) {
			info.meta.put("message", "illegal Command send fail.");
			info.meta.put("code", ConstParm.ERR_ILLEGAL_COMMAND);
			return info;
		}

		try {

			Boolean isOk = this.deviceService.sendCommand(dto, jwtToken.getUser_id());
			if (!isOk) {
				info.meta.put("message", "sendCommand  fail.");
				info.meta.put("code", ConstParm.ERR_NO_DEVICE);
			} else {
				info.meta.put("code", ConstParm.SUCESS_CODE);
			}

		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "sendCommand fail.");
			info.meta.put("code", ConstParm.ERR_DEVICE_SENDCOMMAND);
		}
		return info;
	}

	/**
	 * @name:updateDevAccount
	 * @TODO:更新设备台账信息
	 * @date:2017年12月25日 上午9:39:14
	 * @param dto
	 * @param Authorization
	 * @return RetInfoDto
	 */
	@Transactional
	@RequestMapping(value = "/updateDevAccount", method = RequestMethod.POST)
	public RetInfoDto updateDevAccount(@RequestBody DevAccount dto, @RequestHeader String Authorization) {
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

			Boolean isOk = this.deviceService.updateDevAccount(dto, jwtToken.getUser_id());
			if (!isOk) {
				info.meta.put("message", "updateDevAccount  fail.");
				info.meta.put("code", ConstParm.ERR_DEVICE_UPDATEDEVACCOUNT);
			} else {
				info.meta.put("code", ConstParm.SUCESS_CODE);
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "updateDevAccount fail.");
			info.meta.put("code", ConstParm.ERR_DEVICE_UPDATEDEVACCOUNT);
		}
		return info;
	}

	/**
	 * @name:selectByGisRect
	 * @TODO: 增加APP认证
	 * @date:2018年1月22日 下午1:00:58
	 * @param dto
	 * @param Authorization
	 * @return RetInfoDto
	 */
	@Transactional
	@RequestMapping(value = "/selectByGisRect", method = RequestMethod.POST)
	public RetInfoDto selectByGisRect(@RequestBody GISQuery dto, @RequestHeader String Authorization) {
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
			List<DevAccountMini> list = this.deviceService.selectByGISRect(dto);
			info.meta.put("code", ConstParm.SUCESS_CODE);
			info.data.put("data", list);
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "selectByGISRect fail.");
			info.meta.put("code", ConstParm.ERR_DEVICE_SELECTBYGISRECT);
		}
		return info;
	}

	@Transactional
	@RequestMapping(value = "/updateDevAccountReg", method = RequestMethod.POST)
	public RetInfoDto updateDevAccountReg(@RequestBody DevCommDto dto, @RequestHeader String Authorization) {
		RetInfoDto info = new RetInfoDto();
		// ClientJwtToken jwtToken;
		try {
			// jwtToken =
			jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}

		try {

			Boolean isOk = this.deviceService.updateDevAccount(dto);
			if (!isOk) {
				info.meta.put("message", "updateDevAccount  fail.");
				info.meta.put("code", ConstParm.ERR_DEVICE_UPDATEDEVACCOUNT);
			} else {
				info.meta.put("code", ConstParm.SUCESS_CODE);
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "updateDevAccount fail.");
			info.meta.put("code", ConstParm.ERR_DEVICE_UPDATEDEVACCOUNT);
		}
		return info;
	}

	/**
	 * @name:updateDevAccount
	 * @TODO: 清除设备信息
	 * @date:2018年8月3日 上午11:13:21
	 * @param dto
	 * @param Authorization
	 * @return RetInfoDto
	 */
	@Transactional
	@RequestMapping(value = "/delDevAccount", method = RequestMethod.POST)
	public RetInfoDto delDevAccount(@RequestBody DevCommDto dto, @RequestHeader String Authorization) {
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
			Boolean isOk = this.deviceService.delDevAccount(dto, jwtToken.getUser_id());
			if (!isOk) {
				info.meta.put("message", "delDevAccount  fail.");
				info.meta.put("code", ConstParm.ERR_DEVICE_DELDEVACCOUNT);
			} else {
				info.meta.put("code", ConstParm.SUCESS_CODE);
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "delDevAccount fail.");
			info.meta.put("code", ConstParm.ERR_DEVICE_DELDEVACCOUNT);
		}
		return info;
	}
}
