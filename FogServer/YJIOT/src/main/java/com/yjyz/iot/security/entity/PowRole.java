package com.yjyz.iot.security.entity;

public class PowRole extends PowRoleKey {
	private String roleName;

	public String getRoleName() {
		return roleName;
	}

	public void setRoleName(String roleName) {
		this.roleName = roleName == null ? null : roleName.trim();
	}
}