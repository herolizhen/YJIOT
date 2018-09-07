using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Configuration;
using System.Text;
using System.Net.Http;
using System.Net.Http.Headers;
using Newtonsoft.Json.Linq;
using System.Net;
using System.Security.Cryptography.X509Certificates;
using System.Net.Security;
using System.Globalization;
using YJIOT.ShareAirAPP.ViewModel;

namespace YJIOT.ShareAirAPP.Service
{
    /// <summary>
    /// 易净物联网接口
    /// </summary>
    public partial class IotInterface
    {
        static IotInterface()
        {
            ServicePointManager.ServerCertificateValidationCallback = _RemoteCertificateValidationCallback;
        }
        private static bool _RemoteCertificateValidationCallback(object sender, X509Certificate certificate, X509Chain chain, SslPolicyErrors sslPolicyErrors)
        {
            return true;
        }
        private static HttpClient CreateClient(string jwt = "")
        {
            HttpClient client = new HttpClient();
            if (!string.IsNullOrWhiteSpace(jwt))
            {
                client.DefaultRequestHeaders.Authorization = AuthenticationHeaderValue.Parse(jwt);
            }
            client.DefaultRequestHeaders.Accept.Add(
                new System.Net.Http.Headers.MediaTypeWithQualityHeaderValue("application/json")
                );
            client.DefaultRequestHeaders.AcceptCharset.Add(
                new System.Net.Http.Headers.StringWithQualityHeaderValue("utf-8")
                );

            return client;
        }
        private static StringContent CreateContent(JObject raw)
        {
            string RAW = raw != null ? raw.ToString() : string.Empty;
            StringContent content = new StringContent(RAW, Encoding.UTF8, "application/json");

            return content;
        }
        private static JObject PostRaw(string openid, string url, JObject raw, string jwt = "")
        {
            JObject data = _PostRaw(url, raw, jwt);
            if (data != null)
            {
                if (!string.IsNullOrWhiteSpace(jwt))
                {
                    if (data["meta"] != null && data["meta"]["code"] != null && data["meta"]["code"].Value<int>() == 1000)
                    {
                        jwt = RefreshToken(openid);
                        data = _PostRaw(url, raw, jwt);
                        if (data != null)
                        {
                            data.Add("IotToken", jwt);
                        }
                    }
                }
            }
            return data;
        }
        private static JObject _PostRaw(string url, JObject raw, string jwt)
        {
            JObject ret = null;

            HttpClient client = CreateClient(jwt);
            StringContent content = CreateContent(raw);

            try
            {
                HttpResponseMessage Response = client.PostAsync(url, content).Result;
                if (Response.IsSuccessStatusCode)
                {
                    string json = Response.Content.ReadAsStringAsync().Result;
                    ret = JObject.Parse(json);
                }
            }
            catch (Exception ex)
            {
                ret = null;
                AppHelper.DebugException(ex);
            }

            return ret;
        }
        private static bool IsPostRaw(JObject raw)
        {
            bool yes = false;
            if (raw != null)
            {
                if (raw["meta"]["code"].Value<int>() == 0)
                {
                    yes = true;
                }
            }
            return yes;
        }
        private static JObject GetPostRawData(JObject raw)
        {
            JObject ret = (JObject)raw["data"];
            return ret;
        }
        /// <summary>
        /// 获取接口token
        /// </summary>
        /// <param name="openid"></param>
        /// <returns></returns>
        public static string RefreshToken(string openid)
        {
            string token = string.Empty;
            JObject ret = null;

            string url = ConfigurationManager.AppSettings["IOT:PostRefreshToken"];
            HttpClient client = CreateClient();
            JObject raw = new JObject();
            raw.Add("openid", openid);
            StringContent content = CreateContent(raw);
            try
            {
                HttpResponseMessage Response = client.PostAsync(url, content).Result;
                if (Response.IsSuccessStatusCode)
                {
                    string json = Response.Content.ReadAsStringAsync().Result;
                    ret = JObject.Parse(json);
                }
            }
            catch (Exception ex)
            {
                ret = null;
                AppHelper.DebugException(ex);
            }
            
            if (ret != null&&ret["meta"]!=null&&ret["meta"]["code"]!=null && ret["meta"]["code"].Value<int>()==0)
            {
                token = ret["data"]["token"].Value<string>();
            }

            return token;
        }
        public static void RefreshToken(JObject data, ShareProcessViewModel model)
        {
            if (data != null && data["IotToken"] != null)
            {
                model.IotToken = data["IotToken"].Value<string>();
            }
        }
        public static double ToTotalFree(int totalFree)
        {
            return Math.Round((totalFree / 100D), 2);
        }
        public static DateTime ToDateTime(long time)
        {
            DateTime dt = TimeZone.CurrentTimeZone.ToLocalTime(new DateTime(1970, 1, 1));
            return dt.AddMilliseconds(time);
        }
        public static JObject PostRegister(JObject user)
        {
            JObject ret = null;

            string url = ConfigurationManager.AppSettings["IOT:PostRegister"];
            JObject raw = PostRaw(string.Empty,url, user);
            if (IsPostRaw(raw))
            {
                ret = GetPostRawData(raw);
            }

            return ret;
        }
        /*
    {
      "deviceId": "000ef488-c420-4019-85d6-3d827cd72a1c",
      "ownerType": null,
      "ownerCode": null,
      "ownerName": null,
      "position": null,
      "longitude": null,
      "latitude": null,
      "installer": null,
      "manager": null,
      "tel": null,
      "installDate": null,
      "state": null,
      "isOnline": true,
      "lastTime": 1505897148000,
      "sensor": {
        "p": 9,
        "uv": 0,
        "chips": 0,
        "dtime": 1505925616000,
        "sm": 0,
        "j": 0,
        "z": 0,
        "fa": 0,
        "ni": 0,
        "smd": 0,
        "type": 0,
        "o": 0
      }
    }
         */
        public static JObject PostGetDevInfo(string openid, string mac, string jwt)
        {
            JObject ret = null;

            string url = ConfigurationManager.AppSettings["IOT:PostGetDevInfo"];
            JObject post = new JObject();
            post.Add("deviceMac", mac);
            JObject raw = PostRaw(openid,url, post, jwt);
            if (IsPostRaw(raw))
            {
                ret = (JObject)GetPostRawData(raw);
            }

            return ret;
        }
        /*
         "consumehis": [
      {
        "clientId": "6e6a6de8-192a-4f19-b1f9-e3340f2be604",
        "deviceId": "fecc5b66-ff1e-4490-a700-7634dd842b64",
        "createTime": 1505460267000,
        "orderNo": "3ae3dd67-2047-43ea-a16d-ae6a484f92f3",
        "totalFree": 10,
        "type": "1",
        "prepayId": null,
        "payNo": null,
        "mchId": null,
        "billBeing": null,
        "billExport": null,
        "status": null,
        "chips": 60
      }
    ],
    "chargelist": [
      {
        "chargeType": "001",
        "dispNo": "1",
        "typeName": "白金卡",
        "price": 500,
        "unit": "分",
        "chips": 30,
        "isValid": "1"
      },
      {
        "chargeType": "001",
        "dispNo": "2",
        "typeName": "白金卡",
        "price": 1000,
        "unit": "分",
        "chips": 60,
        "isValid": "1"
      },
      {
        "chargeType": "001",
        "dispNo": "3",
        "typeName": "白金卡",
        "price": 2000,
        "unit": "分",
        "chips": 150,
        "isValid": "1"
      }
    ]
         */
        public static JObject PostGetChargeInfo(string openid, Guid deviceId, string jwt)
        {
            JObject ret = null;

            string url = ConfigurationManager.AppSettings["IOT:PostGetChargeInfo"];
            JObject post = new JObject();
            post.Add("deviceId", deviceId);
            JObject raw = PostRaw(openid,url, post, jwt);
            if (IsPostRaw(raw))
            {
                ret = GetPostRawData(raw);
            }

            return ret;
        }
        /*
        {
  {
    "clientId": "",
    "deviceId": "fecc5b66-ff1e-4490-a700-7634dd842b64",
    "createTime": 1505792058614,
    "orderNo": "6029c9c8-5ca6-477b-a088-4620adcf14c5",
    "totalFree": 600,
    "type": "1",
    "prepayId": null,
    "payNo": null,
    "mchId": null,
    "billBeing": null,
    "billExport": null,
    "status": null,
    "chips": 30
  }
}
         */
        public static JObject PostPreBill(string openid, JObject pay, string jwt)
        {
            JObject ret = null;

            string url = ConfigurationManager.AppSettings["IOT:PostPreBill"];
            JObject raw = PostRaw(openid,url, pay, jwt);
            if (IsPostRaw(raw))
            {
                ret = (JObject)GetPostRawData(raw)["prebill"];
            }

            return ret;
        }
        /*
         {
  "deviceId": "0e6c5cfb-df49-4e5e-8b62-c25f27f8e7d3",
  "orderNo": "b4956b5a-e4fd-4bdc-a9f8-a86653fe4203",
  "totalFree": 500,
  "type": "1",
  "payNo": "4002082001201708258242888599",
  "mchId": "1384201202",
  "status": "1",
  "chips": 30
}
         */
        public static bool PostConsume(string openid, JObject pay)
        {
            bool ret = false;

            string url = ConfigurationManager.AppSettings["IOT:PostConsume"];
            JObject raw = PostRaw(openid,url, pay);
            if (IsPostRaw(raw))
            {
                ret = true;
            }

            return ret;
        }
        /*
        {
  "meta": {
    "code": 0,
    "message": "Get Device Success."
  },
  "data": {
    "devInfo": {
      "deviceId": "f57b740e-f8ae-47e5-9b50-5fc4c52601ba",
      "devicePw": "5330",
      "deviceMac": "D0BAE42D35CF",
      "productId": null,
      "moduleName": "EMW3165",
      "firmware": "EP600SFV2@002",
      "firmwareType": null,
      "isActivate": true,
      "isRecovery": false,
      "iotVersion": "3.0.0",
      "productModel": null
    },
    "user": {
      "openid": "o2BiavzN0EZR1Apl3-WCQVYXTQZE",
      "clientId": "01e14f21-6a59-4c72-9556-9718d260ed3c",
      "tel": "",
      "nickname": "Eden",
      "sex": "2",
      "city": "墨尔本",
      "country": "澳大利亚",
      "province": "维多利亚",
      "language": "",
      "headimgurl": "http://wx.qlogo.cn/mmopen/vi_32/DYAIOgq83eq68R7EyAJQwje4NDeJhrjG5ic6kVkVZTGxsCiaYerCx4XVJOf1aNIRJjfuVWTpriaLB99tfTbS9xuIA/0",
      "remark": "微信用户",
      "tagidList": "",
      "type": "1",
      "password": "",
      "appId": null
    },
    "devAccount": {
      "deviceId": "f57b740e-f8ae-47e5-9b50-5fc4c52601ba",
      "ownerType": "1",
      "ownerCode": "001",
      "ownerName": "北京易净优智环境科技有限公司",
      "position": "",
      "longitude": 116.293981,
      "latitude": 40.052639,
      "installer": "路人甲",
      "manager": "路人乙",
      "tel": "188888888",
      "installDate": 1506015080000,
      "status": "1",
      "isOnline": false,
      "lastTime": 1509533401000,
      "devicePw": "5330",
      "sensor": {
        "p": 2,
        "uv": 0,
        "chips": 0,
        "dtime": 1509561722000,
        "sm": 0,
        "j": 0,
        "z": 0,
        "fa": 0,
        "ni": 0,
        "smd": 0,
        "type": 1,
        "o": 0
      }
    }
  }
}
        */
        public static JObject PostGetOrderInfo(string orderno)
        {
            JObject ret = null;

            string url = ConfigurationManager.AppSettings["IOT:PostGetOrderInfo"];
            JObject post = new JObject();
            post.Add("orderNo",orderno);
            JObject raw = PostRaw(string.Empty,url, post, string.Empty);
            if (IsPostRaw(raw))
            {
                ret = GetPostRawData(raw);
            }

            return ret;
        }
        /// <summary>
        /// 获取设备所在城市天气
        /// </summary>
        /// <param name="longitude"></param>
        /// <param name="latitude"></param>
        /// <returns></returns>
        public static JObject GetCityWeather(double longitude, double latitude)
        {
            JObject ret = null;

            JObject w = null;
            HttpClient http = CreateClient();
            string url = string.Format(@"http://io.bjyjyz.com:8080/api/Service/Weather?longitude={0}&latitude={1}", longitude, latitude);
            try
            {
                string json = http.GetStringAsync(url).Result;
                w = JObject.Parse(json);
            }
            catch (Exception ex)
            {
                ret = null;
                w = null;
            }
            if (w != null)
            {
                if (w["status"].Value<int>() == 0)
                {
                    ret = new JObject();
                    ret.Add("temperature", w["message"]["weather"]["today"]["temperature"].Value<string>());
                    ret.Add("city", w["message"]["city"].Value<string>());
                    ret.Add("weather", w["message"]["weather"]["today"]["weather"].Value<string>());
                    ret.Add("humidity", w["message"]["weather"]["sk"]["humidity"].Value<string>());
                    ret.Add("aqi", w["message"]["aqi"]["AQI"].Value<string>() + w["message"]["aqi"]["quality"].Value<string>());
                    ret.Add("windtitle", w["message"]["weather"]["sk"]["wind_direction"].Value<string>());
                    ret.Add("windvalue", w["message"]["weather"]["sk"]["wind_strength"].Value<string>());
                }
            }
            return ret;
        }
        /// <summary>
        /// 获取MQTT配置信息
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public static JObject GetMqttOptions(ShareProcessViewModel model)
        {
            JObject options = new JObject();
            options.Add("host", APPConfig.IOT_MQTTHOST);
            options.Add("path", APPConfig.IOT_MQTTPATH);
            options.Add("port", APPConfig.IOT_MQTTPORT);
            options.Add("clientid", APPConfig.IOT_MQTTCLIENT);
            options.Add("userName", model.DeviceID);
            options.Add("password", model.DevicePwd);
            options.Add("topic", string.Format(APPConfig.IOT_MQTTTOPIC, model.DeviceID));
            options.Add("iotHost", APPConfig.IOT_Host);
            return options;
        }
    }
}