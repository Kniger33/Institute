using System;
using System.IO;
using System.Net;
using System.Xml;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;

namespace Client {    
    internal class Program {
        static public void SendGetRequest(string url, string param = "") {
            var httpRequest = (HttpWebRequest) WebRequest.Create(url + param);
            httpRequest.Method = "GET";

            var httpResponse = httpRequest.GetResponse();
            var responseStream = httpResponse.GetResponseStream();
            var reader = new StreamReader(responseStream);
            var response = reader.ReadToEnd();
            
            Console.WriteLine(response);
        }

        public static void Main(string[] args) {
            SendGetRequest("https://speller.yandex.net/services/spellservice?WSDL");
            
            SendGetRequest("https://speller.yandex.net/services/spellservice/checkText?", "text=сабака");
        }
    }
}