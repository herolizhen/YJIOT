/*
1.0.0
*/
//日期时间格式化输出
Date.prototype.pattern = function (fmt) {
    var o = {
        "M+": this.getMonth() + 1, //月份     
        "d+": this.getDate(), //日     
        "h+": this.getHours() % 12 == 0 ? 12 : this.getHours() % 12, //小时     
        "H+": this.getHours(), //小时     
        "m+": this.getMinutes(), //分     
        "s+": this.getSeconds(), //秒     
        "q+": Math.floor((this.getMonth() + 3) / 3), //季度     
        "S": this.getMilliseconds() //毫秒     
    };
    var week = {
        "0": "/u65e5",
        "1": "/u4e00",
        "2": "/u4e8c",
        "3": "/u4e09",
        "4": "/u56db",
        "5": "/u4e94",
        "6": "/u516d"
    };
    if (/(y+)/.test(fmt)) {
        fmt = fmt.replace(RegExp.$1, (this.getFullYear() + "").substr(4 - RegExp.$1.length));
    }
    if (/(E+)/.test(fmt)) {
        fmt = fmt.replace(RegExp.$1, ((RegExp.$1.length > 1) ? (RegExp.$1.length > 2 ? "/u661f/u671f" : "/u5468") : "") + week[this.getDay() + ""]);
    }
    for (var k in o) {
        if (new RegExp("(" + k + ")").test(fmt)) {
            fmt = fmt.replace(RegExp.$1, (RegExp.$1.length == 1) ? (o[k]) : (("00" + o[k]).substr(("" + o[k]).length)));
        }
    }
    return fmt;
};
/*!
Math.uuid.js (v1.4)
http://www.broofa.com
mailto:robert@broofa.com
Copyright (c) 2010 Robert Kieffer
Dual licensed under the MIT and GPL licenses.
*/
(function () {
    // Private array of chars to use
    var CHARS = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'.split('');

    Math.uuid = function (len, radix) {
        var chars = CHARS, uuid = [], i;
        radix = radix || chars.length;

        if (len) {
            // Compact form
            for (i = 0; i < len; i++) uuid[i] = chars[0 | Math.random() * radix];
        } else {
            // rfc4122, version 4 form
            var r;

            // rfc4122 requires these characters
            uuid[8] = uuid[13] = uuid[18] = uuid[23] = '-';
            uuid[14] = '4';

            // Fill in random data.  At i==19 set the high bits of clock sequence as
            // per rfc4122, sec. 4.1.5
            for (i = 0; i < 36; i++) {
                if (!uuid[i]) {
                    r = 0 | Math.random() * 16;
                    uuid[i] = chars[(i == 19) ? (r & 0x3) | 0x8 : r];
                }
            }
        }

        return uuid.join('');
    };

    // A more performant, but slightly bulkier, RFC4122v4 solution.  We boost performance
    // by minimizing calls to random()
    Math.uuidFast = function () {
        var chars = CHARS, uuid = new Array(36), rnd = 0, r;
        for (var i = 0; i < 36; i++) {
            if (i == 8 || i == 13 || i == 18 || i == 23) {
                uuid[i] = '-';
            } else if (i == 14) {
                uuid[i] = '4';
            } else {
                if (rnd <= 0x02) rnd = 0x2000000 + (Math.random() * 0x1000000) | 0;
                r = rnd & 0xf;
                rnd = rnd >> 4;
                uuid[i] = chars[(i == 19) ? (r & 0x3) | 0x8 : r];
            }
        }
        return uuid.join('');
    };

    // A more compact, but less performant, RFC4122v4 solution:
    Math.uuidCompact = function () {
        return 'xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g, function (c) {
            var r = Math.random() * 16 | 0, v = c == 'x' ? r : (r & 0x3 | 0x8);
            return v.toString(16);
        });
    };
})();

