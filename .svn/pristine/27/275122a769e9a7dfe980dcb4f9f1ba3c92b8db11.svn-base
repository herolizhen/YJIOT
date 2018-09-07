

/*

*/
//
(function (w) {
    var notice = {};

    notice.token = '';
    notice.username = '';

    function Initialize() {
        var user = $api.getToken();
        if (!$api.isNull(user)) {
        	notice.token = user.token;
        	notice.username = user.username;
        }
    };
    
    //查询配置规则
    notice.selNoticeConfig = function (data, success, error) {
        Initialize();
        $iot.POST($cfg.URL_SELNOTICECONFIG, notice.token, data, success, error);
    };
    
    //保存配置
    notice.addNoticeConfig = function (data, success, error) {
    	$iot.POST($cfg.URL_ADDNOTICECONFIG, notice.token, data, success, error);
    };
    
    
    //更新配置
    notice.updNoticeConfig = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_UPDNOTICECONFIG, notice.token, data, success, error);
    };
    
    //删除配置
    notice.delNoticeConfig = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_DELNOTICECONFIG, notice.token, data, success, error);
    };
    
    //5.9.2	查看通知规则配置
    notice.selNoticeRule = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_SELNOTICERULE, notice.token, data, success, error);
    };
    
    //5.9.3	添加通知规则配置
    notice.addNoticeRule = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_ADDNOTICERULE, notice.token, data, success, error);
    };
    
    //5.9.4	修改通知规则配置
    notice.updNoticeRule = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_UPDNOTICERULE, notice.token, data, success, error);
    };
    
    //5.9.5	删除通知规则配置
    notice.delNoticeRule = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_DELNOTICERULE, notice.token, data, success, error);
    };
    //5.9.5	删除通知规则配置
    notice.noticeTest = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_NOTICETEST, notice.token, data, success, error);
    };
    
    //查询	推送模板配置
    notice.selNoticePush = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_SELNOTICEPUSH, notice.token, data, success, error);
    };
    
    //5.9.3	推送模板配置全部
    notice.selNoticePushAll = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_SELNOTICEPUSHALL, notice.token, data, success, error);
    };
   
    //推送模板配置新增
    notice.addNoticePush = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_ADDNOTICEPUSH, notice.token, data, success, error);
    };
    //推送模板配置新增
    notice.updNoticePush = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_UPDNOTICEPUSH, notice.token, data, success, error);
    };
    
    //推送模板配置删除
    notice.delNoticePush = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_DELNOTICEPUSH, notice.token, data, success, error);
    };
    
    //	测试推送模板配置
    notice.pushTest = function (data, success, error) {
    	Initialize();
    	$iot.POST($cfg.URL_PUSHTEST, notice.token, data, success, error);
    };
    
    
    
    
    w.$notice = notice;
})(window);