using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Text;
using System.Configuration;
using System.Web.Mvc;
using YJIOT.ShareAirAPP.Models;
using YJIOT.ShareAirAPP.Service;
using Newtonsoft.Json.Linq;
using YJIOT.ShareAirAPP.ViewModel;
using Tencent;

namespace YJIOT.ShareAirAPP.Controllers
{
    /// <summary>
    /// 微信应用
    /// </summary>
    public partial class WeChatController : Controller
    {
        public ActionResult Index()
        {
            ActionResult view = null;
            ShareProcessViewModel model = null;
            string mac = this.Request.QueryString["mac"];
            if (!string.IsNullOrWhiteSpace(mac))
            {
                mac = mac.ToUpper();
                return this.RedirectPermanent(this.Aauth(mac));
            }

            string code = this.Request.QueryString["code"];
            string state = this.Request.QueryString["state"];
            if (!string.IsNullOrWhiteSpace(code) && !string.IsNullOrWhiteSpace(state))
            {
                model = this.Aauth(code, state);
            }
            if (model != null)
            {
                view = this.ProcessOne(model);
            }
            else
            {
                return this.ResultError("用户登录异常");
            }
            this.ViewBag.Title = "一方净土•共享好空气";
            return view;
        }
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Index(ShareProcessViewModel model)
        {
            ActionResult view = null;

            if (!string.IsNullOrWhiteSpace(model.OpenID) &&
                !string.IsNullOrWhiteSpace(model.IotToken) &&
                model.DeviceID != Guid.Empty
                )
            {
                switch (model.Step)
                {
                    case ShareStep.Use:
                        if (model.IsUse)
                        {
                            view = this.ProcessFour(model);
                        }
                        else
                        {
                            view = this.ResultError("ShareStep.Use");
                        }
                        break;
                    case ShareStep.One:
                        if (model.IsAgree)
                        {
                            view = this.ProcessTwo(model);
                        }
                        else
                        {
                            model.Step = ShareStep.One;
                            model.Attach = new JObject();
                            model.Attach.Add("p",150);
                            this.ModelState.Clear();
                            view = this.View(model);
                        }
                        break;
                    case ShareStep.Two:
                        if (model.Chips > 0 && model.Payment > 0)
                        {
                            view = this.ProcessThree(model);
                        }
                        else
                        {
                            model.Step = ShareStep.Two;
                            this.ModelState.Clear();
                            view = this.View(model);
                        }
                        break;
                    case ShareStep.Three:
                        view = this.ProcessFour(model);
                        break;
                    case ShareStep.Four:
                        break;
                }
            }
            this.ViewBag.Title = "一方净土•共享好空气";
            return view;
        }
        private string Aauth(string mac)
        {
            string url = APPConfig.Tencent_AAUTHURL;
            url = HttpUtility.UrlEncode(url);
            string aauth = @"https://open.weixin.qq.com/connect/oauth2/authorize?appid={0}&redirect_uri={1}&response_type=code&scope=snsapi_userinfo&state={2}#wechat_redirect";
            aauth = string.Format(aauth, APPConfig.Tencent_APPID, url, mac);
            return aauth;
        }
        private ShareProcessViewModel Aauth(string code, string state)
        {
            ShareProcessViewModel model = null;
            JObject user = TencentHelper.CreateOAuthUser(code);
            if (user != null)
            {
                JObject raw = new JObject();
                raw.Add("openid", user["openid"].Value<string>());
                raw.Add("tel", "");
                raw.Add("nickname", user["nickname"].Value<string>());
                raw.Add("sex", user["sex"].Value<string>());
                raw.Add("city", user["city"].Value<string>());
                raw.Add("country", user["country"].Value<string>());
                raw.Add("province", user["province"].Value<string>());
                raw.Add("language", "");
                raw.Add("headimgurl", user["headimgurl"].Value<string>());
                raw.Add("remark", "微信用户");
                raw.Add("tagidList", "");
                raw.Add("type", "1");
                raw.Add("password", "");
                raw.Add("appId", APPConfig.USE_APPID);

                JObject token = IotInterface.PostRegister(raw);
                if (token != null)
                {
                    model = new ShareProcessViewModel();
                    model.OpenID = user["openid"].Value<string>();
                    model.IotToken = token["token"].Value<string>();
                    JObject info = IotInterface.PostGetDevInfo(model.OpenID,state, model.IotToken);
                    if (info != null)
                    {
                        this._RefreshToken(info, model);

                        JObject dev = (JObject)info["devInfo"];
                        JObject devStatus = info["devStatus"] as JObject;
                        JObject devAccount = (JObject)info["devAccount"];

                        model.DeviceID = new Guid(dev["deviceId"].Value<string>());
                        model.DeviceMac = state;
                        model.DevicePwd = dev["devicePw"].Value<string>();
                        model.Status = devAccount["isOnline"].Value<bool>() ? DevStatus.Normal : DevStatus.Abnormal;
                        model.OwnerName = devAccount["ownerName"].Value<string>();
                        model.Position = devAccount["position"].Value<string>();
                        double longitude, latitude;
                        double.TryParse(devAccount["longitude"].Value<string>(), out longitude);
                        double.TryParse(devAccount["latitude"].Value<string>(), out latitude);
                        model.Longitude = longitude;
                        model.Latitude = latitude;
                        if (devStatus != null&& devStatus["p"]!=null)
                        {
                            model.Attach = devStatus;
                        }
                        else
                        {
                            model.Attach = new JObject();
                            model.Attach.Add("p",135);
                        }

                        model.jsonAttach = IotInterface.GetMqttOptions(model).ToString();
                    }
                    else
                    {
                        model = null;
                    }
                }
            }

            return model;
        }
        private void _RefreshToken(JObject data, ShareProcessViewModel model)
        {
            IotInterface.RefreshToken(data, model);
        }
        private ActionResult ProcessOne(ShareProcessViewModel model)
        {
            model.Step = ShareStep.One;
            JObject consumehis = null;
            JArray chargelist = null;
            JObject info = IotInterface.PostGetChargeInfo(model.OpenID,model.DeviceID, model.IotToken);
            if (info != null)
            {
                this._RefreshToken(info, model);
                chargelist= (JArray)info["chargelist"];
                if (info["consumehis"] != null)
                {
                    JArray tmps = (JArray)info["consumehis"];
                    consumehis = tmps.Where(t => t["status"].Value<int>() == 1|| t["status"].Value<int>() == 2).OrderByDescending(t => t["createTime"].Value<long>()).FirstOrDefault() as JObject;
                }
                model.FeedbackTitle = AppHelper.GetFeedbackTitle();
                model.IotHost = APPConfig.IOT_Host;
                model.WxFollowUrl = AppHelper.GetWxFollowUrl();
            }
            else
            {
                return this.ResultError("获取设备状态异常");
            }
            if (consumehis!=null)
            {
                int chips = consumehis["chips"].Value<int>();
                JObject jotype = chargelist.Where(t => t["chips"].Value<int>() == chips).FirstOrDefault() as JObject;
                if (jotype != null)
                {
                    long billBeing = consumehis["billBeing"].Value<long>();
                    DateTime dt_billBeing = IotInterface.ToDateTime(billBeing);
                    long billExport = consumehis["billExport"].Value<long>();
                    DateTime dt_billExport = IotInterface.ToDateTime(billExport);
                    if (dt_billExport.AddMinutes(APPConfig.USE_CUETIMEOUT) > DateTime.Now)
                    {
                        model.Attach.Add("Use_typeName", jotype["typeName"].Value<string>());
                        model.Attach.Add("Use_totalFree", IotInterface.ToTotalFree(consumehis["totalFree"].Value<int>()));
                        model.Attach.Add("Use_chips", AppHelper.CreateChipsText(consumehis["chips"].Value<int>()));
                        model.Attach.Add("Use_datetime", AppHelper.CreateChipsText((int)(dt_billExport - DateTime.Now).TotalMinutes));
                        model.Attach.Add("Use_billBeing", dt_billBeing.ToString("yyyy年MM月dd日 HH时mm分"));
                        model.Step = ShareStep.Use;
                        if (dt_billExport > DateTime.Now)
                        {
                            model.IsUse = true;
                        }
                        else
                        {
                            model.IsUse = false;
                        }
                    }
                }
            }
            model.PayStartTime = DateTime.Now;
            this.ModelState.Clear();
            return this.View(model);
        }
        private ActionResult ProcessTwo(ShareProcessViewModel model)
        {
            ActionResult view = null;
            JObject info = IotInterface.PostGetChargeInfo(model.OpenID,model.DeviceID, model.IotToken);
            if (info != null&& info["chargelist"]!=null)
            {
                this._RefreshToken(info, model);
                var cps = APPConfig.USE_ConsumptionPackage();
                foreach (var item in info["chargelist"])
                {
                    if (item["isValid"].Value<int>() == 1)
                    {
                        ShareCharge charge = new ShareCharge()
                        {
                            Chips = item["chips"].Value<int>(),
                            Price = item["price"].Value<int>(),
                            Disp_No = item["dispNo"].Value<int>(),
                            Type_Name = item["typeName"].Value<string>()
                        };
                        var p = AppHelper.CreateChipsText(cps, item["chargeType"].Value<string>(), charge.Price);
                        charge.ChipsTitle = Math.Round(charge.Price/100D, 2).ToString("#0.00");
                        if (p != null)
                        {
                            charge.ChipsText = p.ChipsText;
                            charge.TextKey = p.TextKey;
                        }
                        else
                        {
                            charge.ChipsText = AppHelper.CreateChipsText(charge.Chips);
                            charge.TextKey = 0;
                        }
                        model.Types.Add(charge);
                    }
                }
                model.Types = model.Types.OrderBy(t => t.Disp_No).ToList();
                model.PayCondition = AppHelper.CreatePayCondition(model);
                model.Step = ShareStep.Two;
                this.ModelState.Clear();
                view = this.View(model);
            }
            else
            {
                return this.ResultError("获取付费套餐异常");
            }
            return view;
        }
        private ActionResult ProcessThree(ShareProcessViewModel model)
        {
            ActionResult view = null;
            model.Attach = JObject.Parse(model.jsonAttach);

            JObject pay = new JObject();
            pay.Add("deviceId", model.DeviceID);
            pay.Add("totalFree",model.Payment);
            pay.Add("chips", model.Chips);
            pay.Add("type", "1");
            pay.Add("status", "0");

            //超时计算
            if (model.PayStartTime <= DateTime.Parse("2017-01-01"))
            {
                model.PayStartTime = DateTime.Now.AddMinutes(-(APPConfig.USE_PAYTIMEOUT/2));
            }
            var time = DateTime.Now - model.PayStartTime;
            if (time.TotalMinutes > APPConfig.USE_PAYTIMEOUT)
            {
                return this.ResultError("支付操作超时");
            }
            else
            {
                model.PayTimeKey = (int)(APPConfig.USE_PAYTIMEOUT*60000 - time.TotalMilliseconds);
            }

            JObject OrderNo = IotInterface.PostPreBill(model.OpenID,pay, model.IotToken);
            if (OrderNo != null)
            {
                this._RefreshToken(OrderNo, model);
                model.OrderNo = OrderNo["orderNo"].Value<string>();
                string out_trade_no = model.OrderNo.Replace("-",string.Empty);

                JObject options = IotInterface.GetMqttOptions(model);
                model.jsonAttach = options.ToString();
                this.WeChatPayConfig(model, out_trade_no);

                if (!string.IsNullOrWhiteSpace(model.PrepayId)&& !string.IsNullOrWhiteSpace(model.JsSdkConfig)&& !string.IsNullOrWhiteSpace(model.ChooseWXPay))
                {
                    model.Attach.Add("Chips", Math.Round(model.Payment / 100D, 2).ToString("#0.00"));
                    model.Attach.Add("DateTime", DateTime.Now.ToString("yyyy年MM月dd日 HH时mm分"));

                    model.Step = ShareStep.Three;
                    this.ModelState.Clear();
                    view = this.View(model);
                }
                else
                {
                    return this.ResultError("共享付费下单异常");
                }
            }
            else
            {
                return this.ResultError("共享付费下单异常");
            }

            return view;
        }
        private void WeChatPayConfig(ShareProcessViewModel model,string out_trade_no)
        {
            //格式固定，不可修改
            string attach = string.Format(@"DeviceID#{0}@Chips#{1}", model.DeviceID, model.Chips);
            model.PrepayId = TencentHelper.CreateUnifiedorder(model.Payment, out_trade_no, model.OpenID, AppHelper.GetClientIP(this.Request), attach);
            if (!string.IsNullOrWhiteSpace(model.PrepayId))
            {
                JObject config = TencentHelper.CreateJSSDKConfig();
                if (config != null)
                {
                    model.JsSdkConfig = config.ToString();
                    WxPayData pay = new WxPayData();
                    pay.Create_chooseWXPay(model.PrepayId);
                    model.ChooseWXPay = pay.To_chooseWXPay().ToString();
                }
            }
        }
        private ActionResult ProcessFour(ShareProcessViewModel model)
        {
            model.Attach = IotInterface.GetMqttOptions(model);
            //获取城市天气
            JObject w = IotInterface.GetCityWeather(model.Longitude, model.Latitude);
            if (w != null)
            {
                model.jsonAttach = w.ToString();
            }
            model.Step = ShareStep.Four;
            model.FeedbackTitle = AppHelper.GetFeedbackTitle();
            model.IotHost = APPConfig.IOT_Host;
            model.WxFollowUrl = AppHelper.GetWxFollowUrl();
            this.ModelState.Clear();
            ActionResult view = this.View(model);
            return view;
        }
    }
}