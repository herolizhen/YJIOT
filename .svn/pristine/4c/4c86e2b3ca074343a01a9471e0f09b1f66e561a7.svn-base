/*
 *
 */
(function(w) {
	var app = {};
	var _token;

	const TOKEN = 'UserToken';

	app.ProductId = '';

	/**	
	 * 5.1.1	安全认证
	 * */
	//	用户登录
	app.URL_LOGIN = "http://127.0.0.1/YJIOT/power/login";
	//	获取验证码
	app.URL_GETTOKEN = "http://127.0.0.1/YJIOT/power/getToken";

	/**
	 * 5.1.2	用户管理（JWT）
	 * */
	//	用户增加
	app.URL_ADDSYSUSER = "http://127.0.0.1/YJIOT/power/addSysUser";
	//	用户修改
	app.URL_UPDSYSUSER = "http://127.0.0.1/YJIOT/power/updSysUser";
	//	用户删除
	app.URL_DELSYSUSER = "http://127.0.0.1/YJIOT/power/delSysUser";
	//  根据用户名查询用户信息
	app.URL_SELSYSUSER = "http://127.0.0.1/YJIOT/power/selSysUser";

	//	查询  查询一个app下的所有用户
	app.URL_SELSYSUSERBYAPP = "http://127.0.0.1/YJIOT/power/selSysUserByApp";

	/**
	 * 5.1.3	应用管理（JWT）
	 * */
	//	应用增加
	app.URL_ADDAPP = "http://127.0.0.1/YJIOT/power/addApp";
	//	应用修改
	app.URL_UPDAPP = "http://127.0.0.1/YJIOT/power/updApp";
	//	应用删除
	app.URL_DELAPP = "http://127.0.0.1/YJIOT/power/delApp";
	//	根据应用ID获取应用信息
	app.URL_SELAPP = "http://127.0.0.1/YJIOT/power/selApp";
	//	查询所有应用
	app.URL_SELAPPALL = "http://127.0.0.1/YJIOT/power/selAppAll";

	/**
	 * 5.1.4	角色管理（JWT）
	 * */
	//	角色增加
	app.URL_ADDROLE = "http://127.0.0.1/YJIOT/power/addRole";
	//	角色修改
	app.URL_UPDROLE = "http://127.0.0.1/YJIOT/power/updRole";
	//	角色删除
	app.URL_DELROLE = "http://127.0.0.1/YJIOT/power/delRole";
	//	根据应用ID获取角色信息
	app.URL_SELROLE = "http://127.0.0.1/YJIOT/power/selRole";
	//	查询应用下所有的角色
	app.URL_SELROLEBYAPP = "http://127.0.0.1/YJIOT/power/selRoleByApp";


	/**
	 * 5.1.5	资源管理（JWT）
	 * */
	//	增加资源项
	app.URL_ADDRES = "http://127.0.0.1/YJIOT/power/addResource";
	//	修改资源项
	app.URL_UPDRES = "http://127.0.0.1/YJIOT/power/updResource";
	//	删除资源项
	app.URL_DELRES = "http://127.0.0.1/YJIOT/power/delResource";
	//	根据资源id查询资源
	app.URL_SELRES = "http://127.0.0.1/YJIOT/power/selResource";
	//	查询应用下所有的资源
	app.URL_SELRESBYAP = "http://127.0.0.1/YJIOT/power/selResourceByApp";
	/**
	 * 	授权管理（JWT）
	 * */
	//		角色资源增加
	app.URL_ADDROLERES = "http://127.0.0.1/YJIOT/power/addRoleResource";
	//		角色资源删除
	app.URL_DELROLERES = "http://127.0.0.1/YJIOT/power/delRoleResource";
	//		角色资源查询
	app.URL_SELROLERES = "http://127.0.0.1/YJIOT/power/selRoleResource";
	//		资源角色查询--------------------------
	app.URL_SELRESROLE = "http://127.0.0.1/YJIOT/power/selResourceRole";
	//		用户角色增加
	app.URL_ADDUSERROLE = "http://127.0.0.1/YJIOT/power/addUserRole";
	//		用户角色删除
	app.URL_DELUSERROLE = "http://127.0.0.1/YJIOT/power/delUserRole";
	//		查询用户角色
	app.URL_SELUSERROLE = "http://127.0.0.1/YJIOT/power/selUserRole";
	//		查询角色下的用户
	app.URL_SELROLEUSER = "http://127.0.0.1/YJIOT/power/selRoleUser";
	//		查询用户拥有的资源
	app.URL_SELUSERRES = "http://127.0.0.1/YJIOT/power/selUserResource";
	//		根据资源ID查询拥有该资源的所有用户
	app.URL_SELRESUSER = "http://127.0.0.1/YJIOT/power/selResourceUser";
	/**	
	 * 7.1	OTA文件管理
	 * */
	//	获取OTA信息列表
	app.URL_SELECTBYPRIDUCEID= "http://127.0.0.1/YJIOT/otaFile/selectByProduceId";
	//获取OTA信息
	app.URL_SELECT= "http://127.0.0.1/YJIOT/otaFile/select";
	//增加OTA文件
	app.URL_INSERT= "http://127.0.0.1/YJIOT/otaFile/insert";
	//更新OTA信息
	app.URL_UPDATE= "http://127.0.0.1/YJIOT/otaFile/update";
	//删除OTA信息
	app.URL_DELETE= "http://127.0.0.1/YJIOT/otaFile/delete";
	/**
	 * 5.2产品管理（JWT）
	 */
	//产品定义
	app.URL_SAVEPRODINFO= "http://127.0.0.1/YJIOT/product/saveProdInfo";
	//问卷调查
	app.URL_SAVEPROQNR= "http://127.0.0.1/YJIOT/product/saveProdQnr";
	//查询用户所拥有的产品
	app.URL_SELPRODbYAPP= "http://tomcata.yjiot.net/YJIOT/product/selProdByApp";

	app.isNull = function(obj) {
		if (obj == undefined || obj == null) {
			return true;
		} else if ( typeof obj == 'string') {
			if (obj.length > 0) {
				return false;
			} else {
				return true;
			}
		} else {
			return false;
		}
	};

	//手机验证
	app.isPhone = function(txt) {
		var regBox = {
				regEmail : /^([a-z0-9_\.-]+)@([\da-z\.-]+)\.([a-z\.]{2,6})$/,
				regName : /^[a-z0-9_-]{3,16}$/,
				regMobile : /^0?1[3|4|5|7|8][0-9]\d{8}$/,
				regTel : /^0[\d]{2,3}-[\d]{7,8}$/
		};
		var mflag = regBox.regMobile.test(txt);
		if (!mflag)
			return false;
		else
			return true
	};

	//缓存登录信息
	app.saveToken = function(username, password, appList,appId,token) {
		$api.setStorage(TOKEN, {
			username : username,
			password : password,
			appList : appList,
			appId:appId,
			token:token
		});
		_token = null;
	};
	//获取登录信息
	app.getToken = function() {
		if (app.isNull(_token)) {
			_token = $api.getStorage(TOKEN);
		}
		return _token;
	};



	
	w.$app = app;
})(window);
