package com.yjyz.iot.sms;

public interface ISendSMS {
	public SMSResult sendVerCode(String tel, String verCode);

	public SMSResult sendAlerm(String tel, String devName);

	SMSResult sendAlerm(String ytxAppId, String templateCode, String tel, String devName, String message);

	SMSResult sendVerCode(String ytxAppId, String templateCode, String tel, String verCode);
}
