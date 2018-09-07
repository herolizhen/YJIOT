package com.yjyz.iot.device.entity;

public class DevRelationKey {
    private String deviceId;

    private String deviceIdChild;

    public String getDeviceId() {
        return deviceId;
    }

    public void setDeviceId(String deviceId) {
        this.deviceId = deviceId == null ? null : deviceId.trim();
    }

    public String getDeviceIdChild() {
        return deviceIdChild;
    }

    public void setDeviceIdChild(String deviceIdChild) {
        this.deviceIdChild = deviceIdChild == null ? null : deviceIdChild.trim();
    }
}