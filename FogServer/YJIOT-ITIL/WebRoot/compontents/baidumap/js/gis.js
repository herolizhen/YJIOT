(function (w) {
    var gis = {};

    const DEVICEONLINE = 'http://www.yjiot.net/YJIOT-ITIL/static/image/map/online.svg';
    const DEVICEOFFLINE = 'http://www.yjiot.net/YJIOT-ITIL/static/image/map/offline.svg';
    const DEVICES0 = 'http://www.yjiot.net/YJIOT-ITIL/static/image/map/000.svg';
    const DEVICES1 = 'http://www.yjiot.net/YJIOT-ITIL/static/image/map/100.svg';
    const DEVICES2 = 'http://www.yjiot.net/YJIOT-ITIL/static/image/map/110.svg';
    const DEVICES3 = 'http://www.yjiot.net/YJIOT-ITIL/static/image/map/111.svg';

    var map;
    var maplib;

    gis.Initialize = function (id, callback) {
        map = new BMap.Map(id, { minZoom: 4, maxZoom: 25 });
        map.centerAndZoom(new BMap.Point(116.3964, 39.9093), 6);
        map.enableScrollWheelZoom();
        if (!$api.isNull(callback)) {
            map.addEventListener("tilesloaded", callback);
        }
        maplib = new BMapLib.MarkerClusterer(map);
    };

    gis.clearMap = function () {
        map.clearOverlays();
        maplib.clearMarkers();
    };
    gis.getShow = function () {
        var show = {};
        var bs = map.getBounds();   //获取可视区域
        var bssw = bs.getSouthWest();   //可视区域左下角
        var bsne = bs.getNorthEast();   //可视区域右上角

        show.longitudeLB = bssw.lng;
        show.latitudeLB = bssw.lat;
        show.longitudeRT = bsne.lng;
        show.latitudeRT = bsne.lat;
        return show;
    };
    gis.isPointInRect = function (point, bounds) {
        if (!(point instanceof BMap.Point) ||
           !(bounds instanceof BMap.Bounds)) {
            return false;
        }
        var sw = bounds.getSouthWest(); //西南脚点
        var ne = bounds.getNorthEast(); //东北脚点
        return (point.lng >= sw.lng && point.lng <= ne.lng && point.lat >= sw.lat && point.lat <= ne.lat);
    };

    function clusterDevice(ds) {
        var data = [];
        $.each(ds, function (i, d) {
            var tmp;
            $.each(data, function (j, n) {
                if (n.ownerName == d.ownerName) {
                    tmp = n;
                    return false;
                }
            });
            if ($api.isNull(tmp)) {
                tmp = {};
                tmp.ownerName = d.ownerName;
                tmp.arry = [];
                tmp.arry.push(d);
                data.push(tmp);
            } else {
                tmp.arry.push(d);
            }
        });
        return data;
    }
    function oneCluster(n) {
        var marker;
        var d;
        var count = 0;
        var online = 0;
        var offline = 0;
        count = n.arry.length;
        $.each(n.arry, function (i, tmp) {
            if ($api.isNull(d)) {
                d = tmp;
            }
            if (tmp.isOnline) {
                online++;
            } else {
                offline++;
            }
        });
        var point = new BMap.Point(d.longitude, d.latitude);
        var icon;
        var key = online / count;
        if (key <= 0.5) {
            icon = new BMap.Icon(DEVICES0,new BMap.Size(50, 50));
        }
        else if (key>0.5&&key<=0.6) {
            icon = new BMap.Icon(DEVICES1, new BMap.Size(50, 50));
        }
        else if (key > 0.6 && key < 1) {
            icon = new BMap.Icon(DEVICES2, new BMap.Size(50, 50));
        }
        else {
            icon = new BMap.Icon(DEVICES3, new BMap.Size(50, 50));
        }
        marker = new BMap.Marker(point, { icon: icon });
        var label = new BMap.Label(n.ownerName+'-'+count+'/'+online, { offset: new BMap.Size(20, -10) });
        marker.setLabel(label);
        return marker;
    }
    function createSpreadPoints(ps) {
        var datas = [];
        var sps = [];
        $.each(ps, function (i, p) {
            var sp;
            $.each(sps, function (j, tmp) {
                if (tmp.key == (p.longitude + ',' + p.latitude)) {
                    sp = tmp;
                }
            });
            if ($api.isNull(sp)) {
                sps.push({
                    key: (p.longitude + ',' + p.latitude),
                    longitude: $api.roundNumber(p.longitude, 3),
                    latitude: $api.roundNumber(p.latitude, 3),
                    data: [p]
                });
            } else {
                sp.data.push(p);
            }
        });
        if (sps.length > 0) {
            $.each(sps, function (i, tmp) {
                var longitude = tmp.longitude;
                var latitude = tmp.latitude;
                $.each(tmp.data, function (j, v) {
                    v.longitude = longitude + ('0.000' + j) * 1;
                    v.latitude = latitude + ('0.0000' + j) * 1;
                    datas.push(v);
                });
            });
        }
        return datas;
    }
    function createSpreadMarkers(markers) {
        var sps = [];
        $.each(markers, function (i, m) {
            var sp;
            var p = m.getPosition();
            var key = $api.roundNumber(p.lng, 4) + ',' + $api.roundNumber(p.lat, 4);
            $.each(sps, function (j, tmp) {
                if (tmp.key == key) {
                    sp = tmp;
                }
            });
            if ($api.isNull(sp)) {
                sps.push({
                    key: key,
                    data: [m]
                });
            } else {
                sp.data.push(m);
            }
        });
        $.each(sps, function (i, p) {
            var online = 0;
            var count = p.data.length;
            if (count >= 2) {
                $.each(p.data, function (j, m) {
                    var zindex = (j + 1);
                    m.setZIndex(zindex + 10);
                    if (m.$data.isOnline) {
                        online++;
                    }
                    if (zindex == count) {
                        var label = new BMap.Label(count + '/' + online, { offset: new BMap.Size(20, -10) });
                        //label.setStyle({
                        //    color: "#000000",
                        //    fontSize: "12px",
                        //    border: "0",
                        //});
                        m.setLabel(label);
                    }
                });
            }
        });
    }

    gis.createDevices = function (ds, callclick) {
        var markers = [];
        var zoom = map.getZoom();
        var data = clusterDevice(ds);
        if (zoom >= 18) {
            $.each(data, function (i, n) {
                var marker = oneCluster(n);
                if (!$api.isNull(callclick)) {
                    marker.$data = n;
                    marker.addEventListener("click", callclick);
                }
                marker.enableDragging();
                map.addOverlay(marker);
            });
        } else {
            $.each(data, function (i, n) {
                $.each(n.arry, function (j, d) {
                    var point = new BMap.Point(d.longitude, d.latitude);
                    var icon;
                    if (d.isOnline) {
                        icon = new BMap.Icon(
                                        DEVICEONLINE,
                                        new BMap.Size(25, 25)
                                    );
                    } else {
                        icon = new BMap.Icon(
                                        DEVICEOFFLINE,
                                        new BMap.Size(25, 25)
                                    );
                    }
                    var marker = new BMap.Marker(
                                        point, { icon: icon }
                                    );
                    if (n.arry.length == 1) {
                        if (!$api.isNull(callclick)) {
                            marker.$data = d;
                            marker.addEventListener("click", callclick);
                        }
                    }
                    marker.enableDragging();
                    markers.push(marker);
                });
            });
            maplib.addMarkers(markers);
        }
    };
    gis.createMerchants = function (ms, callclick) {
        var markers = [];
        var zoom = map.getZoom();
        $.each(ms, function (i, m) {
            var point = new BMap.Point(m.longitude, m.latitude);
            var marker = new BMap.Marker(point);
            marker.enableDragging();
            if (!$api.isNull(callclick)) {
                marker.$data = m;
                marker.addEventListener("click", callclick);
            }
            markers.push(marker);
        });
        if (zoom >= 12) {
            $.each(markers, function (i, m) {
                var tmp = m.$data;
                var label = new BMap.Label(tmp.name + '-' + tmp.bussLeader, { offset: new BMap.Size(20, -10) });
                m.setLabel(label);
                map.addOverlay(m);
            });
        } else {
            maplib.addMarkers(markers);
        }
    };

    w.$gis = gis;
})(window);