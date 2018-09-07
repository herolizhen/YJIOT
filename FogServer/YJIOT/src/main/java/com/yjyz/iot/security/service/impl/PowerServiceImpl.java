package com.yjyz.iot.security.service.impl;

import java.util.List;
import java.util.UUID;

import javax.annotation.Resource;

import org.springframework.stereotype.Service;

import com.yjyz.iot.security.dao.PowAppInfoMapper;
import com.yjyz.iot.security.dao.PowResourceMapper;
import com.yjyz.iot.security.dao.PowRoleMapper;
import com.yjyz.iot.security.dao.PowRoleResourceMapper;
import com.yjyz.iot.security.dao.PowSysUserMapper;
import com.yjyz.iot.security.dao.PowUserRoleMapper;
import com.yjyz.iot.security.entity.PowAppInfo;
import com.yjyz.iot.security.entity.PowResource;
import com.yjyz.iot.security.entity.PowRole;
import com.yjyz.iot.security.entity.PowRoleKey;
import com.yjyz.iot.security.entity.PowRoleResourceKey;
import com.yjyz.iot.security.entity.PowSysUser;
import com.yjyz.iot.security.entity.PowSysUserKey;
import com.yjyz.iot.security.entity.PowUserRoleKey;
import com.yjyz.iot.security.service.IPowerService;

@Service("powerService")
public class PowerServiceImpl implements IPowerService {

	@Resource
	PowAppInfoMapper powAppInfoDao;
	@Resource
	PowResourceMapper powResourceDao;
	@Resource
	PowRoleMapper powRoleDao;
	@Resource
	PowRoleResourceMapper powRoleResourceDao;
	@Resource
	PowSysUserMapper powSysUserDao;
	@Resource
	PowUserRoleMapper powUserRoleDao;

	@Override
	public List<PowAppInfo> login(PowSysUser powSysUser) throws Exception {
		return this.powSysUserDao.userLogin(powSysUser);
	}

	@Override
	public PowAppInfo addApp(PowAppInfo powAppInfo) throws Exception {
		powAppInfo.setAppId(UUID.randomUUID().toString());
		int ret = this.powAppInfoDao.insertSelective(powAppInfo);
		if (ret == 1) {
			// cereate app master role
			PowRoleKey roleKey = new PowRoleKey();
			roleKey.setAppId("8888");
			roleKey.setRoleId("6666");
			PowRole powRole = this.powRoleDao.selectByPrimaryKey(roleKey);
			powRole.setAppId(powAppInfo.getAppId());
			this.powRoleDao.insertSelective(powRole);
			// caeate app master user
			PowSysUserKey userKey = new PowSysUserKey();
			userKey.setAppId("8888");
			userKey.setUsername(powAppInfo.getMasterId());
			PowSysUser powSysUser = this.powSysUserDao.selectByPrimaryKey(userKey);
			powSysUser.setAppId(powAppInfo.getAppId());
			powSysUser.setPassword("111111");
			this.powSysUserDao.insertSelective(powSysUser);
			// create userRole
			PowUserRoleKey userRole = new PowUserRoleKey();
			userRole.setRoleId("6666");
			userRole.setUsername(powAppInfo.getMasterId());
			userRole.setAppId(powAppInfo.getAppId());
			this.powUserRoleDao.insert(userRole);
			return powAppInfo;
		} else {
			return null;
		}
	}

	@Override
	public boolean delApp(PowAppInfo powAppInfo) throws Exception {

		int ret = this.powAppInfoDao.deleteByPrimaryKey(powAppInfo.getAppId());
		if (ret == 1) {
			return true;
		} else {
			return false;
		}
	}

