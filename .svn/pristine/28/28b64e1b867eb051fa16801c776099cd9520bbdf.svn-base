package com;

import java.lang.reflect.Field;
import java.lang.reflect.Modifier;
import java.util.Date;
import java.util.TreeMap;
import java.util.UUID;

import com.alibaba.fastjson.JSONObject;

public class SignToken {
	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public String getMid() {
		return mid;
	}

	public void setMid(String mid) {
		this.mid = mid;
	}

	public String getDocId() {
		return docId;
	}

	public void setDocId(String docId) {
		this.docId = docId;
	}

	public String getDevId() {
		return devId;
	}

	public void setDevId(String devId) {
		this.devId = devId;
	}

	public Date getCreateTime() {
		return createTime;
	}

	public void setCreateTime(Date createTime) {
		this.createTime = createTime;
	}

	public Date getExpiredIn() {
		return expiredIn;
	}

	public void setExpiredIn(Date expiredIn) {
		this.expiredIn = expiredIn;
	}

	public String getValue() {
		return value;
	}

	public void setValue(String value) {
		this.value = value;
	}

	private String id; // token对外的ID号

	private String mid; // 开发者编号
	private String docId; // 合同编号
	private String devId; // 签约的ID号码

	private Date createTime; // Token的创建时间
	private Date expiredIn; // Token的过期时间

	private String value; // token的值

	public SignToken(String mid, String docId, String devId) {
		this.id = getUID();
		this.mid = mid;
		this.docId = docId;
		this.devId = devId;
	}

	public static synchronized String getUID() {
		UUID uuid = UUID.randomUUID();
		return uuid.toString().replace("-", "");
	}

	public String toJSONString() {
		return this.toJSONObject().toJSONString();
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
			// if (!Modifier.isPublic(modifier) || Modifier.isStatic(modifier)
			// || Modifier.isFinal(modifier)) {
			// continue;
			// }
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