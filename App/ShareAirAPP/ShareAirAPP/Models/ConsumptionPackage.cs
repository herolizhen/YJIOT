using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace YJIOT.ShareAirAPP.Models
{
    /// <summary>
    /// 消费套餐
    /// </summary>
    public class ConsumptionPackage
    {
        public string TypeKey { get; set; }
        public List<Package> Packages { get; set; }
        /// <summary>
        /// 套餐展示内容
        /// </summary>
        public class Package
        {
            public int Price { get; set; }
            public string ChipsText { get; set; }
            public int TextKey { get; set; }
        }
    }
}