阿里厂测APP下载地址 http://open.aliplus.com/download?spm=0.0.0.0.us621G

一、配网
在alink_config.h中，
1、打开宏定义PASS_THROUGH，使用透传方式，配网入口->模组认证->阿里直连v1(LUA)
2、关闭宏定义PASS_THROUGH，使用非透传方式（JSON），配网入口->模组认证->智能云-smartled

alink embed 指示灯说明  
aws配网模式：系统指示灯快闪   射频指示灯长灭
aws配网超时：系统指示灯长灭   射频指示灯长灭
收到SSID：系统指示灯慢闪        射频指示灯长灭
正常工作模式：系统指示灯长亮 射频指示灯长亮