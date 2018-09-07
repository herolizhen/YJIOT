
using Aop.Api.Response;
using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Web;
using System.Web.Mvc;
using System.Web.Routing;
using YJIOT.ShareAirAPP.Models;
using YJIOT.ShareAirAPP.ViewModel;

namespace YJIOT.ShareAirAPP.Service
{
    public sealed partial class AppHelper
    {
        public static string FilterEmoji(string txt)
        {
            string str = string.Empty;
            if (!string.IsNullOrWhiteSpace(txt))
            {
                str = Regex.Replace(txt, @"\p{Cs}", string.Empty);
            }
            return str;
        }

        public static string GetClientIP(HttpRequestBase request)
        {
            string ip = string.Empty;

            if (!string.IsNullOrWhiteSpace(request.Headers["X-Forwarded-For"]))
            {
                ip = request.Headers["X-Forwarded-For"];
            }

            return ip;
        }

        public static string GetWxFollowUrl()
        {
            return ConfigurationManager.AppSettings["USE:WxFollow"].Replace("&amp;", "&");
        }

        public static List<string> GetFeedbackTitle()
        {
            string[] titles = ConfigurationManager.AppSettings["USE:FeedbackTitle"].Split(',');
            return titles.ToList();
        }

        public static string CreateChipsText(int Chips)
        {
            string text = string.Empty;

            if (Chips <= 60)
            {
                text = string.Format("{0}分钟",Chips);
            }
            else
            {
                int h = Chips / 60;
                int m = Chips - h * 60;
                if (m > 0)
                {
                    text = string.Format("{0}小时{1}分钟",h,m);
                }
                else
                {
                    text = string.Format("{0}小时", h);
                }
            }

            return text;
        }

        public static void DebugException(object message)
        {
            ThreadPool.QueueUserWorkItem(QueueUserWorkItem,message);
        }
        private static void QueueUserWorkItem(object state)
        {
            string text = string.Empty;
            string filename = string.Empty;
            string dir = ConfigurationManager.AppSettings["USE:DebugException"];
            if(state!=null)
            {
                text = state.ToString();
            }
            if (!string.IsNullOrWhiteSpace(text))
            {
                dir = string.Format(@"{0}\{1}", dir, DateTime.Now.ToString("yyyy-MM-dd"));
                if (state is Exception)
                {
                    filename = string.Format(@"{0}\ex_{1}.txt", dir, DateTime.Now.ToFileTime());
                }
                else
                {
                    filename = string.Format(@"{0}\log_{1}.txt", dir, DateTime.Now.ToFileTime());
                }
                try
                {
                    if (!Directory.Exists(dir))
                    {
                        Directory.CreateDirectory(dir);
                    }
                    File.WriteAllText(filename, text, Encoding.UTF8);
                }
                catch (Exception ex) { }
            }
        }
    }
}