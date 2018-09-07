(function (w) {
    var iot = {};

    var client;

    iot.Host = '';
    iot.Token = '';
    iot.DeviceId = '';

    iot.mqttClientConnect = function (options, callback, error) {
        iot.mqttClientDisconnect();
        client = new Paho.MQTT.Client(
                options.host,
                options.port,
                options.path,
                options.clientid
            );
        client.onMessageArrived = function (message) {
            var ismessage = false;
            var json;
            try {
                json = JSON.parse(String(message.payloadString));
                ismessage = true;
            } catch (e) {
                error('onMessageArrived');
                ismessage = false;
            }
            if (ismessage && !$app.isNull(json)) {
                callback(json); 
            }
        };
        var useSSL = true;
        client.connect({
            userName: options.userName,
            password: options.password,
            useSSL: useSSL,
            onSuccess: function () {
                client.subscribe(options.topic, {
                    timeout: 3000,
                    onFailure:error
                });
            },
            onFailure: function (err) {
                error('connect'); 
            }
        });
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
    iot.sendCommand = function (cmd, success, error, timeout) {
        var data = {};
        data.deviceId = iot.DeviceId;
        data.payload = JSON.stringify(cmd);
        data.format = 'json';
        data.flag = 1;
        var time = w.setTimeout(timeout, 5000);
        $.ajax({
            url: iot.Host + '/YJIOT/client/sendCommandAdv',
            type: 'POST',
            headers: {
                "Authorization": "JWT " + iot.Token
            },
            contentType: 'application/json;charset=utf-8',
            dataType: 'json',
            data: JSON.stringify(data),
            timeout: 5000,
            success: function (ret) {
                if (ret && ret.meta.code == 0) {
                    w.clearTimeout(time);
                    success();
                } else {
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

    w.$iot = iot;
})(window);