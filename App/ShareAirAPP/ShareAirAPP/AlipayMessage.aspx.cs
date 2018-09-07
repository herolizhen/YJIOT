using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using YJIOT.ShareAirAPP.Service;

namespace YJIOT.ShareAirAPP
{
    public partial class AlipayMessage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            var dic = AlipayHelper.AlipayNotify(this.Request);
            if (dic.Count > 0)
            {
                bool yes = AlipayHelper.ConfirmPay(dic);
                if (yes)
                {
                    this.Response.Write("success");
                }
                else
                {
                    this.Response.Write("error");
                }
            }
            else
            {
                this.Response.Write("error");
            }
            this.Response.End();
        }
    }
}