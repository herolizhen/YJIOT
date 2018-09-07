using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Configuration;

namespace YJIOT.ShareAirAPP.Service
{
    /// <summary>
    /// 
    /// </summary>
    public class APPConfig
    {
        #region 配置数据
        /// <summary>
        /// 随机字符串
        /// </summary>
        /// <returns></returns>
        public static string GenerateNonceStr()
        {
            return Guid.NewGuid().ToString().Replace("-", "");
        }
        /// <summary>
        /// 生成时间戳，标准北京时间，时区为东八区，自1970年1月1日 0点0分0秒以来的秒数
        /// </summary>
        /// <returns></returns>
        public static string GenerateTimeStamp()
        {
            TimeSpan ts = DateTime.UtcNow - new DateTime(1970, 1, 1, 0, 0, 0, 0);
            return Convert.ToInt64(ts.TotalSeconds).ToString();
        }
        /// <summary>
        /// 根据当前系统时间加随机序列来生成订单号
        /// </summary>
        /// <returns></returns>
        public static string GenerateOutTradeNo()
        {
            var ran = new Random();
            return string.Format("{0}{1}{2}", Tencent_MCHID, DateTime.Now.ToString("yyyyMMddHHmmss"), ran.Next(999));
        }
        #endregion
        #region 微信配置
        /// <summary>
        /// 微信访问超时（秒）
        /// </summary>
        public static int Tencent_Timeout
        {
            get
            {
                return int.Parse(ConfigurationManager.AppSettings["Tencent:Timeout"]);
            }
        }
        /// <summary>
        /// 微信公众平台令牌
        /// </summary>
        public static string Tencent_APPToken
        {
            get
            {
                return ConfigurationManager.AppSettings["Tencent:APPToken"];
            }
        }
        /// <summary>
        /// 微信公众平台应用ID
        /// </summary>
        public static string Tencent_APPID
        {
            get
            {
                return ConfigurationManager.AppSettings["Tencent:APPID"];
            }
        }
        /// <summary>
        /// 商户号
        /// </summary>
        public static string Tencent_MCHID
        {
            get
            {
                return ConfigurationManager.AppSettings["Tencent:MCHID"];
            }
        }
        /// <summary>
        /// 商户支付密钥
        /// </summary>
        public static string Tencent_MCHKEY
        {
            get
            {
                return ConfigurationManager.AppSettings["Tencent:MCHKEY"];
            }
        }
        /// <summary>
        /// 公众号开发者身份的密码
        /// </summary>
        public static string Tencent_APPSECRET
        {
            get
            {
                return ConfigurationManager.AppSettings["Tencent:APPSECRET"];
            }
        }
        /// <summary>
        /// 消息加解密密钥
        /// </summary>
        public static string Tencent_EncodingAESKey
        {
            get
            {
                return ConfigurationManager.AppSettings["Tencent:EncodingAESKey"];
            }
        }
        /// <summary>
        /// 支付结果通知url
        /// </summary>
        public static string Tencent_NOTIFY_URL
        {
            get
            {
                return ConfigurationManager.AppSettings["Tencent:NOTIFY_URL"];
            }
        }
        /// <summary>
        /// 微信登录回调url
        /// </summary>
        public static string Tencent_AAUTHURL
        {
            get
            {
                return ConfigurationManager.AppSettings["Tencent:AAUTHURL"];
            }
        }
        /// <summary>
        /// 微信商品描述
        /// </summary>
        public static string Tencent_COMMODITY
        {
            get
            {
                return ConfigurationManager.AppSettings["Tencent:COMMODITY"];
            }
        }
        /// <summary>
        /// 微信JSSDK界面url
        /// </summary>
        public static string Tencent_JSSDKURL
        {
            get
            {
                return ConfigurationManager.AppSettings["Tencent:JSSDKURL"];
            }
        }
        /// <summary>
        /// 微信JSSDK接口列表
        /// </summary>
        public static string[] Tencent_JSSDKAPILIST
        {
            get
            {
                return ConfigurationManager.AppSettings["Tencent:JSSDKAPILIST"].Split(',');
            }
        }
        #endregion
        #region 支付宝应用配置
        public const string Alipay_SERVER = "https://openapi.alipay.com/gateway.do";
        public const string Alipay_FORMAT = "JSON";
        public const string Alipay_CHARSET = "UTF-8";
        public const string Alipay_SIGN_TYPE = "RSA2";
        public const string Alipay_VERSION = "1.0";
        public const string Alipay_PRODUCT_CODE = "QUICK_WAP_PAY";

