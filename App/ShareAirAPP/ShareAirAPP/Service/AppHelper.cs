
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
                text = string.Format("{0}分钟", Chips);
            }
            else
            {
                int h = Chips / 60;
                int m = Chips - h * 60;
                if (m > 0)
                {
                    text = string.Format("{0}小时{1}分钟", h, m);
                }
                else
                {
                    text = string.Format("{0}小时", h);
                }
            }

            return text;
        }
        public static ConsumptionPackage.Package CreateChipsText(List<ConsumptionPackage> cps, string chargeType, int Price)
        {
            ConsumptionPackage.Package text = null;

            foreach (var cp in cps)
            {
                if (cp.TypeKey == chargeType)
                {
                    text = cp.Packages.Where(t => t.Price == Price).FirstOrDefault();
                    break;
                }
            }

            return text;
        }

        public static string CreatePayCondition(ShareProcessViewModel model)
        {
            JArray pay = new JArray();

            List<PayCondition> pcs = APPConfig.USE_PayCondition;
            if (pcs.Count > 0)
            {
                JObject data = IotInterface.PostGetChargeInfo(model.OpenID, model.DeviceID, model.IotToken);
                if (data != null && data["consumehis"] != null)
                {
                    DateTime dt = DateTime.Now;
                    foreach (var pc in pcs)
                    {
                        int count = 0;
                        foreach (var v in (JArray)data["consumehis"])
                        {
                            int totalFree = v["totalFree"].Value<int>();
                            int status = v["status"].Value<int>();
                            if (status == 2 && totalFree == pc._Pay)
                            {
                                DateTime billBeing = IotInterface.ToDateTime(v["billBeing"].Value<long>());
                                if (pc._Time > (dt - billBeing).TotalMinutes)
                                {
                                    count++;
                                }
                            }
                        }
                        if (count >= pc._Count)
                        {
                            JObject key = new JObject();
                            key.Add("IsPay", true);
                            key.Add("totalFree", pc._Pay);
                            key.Add("Count", pc._Count);
                            key.Add("Time", pc._Time);
                            pay.Add(key);
                        }
                    }
                }
            }

            return pay.ToString();
        }

        public static void DebugException(object message)
        {
            ThreadPool.QueueUserWorkItem(QueueUserWorkItem, message);
        }
        private static void QueueUserWorkItem(object state)
        {
            string text = string.Empty;
            string filename = string.Empty;
            string dir = ConfigurationManager.AppSettings["USE:DebugException"];
            if (state != null)
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

        public static void SavePayLog(string fname, string message)
        {
            /*
            Dictionary<string, string> tmp = new Dictionary<string, string>();
            tmp.Add(fname, message);
            ThreadPool.QueueUserWorkItem((object state) =>
            {
                Dictionary<string, string> _tmp = state as Dictionary<string, string>;
                string text = _tmp.First().Value;
                string _fname = _tmp.First().Key;
                string filename = string.Empty;
                string dir = ConfigurationManager.AppSettings["USE:DebugException"];
                dir = string.Format(@"{0}\{1}", dir, DateTime.Now.ToString("yyyy-MM-dd"));
                filename = string.Format(@"{0}\{1}.txt", dir, _fname);
                try
                {
                    if (!Directory.Exists(dir))
                    {
                        Directory.CreateDirectory(dir);
                    }
                    File.WriteAllText(filename, text, Encoding.UTF8);
                }
                catch (Exception ex) { }
            }, tmp);
            */
        }
    }
}