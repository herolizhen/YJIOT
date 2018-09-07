package com.yjyz.iot.share.dto;

public class SyncStatusDto {
	private String product_id;
	private String moduletype;
	private String firmware;
	private String mico;

	public String getProduct_id() {
		return product_id;
	}

	public void setProduct_id(String product_id) {
		this.product_id = product_id;
	}

	public String getModuletype() {
		return moduletype;
	}

	public void setModuletype(String moduletype) {
		this.moduletype = moduletype;
	}

	public String getFirmware() {
		return firmware;
	}

	public void setFirmware(String firmware) {
		this.firmware = firmware;
	}

	public String getMico() {
		return mico;
	}

	public void setMico(String mico) {
		this.mico = mico;
	}

}
