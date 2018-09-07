using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using YJIOT.ShareAirAPP.Service;
using YJIOT.ShareAirAPP.ViewModel;

namespace YJIOT.ShareAirAPP.Controllers
{
    public class ManageController : Controller
    {
        // GET: Manage
        public ActionResult Index()
        {
            ShareProcessViewModel model = new ShareProcessViewModel();
            return View(model);
        }
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Operation(ShareProcessViewModel model)
        {
            string username = ConfigurationManager.AppSettings["USE:ManageUserName"];
            string password = ConfigurationManager.AppSettings["USE:ManagePassword"];
            string openid = ConfigurationManager.AppSettings["USE:ManageOpenID"];
            if (model.OpenID != username || model.DevicePwd != password)
            {
                return this.RedirectToActionPermanent("Index", "Manage");
            }
            string token = IotInterface.RefreshToken(openid);
            if (!string.IsNullOrWhiteSpace(token))
            {
                model.IotToken = token;
                model.OpenID = openid;
                model.DevicePwd = string.Empty;
                JObject config = IotInterface.GetMqttOptions(model);
                model.jsonAttach = config.ToString();
            }
            else
            {
                return this.RedirectToActionPermanent("Index", "Manage");
            }
            this.ModelState.Clear();
            return View(model);
        }
    }
}