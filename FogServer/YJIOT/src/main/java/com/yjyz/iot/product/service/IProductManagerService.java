package com.yjyz.iot.product.service;

import java.util.List;

import com.yjyz.iot.product.entity.ProdInfo;
import com.yjyz.iot.product.entity.ProdQnr;

public interface IProductManagerService {
	ProdQnr selectPQByPK(String freedbackId) throws Exception;
	
	List<ProdInfo> selectPQByAppId(String appId) throws Exception;
	
	ProdQnr insertPQ(ProdQnr record) throws Exception;

	int updatePQByPK(ProdQnr record) throws Exception;

	int deletePQByPK(String freedbackId) throws Exception;

	ProdInfo selectPIByPK(String productId) throws Exception;

	ProdInfo insertPI(ProdInfo record) throws Exception;

	int updatePIByPK(ProdInfo record) throws Exception;

	int deletePIByPK(String productId) throws Exception;

}
