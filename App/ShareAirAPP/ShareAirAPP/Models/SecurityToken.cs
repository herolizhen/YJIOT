using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using YJIOT.ShareAirAPP.Service;

namespace YJIOT.ShareAirAPP.Models
{
    public class SecurityToken
    {
        public SecurityToken(string token,long expires)
        {
            double dl = expires - APPConfig.USE_EXPIRESTIME * 60;
            this.Token = token;
            this.ExpiresTiem = DateTime.Now.AddSeconds(dl);
        }

        public string Token { get; private set;}
        public DateTime ExpiresTiem { get; private set; }
        public bool IsTimeout
        {
            get
            {
                return DateTime.Now > this.ExpiresTiem;
            }
        }

        public SecurityToken Clone()
        {
            SecurityToken token = new SecurityToken(string.Empty,0);
            token.Token = this.Token;
            token.ExpiresTiem = this.ExpiresTiem;
            return token;
        }
    }
}