package com.yjyz.iot.product.service.impl;

import java.util.List;
import java.util.UUID;

import javax.annotation.Resource;

import org.springframework.stereotype.Service;

import com.yjyz.iot.product.dao.ProdInfoMapper;
import com.yjyz.iot.product.dao.ProdQnrMapper;
import com.yjyz.iot.product.entity.ProdInfo;
import com.yjyz.iot.product.entity.ProdQnr;
import com.yjyz.iot.product.service.IProductManagerService;

@Service("productManagerService")
public class ProductManagerServiceImpl implements IProductManagerService {

	@Resource
	ProdQnrMapper productQuestionnaireDao;
	@Resource
	ProdInfoMapper productInfoDao;

	@Override
	public ProdQnr selectPQByPK(String freedbackId) throws Exception {
		return this.productQuestionnaireDao.selectByPrimaryKey(freedbackId);
	}

	@Override
	public ProdQnr insertPQ(ProdQnr record) throws Exception {
		record.setQnrId(UUID.randomUUID().toString());
		int ret = this.productQuestionnaireDao.insertSelective(record);
		if (ret == 1) {
			return record;
		} else {
			return null;
		}
	}

	@Override
	public int updatePQByPK(ProdQnr record) throws Exception {
		return this.productQuestionnaireDao.updateByPrimaryKeySelective(record);
	}

	@Override
	public int deletePQByPK(String freedbackId) throws Exception {
		return this.productQuestionnaireDao.deleteByPrimaryKey(freedbackId);
	}

	@Override
	public ProdInfo selectPIByPK(String productId) throws Exception {
		return this.productInfoDao.selectByPrimaryKey(productId);
	}

	@Override
	public ProdInfo insertPI(ProdInfo record) throws Exception {
		record.setProductId(UUID.randomUUID().toString());
		int ret = this.productInfoDao.insertSelective(record);
		if (ret == 1) {
			return record;
		} else {
			return null;
		}
	}

	@Override
	public int updatePIByPK(ProdInfo record) throws Exception {
		return this.productInfoDao.updateByPrimaryKeySelective(record);
	}

	@Override
	public int deletePIByPK(String productId) throws Exception {
		return this.productQuestionnaireDao.deleteByPrimaryKey(productId);
	}

	@Override
	public List<ProdInfo> selectPQByAppId(String appId) throws Exception {
		return  this.productInfoDao.selectByAppId(appId);
	}

}
