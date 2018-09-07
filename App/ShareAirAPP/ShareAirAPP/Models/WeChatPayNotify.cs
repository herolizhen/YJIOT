using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Xml.Linq;
using YJIOT.ShareAirAPP.Service;

namespace YJIOT.ShareAirAPP.Models
{
    /// <summary>
    /// 微信支付通知
    /// </summary>
    public class WeChatPayNotify
    {
        /// <summary>
        /// 对象是否为空
        /// </summary>
        public bool IsEmpty { get; private set; } = true;
        /// <summary>
        /// 设备ID
        /// </summary>
        public Guid DeviceID { get; private set; }
        /// <summary>
        /// 交易设备时间长筹码
        /// </summary>
        public int Chips { get; private set; }
        /// <summary>
        /// 公众账号ID
        /// </summary>
        public string appid { get; private set; }
        /// <summary>
        /// 付款银行
        /// </summary>
        public string bank_type { get; private set; }
        /// <summary>
        /// 现金支付金额
        /// </summary>
        public int cash_fee { get; private set; }
        /// <summary>
        /// 设备号
        /// </summary>
        public string device_info { get; private set; }
        /// <summary>
        /// 货币种类 CNY
        /// </summary>
        public string fee_type { get; private set; }
        /// <summary>
        /// 是否关注公众账号 Y
        /// </summary>
        public string is_subscribe { get; private set; }
        /// <summary>
        /// 商户号
        /// </summary>
        public string mch_id { get; private set; }
        /// <summary>
        /// 随机字符串
        /// </summary>
        public string nonce_str { get; private set; }
        /// <summary>
        /// 用户标识
        /// </summary>
        public string openid { get; private set; }
        /// <summary>
        /// 商户订单号
        /// </summary>
        public string out_trade_no { get; private set; }
        /// <summary>
        /// 业务结果 SUCCESS
        /// </summary>
        public string result_code { get; private set; }
        /// <summary>
        /// 返回状态码 SUCCESS
        /// </summary>
        public string return_code { get; private set; }
        /// <summary>
        /// 签名
        /// </summary>
        public string sign { get; private set; }
        /// <summary>
        /// 支付完成时间
        /// </summary>
        public long time_end { get; private set; }
        /// <summary>
        /// 订单金额
        /// </summary>
        public int total_fee { get; private set; }
        /// <summary>
        /// 交易类型 	JSAPI
        /// </summary>
        public string trade_type { get; private set; }
        /// <summary>
        /// 微信支付订单号
        /// </summary>
        public string transaction_id { get; private set; }

        /// <summary>
        /// 构建
        /// </summary>
        /// <param name="xml"></param>
        public void Create(string xml)
        {
            this.IsEmpty = true;
            try
            {
                XDocument doc= XDocument.Parse(xml);
                this.return_code = doc.Root.Element("return_code").Value;
                if (this.return_code == "SUCCESS")
                {
                    this.result_code = doc.Root.Element("result_code").Value;
                    this.trade_type = doc.Root.Element("trade_type").Value;
                    if (this.result_code == "SUCCESS" && this.trade_type== "JSAPI")
                    {
                        string attach = doc.Root.Element("attach").Value;
                        var dic = TencentHelper.GetKeyValue(attach);
                        this.DeviceID = new Guid(dic["DeviceID"]);
                        this.Chips = int.Parse(dic["Chips"]);
                        this.appid = doc.Root.Element("appid").Value;
                        this.bank_type = doc.Root.Element("bank_type").Value;
                        this.cash_fee = int.Parse(doc.Root.Element("cash_fee").Value);
                        this.device_info = doc.Root.Element("device_info").Value;
                        this.fee_type = doc.Root.Element("fee_type").Value;
                        this.is_subscribe = doc.Root.Element("is_subscribe").Value;
                        this.mch_id = doc.Root.Element("mch_id").Value;
                        this.nonce_str = doc.Root.Element("nonce_str").Value;
                        this.openid = doc.Root.Element("openid").Value;
                        this.out_trade_no = (new Guid(doc.Root.Element("out_trade_no").Value)).ToString();
                        this.sign = doc.Root.Element("sign").Value;
                        this.time_end = long.Parse(doc.Root.Element("time_end").Value);
                        this.total_fee = int.Parse(doc.Root.Element("total_fee").Value);
                        this.transaction_id = doc.Root.Element("transaction_id").Value;
                        this.IsEmpty = false;
                    }
                }
            }
            catch (Exception ex)
            {
                this.IsEmpty = true;
            }
        }
    }
}