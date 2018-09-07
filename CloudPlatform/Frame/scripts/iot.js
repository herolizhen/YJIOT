(function (w) {
    var iot = {};

    var client;
    var getTokencount = 1;


    iot.POST = function (url, token, data, success, error) {
        $.ajax({
            url: url,
            type: 'POST',
            crossDomain: true,
            contentType: 'application/json',
            data: JSON.stringify(data),
            headers: {
                "content-type": "application/json",
                "authorization": token
            },
            dataType: 'json',
            success: function (ret) {
                if (!$api.isNull(ret) && !$api.isNull(ret.meta) && !$api.isNull(ret.meta.code)) {
                    if (ret.meta.code == 0) {
                        success(ret.data);
                        getTokencount = 0;
                    } else if (ret.meta.code == 1000) {
                        var user = $api.getToken();
                        if (!$api.isNull(user)) {
                            var username = user.username;
                            var appId = user.appId;
                            iot.getToken(username, appId, function (_token) {
                                getTokencount = 1;
                                //保存最新token
                                iot.POST(url, _token, data, success, error);
                            }, error);
                        } else {
                            getTokencount = 0;
                            error();
                        }
                    }
                } else {
                    getTokencount = 0;
                    error();
                }


            },
            error: function (XMLHttpRequest, textStatus, errorThrown) {

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
            var url = '';
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

    iot.mqttClientConnect = function (url,username,password,topic, callback, error) {
        iot.mqttClientDisconnect();
        client = Stomp.client(url);
        client.heartbeat.outgoing = 10000;
        client.heartbeat.incoming = 0;
        client.connect(username, password, function () {
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
    iot.mqttClientDisconnect = function () {
        if (!$api.isNull(client)) {
            try {
                client.disconnect();
                client = null;
            } catch (e) {

            }
        }
    }

    w.$iot = iot;
})(window);