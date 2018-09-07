(function (w) {
    var main = {};
    var alerttag = false;
    var isoepnmenu = true;

    const funcFrameID = 'func-frame';
    var menus = [
	             {

	                 key: '82933fa2-a11d-4a1a-9fdb-be96305cf4c8',
	                 isopen: false,
	                 id: 'AuthorityManagement',
	                 name: '权限管理',
	                 func: 'func-AuthorityManagement',
	                 funcs: [
	            	        {
	            	            key: '30828dbd-8139-4814-be61-e0c2a6ddb547',
	            	            isopen: false,
	            	            name: '用户管理',
	            	            url: '../views/power/userInfo.html'
	            	        },
	            	        {
	            	            key: '23ffa15f-090e-4083-952a-d9b343f20039',
	            	            isopen: false,
	            	            name: '角色管理',
	            	            url: '../views/power/roleInfo.html'
	            	        },
	            	        {
	            	            key: '12ec6252-a888-400e-b0d9-6a6e78dcf166',
	            	            isopen: false,
	            	            name: '资源管理',
	            	            url: '../views/power/ResourceInfo.html'
	            	        },
	            	        {
	            	            key: '97a6132b-efe3-40de-b18e-d68f8e671605',
	            	            isopen: false,
	            	            name: '应用管理',
	            	            url: '../views/power/AppInfo.html'
	            	        },
	            	        {
	            	            key: '9a1b95db-ec70-40cf-b14d-7f6a5feaa5ca',
	            	            isopen: false,
	            	            name: '产品管理',
	            	            url: '../views/power/ProductInfo.html'
	            	        }
	                 ]
	             },
	             {
	                 key: 'a7a0c7d6-7878-4748-9d1d-ddd8e517ba89',
	                 isopen: false,
	                 id: 'ProductionManagement',
	                 name: '生产管理',
	                 func: 'func-ProductionManagement',
	                 funcs: [
	                         {
		            	            key: 'd1838cd5-18f1-4e8d-87d2-da8e2712b1bb',
		            	            isopen: true,
		            	            name: '物流管理',
		            	            url: '../views/device/deviceInfo.html'
		            	        }
	                 ]
	             },
	             {
	                 key: 'af0d61d9-755a-488e-9c87-669bb9a984dd',
	                 isopen: false,
	                 id: 'MochaITOM',
	                 name: '运维管理',
	                 func: 'func-MochaITOM',
	                 funcs: [
                         {
                             key: 'df1cb26e-651d-4893-84ca-85878d05a477',
                             isopen: false,
                             name: '设备信息',
                             url: '../views/operation/device.html'
                         },
                         {
                             key: '3bc169ff-9984-4f08-a21e-f1959d5384d6',
                             isopen: false,
                             name: '商户信息',
                             url: '../views/operation/merchant.html'
                         }
	                 ]
	             },
	             {
	                 key: '77a440da-0482-4cbc-b36b-ee185a1cd3de',
	                 isopen: false,
	                 id: 'OperationManagement',
	                 name: '运营管理',
	                 func: 'func-OperationManagement',
	                 funcs: [
	            	         {
	            	             key: 'd05cf8e1-8c95-4e99-91ab-5fe411cb68cd',
	            	             isopen: false,
	            	             name: '总体分析',
	            	             url: '../views/stata/macro-analysis.html'
	            	         },
	            	         {
	            	             key: '997b7708-f7ed-4947-83fa-20d1f058c7ac',
	            	             isopen: false,
	            	             name: '消费明细报表',
	            	             url: '../views/stata/consumeDetail.html'
	            	         },
	            	         {
	            	             key: 'f8b24c94-84d4-4360-a06f-c75b5cc4abb0',
	            	             isopen: false,
	            	             name: '商户收入报表',
	            	             url: '../views/stata/consumeMerchant.html'
	            	         },
	            	         {
	            	             key: 'b5b311c6-a41c-49c1-b56e-6ac41b318d0f',
	            	             isopen: false,
	            	             name: '商户台账',
	            	             url: '../views/stata/merchantAccountQuery.html'
	            	         },
	            	         {
	            	             key: 'f998d539-af92-460e-a319-679f716ebb3c',
	            	             isopen: false,
	            	             name: '设备台账',
	            	             url: '../views/stata/deviceAccountQuery.html'
	            	         },
	            	         {
	            	        	 key: '2a2e4251-2fe2-4153-8fdf-07977a79f830',
	            	        	 isopen: false,
	            	        	 name: '问题反馈',
	            	        	 url: '../views/stata/qnrQueryInfo.html'
	            	         }
	                 ]
	             },
	             {
	            	 key: 'baa048f2-6157-4367-8000-c3aba9b9afde',
	            	 isopen: false,
	            	 id: 'SystemConfiguration',
	            	 name: '字典管理',
	            	 func: 'func-SystemConfiguration',
	            	 funcs: [
	            	         {
	            	        	 key: '2dfec22e-cdac-4d36-a3d0-8a2c6aa29a33',
	            	        	 isopen: false,
	            	        	 name: '缴费定义',
	            	        	 url: '../views/dictionary/charge.html'
	            	         },
	            	         {
	            	             key: '3a5f9d40-a86a-4b36-92d0-f9a86770c414',
	            	             isopen: false,
	            	             name: '商户维护',
	            	             url: '../views/dictionary/Merchant.html'
	            	         }
	            	         ]
	             }
    ];
    main.menus = menus;
    var user;
    var APPID = '';
    function initToken() {
        user = $api.getToken();
        APPID = $api.getCurrApp();
    }
    function ceateUserMenu(callback) {
        clearMenus();
        initToken();
        var data = {};
        data.userName = user.username;
        data.appId = APPID;
        $pow.getToken(data, function (ret) {
            $api.saveToken(user.username, ret.token);
            //获取用户已有资源
            var data = {};
            data.username = user.username;
            $pow.selUserResource(data, function (ret) {
                $.each(ret.resourceList, function (r, res) {
                    $.each(menus, function (i, m) {
                        if (m.key == res.resId) {
                            m.isopen = true;
                        }
                        $.each(m.funcs, function (j, f) {
                            if (f.key == res.resId) {
                                f.isopen = true;
                            }
                        });
                    });
                });
                initMenu();
                initFunc();
                if (!$api.isNull(callback)) {
                    callback();
                }
            }, function () {
                main.openAlert('提示', '用户状态有误 ，请联系管理员核实后再次登陆!', function () {
                    window.location.href = 'index.html';
                });
            });
        }, function () {
            main.openAlert('提示', '登陆超时 ，请重新登陆!', function () {
                window.location.href = 'index.html';
            });
        });
    }
    function clearMenus() {
        $.each(menus, function (i, m) {
            m.isopen = false;
            $('#' + m.func).hide();
            $('#' + m.id).removeClass('disabled');
            $.each(m.funcs, function (j, f) {
                f.isopen = false;
            });
        });
    }
    function initMenu() {
        $('#func-frame').prop('src', '');
        $.each(menus, function (i, m) {
            if (!m.isopen) {
                $('#' + m.id).addClass('disabled');
            } else {
                $('#' + m.id).addClass('fount');
            }
        });
    }
    function initFunc() {
        $('#func-menu').metisMenu();
        //$.each(menus, function (i, m) {
        //    if (!m.isopen) {
        //        $('#' + m.func).remove();
        //    } else {
        //        $('#' + m.func).hide();
        //    }
        //});
    }

    function getFunc(menu, key) {
        var f;
        $.each(menu.funcs, function (i, n) {
            if (n.key == key) {
                f = n;
                return;
            }
        });
        return f;
    }
    function getMenu(key) {
        var menu;
        $.each(menus, function (i, m) {
            $.each(m.funcs, function (j, n) {
                if (n.key == key) {
                    menu = m;
                    return;
                }
            });
            if (!$api.isNull(menu)) {
                return;
            }
        });
        return menu;
    }
    function setParameter(key) {
        var data = {};
        data.appId = 'c5fbe3aa-b3a4-11e7-9baf00163e120d98';
        $api.setParameter(data);
    }
    function onMacroAnalysis() {
        $('#frame-right').removeClass('col-md-10').addClass('col-md-12');
        var key = 'd05cf8e1-8c95-4e99-91ab-5fe411cb68cd';
        var menu = getMenu(key);
        if ($api.isNull(menu)) { return; }
        var f = getFunc(menu, key);
        if ($api.isNull(f)) { return; }
        if (f.isopen) {
            $('#' + menu.func + ' li').removeClass('active');
            //	$(li).addClass('active');
            var url = f.url;
            url = url + '?v=' + $api.getUUID(16);
            setParameter(key);
            $('#func-frame').prop('src', url);
        }
    }
    main.Initialize = function (callback) {
        ceateUserMenu(function () {
            var tmp = $('#content-frame-navbar').height();
            var h = window.innerHeight - tmp - 15;
            $('#' + funcFrameID).height(h);
            $('.frame-func-menu').css('height', h + 'px');
            main.closeNavbarFunc();
            if (!$api.isNull(callback)) {
                callback();
            }
        });
    };
    main.onFunc = function (li) {
        var key = $(li).attr('data-key');
        var menu = getMenu(key);
        if ($api.isNull(menu)) { return; }
        var f = getFunc(menu, key);
        if ($api.isNull(f)) { return; }
        if (f.isopen) {
            $('#' + menu.func + ' li').removeClass('active');
            $(li).addClass('active');
            var url = f.url;
            url = url + '?v=' + $api.getUUID(16);
            setParameter(key);
            $('#func-frame').prop('src', url);
        }
    };
    main.onMenu = function (li) {
        var id = $(li).prop('id');
        var menu;
        $.each(menus, function (i, m) {
            if (m.isopen && m.id == id) {
                menu = m;
            }
        });
        if (!$api.isNull(menu)) {
            if (!isoepnmenu) {
                var bar = w.document.getElementById('navbar-ctrl-menu');
                main.ctrlMenu(bar);
            }
        }
        if (!$api.isNull(menu)) {

            $('#func-menu').children('div').hide();
            $('#' + menu.func).show();
            $('#content-menu').children('li').removeClass('active');
            $(li).addClass('active');
        }
        if (!$api.isNull(menu)) {
            $('#' + menu.func + ' ul ul li').each(function () {
                var obj = this;
                var key = $(obj).attr('data-key');
                var f = getFunc(menu, key);
                if (!$api.isNull(f)) {
                    if (f.isopen) {

                    } else {
                        $(obj).children('a').addClass('disabled');
                    }
                }
            });
        }
    };
    main.ctrlMenu = function (bar) {
        if (isoepnmenu) {
            $('#frame-left').hide();
            $('#frame-right').removeClass('col-md-10').addClass('col-md-12');
            isoepnmenu = false;
        } else {
            $('.frame-func-menu').show();
            $('#frame-right').removeClass('col-md-12').addClass('col-md-10');
            isoepnmenu = true;
        }
        if (isoepnmenu) {
            $(bar).children('span').removeClass('fa-bars').addClass('fa-outdent');
        } else {
            $(bar).children('span').removeClass('fa-outdent').addClass('fa-bars');
        }
    };
    main.closeNavbarFunc = function () {
        if (isoepnmenu) {
            var bar = w.document.getElementById('navbar-ctrl-menu');
            main.ctrlMenu(bar);
        }
    }
    main.openLoading = function (title, text) {
        $('#loading-modal-title').text(title);
        $('#loading-modal-body').text(text);
        $('#input-loading').modal({
            backdrop: 'static',
            keyboard: false
        });
    };
    main.closeLoading = function () {
        $('#input-loading').modal('hide');
    };
    main.openAlert = function (title, text, callback) {
        $('#alert-dialog').modal('hide');
        $('#alert-dialog-modal-title').text(title);
        $('#alert-dialog-modal-body').text(text);
        if ($api.isNull(callback)) {
            $('#modal-dialog-close').hide();
        } else {
            $('#modal-dialog-close').show();
            $('#alert-dialog').on('hidden.bs.modal', function (e) {
                callback(alerttag);
                $('#alert-dialog').unbind('hidden.bs.modal');
            });
        }

        $('#alert-dialog').modal('show');
    };
    main.closeAlert = function (tag) {
        alerttag = tag;
        $('#alert-dialog').modal('hide');
    };

    w.ui_main = main;

})(window);