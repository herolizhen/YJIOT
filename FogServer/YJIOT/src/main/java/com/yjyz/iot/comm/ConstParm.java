package com.yjyz.iot.comm;

public class ConstParm {

	public static final int SUCESS_CODE = 0;

	public static final int ERR_INSERT = 100;
	public static final int ERR_DELETE = 101;
	public static final int ERR_UPDATE = 102;
	public static final int ERR_SAVE = 103;
	public static final int ERR_SELECT = 104;

	public static final int ERR_NO_CLIENT = 200;
	public static final int ERR_NO_DEVICE = 201;
	public static final int ERR_NO_CHARGE = 202;
	public static final int ERR_NO_ORDER = 203;
	public static final int ERR_NO_CONSUME = 204;
	public static final int ERR_NO_DEVACCOUNT = 205;
	public static final int ERR_NO_DEVINFO = 205;
	public static final int ERR_NO_OTAFILE = 206;
	public static final int ERR_NO_MERCHANT = 207;
	public static final int ERR_NO_STATS = 206;
	public static final int ERR_NO_APPINFO = 208;
	public static final int ERR_NO_POW_ROLE = 209;
	public static final int ERR_NO_POW_SYS_USER = 210;
	public static final int ERR_NO_POW_RESOURCE = 220;
	public static final int ERR_NO_PRODUCT = 230;
	public static final int ERR_DEL_POW_ROLE = 400;
	public static final int ERR_ILLEGAL_COMMAND = 500;
	
	public static final int ERR_CODE_JWT = 1000;
	
	public static final int ERR_SHARE_MX3165_PRODUCTI_ID = 27020;
	public static final int ERR_SHARE_MX3165_PASSWORD = 27030;
	public static final int ERR_SHARE_MX3165_OTA_NO_UPDATE = 25001; // 没有新的固件版本
	
	public static final int ERR_SHARE_MX3165_TOKEN_EXPIRED = 1200; // token过期
	public static final int ERR_SHARE_MX3165_TOKEN_ERROR = 1201; // token错误
	public static final int ERR_SHARE_MX3165_TOKEN_INVAILD = 1202;// 无效的token
	
	public static final int ERR_SHARE_CLIENT_GETCHARGEINFO = 1210;
	public static final int ERR_SHARE_CLIENT_CONSUME = 1220;
	public static final int ERR_SHARE_CLIENT_GETDEVINFO = 1230;
	public static final int ERR_SHARE_CLIENT_SENDCOMMAMD = 1240;
	public static final int ERR_SHARE_CLIENT_GETUNCOSUMEBILL = 1250;
	public static final int ERR_SHARE_CLIENT_PREBILL = 1260;

	public static final int ERR_SHARE_M26_ACTIVATE = 1300;
	public static final int ERR_SHARE_M26_OTACHECK = 1310;
	public static final int ERR_SHARE_M26_UPLOADDATA = 1320;
	public static final int ERR_SHARE_M26_SYNCSTATUS = 1330;
	public static final int ERR_SHARE_M26_CHIPSCONFIRM = 1340;

	public static final int ERR_SHARE_MX3165_ACTIVE = 1400;
	public static final int ERR_SHARE_MX3165_TOKENAUTH = 1410;
	public static final int ERR_SHARE_MX3165_SYNCSTATUS = 1420;
	public static final int ERR_SHARE_MX3165_UPDATECHECK = 1430;
	public static final int ERR_SHARE_MX3165_OTAUPLOADLOG = 1440;
	public static final int ERR_SHARE_MX3165_CHIPSCONFIRM = 1450;
	public static final int ERR_SHARE_MX3165_RECOVERDEVICEGRANT = 1460;
	public static final int ERR_SHARE_MX3165_SENDREALDATA = 1470;
	public static final int ERR_SHARE_MX3165_DEVRELATIONADD = 1480;

	public static final int ERR_SECURITY_CLIENT_VERCODE = 3000;
	public static final int ERR_SECURITY_CLIENT_USERREG = 3001;
	public static final int ERR_SECURITY_CLIENT_LOGIN = 3002;
	public static final int ERR_SECURITY_CLIENT_UPDATEUSER = 3003;
	public static final int ERR_SECURITY_CLIENT_USERGRANT = 3004;
	public static final int ERR_SECURITY_CLIENT_DEVBIND = 3005;
	public static final int ERR_SECURITY_CLIENT_UNDEVBIND = 3006;
	public static final int ERR_SECURITY_CLIENT_GETUSERDEV = 3007;
	public static final int ERR_SECURITY_CLIENT_GETDEVUSER = 3008;
	public static final int ERR_SECURITY_CLIENT_GETUSERINFO = 3009;
	public static final int ERR_SECURITY_CLIENT_GETDEVTOKEN = 3010;
	public static final int ERR_SECURITY_CLIENT_VERCODE_KEY = 3011;
	public static final int ERR_SECURITY_CLIENT_USERBIND = 3012;

	public static final int ERR_POW_APP_INFO = 3110;
	public static final int ERR_POW_ROLE = 3120;
	public static final int ERR_POW_LOGIN = 3130;
	public static final int ERR_POW_SYS_USER = 3140;
	public static final int ERR_POW_RESOURCE = 3150;
	public static final int ERR_POW_ROLE_RESOURCE = 3160;
	public static final int ERR_POW_USER_ROLE = 3170;
	public static final int ERR_POW_USER_RESOURCE = 3180;
	
