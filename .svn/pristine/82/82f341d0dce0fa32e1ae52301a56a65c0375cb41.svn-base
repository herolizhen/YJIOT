package com.yjyz.iot.dict.service.impl;

import java.util.List;
import java.util.UUID;

import javax.annotation.Resource;

import org.springframework.stereotype.Service;

import com.yjyz.iot.comm.GISQuery;
import com.yjyz.iot.comm.PCAQuery;
import com.yjyz.iot.dict.dao.DictChargeMapper;
import com.yjyz.iot.dict.dao.DictMerchantMapper;
import com.yjyz.iot.dict.dao.DictRegionMapper;
import com.yjyz.iot.dict.entity.DictCharge;
import com.yjyz.iot.dict.entity.DictChargeKey;
import com.yjyz.iot.dict.entity.DictMerchant;
import com.yjyz.iot.dict.entity.DictRegion;
import com.yjyz.iot.dict.service.IDictService;

@Service("dictService")
public class DictServiceImpl implements IDictService {
	@Resource
	DictChargeMapper dictChargeDao;
	@Resource
	DictMerchantMapper dictMerchantDao;
	@Resource
	DictRegionMapper dictRegionDao;

	@Override
	public DictCharge addCharge(DictCharge charge) throws Exception {
		// charge.setChargeType(UUID.randomUUID().toString());
		int ret = this.dictChargeDao.insertSelective(charge);
		if (ret == 1) {
			return charge;
		} else {
			return null;
		}
	}

	@Override
	public boolean delCharge(DictCharge charge) throws Exception {
		DictChargeKey key = new DictChargeKey();
		key.setChargeType(charge.getChargeType());
		key.setDispNo(charge.getDispNo());
		int ret = this.dictChargeDao.deleteByPrimaryKey(key);
		if (ret == 1) {
			return true;
		} else {
			return false;
		}
	}

	@Override
	public boolean updCharge(DictCharge charge) throws Exception {
		int ret = this.dictChargeDao.updateByPrimaryKeySelective(charge);
		if (ret == 1) {
			return true;
		} else {
			return false;
		}
	}

	@Override
	public List<DictCharge> selChargeByType(DictCharge charge) throws Exception {
		return this.dictChargeDao.selectByType(charge.getChargeType(), charge.getAppId());

	}

	@Override
	public List<DictCharge> selChargeAll(String appId) throws Exception {
		return this.dictChargeDao.selectAll(appId);
	}

	@Override
	public DictMerchant addMerchant(DictMerchant merchant) throws Exception {

		merchant.setMerchantCode(UUID.randomUUID().toString());
		if (merchant.getMerchantCode() == null) {
			return null;
		}
		int ret = this.dictMerchantDao.insertSelective(merchant);
		if (ret == 1) {
			return merchant;
		} else {
			return null;
		}
	}

	@Override
	public boolean delMerchant(DictMerchant merchant) throws Exception {

		int ret = this.dictMerchantDao.deleteByPrimaryKey(merchant.getMerchantCode());
		if (ret == 1) {
			return true;
		} else {
			return false;
		}
	}

	@Override
	public boolean updMerchant(DictMerchant merchant) throws Exception {

		DictMerchant merchantOld = this.dictMerchantDao.selectByPrimaryKey(merchant.getMerchantCode());
		if (!merchantOld.getName().equals(merchant.getName()) && merchant.getName() != null) {
			this.dictMerchantDao.updateDevAccountOwnerName(merchant);
		}

		int ret = this.dictMerchantDao.updateByPrimaryKeySelective(merchant);
		if (ret == 1) {
			return true;
		} else {
			return false;
		}
	}

	@Override
	public List<DictMerchant> selMerchantAll(String appId) throws Exception {
		return this.dictMerchantDao.selectAll(appId);
	}

	@Override
	public List<DictMerchant> selMerchantByName(String name, String appId) throws Exception {
		return this.dictMerchantDao.selectByName("%" + name + "%", appId);
	}

	@Override
	public List<DictMerchant> selectByGISRect(GISQuery gisQuery) throws Exception {
		return this.dictMerchantDao.selectByGISRect(gisQuery);
	}

	@Override
	public List<DictRegion> selectByPCA(PCAQuery query) throws Exception {
		String[] reg = { "省", "市", "区", "县" };
		for (int i = 0; i < reg.length; i++) {
			if (query.getProvName().endsWith(reg[i])) {
				query.setProvName(query.getProvName().replace(reg[i], ""));
			}
			if (query.getCityName().endsWith(reg[i])) {
				query.setCityName(query.getCityName().replace(reg[i], ""));
			}
			if (query.getAreaName().endsWith(reg[i])) {
				query.setAreaName(query.getAreaName().replace(reg[i], ""));
			}
		}
		query.setProvName(query.getProvName() + "%");
		query.setCityName(query.getCityName() + "%");
		query.setAreaName(query.getAreaName() + "%");
		return this.dictRegionDao.selectByPCA(query);
	}

	@Override
	public List<DictRegion> selectByPCAFree(PCAQuery query) throws Exception {

		String[] reg = { "省", "市", "区", "县" };

		if (query.getProvName() == null) {
			query.setProvName("all");
		} else {
			for (int i = 0; i < reg.length; i++) {
				if (query.getProvName().endsWith(reg[i])) {
					query.setProvName(query.getProvName().replace(reg[i], ""));
				}
			}
			query.setProvName(query.getProvName() + "%");
		}
		if (query.getCityName() == null) {
			query.setCityName("all");
		} else {
			for (int i = 0; i < reg.length; i++) {
				if (query.getCityName().contains(reg[i])) {
					query.setCityName(query.getCityName().replace(reg[i], ""));
				}
			}
			query.setCityName(query.getCityName() + "%");
		}
		if (query.getAreaName() == null) {
			query.setAreaName("all");
		} else {
			for (int i = 0; i < reg.length; i++) {
				if (query.getAreaName().endsWith(reg[i])) {
					query.setAreaName(query.getAreaName().replace(reg[i], ""));
				}
			}
			query.setAreaName(query.getAreaName() + "%");
		}
		return this.dictRegionDao.selectByPCAFree(query);
	}
}
