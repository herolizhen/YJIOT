(function (w) {
    var app = {};

    var timeout;

    app.isNull = function (obj) {
        if (obj == undefined || obj == null) {
            return true;
        } else if (typeof obj == 'string') {
            if (obj.length > 0) {
                return false;
            } else {
                return true;
            }
        } else {
            return false;
        }
    };

    app.getIaqLevel = function (data) {
        var aqi = {};
        aqi.text = '优';
        aqi.color = '#00e400';
        aqi.ratio = 45;
        if (data.P>0&&data.P <= 50) {
            aqi.text = '优';
            aqi.color = '#00e400';
            aqi.ratio = 45;
        } 
        if (data.P > 50 && data.P <= 100) {
            aqi.text = '良';
            aqi.color = '#ffff00';
            aqi.ratio = 90;
        }
        if (data.P > 100 && data.P <= 150) {
            aqi.text = '轻度污染';
            aqi.color = '#ff7e00';
            aqi.ratio = 135;
        }
        if (data.P > 150 && data.P <= 200) {
            aqi.text = '中度污染';
            aqi.color = '#ff0000';
            aqi.ratio = 180;
        }
        if (data.P > 200 && data.P <= 300) {
            aqi.text = '重度污染';
            aqi.color = '#99004c';
            aqi.ratio = 225;
        }
        if (data.P > 300) {
            aqi.text = '严重污染';
            aqi.color = '#7e0023';
            aqi.ratio = 270;
        }

        return aqi;
    };

    app.minuteToDateString = function (min) {
        var h = parseInt(min / 60);
        var m = min - 60 * h;
        var str = '';
        if (String(h).length > 1) {
            str = h;
        } else {
            str = '0' + h;
        }
        str += ':';
        if (String(m).length > 1) {
            str += m;
        } else {
            str += '0' + m;
        }
        str += ':00';
        return str;
    };
    
    app.setTimeout = function (callback) {
        app.clearTimeout();
        timeout = w.setTimeout(callback, 10000);
    };

    app.clearTimeout = function () {
        if (!app.isNull(timeout)) {
            w.clearTimeout(timeout);
        }
    };

    app.goTimeoutError = function () {
        w.location.href = "../../html5/timeout.html";
    };

    w.$app = app;
})(window);