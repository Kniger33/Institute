using System;
using System.Collections;
using System.ServiceModel;

namespace Microsoft.ServiceModel.Samples.BasicWebProgramming {
    public static class Variables {
        public static ArrayList flights = new ArrayList();
        public static int ticketId = 1;
        public static int flightId = 1;
    }

    public class Ticket {
        public int id;
        public float price;

        public Ticket(float price) {
            id = Variables.ticketId;
            this.price = price;
            Variables.ticketId++;
        }

        public int GetId() {
            return id;
        }
    }
    
    public class Flight {
        public int id;
        public string startPlace;
        public string endPlace;
        public DateTime time;
        public ArrayList tickets = new ArrayList();
        public float price;

        public Flight(float price, string startPlace, string endPlace) {
            id = Variables.flightId;
            Variables.flightId++;
            this.startPlace = startPlace;
            this.endPlace = endPlace;
            this.price = price;
            time = DateTime.Now;
            tickets.Add(new Ticket(price));
            tickets.Add(new Ticket(price));
            tickets.Add(new Ticket(price));
            tickets.Add(new Ticket(price));
        }

        public string Str() {
            return String.Format("Id: {0}, Start-place: {1}, End-place: {2}, Time: {3}, NumberOfTickets: {4}, TicketPrice: {5}",
                id, startPlace, endPlace, time, tickets.Count, this.price);
        }

        public int GetId() {
            return id;
        }
    }

    [ServiceContract]
    public interface IService {
        [OperationContract]
        string EchoWithGet(string s);

        [OperationContract]
        string EchoWithPost(string s);
        
        [OperationContract]
        string GetFlights();

        [OperationContract]
        int BuyTicket(int flightId);
    }
    public class Service : IService {
        public string EchoWithGet(string s) {
            return "You said " + s;
        }

        public string EchoWithPost(string s) {
            return "You said " + s;
        }

        public string GetFlights() {
            Console.WriteLine("Client call GetFlights");
            string returnStr = "";
            foreach (Flight flight in Variables.flights) {
                returnStr += flight.Str() + "\n";
            }
            
            return returnStr;
        }

        public int BuyTicket(int flightId) {
            Console.WriteLine("Client call BuyTicket");
            Ticket ticket = null;
            foreach (Flight flight in Variables.flights) {
                if (flight.GetId() == flightId) {
                    if (flight.tickets.Count != 0) {
                        ticket = (Ticket)flight.tickets[0];
                        flight.tickets.Remove(ticket);
                        Console.WriteLine(String.Format("Client buy ticket: {0}", ticket.id));
                    }
                    else {
                        return 0;
                    }
                }
            }

            if (ticket == null) return 0;
            else return ticket.id;
        }
    }
    public class Program {
        static void Main(string[] args) {
            Variables.flights.Add(new Flight(10, "Орел", "Москва"));
            Variables.flights.Add(new Flight(11, "Орел", "Белгород"));
            Variables.flights.Add(new Flight(12, "Орел", "Липецк"));
            Variables.flights.Add(new Flight(13, "Орел", "Брянск"));
            Variables.flights.Add(new Flight(14, "Орел", "Курск"));
            
            ServiceHost host = new ServiceHost(typeof(Service), new Uri("http://127.0.0.1:7777/"));
            host.AddServiceEndpoint(typeof(IService), new BasicHttpBinding(), "");
            
            Console.WriteLine("Server started work at :7777");
            host.Open();
            Console.WriteLine("Press <Enter> to terminate");
            Console.ReadLine();
            host.Close();
        }
    }
}
