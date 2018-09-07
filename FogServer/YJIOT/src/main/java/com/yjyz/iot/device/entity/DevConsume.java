package com.yjyz.iot.device.entity;

import java.util.Date;

public class DevConsume extends DevConsumeKey {
	private String orderNo;

	private Integer totalFree;

	private String type;

	private String prepayId;

	private String payNo;

	private String mchId;

	private Date billBeing;

	private Date billExport;

	private String status;

	private Integer chips;

	public String getOrderNo() {
		return orderNo;
	}

	public void setOrderNo(String orderNo) {
		this.orderNo = orderNo == null ? null : orderNo.trim();
	}

	public Integer getTotalFree() {
		return totalFree;
	}

	public void setTotalFree(Integer totalFree) {
		this.totalFree = totalFree;
	}

	public String getType() {
		return type;
	}

	public void setType(String type) {
		this.type = type == null ? null : type.trim();
	}

	public String getPrepayId() {
		return prepayId;
	}

	public void setPrepayId(String prepayId) {
		this.prepayId = prepayId == null ? null : prepayId.trim();
	}

	public String getPayNo() {
		return payNo;
	}

	public void setPayNo(String payNo) {
		this.payNo = payNo == null ? null : payNo.trim();
	}

	public String getMchId() {
		return mchId;
	}

	public void setMchId(String mchId) {
		this.mchId = mchId == null ? null : mchId.trim();
	}

	public Date getBillBeing() {
		return billBeing;
	}

	public void setBillBeing(Date billBeing) {
		this.billBeing = billBeing;
	}

	public Date getBillExport() {
		return billExport;
	}

	public void setBillExport(Date billExport) {
		this.billExport = billExport;
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