(function (w) {
    var api = {};
    const TOKEN = 'UserToken';
    const _Parameter = 'Parameter';
    const _APPID = 'APPID';
    const Func_ID = 'func-frame';
    const Func_Menu = 'func-menu';

    api.Initialize = function () {
        if (!api.isNull(w.parent)) {
            w.$cfg = w.parent.$cfg;
            w.$iot = w.parent.$iot;
            w.$pow = w.parent.$pow;
            w.$ota = w.parent.$ota;
        }
    };

    function setStorage(key, value) {
        var yes = false;
        if (!api.isNull(w.localStorage)) {
            if (arguments.length === 2) {
                var v = value;
                if (typeof v == 'object') {
                    v = JSON.stringify(v);
                    v = 'obj-' + v;
                } else {
                    v = 'str-' + v;
                }
                var ls = w.localStorage;
                if (ls) {
                    ls.setItem(key, v);
                }
            }
        }
        return yes;
    }
    function getStorage(key) {
        var value;
        if(!api.isNull(w.localStorage)){
            var ls = w.localStorage;
            if (ls) {
                var v = ls.getItem(key);
                if (!v) { return; }
                if (v.indexOf('obj-') === 0) {
                    v = v.slice(4);
                    value = JSON.parse(v);
                } else if (v.indexOf('str-') === 0) {
                    value = v.slice(4);
                }
            }
        }
        return value;
    }
    function rmStorage(key) {
        if(!api.isNull(w.localStorage)){
            w.localStorage.removeItem(key);
        }
    }
    function clearStorage() {
        if(!api.isNull(w.localStorage)){
            w.localStorage.clear();
        }
    }

    api.isNull = function (obj) {
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
    api.getUUID = function (tag) {
        if (api.isNull(tag)) {
            tag = 32;
        }
        return Math.uuid(tag);
    };
    api.roundNumber = function (number, decimals) {
        var newString;
        decimals = Number(decimals);
        if (decimals < 1) {
            newString = (Math.round(number)).toString();
        } else {
            var numString = number.toString();
            if (numString.lastIndexOf(".") == -1) {
                numString += ".";
            }
            var cutoff = numString.lastIndexOf(".") + decimals;
            var d1 = Number(numString.substring(cutoff, cutoff + 1));
            var d2 = Number(numString.substring(cutoff + 1, cutoff + 2));
            if (d2 >= 5) {
                if (d1 == 9 && cutoff > 0) {
                    while (cutoff > 0 && (d1 == 9 || isNaN(d1))) {
                        if (d1 != ".") {
                            cutoff -= 1;
                            d1 = Number(numString.substring(cutoff, cutoff + 1));
                        } else {
                            cutoff -= 1;
                        }
                    }
                }
                d1 += 1;
            }
            if (d1 == 10) {
                numString = numString.substring(0, numString.lastIndexOf("."));
                var roundedNum = Number(numString) + 1;
                newString = roundedNum.toString() + '.';
            } else {
                newString = numString.substring(0, cutoff) + d1.toString();
            }
        }
        return newString * 1;
    };
    api.clone = function (obj) {
        var o;
        if (typeof obj == "object") {
            if (obj === null) {
                o = null;
            } else {
                if (obj instanceof Array) {
                    o = [];
                    for (var i = 0, len = obj.length; i < len; i++) {
                        o.push(api.clone(obj[i]));
                    }
                } else {
                    o = {};
                    for (var j in obj) {
                        o[j] = api.clone(obj[j]);
                    }
                }
            }
        } else {
            o = obj;
        }
        return o;
    };

    api.saveToken = function (username,token) {
        var data = {};
        data.username = username;
        data.token = token;
        setStorage(TOKEN, data);
    };
    api.getToken = function () {
        return getStorage(TOKEN);
    };
    api.saveCurrApp = function (app) {
        return setStorage(_APPID, app);
    };
    api.getCurrApp = function () {
        return getStorage(_APPID);
    };
    api.setParameter = function (data) {
        return setStorage(_Parameter, data);
    };
    api.getParameter = function () {
        return getStorage(_Parameter);
    };

    api.ui_openLoading = function (title,text) {
        if(api.isNull(title)){
            title = '加载提示';
        }
        if (api.isNull(text)) {
            text = '加载中，请耐心等待......';
        }
        if (w.openLoading && typeof (w.openLoading) == 'function') {
            w.ui_main.openLoading(title, text);
        } else {
            if (!api.isNull(w.parent)) {
                w.parent.ui_main.openLoading(title, text);
            }
        }
    };
    api.ui_closeLoading = function () {
        if (w.closeLoading && typeof (w.closeLoading) == 'function') {
            w.ui_main.closeLoading();
        } else {
            if (!api.isNull(w.parent)) {
                w.parent.ui_main.closeLoading();
            }
        }
    };
    api.ui_openAlert = function (title, text, callback) {
        if (api.isNull(title)) {
            title = '加载提示';
        }
        if (api.isNull(text)) {
            text = '易净物联网';
        }
        if (w.openAlert && typeof (w.openAlert) == 'function') {
            w.ui_main.openAlert(title, text, callback);
        } else {
            if (!api.isNull(w.parent)) {
                w.parent.ui_main.openAlert(title, text, callback);
            }
        }
    };

    w.$api = api;
})(window);