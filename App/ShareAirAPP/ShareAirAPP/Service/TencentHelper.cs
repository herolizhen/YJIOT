using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Web;
using System.Xml.Linq;
using Tencent;
using YJIOT.ShareAirAPP.Models;

namespace YJIOT.ShareAirAPP.Service
{
    /// <summary>
    /// 微信应用
    /// </summary>
    public partial class TencentHelper
    {
        private static readonly object AccessTokenSysn = new object();
        private static readonly object JsApiTicketSysn = new object();

        private static SecurityToken AccessToken;
        private static SecurityToken JsApiTicket;

        private static HttpClient CreateHttpClient()
        {
            HttpClient client = new HttpClient();
            client.Timeout = new TimeSpan(0, 0, APPConfig.Tencent_Timeout);

            return client;
        }
        /// <summary>
        /// 附加信息转key-value
        /// </summary>
        /// <param name="attach"></param>
        /// <returns></returns>
        public static Dictionary<string,string> GetKeyValue(string attach)
        {
            Dictionary<string, string> dic = new Dictionary<string, string>();
            try
            {
                string[] tmps = attach.Split('@');
                foreach (var item in tmps)
                {
                    string[] tmp = item.Split('#');
                    dic.Add(tmp[0], tmp[1]);
                }
            }
            catch (Exception ex)
            {
                AppHelper.DebugException(ex);
            }
            return dic;
        }
        /// <summary>
        /// 获取微信推送信息
        /// </summary>
        /// <param name="Request"></param>
        /// <returns></returns>
        public static string CreateCallBackMessage(HttpRequest Request)
        {
            string message = string.Empty;
            try
            {
                if (Request.InputStream.Length > 0)
                {
                    byte[] buffer = new byte[Request.InputStream.Length];
                    Request.InputStream.Read(buffer, 0, buffer.Length);
                    message = Encoding.UTF8.GetString(buffer);
                }
            }
            catch (Exception ex)
            {
                message = string.Empty;
                AppHelper.DebugException(ex);
            }

            return message;
        }
        /// <summary>
        /// 获取微信用户信息
        /// </summary>
        /// <param name="code"></param>
        /// <returns>用户信息</returns>
        public static JObject CreateOAuthUser(string code)
        {
            JObject ret = null;
            HttpClient client = CreateHttpClient();

            JObject token = null;
            if (!string.IsNullOrWhiteSpace(code))
            {
                string json = string.Empty;
                string url = "https://api.weixin.qq.com/sns/oauth2/access_token?appid={0}&secret={1}&code={2}&grant_type=authorization_code";
                url = string.Format(url, APPConfig.Tencent_APPID, APPConfig.Tencent_APPSECRET, code);
                try
                {
                    json = client.GetStringAsync(url).Result;
                    token = JObject.Parse(json);
                    if (token["access_token"] == null || token["openid"] == null)
                    {
                        token = null;
                    }
                }
                catch (Exception ex)
                {
                    token = null;
                }
            }
            if (token != null)
            {
                string json = string.Empty;
                string url = "https://api.weixin.qq.com/sns/userinfo?access_token={0}&openid={1}&lang=zh_CN";
                url = string.Format(url, token["access_token"].Value<string>(), token["openid"].Value<string>());
                try
                {
                    json = client.GetStringAsync(url).Result;
                    ret = JObject.Parse(json);
                    if (ret["openid"] == null)
                    {
                        ret = null;
                        AppHelper.DebugException(new Exception(json) { Source = "CreateOAuthUser" });
                    }
                }
                catch (Exception ex)
                {
                    ret = null;
                    AppHelper.DebugException(ex);
                }
            }
            if (ret != null)
            {
                string nickname = ret["nickname"].Value<string>();
                ret["nickname"] = AppHelper.FilterEmoji(nickname);
            }
            return ret;
        }
        /// <summary>
        /// 获取微信访问access_token
        /// </summary>
        /// <returns></returns>
        public static SecurityToken CreateAccessToken()
        {
            lock (AccessTokenSysn)
            {
                if(AccessToken!=null && !AccessToken.IsTimeout)
                {
                    return AccessToken.Clone();
                }
                //重新获取
                HttpClient http = CreateHttpClient();
                JObject token = null;
                string api = @"https://api.weixin.qq.com/cgi-bin/token?grant_type=client_credential&appid={0}&secret={1}";
                api = string.Format(api, APPConfig.Tencent_APPID, APPConfig.Tencent_APPSECRET);
                try
                {
                    string json = http.GetStringAsync(api).Result;
                    token = JObject.Parse(json);
                }
                catch (Exception ex)
                {
                    token = null;
                    AppHelper.DebugException(ex);
                }
                if (token != null)
                {
                    if (token["access_token"] != null)
                    {
                        //------
                        AccessToken = new SecurityToken(token["access_token"].Value<string>(), token["expires_in"].Value<int>());
                        return AccessToken.Clone();
                    }
                }
                return null;
            }
        }
        /// <summary>
        /// 微信支付统一下单
        /// </summary>
        /// <returns>预支付交易会话标识</returns>
        public static string CreateUnifiedorder(int total_fee, string out_trade_no, string openid, string spbill_create_ip, string attach)
        {
            string prepay_id = string.Empty;
            WxPayData data = new WxPayData();

            data.CreateUnifiedorder(
                    total_fee,
                    out_trade_no,
                    openid,
                    spbill_create_ip,
                    APPConfig.Tencent_COMMODITY,
                    attach
                );
            data.CreateUnifiedorderSign();
            HttpClient http = CreateHttpClient();
            try
            {
                HttpContent content = new StringContent(data.ToXml());
                var req = http.PostAsync("https://api.mch.weixin.qq.com/pay/unifiedorder", content).Result;
                string sxml = req.Content.ReadAsStringAsync().Result;
                var xml = XDocument.Parse(sxml);
                if(xml.Root.Element("return_code")!=null&& xml.Root.Element("return_code").Value.ToUpper() == "SUCCESS")
                {
                    prepay_id = xml.Root.Element("prepay_id").Value;
                }
                //AppHelper.DebugException(sxml);
            }
            catch (Exception ex)
            {
                prepay_id = string.Empty;
                AppHelper.DebugException(ex);
            }

            return prepay_id;
        }
        /// <summary>
        /// 获取JSSDK-access_token
        /// </summary>
        /// <returns></returns>
        public static SecurityToken CreateJsApiTicket()
        {
            lock (JsApiTicketSysn)
            {
                if (JsApiTicket != null && !JsApiTicket.IsTimeout)
                {
                    return JsApiTicket.Clone();
                }
                else
                {
                    SecurityToken token = CreateAccessToken();
                    if (token != null)
                    {
                        HttpClient http = CreateHttpClient();
                        JObject jak = null;
                        string api = @"https://api.weixin.qq.com/cgi-bin/ticket/getticket?type=jsapi&access_token={0}";
                        api = string.Format(api, token.Token);
                        try
                        {
                            string json = http.GetStringAsync(api).Result;
                            jak = JObject.Parse(json);
                        }
                        catch (Exception ex)
                        {
                            jak = null;
                            AppHelper.DebugException(ex);
                        }
                        if (jak != null)
                        {
                            if (jak["errcode"].Value<int>() == 0)
                            {
                                //------
                                JsApiTicket = new SecurityToken(jak["ticket"].Value<string>(), jak["expires_in"].Value<int>());
                                return JsApiTicket.Clone();
                            }
                        }
                    }
                }
                return null;
            }
        }
        /// <summary>
        /// 构建微信JSSDK配置
        /// </summary>
        /// <returns></returns>
        public static JObject CreateJSSDKConfig()
        {
            JObject config = null;
            var ticket = CreateJsApiTicket();
            if (ticket != null)
            {
                config = new JObject();
                config.Add("debug", false);
                config.Add("appId", APPConfig.Tencent_APPID);
                config.Add("timestamp", APPConfig.GenerateTimeStamp());
                config.Add("nonceStr", APPConfig.GenerateNonceStr());
                string signature = CreateSignature(ticket.Token, config, APPConfig.Tencent_JSSDKURL);
                config.Add("signature", signature);
                config.Add("jsApiList", new JArray(APPConfig.Tencent_JSSDKAPILIST));
            }
            return config;
        }
        private static string CreateSignature(string ticket, JObject config, string url)
        {
            string signature = string.Empty;
            StringBuilder skey = new StringBuilder();
            skey.AppendFormat("jsapi_ticket={0}", ticket);
            skey.AppendFormat("&noncestr={0}", config["nonceStr"].Value<string>());
            skey.AppendFormat("&timestamp=={0}", config["timestamp"].Value<string>());
            skey.AppendFormat("&url=={0}", url);
            signature = Cryptography.GetSHA1Hash(skey.ToString()).ToLower();
            return signature;
        }
        /// <summary>
        /// 确认支付订单支付成功
        /// </summary>
        /// <param name="pay"></param>
        /// <returns></returns>
        public static bool ConfirmPay(WeChatPayNotify pay)
        {
            bool yes = false;

            if (!pay.IsEmpty)
            {
                JObject jpay = new JObject();
                jpay.Add("openId",pay.openid);
                jpay.Add("deviceId", pay.DeviceID);
                jpay.Add("orderNo", pay.out_trade_no);
                jpay.Add("totalFree", pay.total_fee);
                jpay.Add("type", "1");
                jpay.Add("payNo", pay.transaction_id);
                jpay.Add("mchId", pay.mch_id);
                jpay.Add("status", "1");
                jpay.Add("chips", pay.Chips);
                yes = IotInterface.PostConsume(pay.openid, jpay);
            }

            return yes;
        }
    }
}