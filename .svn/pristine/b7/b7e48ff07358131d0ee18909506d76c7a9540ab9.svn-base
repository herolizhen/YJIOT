using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using YJIOT.ShareAirAPP.Service;
using YJIOT.ShareAirAPP.ViewModel;

namespace YJIOT.ShareAirAPP.Controllers
{
    public class TimeoutErrorController : Controller
    {
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Index(ShareProcessViewModel model)
        {
            TimeoutErrorViewModel error = new TimeoutErrorViewModel();

            JObject info = IotInterface.PostGetChargeInfo(model.OpenID,model.DeviceID, model.IotToken);
            JObject consumehis = null;
            if (info != null)
            {
                IotInterface.RefreshToken(info, model);
                if (info["consumehis"] != null)
                {
                    JArray tmps = (JArray)info["consumehis"];
                    consumehis = tmps.Where(t => t["status"].Value<int>() == 1).OrderByDescending(t => t["createTime"].Value<long>()).FirstOrDefault() as JObject;
                }
            }
            if (consumehis != null)
            {
                long billBeing = consumehis["billBeing"].Value<long>();
                DateTime dt_billBeing = IotInterface.ToDateTime(billBeing);
                long billExport = consumehis["billExport"].Value<long>();
                DateTime dt_billExport = IotInterface.ToDateTime(billExport);
                if (dt_billExport > DateTime.Now)
                {
                    error.Step = model.Step;
                    error.OrderNo = consumehis["orderNo"].Value<string>();
                    error.OrderNo = error.OrderNo.Replace("-",string.Empty);
                    error.PayNo = consumehis["payNo"].Value<string>();
                    error.Payment = consumehis["totalFree"].Value<int>();
                    error.StrPayment = Math.Round(error.Payment / 100D, 2).ToString("#0.00");
                    error.Chips = consumehis["chips"].Value<int>();
                    error.PayTime = dt_billBeing.ToString("yyyy年MM月dd日 HH时mm分");
                }
            }

            this.ModelState.Clear();
            return this.View(error);
        }
    }
}