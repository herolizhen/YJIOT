/*
 * 
 * 5.6	统计管理
 * */
(function (w) {
	var query = {};
	query.token = '';

	function Initialize() {
		var user = $api.getToken();
		if (!$api.isNull(user)) {
			query.token = user.token;
		}
	};
	//		消费明细报表
	query.consumeDetailQuery = function (data, success, error) {
		Initialize();
		console.log($cfg.URL_CONSUMEDETAIL);
		$iot.POST($cfg.URL_CONSUMEDETAIL,  query.token, data, success, error);
	};

	//	商户收入报表
	query.consumeMerchantQuery = function (data, success, error) {
		Initialize();
		$iot.POST($cfg.URL_CONSUMEMERCHART,  query.token, data, success, error);
	};


	// 5.8.3	查询设备台账
	query.deviceAccountQuery = function (data, success, error) {
		Initialize();
		$iot.POST($cfg.URL_DEVICEACCOUNT,  query.token, data, success, error);
	};


	// 5.8.4	查询商户台账
	query.merchantAccountQuery = function (data, success, error) {
		Initialize();
		$iot.POST($cfg.URL_MERCHANTACCOUNT,  query.token, data, success, error);
	};


	//5.8.5	设备贡献月统计
	query.deviceOfferMonthQuery = function (data, success, error) {
		Initialize();
		$iot.POST($cfg.URL_DEVICEOFFERMONT,  query.token, data, success, error);
	};


	//5.8.6	设备贡献周统计
	query.deviceOfferWeekQuery = function (data, success, error) {
		Initialize();
		$iot.POST($cfg.URL_DEVICEOFFERWEEK,  query.token, data, success, error);
	};


	//5.8.7	商户贡献月统计
	query.merchantOfferMonthQuery = function (data, success, error) {
		Initialize();
		$iot.POST($cfg.URL_MERCHANTOFFERMONTH,  query.token, data, success, error);
	};


	//5.8.8	商户贡献周统计
	query.merchantOfferWeekQuery = function (data, success, error) {
		Initialize();
		$iot.POST($cfg.URL_MERCHANTOFFERWEEK,  query.token, data, success, error);
	};
	//	5.8.9	用户反馈查询
	query.qnrQuery = function (data, success, error) {
		Initialize();
		$iot.POST($cfg.URL_QURQUERY,  query.token, data, success, error);
	};


	w.$query = query;
})(window);