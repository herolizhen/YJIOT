using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using YJIOT.ShareAirAPP.Models;
using YJIOT.ShareAirAPP.Service;

namespace YJIOT.ShareAirAPP.ViewModel
{
    public class ShareProcessViewModel
    {
        public ShareStep Step { get; set; }
        public DateTime PayStartTime { get; set; }
        public string OpenID { get; set; }
        public Guid ClientId { get; set; }
        public string IotToken { get; set; }
        public Guid DeviceID { get; set; }
        public string DevicePwd { get; set; }
        public string DeviceMac { get; set; }
        public string OwnerName { get; set; }
        public string Position { get; set; }
        public DevStatus Status { get; set; }
        public string jsonAttach { get; set; }
        public JObject Attach { get; set; }
        public double Longitude { get; set; }
        public double Latitude { get; set; }
        //FeedbackTitle
        public List<string> FeedbackTitle { get; set; }
        //Use
        public bool IsUse { get; set; }
        //One
        public bool IsAgree { get; set; }
        //Two
        public List<ShareCharge> Types { get; set; } = new List<ShareCharge>();
        public int Payment { get; set; }
        public int Chips { get; set; }
        public string jsonTwo { get; set; }
        //Three
        public string PrepayId { get; set; }
        public string OrderNo { get; set; }
        public string JsSdkConfig { get; set; }
        public string ChooseWXPay { get; set; }
        public string AlipayForm { get; set; }
        public string PayCondition { get; set; }
        public int PayTimeKey { get; set; }
        //Error
        public string ErrorText { get; set; }
        //Iot
        public string IotHost { get; set; }
        public string WxFollowUrl { get; set; }
        public int ToJsDevStatus()
        {
            return (int)this.Status;
        }
    }
}