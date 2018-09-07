package com.yjyz.iot.share.service;

import java.util.List;

import com.yjyz.iot.device.entity.DevConsume;
import com.yjyz.iot.security.entity.PowClientUser;

public interface IClientService {
	PowClientUser register(PowClientUser clientUser) throws Exception;

	PowClientUser getUserByOpenId(PowClientUser clientUser) throws Exception;

	List<DevConsume> getConsumeHistory(String deviceId, String clientId) throws Exception;

	int preBill(DevConsume devConsume) throws Exception;

	int consume(String openId, DevConsume consume) throws Exception;

	DevConsume getUnCosumeBill(String deviceMac) throws Exception;

	public PowClientUser getUserByOrderNo(String orderNo) throws Exception;
}