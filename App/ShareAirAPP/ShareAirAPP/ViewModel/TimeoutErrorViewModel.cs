using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using YJIOT.ShareAirAPP.Models;

namespace YJIOT.ShareAirAPP.ViewModel
{
    public class TimeoutErrorViewModel
    {
        public ShareStep Step { get; set; }
        // Four
        public string OrderNo { get; set; }
        public string PayNo { get; set; }
        public int Payment { get; set; }
        public string StrPayment { get; set; }
        public string PayTime { get; set; }
        public int Chips { get; set; }
    }
}