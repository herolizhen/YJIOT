using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Xml.Linq;

namespace Tencent
{
    /// <summary>
    /// 微信报文
    /// </summary>
    public class WxReport: XElement
    {
        public WxReport() : base("xml")
        {

        }

        public static new WxReport Parse(string text)
        {
            WxReport rp = new WxReport();
            
            return rp;
        }


    }
}