        //public const string ALIPAY_SERVER = "https://openapi.alipay.com/gateway.do";
        //public const string APPID = "2017082408354266";
        //public const string APP_PUBLIC_KEY = "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAsFfidRIKQGw5J5eA63UuEjQHdm7IK5IOuvSKLKh4yb0ZD9qHY2p7VB5tyDvrI1aR44+MCKkcvywPxILUbe+0JciwUHU+JZIJGIBe270gJmsI1Ug/JgyS8G+fwdIp8BWyKZI3Fe28DPf8d6IQxwXw5ArIs/6lXk2VS0mBs5Jn3RhY88EEDQCKgpFtIwejzTsm7CWizwaTKub0/brpBwkoqNnU90NMmdTKUo2XXqD03AoR4sMe4FgHH2CVjMdR1jFLDa5PyK2kyxh3AxCrZZ4ioeSYK8O+nIP5qRislSc8p0yQJXnFHVw3SZB6TCLcVi04idCzcZaGeW0/7Zae+ClNowIDAQAB";
        //public const string APP_PRIVATE_KEY = "MIIEpAIBAAKCAQEAsFfidRIKQGw5J5eA63UuEjQHdm7IK5IOuvSKLKh4yb0ZD9qHY2p7VB5tyDvrI1aR44+MCKkcvywPxILUbe+0JciwUHU+JZIJGIBe270gJmsI1Ug/JgyS8G+fwdIp8BWyKZI3Fe28DPf8d6IQxwXw5ArIs/6lXk2VS0mBs5Jn3RhY88EEDQCKgpFtIwejzTsm7CWizwaTKub0/brpBwkoqNnU90NMmdTKUo2XXqD03AoR4sMe4FgHH2CVjMdR1jFLDa5PyK2kyxh3AxCrZZ4ioeSYK8O+nIP5qRislSc8p0yQJXnFHVw3SZB6TCLcVi04idCzcZaGeW0/7Zae+ClNowIDAQABAoIBAQCc2J5oiHIr2NaBO4UEaIZg1Hwqv+A0uMV3Thg0HmjI7vOCoVk4eLZXHHWC2qCLHu3F3KCt91TFSPiBTeiKG+E8liMUfSOYoSqL62nzwmT9JsiFg6v/OMHdLzuGVlrM209LIGz0iS5wzoV1FuYbT1JyUpEvX3hQx2rZuvis8rSE9i9aQ4mi8LuwbYNKJInI7lRusSZpjC1gNAzEfgqhWBRzskylL4Rgc5crsUNPAhi00lmu6FZ+ZZ14XdMf30AYJ6x+Gr8dyxwLooScwdlMaL5e7JbWWQtewHnDNOrJMwq2DEJn5rYXgF/1WMjgDUUY9LT0F2hJN4FHie9htzTI8w7RAoGBAOEBJmVsfsIcalJDLH+oun6Thg4bxxF1GOOnlZFGyfzdfFeJ/A/7KBCKG7J7pnn6tNTuTHSyPmmbeY5gjsGuztdNF8C8wNOxFFdR4qn4JT7fqbHWcV/KQKNLNL1uycStef3eQqfyQPb0GEQ+U9KQ08dd2A6b+yZL8Ewq7MJdnsPZAoGBAMiiruj1tJjaZ/a1tqVfVqT6RKzmbVJkRkQRVi24WyXAl+K6vCkW/dEaG5U1zQNsu0UFfqNwnN4zl+0HqYzOOD+4P0NIMBKptSQt5RSGuGL+aje0PcmXHHIy398wkEOd7xSo9k8mafwXb+als5NqmVRSvFkHqAWTVQAujIOIovvbAoGBAIG7YwMZsmCDd74koxScGaN/tcyOsZHcPVSNvMw9z5qvrdDfa2lfe7NFnkCj0NIF/pvDJmwmlZvYnBa+j7EW9IXpGmfzrQ6hzEOooBM2U2tUFIjIRyhe+jPs2eTbaxSunWcF7tLc+B4rkY5PjY8cGC+caUXLI9zp7gxMt6Q9zJvJAoGAH4IM3eDYP7js4r2etVHHlZkH9+8n8+xzbHUch4mQJtmcAKs6qWlG6vOiqUgNriABONGoFZq1x99qWHr/kXFBPCB/Lt3DTur/23KpqxONGV7C54SSv3nPqc97gN1rinLe/Oub4soxkrlLhXk4PkpbUfa8RW8CX/3HN4QX5QAsOEkCgYBHMUwVjEoav7lxlhuDVZf3sVQyMHg7MFIwcGbAAKQbwDyqWDLm4hVylSlQzSGs3Sq4Yy2M31hHXt3gVXxhTLKUUZVscUu9yhdKqnxaV48LrW8CNMcfbtXpd9uJ7m6xtH/wsbe36UV9p+ReEThkt8rzHbWe21EYFt6dC3B1k8HBBg==";
        //public const string ALIPAY_PUBLIC_KEY = "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAoYSJjI+yDFvlZww+Jn2thCB6u8Az/xvyZ1iNf40DkaGI9DYt/XSpL7zDxerkK1bCHSH/q9DMUSGEKEvYobZgYsyT62Il5rW8gGuUkIRiXf3TLzSM27IfP+mKwALuIWTskD7pfdhOSm9NhRFP4Zx/XOmHkDn76FXtJak3YfMnYgHGbCfUfXt97w5DvOlWa9m7U14Utz+XE6qh3Y/4qY0HI0D4JQBINSQDQMM/Haja+kKJyzcM/FX97TIL9btjwcbikTl8MX88m67t6DaDqh67xOrGwaZCTztBqkWe9zzwM2HZ3vPvatKPH8xApxU1T9MzSY4mTGDFvUyJdfNQRmDi5QIDAQAB";
        //public const string FORMAT = "JSON";
        //public const string CHARSET = "UTF-8";
        //public const string SIGN_TYPE = "RSA2";
        //public const string VERSION = "1.0";

