package com.yjyz.iot.notice.service;

import java.util.List;

import com.yjyz.iot.notice.entity.NoticeConfig;
import com.yjyz.iot.notice.entity.NoticePush;
import com.yjyz.iot.notice.entity.NoticeRule;

public interface INoticeService {

	boolean delNoticeConfig(String appId) throws Exception;

	boolean insNoticeConfig(NoticeConfig record) throws Exception;

	NoticeConfig selNoticeConfig(String appId) throws Exception;

	boolean updNoticeConfig(NoticeConfig record) throws Exception;

	boolean delNoticeRule(String productId) throws Exception;

	boolean insNoticeRule(NoticeRule record) throws Exception;

	NoticeRule selNoticeRule(String productId) throws Exception;

	boolean updNoticeRule(NoticeRule record) throws Exception;

	boolean delNoticePush(String productId,int pushNo) throws Exception;

	boolean insNoticePush(NoticePush record) throws Exception;

	NoticePush selNoticePush(String productId,int pushNo) throws Exception;

	boolean updNoticePush(NoticePush record) throws Exception;

	List<NoticePush> selNoticePushAll(String productId) throws Exception;

	public boolean noticeSend(String deviceId, int noticeType, int pushNo) throws Exception;

	public boolean noticeTest(String appId, String tel, int type) throws Exception;
	public boolean pushTest(String appId, String tel, String produceId, int pushNo) throws Exception ;
}