/*
全局配置文件
*/
(function (w) {
    var cfg = {};

    const HOST = '127.0.0.1';

    /**	
	 * 5.1.1	安全认证
	 * */
    //	用户登录
    cfg.URL_LOGIN = 'http://' + HOST + '/YJIOT/power/login';
    //	获取验证码
    cfg.URL_GETTOKEN = 'http://' + HOST + '/YJIOT/power/getToken';

    /**
	 * 5.1.2	用户管理（JWT）
	 * */
    //	用户增加
    cfg.URL_ADDSYSUSER = 'http://' + HOST + '/YJIOT/power/addSysUser';
    //	用户修改
    cfg.URL_UPDSYSUSER = 'http://' + HOST + '/YJIOT/power/updSysUser';
    //	用户删除
    cfg.URL_DELSYSUSER = 'http://' + HOST + '/YJIOT/power/delSysUser';
    //  根据用户名查询用户信息
    cfg.URL_SELSYSUSER = 'http://' + HOST + '/YJIOT/power/selSysUser';

    //	查询  查询一个app下的所有用户
    cfg.URL_SELSYSUSERBYAPP = 'http://' + HOST + '/YJIOT/power/selSysUserByApp';

    /**
	 * 5.1.3	应用管理（JWT）
	 * */
    //	应用增加
    cfg.URL_ADDAPP = 'http://' + HOST + '/YJIOT/power/addApp';
    //	应用修改
    cfg.URL_UPDAPP = 'http://' + HOST + '/YJIOT/power/updApp';
    //	应用删除
    cfg.URL_DELAPP = 'http://' + HOST + '/YJIOT/power/delApp';
    //	根据应用ID获取应用信息
    cfg.URL_SELAPP = 'http://' + HOST + '/YJIOT/power/selApp';
    //	查询所有应用
    cfg.URL_SELAPPALL = 'http://' + HOST + '/YJIOT/power/selAppAll';

    /**
	 * 5.1.4	角色管理（JWT）
	 * */
    //	角色增加
    cfg.URL_ADDROLE = 'http://' + HOST + '/YJIOT/power/addRole';
    //	角色修改
    cfg.URL_UPDROLE = 'http://' + HOST + '/YJIOT/power/updRole';
    //	角色删除
    cfg.URL_DELROLE = 'http://' + HOST + '/YJIOT/power/delRole';
    //	根据应用ID获取角色信息
    cfg.URL_SELROLE = 'http://' + HOST + '/YJIOT/power/selRole';
    //	查询应用下所有的角色
    cfg.URL_SELROLEBYAPP = 'http://' + HOST + '/YJIOT/power/selRoleByApp';


    /**
	 * 5.1.5	资源管理（JWT）
	 * */
    //	增加资源项
    cfg.URL_ADDRES = 'http://' + HOST + '/YJIOT/power/addResource';
    //	修改资源项
    cfg.URL_UPDRES = 'http://' + HOST + '/YJIOT/power/updResource';
    //	删除资源项
    cfg.URL_DELRES = 'http://' + HOST + '/YJIOT/power/delResource';
    //	根据资源id查询资源
    cfg.URL_SELRES = 'http://' + HOST + '/YJIOT/power/selResource';
    //	查询应用下所有的资源
    cfg.URL_SELRESBYAP = 'http://' + HOST + '/YJIOT/power/selResourceByApp';
    /**
	 * 	授权管理（JWT）
	 * */
    //		角色资源增加
    cfg.URL_ADDROLERES = 'http://' + HOST + '/YJIOT/power/addRoleResource';
    //		角色资源删除
    cfg.URL_DELROLERES = 'http://' + HOST + '/YJIOT/power/delRoleResource';
    //		角色资源查询
    cfg.URL_SELROLERES = 'http://' + HOST + '/YJIOT/power/selRoleResource';
    //		资源角色查询--------------------------
    cfg.URL_SELRESROLE = 'http://' + HOST + '/YJIOT/power/selResourceRole';
    //		用户角色增加
    cfg.URL_ADDUSERROLE = 'http://' + HOST + '/YJIOT/power/addUserRole';
    //		用户角色删除
    cfg.URL_DELUSERROLE = 'http://' + HOST + '/YJIOT/power/delUserRole';
    //		查询用户角色
    cfg.URL_SELUSERROLE = 'http://' + HOST + '/YJIOT/power/selUserRole';
    //		查询角色下的用户
    cfg.URL_SELROLEUSER = 'http://' + HOST + '/YJIOT/power/selRoleUser';
    //		查询用户拥有的资源
    cfg.URL_SELUSERRES = 'http://' + HOST + '/YJIOT/power/selUserResource';
    //		根据资源ID查询拥有该资源的所有用户
    cfg.URL_SELRESUSER = 'http://' + HOST + '/YJIOT/power/selResourceUser';
    /**	
	 * 7.1	OTA文件管理
	 * */
    //	获取OTA信息列表
    cfg.URL_SELECTBYPRIDUCEID = 'http://' + HOST + '/YJIOT/otaFile/selectByProduceId';
    //获取OTA信息
    cfg.URL_SELECT = 'http://' + HOST + '/YJIOT/otaFile/select';
    //增加OTA文件
    cfg.URL_INSERT = 'http://' + HOST + '/YJIOT/otaFile/insert';
    //更新OTA信息
    cfg.URL_UPDATE = 'http://' + HOST + '/YJIOT/otaFile/update';
    //删除OTA信息
    cfg.URL_DELETE = 'http://' + HOST + '/YJIOT/otaFile/delete';
    /**
	 * 5.2产品管理（JWT）
	 */
    //产品定义
    cfg.URL_SAVEPRODINFO = 'http://' + HOST + '/YJIOT/product/saveProdInfo';
    //问卷调查
    cfg.URL_SAVEPROQNR = 'http://' + HOST + '/YJIOT/product/saveProdQnr';
    //查询用户所拥有的产品
    cfg.URL_SELPRODbYAPP = 'http://' + HOST + '/YJIOT/product/selProdByApp';

    w.$cfg = cfg;
})(window);