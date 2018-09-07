/*
 *
 */
(function(w) {
	var iot = {};
	var getTokencount = 1;
	iot.POST =function(url, token, data, success, error) {
		$.ajax({
			type : 'POST',
			crossDomain : true,
			contentType : 'application/json',
			url :url,
			data :data,
			headers: {
				"content-type": "application/json",
				"authorization": token
			},
			dataType : 'json',
			success : function(ret) {
				if (!$app.isNull(ret) && !$app.isNull(ret.meta) && !$app.isNull(ret.meta.code)) {
					if (ret.meta.code == 0) {
						success(ret.data);
						getTokencount = 0;
					}else if (ret.meta.code == 1000) {
						var user = $app.getToken();
						if (!$app.isNull(user)) {
							var username = user.username;
							var appId = user.appId;
							iot.getToken (username,appId,function(tk) {
								getTokencount = 1;
								var _token = tk.token;

								iot.POST(url, tk.token, data, success, error);
							}, error);
						}else{
							getTokencount = 0;
							error();
						}
					}
				}else{
					getTokencount = 0;
					error();
				}


			},
			error : function(XMLHttpRequest, textStatus, errorThrown) {

				error();
			}
		});
	}

	//获取验证码
	iot.getToken = function(username,appId, success, error) {
		if (!$app.isNull(username)) {
			var data = {};
			data.userName = username;
			data.appId = appId;
			data = JSON.stringify(data);
			iot.POST($app.URL_GETTOKEN, '', data, function(ret){success(ret.token)}, error);
		} else {
			error();
		}
	};

	w.$iot = iot;
})(window);
