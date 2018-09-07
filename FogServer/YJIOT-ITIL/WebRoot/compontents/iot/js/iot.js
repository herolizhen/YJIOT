(function (w) {
    var iot = {};

    var client;
    var client2;
    var getTokencount = 0;
    iot.Host ='www.yjiot.net';


    iot.POST = function (url, token, data, success, error) {
        $.ajax({
            url: url,
            type: 'POST',
            crossDomain: true,
            timeout:5000,
            contentType: 'application/json;charset=UTF-8',
            data: JSON.stringify(data),
            headers: {
                "content-type": "application/json",
                "authorization": token
            },
            dataType: 'json',
            success: function (ret) {
            	//console.log(url+'返回code码：-----------》'+ret.meta.code);
                if (!$api.isNull(ret) && !$api.isNull(ret.meta) && !$api.isNull(ret.meta.code)) {
                    if (ret.meta.code == 0) {
                        success(ret.data);
                        getTokencount = 0;
                    } else if (ret.meta.code == 1000 && getTokencount==0) {
                        var user = $api.getToken();
                        var appid = $api.getCurrApp();
                        if (!$api.isNull(user)&&!$api.isNull(appid)) {
                            var username = user.username;
                            var appId = appid;
                            iot.getToken(username, appId, function (_token) {
                                getTokencount = 1;
                                //保存最新token
                                iot.POST(url, _token, data, success, error);
                            }, function () {
                                getTokencount = 0;
                                error();
                            });
                        } else {
                            getTokencount = 0;
                            error();
                        }
                    }else{
                    	  getTokencount = 0;
                          error();
                    }
                } else {
                    getTokencount = 0;
                    error();
                }


            },
            error: function (XMLHttpRequest, textStatus, errorThrown) {
             	//console.log('XMLHttpRequest-------------------->'+XMLHttpRequest);
                error();
            }
        });
    }
    //获取验证码
    iot.getToken = function (username, appId, success, error) {
        if (!$api.isNull(username)) {
            var data = {};
            data.userName = username;
            data.appId = appId;
            data = JSON.stringify(data);
            var url = $cfg.URL_GETTOKEN;
            console.log('iot.getToken:' + url);
            $.ajax({
                url: url,
                type: 'POST',
                crossDomain: true,
                contentType: 'application/json',
                data: JSON.stringify(data),
                headers: {
                    "content-type": "application/json"
                },
                dataType: 'json',
                success: function (ret) {
                    if (!$api.isNull(ret) && !$api.isNull(ret.meta) && !$api.isNull(ret.meta.code) && ret.meta.code == 0) {

                        success(ret.token);
                    } else {
                        error();
                    }
                },
                error: function () {
                    error();
                }
            });
        } else {
            error();
        }
    };

    iot.mqttClientConnect = function (options, callback, error) {
		iot.mqttClientDisconnect();
		 var url = 'wss://' + $cfg.MQTTHOST  + ':' + $cfg.MQTTPORT + $cfg.MQTTPATH;
		var topic = options.topic;
		client = Stomp.client(url);
		client.heartbeat.outgoing = 10000;
		client.heartbeat.incoming = 0;
		client.connect(options.deviceId, options.devicePw, function () {
			client.subscribe(topic, function (message) {
				var json;
				try {
					json = JSON.parse(message.body);
				} catch (e) {
					json = null;
				}
				if (!$api.isNull(json)) {
					callback(json);
				}
			});
		}, error);
	};
    iot.mqttClientCommands = function (options, callback, error) {
		iot.mqttClientDisconnect2();
		 var url = 'wss://' + $cfg.MQTTHOST  + ':' + $cfg.MQTTPORT + $cfg.MQTTPATH;
		var topic = options.topic;
		client2 = Stomp.client(url);
		client2.heartbeat.outgoing = 10000;
		client2.heartbeat.incoming = 0;
		client2.connect(options.deviceId, options.devicePw, function () {
			client2.subscribe(topic, function (message) {
				var json;
				try {
					json = JSON.parse(message.body);
				} catch (e) {
					json = null;
				}
				if (!$api.isNull(json)) {
					callback(json);
				}
			});
		}, error);
	};
	//commands
    
    iot.mqttClientDisconnect = function () {
        if (!$api.isNull(client)) {
            try {
                client.disconnect();
                client = null;
            } catch (e) {

            }
        }
    };
    iot.mqttClientDisconnect2 = function () {
    	if (!$api.isNull(client2)) {
    		try {
    			client2.disconnect();
    			client2 = null;
    		} catch (e) {
    			
    		}
    	}
    };
    
    
    //{"deviceId":"fecc5b66-ff1e-4490-a700-7634dd842b64","payload": "{\"FA\":1}", "format": "json", "flag": 0 }
    

    w.$iot = iot;
})(window);