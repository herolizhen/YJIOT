/*
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
    //获取OTA信息列表
    ota.selectByProduceId = function (data, success, error) {
        Initialize();

        $iot.POST($cfg.URL_SELECTBYPRIDUCEID, ota.token, data, success, error);
    };

    w.$ota = ota;
})(window);