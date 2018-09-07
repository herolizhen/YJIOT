(function (w) {
    var iot = {};

    var client;

    iot.Host = '';
    iot.Token = '';
    iot.DeviceId = '';
    iot.OpenId = '';

    iot.mqttClientConnect = function (options, callback, error) {
        iot.mqttClientDisconnect();
        var url = 'wss://' + options.host + ':' + options.port + options.path;
        var topic = options.topic;
        client = Stomp.client(url);
        client.heartbeat.outgoing = 10000;
        client.heartbeat.incoming = 0;
        client.connect(options.userName, options.password, function () {
            client.subscribe(topic, function (message) {
                var json;
                try {
                    json = JSON.parse(message.body);
                } catch (e) {
                    json = null;
                }
                if (!$app.isNull(json)) {
                    callback(json);
                }
            });
        }, error);
    };
    iot.mqttClientDisconnect = function () {
        if (!$app.isNull(client)) {
            try{
                client.disconnect();
                client = null;
            } catch (e) {

            }
        }
    }

    //{"deviceId":"fecc5b66-ff1e-4490-a700-7634dd842b64","payload": "{\"FA\":1}", "format": "json", "flag": 0 }
    iot.sendCommand = function (cmd, success, error, timeout, callbacktoken) {
        var data = {};
        data.deviceId = iot.DeviceId;
        data.payload = JSON.stringify(cmd);
        data.format = 'json';
        data.flag = 1;
        var time = w.setTimeout(timeout, 10000);
        $.ajax({
            url: iot.Host + '/YJIOT/client/sendCommand',
            type: 'POST',
            headers: {
                "Content-Type": 'application/json',
                "Authorization":iot.Token
            },
            contentType: 'application/json;charset=utf-8',
            dataType: 'json',
            data: JSON.stringify(data),
            timeout: 5000,
            success: function (ret) {
                if (ret && ret.meta.code == 0) {
                    w.clearTimeout(time);
                    success();
                } else if (ret && ret.meta.code == 1000) {
                    if (!$app.isNull(callbacktoken)) {
                        refreshToken(function (token) {
                            iot.Token = token;
                            w.clearTimeout(time);
                            iot.sendCommand(cmd, success, error);
                            callbacktoken(token);
                        }, function () {
                            error();
                        });
                    } else {
                        error();
                    }
                }else {
                    w.clearTimeout(time);
                    error();
                }
            },
            error: function (err) {
                w.clearTimeout(time);
                error();
            }
        });
    };
    //微信采用GET请求无效或者ｈｔｔｐｓ不支持http，具体不清楚。
    iot.getCityWeather = function (longitude, latitude,success,error) {
        $.ajax({
            url: 'http://io.bjyjyz.com:8080/api/Service/Weather',
            type: 'GET',
            data: {
                longitude: longitude,
                latitude:latitude
            },
            timeout: 5000,
            success: function (ret) {
                if (!$app.isNull(ret) && ret.status == 0) {
                    var w = {};
                    w.temperature = ret.message.weather.today.temperature;
                    w.city = ret.message.city;
                    w.weather = ret.message.weather.today.weather;
                    w.humidity = ret.message.weather.sk.humidity;
                    w.aqi = ret.message.aqi.AQI + ret.message.aqi.quality;
                    w.windtitle = ret.message.weather.sk.wind_direction;
                    w.windvalue = ret.message.weather.sk.wind_strength;
                    success(w);
                } else {
                    if (!$app.isNull(error)) {
                        error();
                    }
                }
            },
            error: function (err) {
                if (!$app.isNull(error)) {
                    error(err);
                }
            }
        });
    };
    //问题反馈
    iot.postFeedback = function (raw, success, error, callbacktoken) {
        $.ajax({
            url: iot.Host + '/YJIOT/product/saveProdQnr',
            type: 'POST',
            headers: {
                "Content-Type": 'application/json',
                "Authorization": iot.Token
            },
            contentType: 'application/json;charset=utf-8',
            dataType: 'json',
            data: JSON.stringify(raw),
            timeout: 5000,
            success: function (ret) {
                if (ret && ret.meta.code == 0) {
                    success();
                } else if (ret && ret.meta.code == 1000) {
                    if (!$app.isNull(callbacktoken)) {
                        refreshToken(function (token) {
                            iot.Token = token;
                            iot.postFeedback(raw, success, error);
                            callbacktoken(token);
                        }, function () {
                            error();
                        });
                    } else {
                        error();
                    }
                } else {
                    error();
                }
            },
            error: function (err) {
                error();
            }
        });
    };

    //private
    function refreshToken(callbacktoken,error) {
        var data = {};
        data.openid = iot.OpenId;
        $.ajax({
            url: iot.Host + '/YJIOT/client/getJwtToken',
            type: 'POST',
            headers: {
                "Content-Type": 'application/json'
            },
            contentType: 'application/json;charset=utf-8',
            dataType: 'json',
            data: JSON.stringify(data),
            timeout: 5000,
            success: function (ret) {
                if (ret && ret.meta.code == 0) {
                    callbacktoken(ret.data.token);
                } else {
                    error();
                }
            },
            error: function (err) {
                error();
            }
        });
    }

    w.$iot = iot;
})(window);