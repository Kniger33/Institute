using System;
using System.Collections.Generic;
using System.Text;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using Server.Models;

namespace Server {
    internal class Program {
        //private static List<Client> clients = new List<Client>();

        private static void SendAll(string clientMessage, string clientName) {
            byte[] data = new byte[1024];
            data = Encoding.UTF8.GetBytes(clientName + ": " + clientMessage);

            View.LogClientSendMessage(clientMessage, clientName);
            //Console.WriteLine(clientName + ": " + clientMessage);
            
            foreach (var client in ClientArray.GetClientsArray()) {
                Socket clientSocket = client.GetClientSocket();
                
                clientSocket.Send(data);
            }
        }

        private static void ListenToClient() {
            Client client = ClientArray.GetClient(ClientArray.CountOfClients() - 1);
                //clients[clients.Count - 1];
            byte[] data = new byte[1024];
            string message;
            string clientName;
            string clientMessage;
            Socket clientSocket = client.GetClientSocket();
            int dataSize;
            
            try {
                clientSocket.Send(Encoding.UTF8.GetBytes("Nickname"));
                dataSize = clientSocket.Receive(data);
                message = Encoding.UTF8.GetString(data, 0, dataSize);
                client.SetClientName(message);
                clientName = message;
                View.LogClientConnected(clientName);
                //Console.WriteLine(clientName + " подключен!");

                while (true) {
                    dataSize = clientSocket.Receive(data);
                    clientMessage = Encoding.UTF8.GetString(data, 0 ,dataSize);
                    
                    SendAll(clientMessage, clientName);
                }
            }
            catch (Exception) {
                View.LogClientDisconnected(client.GetClientName());
                //Console.WriteLine("Client " + client.GetClientName() + " disconnected!");
                ClientArray.RemoveClient(client);
                //clients.Remove(client);
            } 
        }
        
        public static void Main(string[] args) {
            try {
                IPAddress address = Dns.GetHostEntry("127.0.0.1").AddressList[0];
                Socket listener = new Socket(
                                            address.AddressFamily,
                                            SocketType.Stream,
                                            ProtocolType.Tcp);
                IPEndPoint endPoint = new IPEndPoint(address, 7777);
                
                listener.Bind(endPoint);
                listener.Listen(1);
                View.LogStart();
                //Console.WriteLine("Start listening");

                while (true) {
                    Socket client = listener.Accept();
                    View.LogNewClientConnected();
                    //Console.WriteLine("New client");

                    ClientArray.AddClient(client);
                    //clients.Add(new Client(client));
                    
                    Thread newThread = new Thread(ListenToClient);
                    newThread.Start();
                }
            }
            catch (Exception e) {
                View.LogException(e);
                //Console.WriteLine(e);
                throw;
            }
        }
    }
}