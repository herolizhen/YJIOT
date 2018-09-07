/*
权限管理
*/
//
(function (w) {
    var pow = {};

    pow.token = '';
    pow.username = '';

    function Initialize() {
        var user = $api.getToken();
        if (!$api.isNull(user)) {
            pow.token = user.token;
            pow.username = user.username;
        }
    };
    pow.test = function (data, success, error) {
        $iot.POST($cfg.URL_LOGIN, '', data, success, error);
    }

    //登陆
    pow.login = function (data, success, error) {
        $iot.POST($cfg.URL_LOGIN, '', data, success, error);
    };

    //获取验证码
    pow.getToken = function (data, success, error) {
        $iot.POST($cfg.URL_GETTOKEN, '', data, success, error);
    };


    //用户增加
    pow.addSysUser = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_ADDSYSUSER, pow.token, data, success, error);
    };

    //用户修改
    pow.updSysUser = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_UPDSYSUSER, pow.token, data, success, error);
    };

    //用户删除
    pow.delSysUser = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_DELSYSUSER, pow.token, data, success, error);
    };

    //用户查询1
    pow.selSysUser = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_SELSYSUSER, pow.token, data, success, error);
    };

    //用户查询2
    pow.selSysUserByApp = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_SELSYSUSERBYAPP, pow.token, data, success, error);
    };



    //应用添加
    pow.addApp = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_ADDAPP, pow.token, data, success, error);
    };

    //应用修改
    pow.updApp = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_UPDAPP, pow.token, data, success, error);
    };

    //应用删除
    pow.delApp = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_DELAPP, pow.token, data, success, error);
    };

    //应用查询
    pow.selApp = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_SELAPP, pow.token, data, success, error);
    };

    //应用查询 全部
    pow.selAppAll = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_SELAPPALL, pow.token, data, success, error);
    };


    //角色添加
    pow.addRole = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_ADDROLE, pow.token, data, success, error);
    };

    //角色修改
    pow.updRole = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_UPDROLE, pow.token, data, success, error);
    };

    //角色删除
    pow.delRole = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_DELROLE, pow.token, data, success, error);
    };

    //角色查询 
    pow.selRole = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_SELROLE, pow.token, data, success, error);
    };

    //角色查询 全部
    pow.selRoleByApp = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_SELROLEBYAPP, pow.token, data, success, error);
    };

    //资源添加 
    pow.addResource = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_ADDRES, pow.token, data, success, error);
    };
    //资源添修改
    pow.updResource = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_UPDRES, pow.token, data, success, error);
    };

    //资源添删除
    pow.delResource = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_DELRES, pow.token, data, success, error);
    };

    //资源查询 appId全部
    pow.selResource = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_SELRES, pow.token, data, success, error);
    };

    //资源查询 appId全部
    pow.selResourceByApp = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_SELRESBYAP, pow.token, data, success, error);
    };


    /**
	 * 
	 * 	授权管理
	 * */

    //角色资源增加
    pow.addRoleResource = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_ADDROLERES, pow.token, data, success, error);
    };

    //角色资源删除
    pow.delRoleResource = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_DELROLERES, pow.token, data, success, error);
    };

    //角色资源查询
    pow.selRoleResource = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_SELROLERES, pow.token, data, success, error);
    };

    //资源角色查询
    pow.selResourceRole = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_SELRESROLE, pow.token, data, success, error);
    };


    //用户角色增加
    pow.addUserRole = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_ADDUSERROLE, pow.token, data, success, error);
    };

    //用户角色删除
    pow.delUserRole = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_DELUSERROLE, pow.token, data, success, error);
    };

    //根据用户名查询用户所拥有的角色
    pow.selUserRole = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_SELUSERROLE, pow.token, data, success, error);
    };

    //查询角色下的用户
    pow.selRoleUser = function (data, success, error) {
        Initialize();

        $iot.POST($cfg.URL_SELROLEUSER, pow.token, data, success, error);
    };
    //查询用户资源
    pow.selUserResource = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_SELUSERRES, pow.token, data, success, error);
    };
    //查询资源用户
    pow.selResourceUser = function (data, success, error) {
        Initialize();

        $iot.POST($cfg.URL_SELRESUSER, pow.token, data, success, error);
    };
  //产品定义
  	pow.saveProdInfo = function(data, success, error) {
  		Initialize();
  		$iot.POST ($cfg.URL_SAVEPRODINFO, pow.token, data, function(ret){
  			success(ret);
  		}, error) ;
  	};
  	//问卷调查
  	pow.saveProdQnr = function(data, success, error) {
  		Initialize();
  		$iot.POST ($cfg.URL_SAVEPROQNR, pow.token, data, function(ret){
  			success(ret);
  		}, error) ;
  	};
  	//根据用户名查询用户信息
  	pow.selProdByApp = function(data, success, error) {
  		Initialize();
  		$iot.POST ($cfg.URL_SELPRODbYAPP, pow.token, data, function(ret){
  			success(ret);
  		}, error) ;
  	};

    w.$pow = pow;
})(window);