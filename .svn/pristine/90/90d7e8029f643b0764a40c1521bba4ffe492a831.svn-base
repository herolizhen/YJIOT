using Aop.Api.Response;
using Newtonsoft.Json.Linq;
using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using YJIOT.ShareAirAPP.Models;
using YJIOT.ShareAirAPP.Service;
using YJIOT.ShareAirAPP.ViewModel;

namespace YJIOT.ShareAirAPP.Controllers
{
    /// <summary>
    /// 支付宝应用
    /// </summary>
    public partial class AlipayController : Controller
    {
        public ActionResult Index()
        {
            ActionResult view = null;
            ShareProcessViewModel model = null;

            //支付宝支付回调界面
            var tmp = AlipayHelper.CeateAlipayReturn(this.Request);
            if (tmp != null)
            {
                model = tmp;
                return this.ProcessFour(model);
            }

            string mac = this.Request.QueryString["mac"];
            if (!string.IsNullOrWhiteSpace(mac))
            {
                mac = mac.ToUpper();
                return this.RedirectPermanent(this.Aauth(mac));
            }
            string app_id = this.Request.QueryString["app_id"];
            string auth_code = this.Request.QueryString["auth_code"];
            string state = this.Request.QueryString["state"];
            if (app_id != APPConfig.Alipay_APPID)
            {
                return this.ResultError("用户登录异常");
            }
            else
            {
                if (!string.IsNullOrWhiteSpace(auth_code) && !string.IsNullOrWhiteSpace(state))
                {
                    model = this.Aauth(auth_code, state);
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
            }
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
                            model.Attach.Add("p", 150);
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
            string aauth = AlipayHelper.CreateOAuthUrl(mac);
            return aauth;
        }
        private ShareProcessViewModel Aauth(string auth_code, string state)
        {
            ShareProcessViewModel model = null;
            var user = AlipayHelper.alipay_system_oauth_token(auth_code);
            if (user != null)
            {
                JObject raw = new JObject();
                raw.Add("openid", user.UserId);
                raw.Add("tel", user.Mobile);
                raw.Add("nickname", AppHelper.FilterEmoji(user.NickName));
                raw.Add("sex", user.CertType);
                raw.Add("city", user.City);
                raw.Add("country", user.CountryCode);
                raw.Add("province", user.Province);
                raw.Add("language", "");
                raw.Add("headimgurl", user.Avatar);
                raw.Add("remark", "支付宝用户");
                raw.Add("tagidList", "");
                raw.Add("type", "2");
                raw.Add("password", "");
                raw.Add("appId", APPConfig.USE_APPID);

                JObject token = IotInterface.PostRegister(raw);
                if (token != null)
                {
                    model = new ShareProcessViewModel();
                    model.OpenID = user.UserId;
                    model.IotToken = token["token"].Value<string>();
                    JObject info = IotInterface.PostGetDevInfo(model.OpenID,state, model.IotToken);
                    if (info != null)
                    {
                        IotInterface.RefreshToken(info, model);

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
                        if (devAccount != null && devAccount["p"] != null)
                        {
                            model.Attach = devAccount;
                        }
                        else
                        {
                            model.Attach = new JObject();
                            model.Attach.Add("p", 135);
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
        private ActionResult ProcessOne(ShareProcessViewModel model)
        {
            model.Step = ShareStep.One;
            JObject consumehis = null;
            JArray chargelist = null;
            JObject info = IotInterface.PostGetChargeInfo(model.OpenID,model.DeviceID, model.IotToken);
            if (info != null)
            {
                IotInterface.RefreshToken(info, model);
                chargelist = (JArray)info["chargelist"];
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
            if (consumehis != null)
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
            this.ModelState.Clear();
            return this.View(model);
        }
        private ActionResult ProcessTwo(ShareProcessViewModel model)
        {
            ActionResult view = null;
            JObject info = IotInterface.PostGetChargeInfo(model.OpenID,model.DeviceID, model.IotToken);
            if (info != null && info["chargelist"] != null)
            {
                IotInterface.RefreshToken(info, model);
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
                        charge.ChipsTitle = Math.Round(charge.Price / 100D, 2).ToString("#0.00");
                        charge.ChipsText = AppHelper.CreateChipsText(charge.Chips);
                        model.Types.Add(charge);
                    }
                }
                model.Types = model.Types.OrderBy(t => t.Disp_No).ToList();
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
            pay.Add("totalFree", model.Payment);
            pay.Add("chips", model.Chips);
            pay.Add("type", "2");
            pay.Add("status", "0");

            JObject OrderNo = IotInterface.PostPreBill(model.OpenID,pay, model.IotToken);
            if (OrderNo != null)
            {
                IotInterface.RefreshToken(OrderNo, model);
                model.OrderNo = OrderNo["orderNo"].Value<string>();
                string out_trade_no = model.OrderNo.Replace("-", string.Empty);

                JObject options = IotInterface.GetMqttOptions(model);
                model.jsonAttach = options.ToString();

                AlipayTradeWapPayResponse alipay = AlipayHelper.alipay_trade_wap_pay(model, out_trade_no);

                if (alipay != null)
                {
                    model.Attach.Add("Chips", Math.Round(model.Payment / 100D, 2).ToString("#0.00"));
                    model.Attach.Add("DateTime", DateTime.Now.ToString("yyyy年MM月dd日 HH时mm分"));

                    model.AlipayForm=alipay.Body.Replace("<script>document.forms['alipaysubmit'].submit();</script>", string.Empty);

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