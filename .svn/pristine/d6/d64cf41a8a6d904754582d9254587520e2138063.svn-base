/*
权限管理
*/
//
(function (w) {
    var clientPower = {};
    clientPower.token = '';
    clientPower.username = '';

    function Initialize() {
        var user = $api.getToken();
        if (!$api.isNull(user)) {
        	clientPower.token = user.token;
        	clientPower.username = user.username;
        }
    };
  
    //获取用户令牌
    clientPower.getToken = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_CLIENTPOSERGETTOKEN, clientPower.token, data, success, error);
    };
    
	//获取设备令牌
    clientPower.getDevToken = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_GETDECVTOKEN, clientPower.token, data, success, error);
    };
    
    //用户绑定
    clientPower.bindDevice = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_BINDDEVICE, clientPower.token, data, success, error);
    };
    
    //用户解绑
    clientPower.unBindDevice = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_UNBINDDEVICE, clientPower.token, data, success, error);
    };
    
    //查看设备用户列表
    clientPower.getDevUser = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_GETDEVUSER, clientPower.token, data, success, error);
    };

    w.clientPower = clientPower;
})(window);