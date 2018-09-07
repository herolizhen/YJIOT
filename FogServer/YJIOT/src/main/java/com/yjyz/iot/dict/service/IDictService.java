package com.yjyz.iot.dict.service;

import java.util.List;

import com.yjyz.iot.comm.GISQuery;
import com.yjyz.iot.comm.PCAQuery;
import com.yjyz.iot.dict.entity.DictCharge;
import com.yjyz.iot.dict.entity.DictMerchant;
import com.yjyz.iot.dict.entity.DictRegion;

public interface IDictService {

	DictCharge addCharge(DictCharge charge) throws Exception;

	boolean delCharge(DictCharge charge) throws Exception;

	boolean updCharge(DictCharge charge) throws Exception;

	List<DictCharge> selChargeByType(DictCharge charge) throws Exception;

	List<DictCharge> selChargeAll(String appId) throws Exception;

	DictMerchant addMerchant(DictMerchant merchant) throws Exception;

	boolean delMerchant(DictMerchant merchant) throws Exception;

	boolean updMerchant(DictMerchant merchant) throws Exception;

	List<DictMerchant> selMerchantAll(String appId) throws Exception;

	List<DictMerchant> selMerchantByName(String name,String appId) throws Exception;

	List<DictMerchant> selectByGISRect(GISQuery gisQuery) throws Exception;

	List<DictRegion> selectByPCAFree(PCAQuery query) throws Exception;

	List<DictRegion> selectByPCA(PCAQuery query) throws Exception;
}