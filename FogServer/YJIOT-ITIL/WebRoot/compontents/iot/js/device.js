(function (w) {
    var dev = {};

    dev.token = '';
    function Initialize() {
        var user = $api.getToken();
        if (!$api.isNull(user)) {
            dev.token = user.token;
        }
    };
    
    //通过设备ID获取设备信息
    dev.getDevInfoById = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_GETDEVINFOBYID, dev.token, data, success, error);
    };
  
    //通过设备MAC获取设备信息
    dev.getDevInfoByMac = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_GETDEVINFOBYMAC, dev.token, data, success, error);
    };
    
    //通过订单号获取设备信息。
    dev.getDevInfoByOrderNo = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_GETDEVINFOBYORDERNO, dev.token, data, success, error);
    };
    
    //通过设备ID获取设备台账信息
    dev.getDevAccount = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_GETDEVACCOUNT, dev.token, data, success, error);
    };
    
    
    //根据设备GIS坐标获取设备台账信息
    dev.selectByGisRect = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.DEVSELECTBYGISRECT, dev.token, data, success, error);
    };
    
    //获取设备的缴费信息，以及该用户针对该设备最近10笔缴费记录
    dev.getChargeInfo = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.GETCHARGEINFO, dev.token, data, success, error);
    };
    
    //5.3.7	实时数据统计-天
    dev.getLastDayHourStats = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.GETLASTDAYHOURSTATS, dev.token, data, success, error);
    };

    //5.3.8	实时数据统计-周
    dev.getLastWeekDayStats = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.GETLASTWEEKDAYSTATS, dev.token, data, success, error);
    };
  
    //5.3.9	实时数据统计-月
    dev.getLastMonthDayStats = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.GETLASTMONTHDAYSTATS, dev.token, data, success, error);
    };
   
    //5.3.10	实时数据统计-年
    dev.getLastYearMonthStats = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.GETLASTYEARMONTHSTATS, dev.token, data, success, error);
    };
   
    //5.3.11	移动端向设备端发送控制指令
    dev.sendCommand = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.SENDCOMMAND, dev.token, data, success, error);
    };
    
    //更新设备调账信息
    dev.updateDevAccount = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.UPDATEDEVACCOUNT, dev.token, data, success, error);
    };
    
    //更新设备区域信息
    dev.updateDevAccountReg = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.UPDATEDEVACCOUNTREG, dev.token, data, success, error);
    };
    
    //根据设备ID获取设备最近20条消费信息
    dev.getDevConsume = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_GETDEVCONSUME, dev.token, data, success, error);
    };
    
    
    //根据设备ID获取设备最近20条消费信息
    dev.delDevAccount = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_DELDEVACCOUNT, dev.token, data, success, error);
    };
    
    
    
    /**
     * 物流管理
     */
    
    dev.addLogisticeInfo = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.ADDLOGISTICE, dev.token, data, success, error);
    };
   
    dev.selLogisticeInfoByMac = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.SELLOGISTICE, dev.token, data, success, error);
    };
  
    dev.updLogisticeInfo = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.UPDLOGISTICE, dev.token, data, success, error);
    };
    
    w.$dev = dev;
})(window);