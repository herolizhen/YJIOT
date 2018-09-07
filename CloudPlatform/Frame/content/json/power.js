//权限管理
(function(w) {
	var pow = {};

	pow.token = '';
	pow.username = '';
	function Initialize() {
		var user = $app.getToken();
		if (!$app.isNull(user)) {
			pow.token = user.token;
		//	alert("pow.token------------"+pow.token)
			pow.username = user.username;
		}
	};
	pow.test=function(data, success, error) {
		$iot.POST ($app.URL_LOGIN, '', data, function(ret){
			success(ret);
		}, error) ;
	}

	//登陆
	pow.login = function(data, success, error) {
		$iot.POST ($app.URL_LOGIN, '', data, function(ret){
			var jsonObj = JSON.parse(data); 
			var username =jsonObj.username;
			var password =jsonObj.password;
			var appList = ret.appList;
			$app.saveToken(username, password, appList);
			success(ret);
		}, error) ;
	};

	//获取验证码
	pow.getToken = function(data, success, error) {
		$iot.POST ($app.URL_GETTOKEN, '', data, function(ret){
			pow.token = ret.token;
			success(ret);
		}, error) ;
	};


	//用户增加
	pow.addSysUser = function(data, success, error) {
		Initialize();
		$iot.POST ($app.URL_ADDSYSUSER, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};

	//用户修改
	pow.updSysUser = function(data, success, error) {
		Initialize();
		$iot.POST ($app.URL_UPDSYSUSER, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};

	//用户删除
	pow.delSysUser = function(data, success, error) {
		Initialize();
		$iot.POST ($app.URL_DELSYSUSER, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};

	//用户查询1
	pow.selSysUser = function(data, success, error) {
		Initialize();
		$iot.POST ($app.URL_SELSYSUSER, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};

	//用户查询2
	pow.selSysUserByApp = function(data, success, error) {
		Initialize();
		$iot.POST ($app.URL_SELSYSUSERBYAPP, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};



	//应用添加
	pow.addApp = function(data, success, error) {
		Initialize();
		$iot.POST ($app.URL_ADDAPP, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};

	//应用修改
	pow.updApp = function(data, success, error) {
		Initialize();
		$iot.POST ($app.URL_UPDAPP, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};

	//应用删除
	pow.delApp = function(data, success, error) {
		Initialize();
		$iot.POST ($app.URL_DELAPP, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};

	//应用查询
	pow.selApp = function(data, success, error) {
		Initialize();
		$iot.POST ($app.URL_SELAPP, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};

	//应用查询 全部
	pow.selAppAll = function(data, success, error) {
		Initialize();
		$iot.POST ($app.URL_SELAPPALL, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};


	//角色添加
	pow.addRole = function(data, success, error) {
		Initialize();
		$iot.POST ($app.URL_ADDROLE, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};

	//角色修改
	pow.updRole = function(data, success, error) {
		Initialize();
		$iot.POST ($app.URL_UPDROLE, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};

	//角色删除
	pow.delRole = function(data, success, error) {
		Initialize();
		$iot.POST ($app.URL_DELROLE, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};

	//角色查询 
	pow.selRole = function(data, success, error) {
		Initialize();
		$iot.POST ($app.URL_SELROLE, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};

	//角色查询 全部
	pow.selRoleByApp = function(data, success, error) {
		Initialize();
		$iot.POST ($app.URL_SELROLEBYAPP, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};

	//资源添加 
	pow.addResource = function(data, success, error) {
		Initialize();
		$iot.POST ($app.URL_ADDRES, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};
	//资源添修改
	pow.updResource = function(data, success, error) {
		Initialize();
		$iot.POST ($app.URL_UPDRES, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};

	//资源添删除
	pow.delResource = function(data, success, error) {
		Initialize();
		$iot.POST ($app.URL_DELRES, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};

	//资源查询 appId全部
	pow.selResource = function(data, success, error) {
		Initialize();
		$iot.POST ($app.URL_SELRES, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};

	//资源查询 appId全部
	pow.selResourceByApp = function(data, success, error) {
		Initialize();
		$iot.POST ($app.URL_SELRESBYAP, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};


	/**
	 * 
	 * 	授权管理
	 * */

	//角色资源增加
	pow.addRoleResource = function(data, success, error) {
		Initialize();
		$iot.POST ($app.URL_ADDROLERES, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};

	//角色资源删除
	pow.delRoleResource = function(data, success, error) {
		Initialize();
		$iot.POST ($app.URL_DELROLERES, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};
	
	//角色资源查询
	pow.selRoleResource = function(data, success, error) {
		Initialize();
		$iot.POST ($app.URL_SELROLERES, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};

	//资源角色查询
	pow.selResourceRole = function(data, success, error) {
		Initialize();
		$iot.POST ($app.URL_SELRESROLE, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};
	
	
	//用户角色增加
	pow.addUserRole = function(data, success, error) {
		Initialize();
		$iot.POST ($app.URL_ADDUSERROLE, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};
	
	//用户角色删除
	pow.delUserRole = function(data, success, error) {
		Initialize();
		$iot.POST ($app.URL_DELUSERROLE, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};
	
	//根据用户名查询用户所拥有的角色
	pow.selUserRole = function(data, success, error) {
		Initialize();
		$iot.POST ($app.URL_SELUSERROLE, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};
	
	//查询角色下的用户
	pow.selRoleUser = function(data, success, error) {
		Initialize();

		$iot.POST ($app.URL_SELROLEUSER, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};
	//查询用户资源
	pow.selUserResource = function(data, success, error) {
		Initialize();
		$iot.POST ($app.URL_SELUSERRES, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};
	//查询资源用户
	pow.selResourceUser = function(data, success, error) {
		Initialize();

		$iot.POST ($app.URL_SELRESUSER, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};
	//获取OTA信息列表
	pow.selectByProduceId = function(data, success, error) {
		Initialize();

		$iot.POST ($app.URL_SELECTBYPRIDUCEID, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};
	//获取OTA信息
	pow.select = function(data, success, error) {
		Initialize();

		$iot.POST ($app.URL_SELECT, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};
	//增加OTA文件
	pow.insert = function(data, success, error) {
		Initialize();

		$iot.POST ($app.URL_INSERT, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};
	//获取OTA信息列表
	pow.selectByProduceId = function(data, success, error) {
		Initialize();

		$iot.POST ($app.URL_SELECTBYPRIDUCEID, pow.token, data, function(ret){
			success(ret);
		}, error) ;
	};
	
	w.$pow = pow;
})(window); 