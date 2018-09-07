/*
全局配置文件
 */
var browser = {
		versions: function () {
			var u = navigator.userAgent;
			return {     //移动终端浏览器版本信息
				trident: u.indexOf('Trident') > -1, //IE内核
				presto: u.indexOf('Presto') > -1, //opera内核
				webKit: u.indexOf('AppleWebKit') > -1, //苹果、谷歌内核
				gecko: u.indexOf('Gecko') > -1 && u.indexOf('KHTML') == -1, //火狐内核
				mobile: !!u.match(/AppleWebKit.*Mobile.*/), //是否为移动终端
				ios: !!u.match(/\(i[^;]+;( U;)? CPU.+Mac OS X/), //ios终端
				android: u.indexOf('Android') > -1 || u.indexOf('Linux') > -1, //android终端或uc浏览器
				iPhone: u.indexOf('iPhone') > -1, //是否为iPhone或者QQHD浏览器
				iPad: u.indexOf('iPad') > -1, //是否iPad
				webApp: u.indexOf('Safari') == -1 //是否web应该程序，没有头部与底部
			};
		}()
};
(function (w) {
	var cfg = {};
	const HOST = '127.0.0.1';
	cfg.MQTTHOST = 'io.bjyjyz.com';
	//cfg.MQTTHOST = 'www.yjiot.net';
	cfg.MQTTPORT =443;
	cfg.MQTTPATH ='/mqtt';
	

    
	
	//系统颜色
	var colorindex = 0;
	cfg.color = [
	             'rgb(255,160,122)',
	             'rgb(32,178,170)',
	             'rgb(135,206,250)',
	             'rgb(119,136,153)',
	             'rgb(123,104,238)',
	             'rgb(0,0,128)',
	             'rgb(128,0,0)',
	             'rgb(0,0,205)',
	             'rgb(186,85,211)',
	             'rgb(0,250,154)',
	             'rgb(255,255,224)',
	             'rgb(255,222,173)',
	             'rgb(255,0,255)',
	             'rgb(107,142,45)',
	             'rgb(128,128,0)',
	             'rgb(255,69,0)',
	             'rgb(218,112,214)',
	             'rgb(238,232,170)',
	             'rgb(152,251,152)',
	             'rgb(128,0,128)',
	             'rgb(255,0,0)',
	             'rgb(65,105,225)',
	             'rgb(255,255,0)',
	             'rgb(154,205,50)',
	             'rgb(0, 0, 238)',
	             'rgb(0, 255, 187)',
	             'rgb(255, 0, 187)',
	             'rgb(255, 255, 0)',
	             'rgb(255, 0, 51)',
	             'rgb(187, 85, 221)',
	             'rgb(187, 0, 119)',
	             'rgb(187, 255, 238)',
	             'rgb(102, 0, 119)',
	             'rgb(102, 187, 85)',
	             'rgb(187, 0, 102)',
	             'rgb(238, 0, 119)',

	             ];
	cfg.createColor = function (index) {
		if (!$api.isNull(index)) {
			colorindex = index;
		}
		colorindex = colorindex > cfg.color.length ? 0 : colorindex;
		return cfg.color[colorindex];
	};

	/*
	 *全局信息
	 */
	cfg.isMobile = browser.versions.mobile;
	cfg.host = HOST;

	cfg.URL_GETUNCOSUMEBILL ='http://' + HOST + '/YJIOT/client/getUnCosumeBill';
	
	
	//MQTT  下发指令
	cfg.URL_SENDCOMMAND='http://' + HOST + '/YJIOT/client/sendCommand';
	
	//确认缴费
	cfg.URL_CONSONSUME = 'http://' + HOST + '/YJIOT/client/consume';
	
	/**	
	 * 5.1.	权限管理
	 * */
	//	5.1.2	用户登录
	cfg.URL_LOGIN = 'http://' + HOST + '/YJIOT/power/login';
	//	5.1.3	获取验证码
	cfg.URL_GETTOKEN = 'http://' + HOST + '/YJIOT/power/getToken';

	/**	
	 * 5.1.4	用户管理（JWT）
	 * */
	//	5.1.4.1	用户增加
	cfg.URL_ADDSYSUSER = 'http://' + HOST + '/YJIOT/power/addSysUser';
	//	5.1.4.2	用户修改
	cfg.URL_UPDSYSUSER = 'http://' + HOST + '/YJIOT/power/updSysUser';
	//	5.1.4.3	用户删除
	cfg.URL_DELSYSUSER = 'http://' + HOST + '/YJIOT/power/delSysUser';
	//  5.1.4.4	用户查询1 	根据用户名查询用户信息
	cfg.URL_SELSYSUSER = 'http://' + HOST + '/YJIOT/power/selSysUser';
	//	5.1.4.5	用户查询2	查询  查询一个app下的所有用户
	cfg.URL_SELSYSUSERBYAPP = 'http://' + HOST + '/YJIOT/power/selSysUserByApp';

	/**	
	 * 
	 * 5.1.5	应用管理
	 * */
	//	5.1.5.1	应用增加
	cfg.URL_ADDAPP = 'http://' + HOST + '/YJIOT/power/addApp';
	//	5.1.5.2	应用修改
	cfg.URL_UPDAPP = 'http://' + HOST + '/YJIOT/power/updApp';
	//	5.1.5.3	应用删除	
	cfg.URL_DELAPP = 'http://' + HOST + '/YJIOT/power/delApp';
	//	5.1.5.4	应用查询1	根据应用ID获取应用信息
	cfg.URL_SELAPP = 'http://' + HOST + '/YJIOT/power/selApp';
	//	5.1.5.5	应用查询2	查询所有应用
	cfg.URL_SELAPPALL = 'http://' + HOST + '/YJIOT/power/selAppAll';

	/**
	 * 5.1.6	角色管理（JWT）
	 * */
	//	5.1.6.1	角色增加角色增加
	cfg.URL_ADDROLE = 'http://' + HOST + '/YJIOT/power/addRole';
	//	5.1.6.2	角色修改
	cfg.URL_UPDROLE = 'http://' + HOST + '/YJIOT/power/updRole';
	//	5.1.6.3	角色删除	
	cfg.URL_DELROLE = 'http://' + HOST + '/YJIOT/power/delRole';
	//	5.1.6.4	角色查询1	根据应用ID获取角色信息
	cfg.URL_SELROLE = 'http://' + HOST + '/YJIOT/power/selRole';
	//	5.1.6.5	角色查询2	查询应用下所有的角色
	cfg.URL_SELROLEBYAPP = 'http://' + HOST + '/YJIOT/power/selRoleByApp';


	/**
	 * 5.1.7	资源管理（JWT）
	 * */
	//	5.1.7.1	资源增加
	cfg.URL_ADDRES = 'http://' + HOST + '/YJIOT/power/addResource';
	//	5.1.7.2	资源修改
	cfg.URL_UPDRES = 'http://' + HOST + '/YJIOT/power/updResource';
	//	5.1.7.3	资源删除
	cfg.URL_DELRES = 'http://' + HOST + '/YJIOT/power/delResource';
	//	5.1.7.4	资源查询1	根据资源id查询资源
	cfg.URL_SELRES = 'http://' + HOST + '/YJIOT/power/selResource';
	//	1.1.1.1	资源查询2	查询应用下所有的资源
	cfg.URL_SELRESBYAP = 'http://' + HOST + '/YJIOT/power/selResourceByApp';

	/**
	 * 	5.1.8	授权管理（JWT）
	 * */
	//		5.1.8.1	角色资源增加
	cfg.URL_ADDROLERES = 'http://' + HOST + '/YJIOT/power/addRoleResource';
	//		5.1.8.2	角色资源删除
	cfg.URL_DELROLERES = 'http://' + HOST + '/YJIOT/power/delRoleResource';
	//		5.1.8.3	角色资源查询
	cfg.URL_SELROLERES = 'http://' + HOST + '/YJIOT/power/selRoleResource';
	//		5.1.8.4	资源角色查询
	cfg.URL_SELRESROLE = 'http://' + HOST + '/YJIOT/power/selResourceRole';
	//		5.1.8.5	用户角色增加
	cfg.URL_ADDUSERROLE = 'http://' + HOST + '/YJIOT/power/addUserRole';
	//		5.1.8.6	用户角色删除
	cfg.URL_DELUSERROLE = 'http://' + HOST + '/YJIOT/power/delUserRole';
	//		5.1.8.7	查询用户角色
	cfg.URL_SELUSERROLE = 'http://' + HOST + '/YJIOT/power/selUserRole';
	//		5.1.8.8	查询角色用户
	cfg.URL_SELROLEUSER = 'http://' + HOST + '/YJIOT/power/selRoleUser';
	//		5.1.8.9	查询用户资源
	cfg.URL_SELUSERRES = 'http://' + HOST + '/YJIOT/power/selUserResource';
	//		5.1.8.10查询资源用户		根据资源ID查询拥有该资源的所有用户
	cfg.URL_SELRESUSER = 'http://' + HOST + '/YJIOT/power/selResourceUser';


	/**
	 * 5.2	产品管理（JWT）
	 */
	//5.2.1	问卷调查（JWT）
	cfg.URL_SAVEPROQNR = 'http://' + HOST + '/YJIOT/product/saveProdQnr';
	//5.2.2	产品定义(JWT)
	cfg.URL_SAVEPRODINFO = 'http://' + HOST + '/YJIOT/product/saveProdInfo';
	//5.2.3	产品查询（JWT）
	cfg.URL_SELPRODbYAPP = 'http://' + HOST + '/YJIOT/product/selProdByApp';

	/** 
	 * 5.3	设备操作（JWT）
	 * */
	//5.3.1	获取设备信息1	通过设备ID获取设备信息
	cfg.URL_GETDEVINFOBYID = 'http://' + HOST + '/YJIOT/device/getDevInfoById';
	//5.3.2	获取设备信息2	通过设备MAC获取设备信息
	cfg.URL_GETDEVINFOBYMAC= 'http://' + HOST + '/YJIOT/device/getDevInfoByMac';
	//5.3.3	获取设备信息3	通过订单号获取设备信息。
	cfg.URL_GETDEVINFOBYORDERNO= 'http://' + HOST + '/YJIOT/device/getDevInfoByOrderNo';
	//5.3.4	获取设备台账信息1	通过设备ID获取设备台账信息
	cfg.URL_GETDEVACCOUNT= 'http://' + HOST + '/YJIOT/device/getDevAccount';
	//5.3.5 根据设备GIS坐标获取设备台账信息
	cfg.DEVSELECTBYGISRECT = 'http://' + HOST + '/YJIOT/device/selectByGisRect';
	//5.3.6	获取设备的收费标准	获取设备的缴费信息，以及该用户针对该设备最近10笔缴费记录
	cfg.GETCHARGEINFO = 'http://' + HOST + '/YJIOT/client/getChargeInfo';
	//5.3.7	实时数据统计-天
	cfg.GETLASTDAYHOURSTATS = 'http://' + HOST + '/YJIOT/device/getLastDayHourStats';
	// 5.3.8	实时数据统计-周
	cfg.GETLASTWEEKDAYSTATS = 'http://' + HOST + '/YJIOT/device/getLastWeekDayStats';
	//5.3.9	实时数据统计-月
	cfg.GETLASTMONTHDAYSTATS = 'http://' + HOST + '/YJIOT/device/getLastMonthDayStats';
	//5.3.10	实时数据统计-年
	cfg.GETLASTYEARMONTHSTATS = 'http://' + HOST + '/YJIOT/device/getLastYearMonthStats';
	// 5.3.11	发送指令		移动端向设备端发送控制指令。
	cfg.SENDCOMMAND = 'http://' + HOST + '/YJIOT/device/sendCommand';
	// 5.3.12	设备台账维护1	更新设备调账信息
	cfg.UPDATEDEVACCOUNT = 'http://' + HOST + '/YJIOT/device/updateDevAccount';
	// 5.3.13	设备台账维护2	更新设备区域信息
	cfg.UPDATEDEVACCOUNTREG = 'http://' + HOST + '/YJIOT/device/updateDevAccountReg';
	
	//5.3.15根据设备ID获取设备最近20条消费信息
	cfg.URL_GETDEVCONSUME = 'http://' + HOST + '/YJIOT/device/getDevConsume';
	


	/**	
	 * 5.4	OTA文件管理（JWT）
	 * */
	//	5.4.1	获取OTA信息列表
	cfg.URL_SELECTBYPRIDUCEID = 'http://' + HOST + '/YJIOT/otaFile/selectByProduceId';
	//5.4.2	获取OTA信息	根据ID获取OTA信息
	cfg.URL_SELECT = 'http://' + HOST + '/YJIOT/otaFile/select';
	//5.4.3	增加OTA文件
	cfg.URL_INSERT = 'http://' + HOST + '/YJIOT/otaFile/insert';
	//5.4.4	更新OTA信息
	cfg.URL_UPDATE = 'http://' + HOST + '/YJIOT/otaFile/update';
	//5.4.5	删除OTA信息	
	cfg.URL_DELETE = 'http://' + HOST + '/YJIOT/otaFile/delete';

	/**	
	 *5.5	字典管理（JWT）       
	 * */
	//5.5.1	增加收费
	cfg.ADDCHARGE = 'http://' + HOST + '/YJIOT/dict/addCharge';
	//5.5.2	修改收费
	cfg.UPDCHARGE = 'http://' + HOST + '/YJIOT/dict/updCharge';
	//5.5.3	删除收费
	cfg.DELCHARGE = 'http://' + HOST + '/YJIOT/dict/delCharge';
	//5.5.4 根据收费类型获取收费条目
	cfg.SELCHARGEBYTYPE = 'http://' + HOST + '/YJIOT/dict/selChargeByType';
	//5.5.5 获取全部收费记录
	cfg.SELCHARGEALL = 'http://' + HOST + '/YJIOT/dict/selChargeAll';
	//5.5.6	增加商户
	cfg.ADDMERCHANT = 'http://' + HOST + '/YJIOT/dict/addMerchant';
	//5.5.7	修改商户
	cfg.UPDMERCHANT = 'http://' + HOST + '/YJIOT/dict/updMerchant';
	//5.5.8	删除商户
	cfg.DELMERCHANT = 'http://' + HOST + '/YJIOT/dict/delMerchant';
	//5.5.9 模糊查询，根据商户名称查询商户信息。
	cfg.SELMERCHANTBYNAME = 'http://' + HOST + '/YJIOT/dict/selMerchantByName';
	//5.5.10 查询所有商户信息
	cfg.SELMERCHARTALL = 'http://' + HOST + '/YJIOT/dict/selMerchantAll';
	//5.5.11	查询商户（GIS）
	cfg.MATSELECTBYGISRECT = 'http://' + HOST + '/YJIOT/dict/selMerchantByGisRect';



	/**
	 * 5.6	统计管理（JWT）
	 */
	//	5.6.1	设备生命周期状态状态
	cfg.URL_DEVSTATETYPE = 'http://' + HOST + '/YJIOT/stats/devStateType';
	//	5.6.2	用户注册情况
	cfg.URL_USERREGMONTH = 'http://' + HOST + '/YJIOT/stats/userRegMonth';
	//	5.6.3	资金回流情况
	cfg.URL_FUNDMONTH = 'http://' + HOST + '/YJIOT/stats/fundMonth';
	//	5.6.4	资金周回流情况
	cfg.URL_FUNDMERCHANDAY = 'http://' + HOST + '/YJIOT/stats/fundMerChantDay';
	//	5.6.5	周资金回流情况
	cfg.URL_FUNdMERCHANWEEK = 'http://' + HOST + '/YJIOT/stats/fundMerChantWeek';
	// 5.6.6	周缴费频次情况	统计一周每天，各个收费标准的收费次数
	cfg.URL_FUNDTIMESDAY = 'http://' + HOST + '/YJIOT/stats/fundTimesDay';
	//	5.6.7	周缴费频次情况	统计三个月每周，各个收费标准的收费次数
	cfg.URL_FUNDTIMESWEEK = 'http://' + HOST + '/YJIOT/stats/fundTimesWeek';
	//5.6.8	运营人员设备情况		统计每个运营人员所管理的设备数量
	cfg.URL_DEVSELLER = 'http://' + HOST + '/YJIOT/stats/devSeller';
	//5.6.9	运营资金回流情况		统计最近三个月运营人员每周的资金回流情况
	cfg.URL_DEVSELLERWEEK = 'http://' + HOST + '/YJIOT/stats/fundSellerWeek';
	//5.6.10	设备部署情况统计	统计各个商户设备的个状态数量
	cfg.URL_DEVONLINE = 'http://' + HOST + '/YJIOT/stats/devOnlineState';
	//5.6.11	最大出力前15台机器	统计消费最多的15台机器的消费金额及使用次数
	cfg.URL_FUNDDEVTOP15 = 'http://' + HOST + '/YJIOT/stats/fundDevTop15';
	//5.6.12	最大处理前10名消费用户	最大出力前10名消费用户
	cfg.URL_FUNDUSERTOP10 = 'http://' + HOST + '/YJIOT/stats/fundUserTop10';
	//5.6.13	设备出厂质检情况
	cfg.DEVEXAMMAIN = 'http://' + HOST + '/YJIOT/stats/devExamMain';
	//5.6.14	设备检测项目情况设备检测项目情况
	cfg.DEVEXAITEM = 'http://' + HOST + '/YJIOT/stats/devExamItem';
	//周用户增加情况
	cfg.USERREGTYPEWEE = 'http://' + HOST + '/YJIOT/stats/userRegTypeWeek';

	/**
	 * 5.8	报表管理（JWT）
	 */
	// 5.8.1	消费明细报表
	cfg.URL_CONSUMEDETAIL = 'http://' + HOST + '/YJIOT/query/consumeDetailQuery';
	// 5.8.2	商户收入报表
	cfg.URL_CONSUMEMERCHART = 'http://' + HOST + '/YJIOT/query/consumeMerchantQuery';
	// 5.8.3	查询设备台账
	cfg.URL_DEVICEACCOUNT = 'http://' + HOST + '/YJIOT/query/deviceAccountQuery';
	// 5.8.4	查询商户台账
	cfg.URL_MERCHANTACCOUNT = 'http://' + HOST + '/YJIOT/query/merchantAccountQuery';
	//5.8.5	设备贡献月统计
	cfg.URL_DEVICEOFFERMONT = 'http://' + HOST + '/YJIOT/query/deviceOfferMonthQuery';
	//5.8.6	设备贡献周统计
	cfg.URL_DEVICEOFFERWEEK = 'http://' + HOST + '/YJIOT/query/deviceOfferWeekQuery';
	//5.8.7	商户贡献月统计
	cfg.URL_MERCHANTOFFERMONTH = 'http://' + HOST + '/YJIOT/query/merchantOfferMonthQuery';
	//5.8.8	商户贡献周统计
	cfg.URL_MERCHANTOFFERWEEK = 'http://' + HOST + '/YJIOT/query/merchantOfferWeekQuery';
	//	5.8.9	用户反馈查询
	cfg.URL_QURQUERY= 'http://' + HOST + '/YJIOT/query/qnrQuery';


	/**
	 * 5.9	通知管理（JWT）
	 */
	cfg.URL_SELNOTICECONFIG ='http://' + HOST + '/YJIOT/notice/selNoticeConfig';
	cfg.URL_ADDNOTICECONFIG ='http://' + HOST + '/YJIOT/notice/addNoticeConfig';
	cfg.URL_UPDNOTICECONFIG ='http://' + HOST + '/YJIOT/notice/updNoticeConfig';
	cfg.URL_DELNOTICECONFIG ='http://' + HOST + '/YJIOT/notice/delNoticeConfig';
	cfg.URL_SELNOTICERULE ='http://' + HOST + '/YJIOT/notice/selNoticeRule';
	cfg.URL_ADDNOTICERULE ='http://' + HOST + '/YJIOT/notice/addNoticeRule';
	cfg.URL_UPDNOTICERULE ='http://' + HOST + '/YJIOT/notice/updNoticeRule';
	cfg.URL_DELNOTICERULE ='http://' + HOST + '/YJIOT/notice/delNoticeRule';
	cfg.URL_NOTICETEST ='http://' + HOST + '/YJIOT/notice/noticeTest';
	
	//	推送模板配置
	cfg.URL_SELNOTICEPUSH ='http://' + HOST + '/YJIOT/notice/selNoticePush';
	cfg.URL_SELNOTICEPUSHALL ='http://' + HOST + '/YJIOT/notice/selNoticePushAll';
	cfg.URL_DELNOTICEPUSH ='http://' + HOST + '/YJIOT/notice/delNoticePush';
	cfg.URL_ADDNOTICEPUSH ='http://' + HOST + '/YJIOT/notice/addNoticePush';
	cfg.URL_UPDNOTICEPUSH ='http://' + HOST + '/YJIOT/notice/updNoticePush';
	cfg.URL_PUSHTEST ='http://' + HOST + '/YJIOT/notice/pushTest';
	
	

	/**
	 * 6	物流管理（JWT）
	 */
	//6.2	增加		增加设备物流信息
	cfg.ADDLOGISTICE = 'http://' + HOST + '/YJIOT/device/addLogisticeInfo';
	//6.3	查询物流信息		根据设备ID查询设备的全部物流信息
	cfg.SELLOGISTICE = 'http://' + HOST + '/YJIOT/device/selLogisticeInfoByMac';
	//6.4	修改物流信息	根据物流ID号修改设备物流信息
	cfg.UPDLOGISTICE = 'http://' + HOST + '/YJIOT/device/updLogisticeInfo';
	
	
	
	/**
	 * 设备台账 	用户项（JWT）
	 */
	//4.12	获取设备用户（JWT）
	cfg.URL_GETDEVUSER ='http://' + HOST + '/YJIOT/clientPower/getDevUser';
	
	//获取用户令牌
	cfg.URL_CLIENTPOSERGETTOKEN ='http://' + HOST + '/YJIOT/clientPower/getToken';
	
	//获取设备令牌
	cfg.URL_GETDECVTOKEN ='http://' + HOST + '/YJIOT/clientPower/getDevToken';
	
	//设备绑定
	cfg.URL_BINDDEVICE ='http://' + HOST + '/YJIOT/clientPower/bindUser';
	
	//用户解绑
	cfg.URL_UNBINDDEVICE ='http://' + HOST + '/YJIOT/clientPower/unBindDevice';
	
	
	/**
	 * 设备台账 	设备维护项（JWT）
	 */
	
	cfg.URL_DELDEVACCOUNT ='http://' + HOST + '/YJIOT/device/delDevAccount';
	
	
										
	


	w.$cfg = cfg;
})(window);