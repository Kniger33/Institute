using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net.Sockets;

namespace Server.Models
{
    class ClientArray
    {
        private static List<Client> clients = new List<Client>();

        public static Client GetClient(int numClient)
        {
            return clients[numClient];
        }

        public static void AddClient(Socket client)
        {
            clients.Add(new Client(client));            
        }

        public static void RemoveClient(Client client)
        {
            clients.Remove(client);
        }

        public static int CountOfClients()
        {
            return clients.Count;
        }

        public static List<Client> GetClientsArray()
        {
            return clients;
        }
    }
}
