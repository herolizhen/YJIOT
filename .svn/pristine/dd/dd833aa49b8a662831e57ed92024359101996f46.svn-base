(function (w) {
    var dict = {};

    dict.token = '';
    function Initialize() {
        var user = $api.getToken();
        if (!$api.isNull(user)) {
            dict.token = user.token;
        }
    };

    dict.selMerchantByGisRect = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.MATSELECTBYGISRECT, dict.token, data, success, error);
    };
    dict.selMerchantAll = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.SELMERCHARTALL, dict.token, data, success, error);
    };
    dict.addCharge = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.ADDCHARGE, dict.token, data, success, error);
    };
    dict.updCharge = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.UPDCHARGE, dict.token, data, success, error);
    };
    dict.delCharge = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.DELCHARGE, dict.token, data, success, error);
    };
    dict.selChargeByType = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.SELCHARGEBYTYPE, dict.token, data, success, error);
    };
    dict.selChargeAll = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.SELCHARGEALL, dict.token, data, success, error);
    };
    dict.addMerchant = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.ADDMERCHANT, dict.token, data, success, error);
    };
    dict.updMerchant = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.UPDMERCHANT, dict.token, data, success, error);
    };
    dict.delMerchant = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.DELMERCHANT, dict.token, data, success, error);
    };
    dict.selMerchantByName = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.SELMERCHANTBYNAME, dict.token, data, success, error);
    };
    dict.selMerchantAll = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.SELMERCHARTALL, dict.token, data, success, error);
    };

    w.$dict = dict;
})(window);