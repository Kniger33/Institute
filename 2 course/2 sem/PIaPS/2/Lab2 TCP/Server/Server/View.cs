using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Server
{
    class View
    {
        public static void LogClientSendMessage(string clientMessage, string clientName)
        {
            Console.WriteLine(clientName + ": " + clientMessage);
        }

        public static void LogClientConnected(string clientName)
        {
            Console.WriteLine(clientName + " подключен!");
        }

        public static void LogClientDisconnected(string clientName)
        {
            Console.WriteLine("Client " + clientName + " disconnected!");
        }

        public static void LogStart()
        {
            Console.WriteLine("Start listening");
        }

        public static void LogNewClientConnected()
        {
            Console.WriteLine("New client");
        }

        public static void LogException(Exception e)
        {
            Console.WriteLine(e);
        }
    }
}
