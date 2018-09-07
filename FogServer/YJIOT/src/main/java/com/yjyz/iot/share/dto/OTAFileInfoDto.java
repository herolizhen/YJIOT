package com.yjyz.iot.share.dto;

import java.lang.reflect.Field;
import java.lang.reflect.Modifier;
import java.util.TreeMap;

import com.alibaba.fastjson.JSONObject;

public class OTAFileInfoDto {
	private long id;
	private String otaid;
	private String description;
	private String upgrade;
	private String firmware;
	private String md5;
	private String fileurl;
	private String size;
	private String uploadTime;
	private String status;
	private String effectTime;
	private long verson;
	private String productid;
	private String modulename;

	public OTAFileInfoDto() {
	}

	public long getId() {
		return id;
	}

	public void setId(long id) {
		this.id = id;
	}

	public String getOtaid() {
		return otaid;
	}

	public void setOtaid(String otaid) {
		this.otaid = otaid;
	}

	public String getDescription() {
		return description;
	}

	public void setDescription(String description) {
		this.description = description;
	}

	public String getUpgrade() {
		return upgrade;
	}

	public void setUpgrade(String upgrade) {
		this.upgrade = upgrade;
	}

	public String getFirmware() {
		return firmware;
	}

	public void setFirmware(String firmware) {
		this.firmware = firmware;
	}

	public String getMd5() {
		return md5;
	}

	public void setMd5(String md5) {
		this.md5 = md5;
	}

	public String getFileurl() {
		return fileurl;
	}

	public void setFileurl(String fileurl) {
		this.fileurl = fileurl;
	}

	public String getSize() {
		return size;
	}

	public void setSize(String size) {
		this.size = size;
	}

	public String getUploadTime() {
		return uploadTime;
	}

	public void setUpload_time(String uploadTime) {
		this.uploadTime = uploadTime;
	}

	public String getStatus() {
		return status;
	}

	public void setStatus(String status) {
		this.status = status;
	}

	public String getEffectTime() {
		return effectTime;
	}

	public void setEffect_time(String effectTime) {
		this.effectTime = effectTime;
	}

	public long getVerson() {
		return verson;
	}

	public void setVerson(long verson) {
		this.verson = verson;
	}

	public String getProductid() {
		return productid;
	}

	public void setProductid(String productid) {
		this.productid = productid;
	}

	public String getModulename() {
		return modulename;
	}

	public void setModulename(String modulename) {
		this.modulename = modulename;
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
}