	public static final int ERR_DEVICE_GETDEVCHARGEINFO = 4001;
	public static final int ERR_DEVICE_GETDEVINFOBYID = 4002;
	public static final int ERR_DEVICE_GETDEVINFOBYMAC = 4003;
	public static final int ERR_DEVICE_GETDEVINFOBYORDERNO = 4004;
	public static final int ERR_DEVICE_GETDEVACCOUNT = 4005;
	public static final int ERR_DEVICE_GETDEVCONSUME = 4006;
	public static final int ERR_DEVICE_SENDCOMMAND = 4007;
	public static final int ERR_DEVICE_UPDATEDEVACCOUNT = 4008;
	public static final int ERR_DEVICE_UPDATEDEVINFOBYID = 4009;
	public static final int ERR_DEVICE_SELECTBYGISRECT =4010;
	public static final int ERR_DEVICE_DELDEVACCOUNT = 4011;
	
	public static final int ERR_PRODUCT_SQVEPROQNR = 4101;
	public static final int ERR_PRODUCT_SAVEPRODINFO = 4102;
	public static final int ERR_PRODUCT_SELPRODBYAPP = 4103;
	
	public static final int ERR_OTAFILE_SELECT = 4201;
	public static final int ERR_OTAFILE_DELETE = 4202;
	public static final int ERR_OTAFILE_INSERT = 4203;
	public static final int ERR_OTAFILE_UPDATE = 4204;

	public static final int ERR_EXAM_STARTEXAM = 4301;
	public static final int ERR_EXAM_GETEXAMRESULT = 4302;
	public static final int ERR_EXAM_CONFIRMEXAMRESULT = 4303;
	public static final int ERR_EXAM_SAVEEXAMITEM = 4304;
	public static final int ERR_EXAM_STOPEXM = 4305;
	public static final int ERR_EXAM_QUERYEXAMlIST = 4306;
	public static final int ERR_EXAM_CONFIRMEXAMMANU= 4307;

	public static final int ERR_LOGISTICE_ADD = 4401;
	public static final int ERR_LOGISTICE_UPDATE = 4402;
	public static final int ERR_LOGISTICE_SELECT = 4403;
	
	public static final int ERR_NOTICE_NOTICETEST = 4501;
	public static final int ERR_NOTICE_PUSHTEST = 4502;
	
	public static final int ERR_STATS_DEVSTATETYPE = 7001;
	public static final int ERR_STATS_USERREGMONTH = 7002;
	public static final int ERR_STATS_FUNDMONTH = 7003;
	public static final int ERR_STATS_FUNDMERCHANTDAY = 7004;
	public static final int ERR_STATS_FUNDMERCHANTWEEK = 7005;
	public static final int ERR_STATS_FUNDTIMESDAY = 7006;
	public static final int ERR_STATS_FUNDTIMESWEEK = 7007;
	public static final int ERR_STATS_DEVSELLER = 7008;
	public static final int ERR_STATS_DEVONLINESTATE = 7009;
	public static final int ERR_STATS_FUNDSELLERWEEK = 7010;
	public static final int ERR_STATS_FUNDDEVTOP15 = 7011;
	public static final int ERR_STATS_FUNDUSERTOP10 = 7012;
	public static final int ERR_STATS_USERREGTYPEWEEK = 7013;
	public static final int ERR_STATS_DEVEXAMMAIN = 7014;
	public static final int ERR_STATS_DEVEXAMITEM = 7015;
	
	public static final int ERR_DEVICE_STATS_METHOD = 7101;
	public static final int ERR_DEVICE_DAYSTATS = 7102;
	public static final int ERR_DEVICE_WEEKSTATS = 7103;
	public static final int ERR_DEVICE_MONTHSTATS = 7104;
	public static final int ERR_DEVICE_YEARSTATS = 7105;
	
	public static final int ERR_QUERY_CONSUMEDETAILQUERY= 7501;
	public static final int ERR_QUERY_CONSUMEMERCHANTQUERY= 7502;
	public static final int ERR_QUERY_DEVICEACCOUNTQUERY= 7503;
	public static final int ERR_QUERY_MERCHANTACCOUNTQUERY= 7504;
	public static final int ERR_QUERY_DEVICEOFFERMONTHQUERY= 7505;
	public static final int ERR_QUERY_MERCHANTOFFERMONTHQUERY= 7506;
	public static final int ERR_QUERY_DEVICEOFFERWEEKQUERY= 7507;
	public static final int ERR_QUERY_MERCHANTOFFERWEEKQUERY= 7508;
	public static final int ERR_QUERY_QNRQUERY= 7509;
	
	public static final int DICT_SHARE_M26_DATA = 1;
	public static final int DICT_SHARE_M26_NODATA = 0;

	public static final int DICT_SHARE_MX3165_DATA = 1;
	public static final int DICT_SHARE_MX3165_NODATA = 0;

	public static final String CLIENT_USER_TYPE = "3";
	public static final String CLIENT_USER_TYPENAME = "APP用户";

	public static String STATS_TYPE[] = { "max", "min", "avg" };

	public static final String DEV_EXAM_START = "1";
	public static final String DEV_EXAM_STOP = "0";
	public static final String DEV_EXAM_TYPE_AUTO = "1";
	public static final String DEV_EXAM_TYPE_MANU = "2";

}
