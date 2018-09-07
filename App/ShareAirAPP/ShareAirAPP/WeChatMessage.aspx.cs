using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using YJIOT.ShareAirAPP.Models;
using YJIOT.ShareAirAPP.Service;

namespace YJIOT.ShareAirAPP
{
    public partial class WeChatMessage : System.Web.UI.Page
    {
        private const string Success = "SUCCESS";
        private const string Fall = "FAIL";

        protected void Page_Load(object sender, EventArgs e)
        {
            string response = Success;
            StringBuilder log = new StringBuilder();
            string message = TencentHelper.CreateCallBackMessage(this.Request);
            log.Append("NOTIFY:\r\n");
            log.Append(message);
            log.Append("\r\nQueryString:\r\n");
            foreach (string key in this.Request.QueryString.Keys)
            {
                log.AppendFormat("{0}={1}\r\n",key,this.Request.QueryString[key]);
            }
            //AppHelper.DebugException(log.ToString());
            string echostr = this.Request.QueryString["echostr"];
            if (!string.IsNullOrWhiteSpace(echostr))
            {
                response = echostr;
            }
            if (!string.IsNullOrWhiteSpace(message))
            {
                WeChatPayNotify pay = new WeChatPayNotify();
                pay.Create(message);
                if (!pay.IsEmpty)
                {
                    bool yes = TencentHelper.ConfirmPay(pay);

                    string trade_no = pay.transaction_id;
                    string fname = string.Format("Wx_{0}", trade_no);
                    AppHelper.SavePayLog(fname, message);

                    if (yes)
                    {
                        response = Success;
                    }
                    else
                    {
                        response = Fall;
                    }
                }
            }

            this.Response.Write(response);
            this.Response.End();
        }
    }
}