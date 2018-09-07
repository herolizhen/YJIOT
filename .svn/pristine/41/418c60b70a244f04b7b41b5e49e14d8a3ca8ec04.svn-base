using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using YJIOT.ShareAirAPP.Service;

namespace YJIOT.ShareAirAPP.Controllers
{
    public partial class WeChatController
    {
        private ActionResult ResultError(string error)
        {
            Exception ex = new Exception(error + "+WeChatController:" + AppHelper.GetClientIP(this.Request));
            AppHelper.DebugException(ex);
            this.ViewBag.Error = error;
            return this.View("Error");
        }
    }
    public partial class AlipayController
    {
        private ActionResult ResultError(string error)
        {
            Exception ex = new Exception(error + "+AlipayController:" + AppHelper.GetClientIP(this.Request));
            AppHelper.DebugException(ex);
            this.ViewBag.Error = error;
            return this.View("Error");
        }
    }
}