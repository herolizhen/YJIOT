package com.yjyz.iot.share.service;

import java.util.Map;

import com.yjyz.iot.device.entity.DeviceInfo;
import com.yjyz.iot.ota.entity.OTAFileInfo;

public interface IM26DeviceService {

	public DeviceInfo activate(DeviceInfo deviceInfo) throws Exception;

	public OTAFileInfo otaCheck(DeviceInfo deviceInfo) throws Exception;

	public boolean uploadData(String deviceId, boolean isSave, String jsonData) throws Exception;

	public Map<String, Object> syncStatus(String deviceId, String jsonData) throws Exception;

	public boolean chipsConfirm(String deviceId, String orderNo) throws Exception;

}
