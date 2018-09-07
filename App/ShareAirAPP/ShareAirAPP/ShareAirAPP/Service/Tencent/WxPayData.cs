using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Web;
using System.Xml;
using YJIOT.ShareAirAPP.Service;

namespace Tencent
{
    /// <summary>
    /// 微信支付协议接口数据类，所有的API接口通信都依赖这个数据结构，
    /// 在调用接口之前先填充各个字段的值，然后进行接口通信，
    /// 这样设计的好处是可扩展性强，用户可随意对协议进行更改而不用重新设计数据结构，
    /// 还可以随意组合出不同的协议数据包，不用为每个协议设计一个数据包结构
    /// </summary>
    public class WxPayData
    {
        public WxPayData()
        {

        }

        //采用排序的Dictionary的好处是方便对数据包进行签名，不用再签名之前再做一次排序
        private SortedDictionary<string, object> m_values = new SortedDictionary<string, object>();

        /**
        * 设置某个字段的值
        * @param key 字段名
         * @param value 字段值
        */
        public void SetValue(string key, object value)
        {
            m_values[key] = value;
        }

        /**
        * 根据字段名获取某个字段的值
        * @param key 字段名
         * @return key对应的字段值
        */
        public object GetValue(string key)
        {
            object o = null;
            m_values.TryGetValue(key, out o);
            return o;
        }

        /**
         * 判断某个字段是否已设置
         * @param key 字段名
         * @return 若字段key已被设置，则返回true，否则返回false
         */
        public bool IsSet(string key)
        {
            object o = null;
            m_values.TryGetValue(key, out o);
            if (null != o)
                return true;
            else
                return false;
        }

        /**
        * @将Dictionary转成xml
        * @return 经转换得到的xml串
        * @throws WxPayException
        **/
        public string ToXml()
        {
            //数据为空时不能转化为xml格式
            if (0 == m_values.Count)
            {
                return string.Empty;
            }

            string xml = "<xml>";
            foreach (KeyValuePair<string, object> pair in m_values)
            {
                //字段值不能为null，会影响后续流程
                if (pair.Value == null)
                {
                    return string.Empty;
                }

                if (pair.Value.GetType() == typeof(int))
                {
                    xml += "<" + pair.Key + ">" + pair.Value + "</" + pair.Key + ">";
                }
                else if (pair.Value.GetType() == typeof(string))
                {
                    xml += "<" + pair.Key + ">" + "<![CDATA[" + pair.Value + "]]></" + pair.Key + ">";
                }
                else//除了string和int类型不能含有其他数据类型
                {
                    return string.Empty;
                }
            }
            xml += "</xml>";
            return xml;
        }

        public JObject To_chooseWXPay()
        {
            JObject config = new JObject();
            config.Add("timestamp", Convert.ToInt64(this.GetValue("timeStamp")));
            config.Add("nonceStr", (string)this.GetValue("nonceStr"));
            config.Add("package", (string)this.GetValue("package"));
            config.Add("signType", (string)this.GetValue("signType"));
            config.Add("paySign", (string)this.GetValue("paySign"));
            return config;
        }

        /**
        * @获取Dictionary
        */
        public SortedDictionary<string, object> GetValues()
        {
            return m_values;
        }
        /// <summary>
        /// 构建统一下单
        /// </summary>
        /// <param name="total_fee">钱</param>
        /// <param name="out_trade_no">本地订单号</param>
        /// <param name="openid"></param>
        /// <param name="spbill_create_ip">客户端IP</param>
        /// <param name="body">商品描述</param>
        /// <param name="attach">附件信息</param>
        public void CreateUnifiedorder(int total_fee,string out_trade_no, string openid, string spbill_create_ip, string body,string attach)
        {
            this.SetValue("appid", APPConfig.Tencent_APPID);
            this.SetValue("mch_id", APPConfig.Tencent_MCHID);
            this.SetValue("nonce_str", APPConfig.GenerateNonceStr());
            this.SetValue("sign_type", "MD5");
            this.SetValue("body", body);
            this.SetValue("attach", attach);
            this.SetValue("device_info", "WEB");
            this.SetValue("out_trade_no", out_trade_no);
            this.SetValue("fee_type", "CNY");
            this.SetValue("total_fee", total_fee);
            this.SetValue("spbill_create_ip", spbill_create_ip);
            this.SetValue("notify_url", APPConfig.Tencent_NOTIFY_URL);
            this.SetValue("trade_type", "JSAPI");
            this.SetValue("openid", openid);
        }
        /// <summary>
        /// 构建JS-SDK配置
        /// </summary>
        /// <param name="prepay_id"></param>
        public void Create_chooseWXPay(string prepay_id)
        {
            this.SetValue("appId", APPConfig.Tencent_APPID);
            this.SetValue("timeStamp", APPConfig.GenerateTimeStamp());
            this.SetValue("nonceStr", APPConfig.GenerateNonceStr());
            this.SetValue("package", "prepay_id=" + prepay_id);
            this.SetValue("signType", "MD5");
            this.SetValue("paySign", GenerateMD5Sign());
        }
        /// <summary>
        /// 构建下单签名
        /// </summary>
        public void CreateUnifiedorderSign()
        {
            this.SetValue("sign", GenerateMD5Sign());
        }
        public string GenerateMD5Sign()
        {
            string sign = string.Empty;
            StringBuilder stmp = new StringBuilder();
            foreach (var item in GetValues())
            {
                if (item.Value != null)
                {
                    stmp.AppendFormat("&{0}={1}", item.Key, item.Value);
                }
            }
            stmp.Remove(0, 1);
            stmp.AppendFormat("&key={0}", APPConfig.Tencent_MCHKEY);
            sign = Cryptography.GetMd5Hash(stmp.ToString()).ToUpper();
            return sign;
        }
    }
}