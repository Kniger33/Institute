using System;
using System.Collections.Generic;
using System.Net.Mime;
using System.ServiceModel;
using System.ServiceModel.Description;
using System.ServiceModel.Web;
using System.Text;

namespace WCFClient {
    [ServiceContract]
    public interface IService {
        [OperationContract]
        string EchoWinGet(string s);

        [OperationContract]
        string EchoWithPost(string s);
        
        [OperationContract]
        string GetFlights();
        
        [OperationContract]
        int BuyTicket(int flightId);
    }
    
    internal class Program {
        public static void Main(string[] args) {
            Uri serverUri = new Uri("http://localhost:7777/");
            EndpointAddress address = new EndpointAddress(serverUri);
            BasicHttpBinding binding = new BasicHttpBinding();
            
            ChannelFactory<IService> factory = new ChannelFactory<IService>(binding, address);
            IService myService = factory.CreateChannel();

            while (true) {
                Console.WriteLine("1 - List of flights");
                Console.WriteLine("2 - Buy ticket");
                Console.WriteLine("0 - Exit");
                Console.Write("Choose command: ");
                string command = Console.ReadLine();
                switch (command) {
                    case "1": {
                        Console.WriteLine(myService.GetFlights());
                        break;
                    }

                    case "2": {
                        Console.Write("Write flight id to buy ticket: ");
                        int flightId = Convert.ToInt32(Console.ReadLine());
                        int ticketId = myService.BuyTicket(flightId);
                        Console.WriteLine(String.Format("Your ticket id: {0}", ticketId));
                        break;
                    }

                    case "0": {
                        Environment.Exit(0);
                        break;
                    }
                    
                    default:
                        break;
                }
            }
            return;
        }
    }
}