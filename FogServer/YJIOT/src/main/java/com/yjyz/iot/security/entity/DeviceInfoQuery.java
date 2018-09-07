package com.yjyz.iot.security.entity;

import java.util.Date;

import com.yjyz.iot.device.entity.DeviceInfo;

public class DeviceInfoQuery extends DeviceInfo {
	private Boolean ownType;

	public Boolean getIsOnline() {
		return isOnline;
	}

	public void setIsOnline(Boolean isOnline) {
		this.isOnline = isOnline;
	}

	public Date getLastTime() {
		return lastTime;
	}

	public void setLastTime(Date lastTime) {
		this.lastTime = lastTime;
	}

	private Boolean isOnline;

	private Date lastTime;

	public Boolean getOwnType() {
		return ownType;
	}

	public void setOwnType(Boolean ownType) {
		this.ownType = ownType;
	}
}
