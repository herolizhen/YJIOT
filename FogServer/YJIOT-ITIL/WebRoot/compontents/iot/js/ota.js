﻿/*
5.4	OTA文件管理（JWT）
*/
(function (w) {
    var ota = {};

    ota.token = '';
    ota.username = '';

    function Initialize() {
        var user = $api.getToken();
        if (!$api.isNull(user)) {
            ota.token = user.token;
            ota.username = user.username;
        }
    };

    //获取OTA信息列表
    ota.selectByProduceId = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_SELECTBYPRIDUCEID, ota.token, data, success, error);
    };
    //获取OTA信息
    ota.select = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_SELECT, ota.token, data, success, error);
    };
    //增加OTA文件
    ota.insert = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_INSERT, ota.token, data, success, error);
    };
    //删除OTA文件
    ota.deleteota = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_DELETE, ota.token, data, success, error);
    };
    //修改OTA文件
    ota.update = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_UPDATE, ota.token, data, success, error);
    };  
    
    //时间格式转成时间戳
    ota.toUnix = function (time) {
    	var timestamp2 = Date.parse(new Date(time));
		return strtotime = timestamp2 = timestamp2 / 1000;
    };
    //时间戳转成时间格式
    ota.fromUnix = function (unixtime,fmt) {
        var unixTimestamp = new Date(unixtime);
        return unixTimestamp.pattern(fmt);
    };
    w.$ota = ota;
})(window);