using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace YJIOT.ShareAirAPP.Models
{
    /// <summary>
    /// 缴费条件
    /// </summary>
    public class PayCondition
    {
        /// <summary>
        /// 用户
        /// </summary>
        public string OpenID { get; set; }
        /// <summary>
        /// 设备
        /// </summary>
        public Guid DeviceID { get; set; }
        /// <summary>
        /// 根据条件（此_Pay）是否可以缴费
        /// </summary>
        public bool Is_Pay { get; set; }
        /// <summary>
        /// 计算费用
        /// </summary>
        public int _Pay { get; set; }
        /// <summary>
        /// 允许次数
        /// </summary>
        public int _Count { get; set; }
        /// <summary>
        /// 限定时长（分钟）
        /// </summary>
        public int _Time { get; set; }
    }
}