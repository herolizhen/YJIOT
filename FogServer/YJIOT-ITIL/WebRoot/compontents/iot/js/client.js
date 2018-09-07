﻿/*
5.4	OTA文件管理（JWT）
*/
(function (w) {
    var client = {};

    client.token = '';
    client.username = '';

    function Initialize() {
        var user = $api.getToken();
        if (!$api.isNull(user)) {
        	client.token = user.token;
        	client.username = user.username;
        }
    };

    client.getUnCosumeBill = function (data, success, error) {
    	Initialize();
        $iot.POST($cfg.URL_GETUNCOSUMEBILL, client.token, data, success, error);
    };
    
    //下发指令
    client.sendCommand = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_SENDCOMMAND, client.token, data, success, error);
    };

    
   
    client.consume = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_CONSONSUME, client.token, data, success, error);
    };
    
    
    //查看设备用户列表
    client.getDevUser = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_GETDEVUSER, client.token, data, success, error);
    };
    
    
    //获取用户令牌
    client.getToken = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_CLIENTPOSERGETTOKEN, client.token, data, success, error);
    };
    
    
	//获取设备令牌
    client.getDevToken = function (data,token, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_GETDECVTOKEN, token, data, success, error);
    };
    
    //用户绑定
    client.bindDevice = function (data,token, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_BINDDEVICE, token, data, success, error);
    };
    
    
    
    //用户解绑
    client.unBindDevice = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_UNBINDDEVICE, client.token, data, success, error);
    };
    
    w.$client = client;
})(window);