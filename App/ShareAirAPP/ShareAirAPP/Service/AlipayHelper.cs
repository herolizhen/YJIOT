using Aop.Api;
using Aop.Api.Domain;
using Aop.Api.Request;
using Aop.Api.Response;
using Aop.Api.Util;
using Newtonsoft.Json.Linq;
using System;
using System.Text;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;
using System.Web;
using YJIOT.ShareAirAPP.ViewModel;
using YJIOT.ShareAirAPP.Models;

namespace YJIOT.ShareAirAPP.Service
{
    /// <summary>
    /// 支付宝应用
    /// </summary>
    public partial class AlipayHelper
    {
        private static IAopClient CreateAopClient()
        {
            IAopClient client = new DefaultAopClient(
                APPConfig.Alipay_SERVER,
                APPConfig.Alipay_APPID,
                APPConfig.Alipay_APP_PRIVATE_KEY,
                "json",
                "1.0",
                "RSA2",
                APPConfig.Alipay_ALIPAY_PUBLIC_KEY,
                "utf-8",
                false);

            return client;
        }

        /// <summary>
        /// 构建认证URL
        /// </summary>
        /// <returns></returns>
        public static string CreateOAuthUrl(string state)
        {
            string url = string.Empty;

            url = @"https://openauth.alipay.com/oauth2/publicAppAuthorize.htm?app_id={0}&scope=auth_user&redirect_uri={1}&state={2}";
            url = string.Format(url, APPConfig.Alipay_APPID, HttpUtility.UrlEncode(APPConfig.Alipay_AAUTHURL),state);

            return url;
        }
        /// <summary>
        /// 登录并获取用户信息
        /// </summary>
        /// <param name="auth_code"></param>
        public static AlipayUserInfoShareResponse alipay_system_oauth_token(string auth_code)
        {
            AlipayUserInfoShareResponse user = null;

            IAopClient client = CreateAopClient();
            try
            {
                AlipaySystemOauthTokenRequest reqtoken = new AlipaySystemOauthTokenRequest();
                reqtoken.Code = auth_code;
                reqtoken.GrantType = "authorization_code";
                AlipaySystemOauthTokenResponse token = client.Execute<AlipaySystemOauthTokenResponse>(reqtoken);
                if (!token.IsError)
                {
                    AlipayUserInfoShareRequest requser = new AlipayUserInfoShareRequest();
                    user = client.Execute<AlipayUserInfoShareResponse>(requser, token.AccessToken);
                    if (user.IsError)
                    {
                        user = null;
                    }
                }
            }
            catch (Exception ex)
            {
                user = null;
            }

            return user;
        }
        /// <summary>
        /// 支付宝下单
        /// </summary>
        /// <returns></returns>
        public static AlipayTradeWapPayResponse alipay_trade_wap_pay(ShareProcessViewModel model, string out_trade_no)
        {
            AlipayTradeWapPayResponse pay = null;
            AlipayTradeWapPayModel paymodel = new AlipayTradeWapPayModel();
            paymodel.OutTradeNo = out_trade_no;
            paymodel.Subject = APPConfig.Alipay_COMMODITY;
            paymodel.TotalAmount = Math.Round(model.Payment / 100D, 2).ToString("#0.00");
            paymodel.Body= "一方净土——" + model.Attach["Type_Name"].Value<string>();
            //固定格式
            string PassbackParams = $"DeviceID#{model.DeviceID}@Chips#{model.Chips}";
            PassbackParams = HttpUtility.UrlEncode(PassbackParams);
            paymodel.PassbackParams = PassbackParams;
            paymodel.ProductCode = APPConfig.Alipay_PRODUCT_CODE;
            paymodel.TimeoutExpress = "10m";
            paymodel.QuitUrl = APPConfig.Alipay_QuitUrl;

            AlipayTradeWapPayRequest request = new AlipayTradeWapPayRequest();
            // 设置同步回调地址
            request.SetReturnUrl(APPConfig.Alipay_AAUTHURL);
            // 设置异步通知接收地址
            request.SetNotifyUrl(APPConfig.Alipay_NOTIFY_URL);
            request.SetBizModel(paymodel);

            IAopClient client = CreateAopClient();
            try
            {
                pay = client.pageExecute<AlipayTradeWapPayResponse>(request, null, "post");

                if (pay.IsError)
                {
                    AppHelper.DebugException(new Exception(StringUtil.ToString(pay)));
                    pay = null;
                }
            }
            catch (Exception ex)
            {
                AppHelper.DebugException(ex);
                pay = null;
            }

            return pay;
        }
        /// <summary>
        /// 支付宝同步回调
        /// </summary>
        /// <param name="request"></param>
        /// <returns></returns>
        public static ShareProcessViewModel CeateAlipayReturn(HttpRequestBase request)
        {
            ShareProcessViewModel model = null;
            bool isretun = false;
            
            string app_id = request.QueryString["app_id"];
            string method = request.QueryString["method"];
            if (!string.IsNullOrWhiteSpace(app_id) && !string.IsNullOrWhiteSpace(method))
            {
                if (app_id == APPConfig.Alipay_APPID && method == "alipay.trade.wap.pay.return")
                {
                    Dictionary<string, string> sArray = GetRequestGet(request);
                    isretun = AlipaySignature.RSACheckV1(sArray, APPConfig.Alipay_ALIPAY_PUBLIC_KEY, APPConfig.Alipay_CHARSET, APPConfig.Alipay_SIGN_TYPE, false);
                    if (isretun)
                    {
                        string out_trade_no = (new Guid(sArray["out_trade_no"])).ToString();
                        JObject info = IotInterface.PostGetOrderInfo(out_trade_no);
                        if (info != null)
                        {
                            model = new ShareProcessViewModel();
                            model.OpenID = info["user"]["openid"].Value<string>();
                            model.IotToken = IotInterface.RefreshToken(model.OpenID);
                            if (string.IsNullOrWhiteSpace(model.IotToken))
                            {
                                model = null;
                            }
                            else
                            {
                                model.DeviceID = new Guid(info["devInfo"]["deviceId"].Value<string>());
                                model.DevicePwd = info["devInfo"]["devicePw"].Value<string>();
                                model.DeviceMac = info["devInfo"]["deviceMac"].Value<string>();
                                model.OwnerName = info["devAccount"]["ownerName"].Value<string>();
                                model.Position = info["devAccount"]["position"].Value<string>();
                                model.Longitude = info["devAccount"]["longitude"].Value<double>();
                                model.Latitude = info["devAccount"]["latitude"].Value<double>();
                                model.IsAgree = true;
                            }
                        }
                    }
                }
            }

            return model;
        }
        /// <summary>
        /// 确认支付宝支付成功
        /// </summary>
        /// <returns></returns>
        public static bool ConfirmPay(Dictionary<string, string> notify)
        {
            bool yes = false;

            string app_id = notify["app_id"];
            string openid = notify["buyer_id"];
            string out_trade_no = (new Guid(notify["out_trade_no"])).ToString();
            string trade_no = notify["trade_no"];
            int receipt_amount = (int)(decimal.Parse(notify["receipt_amount"]) * 100);
            string passback_params = HttpUtility.UrlDecode(notify["passback_params"]);
            var dic = TencentHelper.GetKeyValue(passback_params);
            JObject jpay = new JObject();
            jpay.Add("openId", openid);
            jpay.Add("deviceId", dic["DeviceID"]);
            jpay.Add("orderNo", out_trade_no);
            jpay.Add("totalFree", receipt_amount);
            jpay.Add("type", "2");
            jpay.Add("payNo", trade_no);
            jpay.Add("mchId", APPConfig.Alipay_APPID);
            jpay.Add("status", "1");
            jpay.Add("chips", int.Parse(dic["Chips"]));
            yes = IotInterface.PostConsume(openid, jpay);
            return yes;
        }
        /// <summary>
        /// 支付宝支持成功异步通知
        /// </summary>
        /// <param name="request"></param>
        /// <returns></returns>
        public static Dictionary<string, string> AlipayNotify(HttpRequest request)
        {
            Dictionary<string, string> parameter = new Dictionary<string, string>();
            StringBuilder log = new StringBuilder();
            int i = 0;
            NameValueCollection coll;
            coll = request.Form;
            String[] requestItem = coll.AllKeys;
            for (i = 0; i < requestItem.Length; i++)
            {
                parameter.Add(requestItem[i], request.Form[requestItem[i]]);
                log.AppendFormat("{0}={1}\r\n", requestItem[i], request.Form[requestItem[i]]);
            }
            if (parameter.Count > 0)
            {
                bool tmp= AlipaySignature.RSACheckV1(parameter, APPConfig.Alipay_ALIPAY_PUBLIC_KEY, APPConfig.Alipay_CHARSET, APPConfig.Alipay_SIGN_TYPE, false);
                log.AppendFormat("\r\nRSACheckV1={0}", tmp);
                if (!tmp)
                {
                    parameter.Clear();
                }
            }
            if (log.Length > 0)
            {
                string trade_no = parameter["trade_no"];
                string fname = string.Format("Alipay_{0}", trade_no);
                AppHelper.SavePayLog(fname, log.ToString());
            }
            return parameter;


        }
        private static Dictionary<string, string> GetRequestGet(HttpRequestBase request)
        {
            int i = 0;
            Dictionary<string, string> sArray = new Dictionary<string, string>();
            NameValueCollection coll;
            coll = request.QueryString;
            String[] requestItem = coll.AllKeys;
            for (i = 0; i < requestItem.Length; i++)
            {
                sArray.Add(requestItem[i], request.QueryString[requestItem[i]]);
            }
            return sArray;

        }
    }
}