	@Override
	public boolean updApp(PowAppInfo powAppInfo) throws Exception {

		PowAppInfo appInfo = this.powAppInfoDao.selectByPrimaryKey(powAppInfo.getAppId());
		// 更换系统管理员
		if (appInfo.getMasterId()== null ||!appInfo.getMasterId().equals(powAppInfo.getMasterId())) {
			PowUserRoleKey userRole = new PowUserRoleKey();
			userRole.setRoleId("6666");
			userRole.setUsername(appInfo.getMasterId());
			this.powUserRoleDao.deleteByPrimaryKey(userRole);

			// caeate new app master user
			PowSysUserKey userKey = new PowSysUserKey();
			userKey.setAppId(powAppInfo.getAppId());
			userKey.setUsername(powAppInfo.getMasterId());
			PowSysUser powSysUser = this.powSysUserDao.selectByPrimaryKey(userKey);
			if (powSysUser == null) {
				userKey = new PowSysUserKey();
				userKey.setAppId("8888");
				userKey.setUsername(powAppInfo.getMasterId());
				powSysUser = this.powSysUserDao.selectByPrimaryKey(userKey);
				powSysUser.setAppId(powAppInfo.getAppId());
				powSysUser.setPassword("111111");
				this.powSysUserDao.insertSelective(powSysUser);
				powAppInfo.setMasterName(powSysUser.getRealname());
			}

			// create userRole
			userRole = new PowUserRoleKey();
			userRole.setRoleId("6666");
			userRole.setUsername(powAppInfo.getMasterId());
			userRole.setAppId(powAppInfo.getAppId());
			this.powUserRoleDao.insert(userRole);
		}

		int ret = this.powAppInfoDao.updateByPrimaryKeySelective(powAppInfo);
		if (ret == 1) {
			return true;
		} else {
			return false;
		}
	}

	@Override
	public PowAppInfo selApp(PowAppInfo powAppInfo) throws Exception {
		return this.powAppInfoDao.selectByPrimaryKey(powAppInfo.getAppId());

	}

	@Override
	public List<PowAppInfo> selAppAll() throws Exception {
		return this.powAppInfoDao.selectAll();
	}

	@Override
	public PowRole addRole(PowRole powRole) throws Exception {

		PowAppInfo appInfo = this.powAppInfoDao.selectByPrimaryKey(powRole.getAppId());
		if (appInfo == null) {
			return null;
		}
		powRole.setRoleId(UUID.randomUUID().toString());
		int ret = this.powRoleDao.insertSelective(powRole);
		if (ret == 1) {
			return powRole;
		} else {
			return null;
		}
	}

	@Override
	public boolean delRole(PowRole powRole) throws Exception {

		if (powRole.getRoleId().equalsIgnoreCase("6666") || powRole.getRoleId().equalsIgnoreCase("8888")) {
			return false;
		}
		int ret = this.powRoleDao.deleteByPrimaryKey(powRole);
		if (ret == 1) {
			this.powRoleResourceDao.deleteByRoleId(powRole.getRoleId());
			return true;
		} else {
			return false;
		}
	}

	@Override
	public boolean updRole(PowRole powRole) throws Exception {
		if (powRole.getRoleId().equalsIgnoreCase("6666") || powRole.getRoleId().equalsIgnoreCase("8888")) {
			return false;
		}
		int ret = this.powRoleDao.updateByPrimaryKeySelective(powRole);
		if (ret == 1) {
			return true;
		} else {
			return false;
		}
	}

	@Override
	public PowRole selRole(PowRole powRole) throws Exception {
		return this.powRoleDao.selectByPrimaryKey(powRole);

	}

	@Override
	public List<PowRole> selRoleByApp(String appId) throws Exception {
		PowRoleKey key = new PowRoleKey();
		key.setAppId(appId);
		return this.powRoleDao.selectByAppId(key);
	}

	@Override
	public boolean addSysUser(PowSysUser powSysUser) throws Exception {
		int ret = this.powSysUserDao.insertSelective(powSysUser);
		if (ret == 1) {
			return true;
		} else {
			return false;
		}
	}

	@Override
	public boolean delSysUser(PowSysUser powSysUser) throws Exception {
		PowSysUser psu = this.powSysUserDao.isAppAdmin(powSysUser);
		if (psu != null) {
			return false;
		}
		int ret = this.powSysUserDao.deleteByPrimaryKey(powSysUser);
		if (ret == 1) {
			PowUserRoleKey key = new PowUserRoleKey();
			key.setUsername(powSysUser.getUsername());
			this.powUserRoleDao.deleteByUserName(key);
			return true;
		} else {
			return false;
		}
	}

