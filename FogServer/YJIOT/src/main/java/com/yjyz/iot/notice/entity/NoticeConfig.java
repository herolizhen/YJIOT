package com.yjyz.iot.notice.entity;

public class NoticeConfig {
    private String appId;

    private String ytxAppid;

    private String sign;

    private String verTemplateId;

    private String verTemplate;

    private String mesTemplateId;

    private String mesTemplate;

    private String voiceTelNo;

    private String voiceWav;

    private String voiceText;

    private String apiAppid;

    private String apiAppkey;

    private String apiTemplate;

    private Boolean noticeOpen;

    public String getAppId() {
        return appId;
    }

    public void setAppId(String appId) {
        this.appId = appId == null ? null : appId.trim();
    }

    public String getYtxAppid() {
        return ytxAppid;
    }

    public void setYtxAppid(String ytxAppid) {
        this.ytxAppid = ytxAppid == null ? null : ytxAppid.trim();
    }

    public String getSign() {
        return sign;
    }

    public void setSign(String sign) {
        this.sign = sign == null ? null : sign.trim();
    }

    public String getVerTemplateId() {
        return verTemplateId;
    }

    public void setVerTemplateId(String verTemplateId) {
        this.verTemplateId = verTemplateId == null ? null : verTemplateId.trim();
    }

    public String getVerTemplate() {
        return verTemplate;
    }

    public void setVerTemplate(String verTemplate) {
        this.verTemplate = verTemplate == null ? null : verTemplate.trim();
    }

    public String getMesTemplateId() {
        return mesTemplateId;
    }

    public void setMesTemplateId(String mesTemplateId) {
        this.mesTemplateId = mesTemplateId == null ? null : mesTemplateId.trim();
    }

    public String getMesTemplate() {
        return mesTemplate;
    }

    public void setMesTemplate(String mesTemplate) {
        this.mesTemplate = mesTemplate == null ? null : mesTemplate.trim();
    }

    public String getVoiceTelNo() {
        return voiceTelNo;
    }

    public void setVoiceTelNo(String voiceTelNo) {
        this.voiceTelNo = voiceTelNo == null ? null : voiceTelNo.trim();
    }

    public String getVoiceWav() {
        return voiceWav;
    }

    public void setVoiceWav(String voiceWav) {
        this.voiceWav = voiceWav == null ? null : voiceWav.trim();
    }

    public String getVoiceText() {
        return voiceText;
    }

    public void setVoiceText(String voiceText) {
        this.voiceText = voiceText == null ? null : voiceText.trim();
    }

    public String getApiAppid() {
        return apiAppid;
    }

    public void setApiAppid(String apiAppid) {
        this.apiAppid = apiAppid == null ? null : apiAppid.trim();
    }

    public String getApiAppkey() {
        return apiAppkey;
    }

    public void setApiAppkey(String apiAppkey) {
        this.apiAppkey = apiAppkey == null ? null : apiAppkey.trim();
    }

    public String getApiTemplate() {
        return apiTemplate;
    }

    public void setApiTemplate(String apiTemplate) {
        this.apiTemplate = apiTemplate == null ? null : apiTemplate.trim();
    }

    public Boolean getNoticeOpen() {
        return noticeOpen;
    }

    public void setNoticeOpen(Boolean noticeOpen) {
        this.noticeOpen = noticeOpen;
    }
}