package com.yjyz.iot.ota.entity;

import java.lang.reflect.Field;
import java.lang.reflect.Modifier;
import java.util.Date;
import java.util.TreeMap;

import com.alibaba.fastjson.JSONObject;

public class OTAFileInfo {
	private Integer id;

	private String otaId;

	private String description;

	private String upgrade;

	private String firmware;

	private String md5;

	private String fileurl;

	private String size;

	private Date uploadTime;

	private String status;

	private Date effectTime;

	private Integer version;

	private String productId;

	private String modulename;

	public Integer getId() {
		return id;
	}

	public void setId(Integer id) {
		this.id = id;
	}

	public String getOtaId() {
		return otaId;
	}

	public void setOtaId(String otaId) {
		this.otaId = otaId == null ? null : otaId.trim();
	}

	public String getDescription() {
		return description;
	}

	public void setDescription(String description) {
		this.description = description == null ? null : description.trim();
	}

	public String getUpgrade() {
		return upgrade;
	}

	public void setUpgrade(String upgrade) {
		this.upgrade = upgrade == null ? null : upgrade.trim();
	}

	public String getFirmware() {
		return firmware;
	}

	public void setFirmware(String firmware) {
		this.firmware = firmware == null ? null : firmware.trim();
	}

	public String getMd5() {
		return md5;
	}

	public void setMd5(String md5) {
		this.md5 = md5 == null ? null : md5.trim();
	}

	public String getFileurl() {
		return fileurl;
	}

	public void setFileurl(String fileurl) {
		this.fileurl = fileurl == null ? null : fileurl.trim();
	}

	public String getSize() {
		return size;
	}

	public void setSize(String size) {
		this.size = size == null ? null : size.trim();
	}

	public Date getUploadTime() {
		return uploadTime;
	}

	public void setUploadTime(Date uploadTime) {
		this.uploadTime = uploadTime;
	}

	public String getStatus() {
		return status;
	}

	public void setStatus(String status) {
		this.status = status == null ? null : status.trim();
	}

	public Date getEffectTime() {
		return effectTime;
	}

	public void setEffectTime(Date effectTime) {
		this.effectTime = effectTime;
	}

	public String getProductId() {
		return productId;
	}

	public void setProductId(String productId) {
		this.productId = productId == null ? null : productId.trim();
	}

	public String getModulename() {
		return modulename;
	}

	public void setModulename(String modulename) {
		this.modulename = modulename == null ? null : modulename.trim();
	}

	public JSONObject toJSONObject() {
		Field[] fields = this.getClass().getDeclaredFields();
		if (fields.length == 0) {
			return null;
		}
		TreeMap<String, Object> map = new TreeMap<String, Object>();
		for (int i = 0; i < fields.length; i++) {
			Field field = fields[i];
			int modifier = field.getModifiers();
			if (Modifier.isStatic(modifier) || Modifier.isFinal(modifier)) {
				continue;
			}
			field.setAccessible(true);
			String name = field.getName();
			Object value = null;
			try {
				value = field.get(this);
			} catch (IllegalArgumentException e) {
				continue;
			} catch (IllegalAccessException e) {
				continue;
			}
			map.put(name, value);
		}
		JSONObject object = new JSONObject(map);
		return object;
	}

	public Integer getVersion() {
		return version;
	}

	public void setVersion(Integer version) {
		this.version = version;
	}
	
}