	@Override
	public boolean updSysUser(PowSysUser powSysUser) throws Exception {
		int ret = this.powSysUserDao.updateByPrimaryKeySelective(powSysUser);
		if (ret == 1) {
			powSysUser.setAppId("8888");
			this.powSysUserDao.updateByPrimaryKeySelective(powSysUser);		
			return true;
		} else {
			return false;
		}
	}

	@Override
	public PowSysUser selSysUser(PowSysUser powSysUser) throws Exception {
		return this.powSysUserDao.selectByPrimaryKey(powSysUser);

	}

	@Override
	public List<PowSysUser> selSysUserByApp(String appId) throws Exception {
		PowSysUserKey key = new PowSysUserKey();
		key.setAppId(appId);
		return this.powSysUserDao.selectByAppId(key);
	}

	@Override
	public PowResource addResource(PowResource powResource) throws Exception {
		powResource.setResId(UUID.randomUUID().toString());
		int ret = this.powResourceDao.insertSelective(powResource);
		if (ret == 1) {
			return powResource;
		} else {
			return null;
		}
	}

	@Override
	public boolean delResource(PowResource powResource) throws Exception {

		int ret = this.powResourceDao.deleteByPrimaryKey(powResource.getResId());
		if (ret == 1) {
			this.powRoleResourceDao.deleteByResId(powResource.getResId());
			return true;
		} else {
			return false;
		}
	}

	@Override
	public boolean updResource(PowResource powResource) throws Exception {
		int ret = this.powResourceDao.updateByPrimaryKeySelective(powResource);
		if (ret == 1) {
			return true;
		} else {
			return false;
		}
	}

	@Override
	public PowResource selResource(PowResource powResource) throws Exception {
		return this.powResourceDao.selectByPrimaryKey(powResource.getResId());

	}

	@Override
	public List<PowResource> selResourceByApp(String appId) throws Exception {
		return this.powResourceDao.selectByAppId(appId);
	}

	@Override
	public boolean addRoleResource(PowRoleResourceKey powRoleResource) throws Exception {
		int ret = this.powRoleResourceDao.insertSelective(powRoleResource);
		if (ret == 1) {
			return true;
		} else {
			return false;
		}
	}

	@Override
	public boolean delRoleResource(PowRoleResourceKey powRoleResource) throws Exception {
		int ret = this.powRoleResourceDao.deleteByPrimaryKey(powRoleResource);
		if (ret == 1) {
			return true;
		} else {
			return false;
		}
	}

	@Override
	public List<PowResource> selRoleResource(PowRole powRole) throws Exception {
		return this.powRoleResourceDao.selectRoleResource(powRole);
	}

	@Override
	public List<PowRole> selResourceRole(PowResource powResource) throws Exception {
		return this.powRoleResourceDao.selectResourceRole(powResource);
	}

	@Override
	public boolean addUserRole(PowUserRoleKey powUserRole) throws Exception {
		int ret = this.powUserRoleDao.insert(powUserRole);
		if (ret == 1) {
			return true;
		} else {
			return false;
		}
	}

	@Override
	public boolean delUserRole(PowUserRoleKey powUserRole) throws Exception {
		PowSysUser sysUser  = new PowSysUser();
		sysUser.setUsername(powUserRole.getAppId());
		sysUser.setAppId(powUserRole.getAppId());
		PowSysUser psu = this.powSysUserDao.isAppAdmin(sysUser);
		if (psu != null && powUserRole.getRoleId().equals("666666")) {
			return false;
		}
		int ret = this.powUserRoleDao.deleteByPrimaryKey(powUserRole);
		if (ret == 1) {
			return true;
		} else {
			return false;
		}
	}

	@Override
	public List<PowRole> selUserRole(PowUserRoleKey powUserRole) throws Exception {
		return this.powUserRoleDao.selectRoleByUser(powUserRole);
	}

	@Override
	public List<PowSysUser> selRoleUser(PowUserRoleKey powUserRole) throws Exception {
		return this.powUserRoleDao.selectUserByRole(powUserRole);
	}

	@Override
	public List<PowResource> selUserResource(PowSysUser powSysUser) throws Exception {
		return this.powSysUserDao.selectResourceByUser(powSysUser);
	}

	@Override
	public List<PowSysUser> selResourceUser(PowResource powResource) throws Exception {
		return this.powResourceDao.selectUserByResource(powResource);
	}

}