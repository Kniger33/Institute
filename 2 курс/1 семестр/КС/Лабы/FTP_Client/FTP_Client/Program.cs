using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;
using System.IO;

namespace FTP_Client
{
    class Program
    {
        public static Socket PD_Socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        public static Thread recv = new Thread(Receiver);
        public static Thread send = new Thread(Sender); 
        public static Thread active_conncetion = new Thread(ActiveDataConnection);
        public static string file_path = "";
        public static bool retr = false;

        static void Sender()
        {
            byte[] bytes = File.ReadAllBytes(file_path);
           
            if (file_path != "")
            {
                PD_Socket.Send(bytes);
                Disconnect_PD_Socket();
            }
        }

        static void Receiver()
        {
            int b_cnt;
            byte[] bytes = new byte[40000];
            string answer = "";
            
            b_cnt = PD_Socket.Receive(bytes);
            answer = Encoding.UTF8.GetString(bytes, 0, b_cnt);
            if (answer != "")
            {
                if (retr)
                {
                    File.WriteAllBytes(file_path, bytes);
                    retr = false;
                }
                else
                {
                    Console.WriteLine("\nS_recv: {0}\n\n", answer);
                }
            }
        }

        static void Disconnect_PD_Socket()
        {
            if(recv.ThreadState == ThreadState.Running)
            {
                recv.Abort();
            }

            PD_Socket.Shutdown(SocketShutdown.Both);
            PD_Socket.Close();

            if (send.ThreadState == ThreadState.Running)
            {
                send.Abort();
            }

            if (active_conncetion.ThreadState == ThreadState.Running)
            {
                active_conncetion.Abort();
            }
        }

        static void PassiveDataConnection(string str)
        {
            byte[] cmd = new byte[1024];
            byte[] ans = { };
            int bytesRec;
            int bytesSent;
            string command;
            string answer = "";

            string[] parts = str.Split(new char[] { ',' });
            
            parts[parts.Length - 1] = parts[parts.Length - 1].Substring(0, parts[parts.Length - 1].Length - 4);

            int port = Int32.Parse(parts[parts.Length - 2]) * 256 + Int32.Parse(parts[parts.Length - 1]);
            
            IPAddress PD_IpAddr = IPAddress.Parse("127.0.0.1");
            IPEndPoint PD_EndPoint = new IPEndPoint(PD_IpAddr, port);

            PD_Socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            PD_Socket.Connect(PD_EndPoint);
            
            recv = new Thread(Receiver);
            if (recv.ThreadState != ThreadState.Running)
            {
                recv.Priority = ThreadPriority.Highest;
                recv.Start();
            }
        }

        static void ActiveDataConnection()
        {
            int port = 2580;
            IPAddress ipAddr = IPAddress.Parse("127.0.0.1");
            IPEndPoint ipEndPoint = new IPEndPoint(ipAddr, port);

            Socket sListener = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            sListener.Bind(ipEndPoint);
            sListener.Listen(10);

            PD_Socket = sListener.Accept();

            int b_cnt;
            byte[] bytes = new byte[4086];
            byte[] cmd = { };
            string answer;
            string command;
            
            recv = new Thread(Receiver);
            if(recv.ThreadState != ThreadState.Running)
            {
                recv.Priority = ThreadPriority.Highest;
                recv.Start();
            }

            sListener.Close();
        }

        static void ParseFilePath(string str)
        {
            string[] parts = str.Split(new char[] {' '});
            file_path = parts[1];
        }

        static void Main(string[] args)
        {
            try
            {
                byte[] bytes = new byte[1024];
                byte[] msg = { };
                int bytesRec;
                int bytesSent;
                string message;
                string answer = "";

                int port = 21;

                IPAddress ipAddr = IPAddress.Parse("127.0.0.1");
                IPEndPoint ipEndPoint = new IPEndPoint(ipAddr, port);

                Socket socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                socket.Connect(ipEndPoint);

                bytesRec = socket.Receive(bytes);
                Console.WriteLine("\nS: {0}\n\n", Encoding.UTF8.GetString(bytes, 0, bytesRec));
                
                while (socket.Connected)
                {
                    System.Threading.Thread.Sleep(500);

                    Console.Write("C: ");
                    message = Console.ReadLine();

                    if (message.Contains("port"))
                    {
                        Thread active_conncetion = new Thread(ActiveDataConnection);
                        active_conncetion.Priority = ThreadPriority.Highest;
                        active_conncetion.Start();
                    }
                    if (message.Contains("stor"))
                    {
                        ParseFilePath(message);
                        send = new Thread(Sender);
                        send.Priority = ThreadPriority.Highest;
                        send.Start();
                    }
                    if (message.Contains("retr"))
                    {
                        ParseFilePath(message);
                        retr = true;
                    }

                    message += "\r\n";
                    
                    msg = Encoding.UTF8.GetBytes(message);
                    bytesSent = socket.Send(msg);
                    
                    bytesRec = socket.Receive(bytes);
                    answer = Encoding.UTF8.GetString(bytes, 0, bytesRec);
                    Console.WriteLine("\nS: {0}\n\n", answer);
                    
                    if (answer.Contains("227"))
                    {
                        PassiveDataConnection(answer);
                    }
                    if (answer.Contains("226"))
                    {
                        Disconnect_PD_Socket();
                    }
                    if (answer.Contains("150"))
                    {
                        System.Threading.Thread.Sleep(500);
                        bytesRec = socket.Receive(bytes);
                        answer = Encoding.UTF8.GetString(bytes, 0, bytesRec);
                        Console.WriteLine("\nS: {0}\n\n", answer);
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            Console.Read();
        }
    }
}
