package com.yjyz.iot.product.action;

import java.util.List;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestHeader;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import com.yjyz.iot.comm.ConstParm;
import com.yjyz.iot.comm.RetInfoDto;
import com.yjyz.iot.product.entity.ProdInfo;
import com.yjyz.iot.product.entity.ProdQnr;
import com.yjyz.iot.product.service.IProductManagerService;
import com.yjyz.iot.security.utils.ClientJwtToken;
import com.yjyz.iot.security.utils.ClientJwtUtil;

/**
 * @class :ProductResearch
 * @TODO :
 * @author:Herolizhen
 * @date :2017年10月25日下午4:09:12
 */

@CrossOrigin
@RestController
@RequestMapping("/product")
public class ProductController {
	private static Log log = LogFactory.getLog(ProductController.class);
	@Autowired
	private IProductManagerService productManagerService;

	@Autowired
	ClientJwtUtil jwtUtil;

	/**
	 * @name:saveQnr
	 * @TODO:保存调研问卷
	 * @date:2017年10月25日 下午4:09:03
	 * @param prodQnr
	 * @return RetInfoDto
	 */
	@Transactional
	@RequestMapping(value = "/saveProdQnr", method = RequestMethod.POST)
	public RetInfoDto saveProdQnr(@RequestBody ProdQnr prodQnr, @RequestHeader String Authorization) {
		RetInfoDto info = new RetInfoDto();

		ClientJwtToken jwtToken;
		try {
			jwtToken = jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}

		try {
			String clientId = jwtToken.getUser_id();
			if (prodQnr.getQnrId() != null) {
				this.productManagerService.updatePQByPK(prodQnr);
			} else {
				prodQnr.setClientId(clientId);
				prodQnr = this.productManagerService.insertPQ(prodQnr);
			}
			info.meta.put("message", "SaveQnr sucess.");
			info.meta.put("code", ConstParm.SUCESS_CODE);
			info.data.put("ProdQnr", prodQnr);
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "SaveProdQnr fail.");
			info.meta.put("code", ConstParm.ERR_PRODUCT_SQVEPROQNR);
		}
		return info;
	}

	/**
	 * @name:saveProdInfo
	 * @TODO:保存产品信息
	 * @date:2017年10月31日 上午10:00:16
	 * @param prodInfo
	 * @param Authorization
	 * @return RetInfoDto
	 */
	@Transactional
	@RequestMapping(value = "/saveProdInfo", method = RequestMethod.POST)
	public RetInfoDto saveProdInfo(@RequestBody ProdInfo prodInfo, @RequestHeader String Authorization) {

		RetInfoDto info = new RetInfoDto();
		ClientJwtToken jwtToken;
		try {
			jwtToken = jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}

		try {
			if (prodInfo.getProductId() != null) {
				this.productManagerService.updatePIByPK(prodInfo);
			} else {
				prodInfo.setAppId(jwtToken.getApp_id());
				prodInfo = this.productManagerService.insertPI(prodInfo);
			}
			info.meta.put("message", "SaveProdInfo sucess.");
			info.meta.put("code", ConstParm.SUCESS_CODE);
			info.data.put("ProdInfo", prodInfo);
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "SaveProdInfo fail.");
			info.meta.put("code", ConstParm.ERR_PRODUCT_SAVEPRODINFO);
		}
		return info;
	}

	@Transactional
	@RequestMapping(value = "/selProdByApp", method = RequestMethod.POST)
	public RetInfoDto selProdByApp(@RequestHeader String Authorization) {

		RetInfoDto info = new RetInfoDto();
		ClientJwtToken jwtToken;
		try {
			jwtToken = jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}

		try {
			List<ProdInfo> prodList = this.productManagerService.selectPQByAppId(jwtToken.getApp_id());
			if (prodList.size() > 0) {
				info.meta.put("message", "selProdByApp sucess.");
				info.meta.put("code", ConstParm.SUCESS_CODE);
				info.data.put("prodList", prodList);
			} else {
				info.meta.put("message", "no product data for this appid .");
				info.meta.put("code", ConstParm.ERR_NO_APPINFO);
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "selProdByApp fail.");
			info.meta.put("code", ConstParm.ERR_PRODUCT_SELPRODBYAPP);
		}
		return info;
	}

}
