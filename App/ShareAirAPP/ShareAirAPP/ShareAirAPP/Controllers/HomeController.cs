using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Routing;
using YJIOT.ShareAirAPP.Service;

namespace YJIOT.ShareAirAPP.Controllers
{
    public class HomeController : Controller
    {
        public ActionResult Default()
        {
            RouteValueDictionary routeValues = new RouteValueDictionary();
            string mac = this.Request.QueryString["mac"];
            if (!string.IsNullOrWhiteSpace(mac))
            {
                routeValues.Add("mac",mac);
            }
            string key = this.Request.UserAgent;
            if (key.ToLower().Contains("micromessenger"))
            {
                return this.RedirectToActionPermanent("Index", "WeChat", routeValues);
            }
            else if(key.ToLower().Contains("alipay"))
            {
                return this.RedirectToActionPermanent("Index", "Alipay", routeValues);
            }
            return this.View();
        }
    }
}