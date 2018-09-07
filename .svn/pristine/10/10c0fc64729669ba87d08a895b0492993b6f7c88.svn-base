/*
 * 
 * 5.6	统计管理
 * */
(function (w) {
    var stats = {};
    stats.token = '';

    function Initialize() {
        var user = $api.getToken();
        if (!$api.isNull(user)) {
        	stats.token = user.token;
        }
    };
    //	设备生命周期状态
    stats.devStateType = function (data, success, error) {
    	Initialize();
        $iot.POST($cfg.URL_DEVSTATETYPE,  stats.token, data, success, error);
    };

    //	用户注册情况
    stats.userRegMonth = function (data, success, error) {
    	Initialize();
        $iot.POST($cfg.URL_USERREGMONTH,  stats.token, data, success, error);
    };

    //	资金回流情况
    stats.fundMonth = function (data, success, error) {
    	Initialize() ;
        $iot.POST($cfg.URL_FUNDMONTH,  stats.token, data, success, error);
    };

    //	资金周回流情况
    stats.fundMerChantDay = function (data, success, error) {
    	Initialize() ;
        $iot.POST($cfg.URL_FUNDMERCHANDAY,  stats.token, data, success, error);
    };

    //	三个月每周周每个商户的资金回流情况
    stats.fundMerChantWeek = function (data, success, error) {
    	Initialize() ;
        $iot.POST($cfg.URL_FUNdMERCHANWEEK,  stats.token, data, success, error);
    };

    //	统计一周每天，各个收费标准的收费次数
    stats.fundTimesDay = function (data, success, error) {
    	Initialize() ;
        $iot.POST($cfg.URL_FUNDTIMESDAY,  stats.token, data, success, error);
    };

    //	统计三个月每周，各个收费标准的收费次数
    stats.fundTimesWeek = function (data, success, error) {
       	Initialize() ;
        $iot.POST($cfg.URL_FUNDTIMESWEEK,  stats.token, data, success, error);
    };

    //统计每个运营人员所管理的设备数量
    stats.devSeller = function (data, success, error) {
       	Initialize() ;
        $iot.POST($cfg.URL_DEVSELLER,  stats.token, data, success, error);
    };

    //统计最近三个月运营人员每周的资金回流情况
    stats.fundSellerWeek = function (data, success, error) {
       	Initialize() ;
        $iot.POST($cfg.URL_DEVSELLERWEEK,  stats.token, data, success, error);
    };

    //统计各个商户设备的个状态数量
    stats.devOnlineState = function (data, success, error) {
       	Initialize() ;
        $iot.POST($cfg.URL_DEVONLINE,  stats.token, data, success, error);
    };

    //统计消费最多的15台机器的消费金额及使用次数
    stats.fundDevTop15 = function (data, success, error) {
       	Initialize() ;
        $iot.POST($cfg.URL_FUNDDEVTOP15,  stats.token, data, success, error);
    };

    //	最大处理前10名消费用户
    stats.fundUserTop10 = function (data, success, error) {
       	Initialize() ;
        $iot.POST($cfg.URL_FUNDUSERTOP10,  stats.token, data, success, error);
    };

    //周用户增加情况
    stats.userRegTypeWeek = function (data, success, error) {
       	Initialize() ;
        $iot.POST($cfg.USERREGTYPEWEE,  stats.token, data, success, error);
    };

    
    stats.devExamMain =function(data, success, error) {
       	Initialize() ;
        $iot.POST($cfg.DEVEXAMMAIN,  stats.token, data, success, error);
    };
    stats.devExamItem =function(data, success, error) {
       	Initialize() ;
    	$iot.POST($cfg.DEVEXAITEM,  stats.token, data, success, error);
    };
    
    
    
    stats.createNames_fundMerChantDay = function (data) {
        var names = [];
        $.each(data, function (i, v) {
            if ($.inArray(v.name, names) < 0) {
                names.push(v.name);
            }
        });
        return names;
    };
    stats.createDates_fundMerChantDay = function (data) {
        var dates = [];

        $.each(data, function (i, v) {
            if ($.inArray(v.data, dates) < 0) {
                dates.push(v.data);
            }
        });

        return dates;
    };
    stats.createFunds_fundDayMerChant = function (name, dates, data) {
        var funds = [];
        $.each(dates, function (i, date) {
            var isadd = true;
            $.each(data, function (j, v) {
                if (v.name == name && v.data == date) {
                    funds.push(v.fund);
                    isadd = false;
                    return;
                }
            });
            if (isadd) {
                funds.push(0);
            }
        });


        return funds;
    };
    stats.createFunds_fundMerChantDay = function (date, names, data) {
        var funds = [];
        $.each(names, function (i, name) {
            var isadd = true;
            $.each(data, function (j, v) {
                if (v.name == name && v.data == date) {
                    funds.push(v.fund);
                    isadd = false;
                    return;
                }
            });
            if (isadd) {
                funds.push(0);
            }
        });


        return funds;
    };

    stats.createNames_fundMerChantWeek = function (data) {
        var names = [];
        $.each(data, function (i, v) {
            if ($.inArray(v.NAME, names) < 0) {
                names.push(v.NAME);
            }
        });
        return names;
    };
    stats.createDates_fundMerChantWeek = function (data) {
        var dates = [];

        $.each(data, function (i, v) {
            if ($.inArray(v.weekno, dates) < 0) {
                dates.push(v.weekno);
            }
        });

        return dates;
    };
    stats.createFunds_fundMerChantWeek = function (name,dates,data) {
        var funds = [];
        $.each(dates, function (i, date) {
            var isadd = true;
            $.each(data, function (j, v) {
                if (v.weekno == date && v.NAME == name) {
                    funds.push(v.fund);
                    isadd = false;
                    return;
                }
            });
            if (isadd) {
                funds.push(0);
            }
        });
        return funds;
    };

    stats.createDates_fundTimesDay = function (data) {
        var dates = [];

        $.each(data, function (i, v) {
            if ($.inArray(v.data, dates) < 0) {
                dates.push(v.data);
            }
        });

        return dates;
    };
    stats.createPrices_fundTimesDay = function (data) {
        var prices = [];
        $.each(data, function (i, v) {
            if ($.inArray(('￥'+v.price), prices) < 0) {
                prices.push(('￥' + v.price));
            }
        });
        return prices;
    };
    stats.createCounts_fundTimesDay = function (price, dates, data) {
        var counts = [];
        $.each(dates, function (i, date) {
            var isadd = true;
            $.each(data, function (j, v) {
                if (('￥' + v.price) == price && v.data == date) {
                    counts.push(v.count);
                    isadd = false;
                    return;
                }
            });
            if (isadd) {
                counts.push(0);
            }
        });
        return counts;
    };

    stats.createDates_fundTimesWeek = function (data) {
        var dates = [];

        $.each(data, function (i, v) {
            if ($.inArray(v.weekno, dates) < 0) {
                dates.push(v.weekno);
            }
        });

        return dates;
    };
    stats.createPrices_fundTimesWeek = function (data) {
        var prices = [];
        $.each(data, function (i, v) {
            if ($.inArray(('￥' + v.price), prices) < 0) {
                prices.push(('￥' + v.price));
            }
        });
        return prices;
    };
    stats.createCounts_fundTimesWeek = function (price, dates, data) {
        var counts = [];
        $.each(dates, function (i, date) {
            var isadd = true;
            $.each(data, function (j, v) {
                if (('￥' + v.price) == price && v.weekno == date) {
                    counts.push(v.count);
                    isadd = false;
                    return;
                }
            });
            if (isadd) {
                counts.push(0);
            }
        });
        return counts;
    };

    stats.createDevSeller = function (data) {
        var ds = {};
        ds.names = [];
        ds.counts = [];
        $.each(data, function (i, v) {
            ds.names.push(v.seller);
            ds.counts.push(v.count);
        });
        return ds;
    };

    stats.createDates_fundSellerWeek = function (data) {
        var dates = [];

        $.each(data, function (i, v) {
            if ($.inArray(v.weekno, dates) < 0) {
                dates.push(v.weekno);
            }
        });

        return dates;
    };
    stats.createNames_fundSellerWeek = function (data) {
        var names = [];
        $.each(data, function (i, v) {
            if ($.inArray(v.seller, names) < 0) {
                names.push(v.seller);
            }
        });
        return names;
    };
    stats.createFree_fundSellerWeek = function (name, dates, data) {
        var frees = [];
        $.each(dates, function (i, date) {
            var isadd = true;
            $.each(data, function (j, v) {
                if (v.seller == name && v.weekno == date) {
                    frees.push(v.free);
                    isadd = false;
                    return;
                }
            });
            if (isadd) {
                frees.push(0);
            }
        });
        return frees;
    };

    stats.createKeys_devOnlineState = function (data) {
        var keys = [];
        keys.push('失联');//longoff
        keys.push('在线');//online
        keys.push('离线一天');//dayoff
        keys.push('离线一周');//weekoff
        return keys;
    };
    stats.createNames_devOnlineState = function (data) {
        var names = [];
        $.each(data, function (i, v) {
            if ($.inArray(v.name, names) < 0) {
                names.push(v.name);
            }
        });
        return names;
    };
    stats.createCounts_devOnlineState = function (key, names, data) {
        var counts = [];
        $.each(names, function (i, name) {
            var isadd = true;
            $.each(data, function (j, v) {
                if (v.name == name) {
                    switch (key) {
                        case '在线':
                            counts.push(v.online);
                            break;
                        case '失联':
                            counts.push(v.longoff);
                            break;
                        case '离线一天':
                            counts.push(v.dayoff);
                            break;
                        case '离线一周':
                            counts.push(v.weekoff);
                            break;
                    }
                    isadd = false;
                }
            });
            if (isadd) {
                counts.push(0);
            }
        });
        return counts;
    };
    stats.createKeys_fundDevTop15 = function (data) {
        var keys = [];
        keys.push('金额');//fund
        keys.push('消费次数');//count
        return keys;
    };
    stats.createNames_fundDevTop15 = function (data) {
        var names = [];
        $.each(data, function (i, v) {
            if ($.inArray(v.dev_name, names) < 0) {
                names.push(v.dev_name);
            }
        });
        return names;
    };
    stats.createCounts_fundDevTop15 = function (key, names, data) {
        var counts = [];
        $.each(names, function (i, name) {
            var isadd = true;
            $.each(data, function (j, v) {
                if (v.dev_name == name) {
                    switch (key) {
                        case '金额':
                            counts.push(v.fund);
                            break;
                        case '消费次数':
                            counts.push(v.count);
                            break;
                    }
                    isadd = false;
                }
            });
            if (isadd) {
                counts.push(0);
            }
        });
        return counts;
    };

    stats.createKeys_fundUserTop10 = function (data) {
        var keys = [];
        keys.push('金额');//fund
        keys.push('消费次数');//count
        return keys;
    };
    stats.createNames_fundUserTop10 = function (data) {
        var names = [];
        $.each(data, function (i, v) {
            if ($.inArray(v.nickname, names) < 0) {
                names.push(v.nickname);
            }
        });
        return names;
    };
    stats.createCounts_fundUserTop10 = function (key, names, data) {
        var counts = [];
        $.each(names, function (i, name) {
            var isadd = true;
            $.each(data, function (j, v) {
                if (v.nickname == name) {
                    switch (key) {
                        case '金额':
                            counts.push(v.fund);
                            break;
                        case '消费次数':
                            counts.push(v.count);
                            break;
                    }
                    isadd = false;
                }
            });
            if (isadd) {
                counts.push(0);
            }
        });
        return counts;
    };

    stats.createKeys_userRegTypeWeek = function (data) {
        var keys = [];
        keys.push('APP用户');//app
        keys.push('微信用户');//wexin
        keys.push('支付宝用户');//zhifubao
        return keys;
    };
    stats.createDates_userRegTypeWeek = function (data) {
        var dates = [];

        $.each(data, function (i, v) {
            if ($.inArray(v.weekno, dates) < 0) {
                dates.push(v.weekno);
            }
        });

        return dates;
    };
    stats.createCounts_userRegTypeWeek = function (key, dates, data) {
        var counts = [];
        $.each(dates, function (i, date) {
            var isadd = true;
            $.each(data, function (j, v) {
                if (v.weekno == date) {
                    switch (key) {
                        case 'APP用户':
                            counts.push(v.app);
                            break;
                        case '微信用户':
                            counts.push(v.wexin);
                            break;
                        case '支付宝用户':
                            counts.push(v.zhifubao);
                            break;
                    }
                    isadd = false;
                    return;
                }
            });
            if (isadd) {
                counts.push(0);
            }
        });
        return counts;
    };

    stats.createKeys_devExamItem = function (data) {
        var keys = [];
        keys.push('通过');//pass
        keys.push('未通过');//nopass
        return keys;
    };
    stats.createNames_devExamItem = function (data) {
        var names = [];
        $.each(data, function (i, v) {
            if ($.inArray(v.item, names) < 0) {
                names.push(v.item);
            }
        });
        return names;
    };
    stats.createCounts_devExamItem = function (key, names, data) {
        var counts = [];
        $.each(names, function (i, name) {
            var isadd = true;
            $.each(data, function (j, v) {
                if (v.item == name) {
                    switch (key) {
                        case '通过':
                            counts.push(v.pass);
                            break;
                        case '未通过':
                            counts.push(v.nopass);
                            break;
                    }
                    isadd = false;
                }
            });
            if (isadd) {
                counts.push(0);
            }
        });
        return counts;
    };
    
    stats.createKeys_merchantOfferMonth = function (data) {
        var keys = [];
        keys.push('金额');//fund
        keys.push('消费次数');//count
        return keys;
    };
    stats.createNames_merchantOfferMonth = function (data) {
        var names = [];
        $.each(data, function (i, v) {
            if ($.inArray(v.date, names) < 0) {
                names.push(v.date);
            }
        });
        return names;
    };
    stats.createCounts_merchantOfferMonth = function (key, names, data) {
        var counts = [];
        $.each(names, function (i, name) {
            var isadd = true;
            $.each(data, function (j, v) {
                if (v.date == name) {
                    switch (key) {
                        case '金额':
                            counts.push(v.fund);
                            break;
                        case '消费次数':
                            counts.push(v.count);
                            break;
                    }
                    isadd = false;
                }
            });
            if (isadd) {
                counts.push(0);
            }
        });
        return counts;
    };

    
    stats.createKeys_merchantOfferWeek = function (data) {
    	var keys = [];
    	keys.push('金额');//fund
    	keys.push('消费次数');//count
    	return keys;
    };
    stats.createNames_merchantOfferWeek = function (data) {
    	var names = [];
    	$.each(data, function (i, v) {
    		if ($.inArray(v.weekno, names) < 0) {
    			names.push(v.weekno);
    		}
    	});
    	return names;
    };
    stats.createCounts_merchantOfferWeek = function (key, names, data) {
    	var counts = [];
    	$.each(names, function (i, name) {
    		var isadd = true;
    		$.each(data, function (j, v) {
    			if (v.weekno == name) {
    				switch (key) {
    				case '金额':
    					counts.push(v.fund);
    					break;
    				case '消费次数':
    					counts.push(v.count);
    					break;
    				}
    				isadd = false;
    			}
    		});
    		if (isadd) {
    			counts.push(0);
    		}
    	});
    	return counts;
    };
    
    
    w.$stats = stats;
})(window);