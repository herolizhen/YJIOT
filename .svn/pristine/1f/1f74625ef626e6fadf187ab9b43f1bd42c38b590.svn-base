package com.yjyz.iot.security.utils;

import java.lang.reflect.Field;
import java.lang.reflect.Modifier;
import java.util.TreeMap;

import com.alibaba.fastjson.JSONObject;

import io.jsonwebtoken.Claims;

/**
 * @class :ClientJwtToken
 * @TODO :
 * @author:Herolizhen
 * @date :2017年10月27日上午11:52:08
 */
public class ClientJwtToken {

	private long orig_iat;
	private String user_id;
	private String device_id;
	private String app_id;
	private long exp;

	public long getOrig_iat() {
		return orig_iat;
	}

	public void setOrig_iat(long orig_iat) {
		this.orig_iat = orig_iat;
	}

	public String getUser_id() {
		return user_id;
	}

	public void setUser_id(String user_id) {
		this.user_id = user_id;
	}

	public String getDevice_id() {
		return device_id;
	}

	public void setDeviceid(String device_id) {
		this.device_id = device_id;
	}

	public long getExp() {
		return exp;
	}

	public void setExp(long exp) {
		this.exp = exp;
	}

	public ClientJwtToken(String user_id, String device_id, String app_id) {
		this.user_id = user_id;
		this.app_id = app_id;
		this.device_id = device_id;
	}

	public ClientJwtToken(String user_id, String app_id) {
		this.user_id = user_id;
		this.app_id = app_id;
	}

	public ClientJwtToken(String user_id) {
		this.user_id = user_id;
	}

	public ClientJwtToken() {
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

	public void toSingToken(Claims claims) {
		this.setUser_id((String) claims.get("user_id"));
		this.setApp_id((String) claims.get("app_id"));
		this.setOrig_iat((long) claims.get("orig_iat"));
		this.setDeviceid((String) claims.get("deviceid"));
		this.setExp((long) claims.get("exp"));
	}

	public String getApp_id() {
		return app_id;
	}

	public void setApp_id(String app_id) {
		this.app_id = app_id;
	}

}