        /// <summary>
        /// 支付宝访问超时（秒）
        /// </summary>
        public static int Alipay_Timeout
        {
            get
            {
                return int.Parse(ConfigurationManager.AppSettings["Alipay:Timeout"]);
            }
        }
        /// <summary>
        /// 商品描述
        /// </summary>
        public static string Alipay_COMMODITY
        {
            get
            {
                return ConfigurationManager.AppSettings["Alipay:COMMODITY"];
            }
        }
        /// <summary>
        /// 登录回调URL
        /// </summary>
        public static string Alipay_AAUTHURL
        {
            get
            {
                return ConfigurationManager.AppSettings["Alipay:AAUTHURL"];
            }
        }
        /// <summary>
        /// 支付宝应用ID
        /// </summary>
        public static string Alipay_APPID
        {
            get
            {
                return ConfigurationManager.AppSettings["Alipay:APPID"];
            }
        }
        /// <summary>
        /// 应用公钥
        /// </summary>
        public static string Alipay_APP_PUBLIC_KEY
        {
            get
            {
                return ConfigurationManager.AppSettings["Alipay:APP_PUBLIC_KEY"];
            }
        }
        /// <summary>
        /// 应用私钥
        /// </summary>
        public static string Alipay_APP_PRIVATE_KEY
        {
            get
            {
                return ConfigurationManager.AppSettings["Alipay:APP_PRIVATE_KEY"];
            }
        }
        /// <summary>
        /// 支付KEY
        /// </summary>
        public static string Alipay_ALIPAY_PUBLIC_KEY
        {
            get
            {
                return ConfigurationManager.AppSettings["Alipay:ALIPAY_PUBLIC_KEY"];
            }
        }
        /// <summary>
        /// 支付通知
        /// </summary>
        public static string Alipay_NOTIFY_URL
        {
            get
            {
                return ConfigurationManager.AppSettings["Alipay:NOTIFY_URL"];
            }
        }
        /// <summary>
        /// 取消支付回调
        /// </summary>
        public static string Alipay_QuitUrl
        {
            get
            {
                return ConfigurationManager.AppSettings["Alipay:QuitUrl"];
            }
        }
        #endregion
        #region IOT配置
        public static string IOT_Host
        {
            get
            {
                return ConfigurationManager.AppSettings["IOT:Host"];
            }
        }
        public static string IOT_MQTTHOST
        {
            get
            {
                return ConfigurationManager.AppSettings["IOT:MQTTHOST"];
            }
        }
        public static string IOT_MQTTPATH
        {
            get
            {
                return ConfigurationManager.AppSettings["IOT:MQTTPATH"];
            }
        }
        public static int IOT_MQTTPORT
        {
            get
            {
                return int.Parse(ConfigurationManager.AppSettings["IOT:MQTTPORT"]);
            }
        }
        public static string IOT_MQTTCLIENT
        {
            get
            {
                return Guid.NewGuid().ToString().Replace("-",string.Empty);
            }
        }
        public static string IOT_MQTTTOPIC
        {
            get
            {
                return ConfigurationManager.AppSettings["IOT:MQTTTOPIC"];
            }
        }
        #endregion
        #region 应用配置
        public static string USE_APPID
        {
            get
            {
                return ConfigurationManager.AppSettings["USE:APPID"];
            }
        }
        public static int USE_CUETIMEOUT
        {
            get
            {
                return int.Parse(ConfigurationManager.AppSettings["USE:CUETIMEOUT"]);
            }
        }
        public static int USE_EXPIRESTIME
        {
            get
            {
                return int.Parse(ConfigurationManager.AppSettings["USE:EXPIRESTIME"]);
            }
        }
        #endregion
    }
}