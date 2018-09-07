package com.yjyz.iot.share.dto;

public class ChipsConfirmDto {
	private String orderNo;

	private String type;

	private String status;

	private Integer chips;

	public String getOrderNo() {
		return orderNo;
	}

	public void setOrderNo(String orderNo) {
		this.orderNo = orderNo;
	}

	public String getType() {
		return type;
	}

	public void setType(String type) {
		this.type = type;
	}

	public Integer getChips() {
		return chips;
	}

	public void setChips(Integer chips) {
		this.chips = chips;
	}

	public String getStatus() {
		return status;
	}

	public void setStatus(String status) {
		this.status = status;
	}

}
