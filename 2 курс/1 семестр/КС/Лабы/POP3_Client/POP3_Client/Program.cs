using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;

namespace POP3_Client
{
    class Program
    {
        static string Parser(string ans)
        {
            int headerTail = ans.IndexOf("\r\n\r\n");
            if (headerTail != -1)
            {
                Console.Write("\n\n" + headerTail + "\n\n");
            }
            
            int index = ans.IndexOf("From");
            ans = ans.Remove(0, index);

            index = ans.IndexOf(" ") + 1;
            while (ans[index + 1] != ' ')
            {
                index++;
            }
            string from = ans.Substring(ans.IndexOf(" ") + 1, index - ans.IndexOf(" ") + 1);
            from = FromParser(from);

            ans = ans.Remove(ans.IndexOf(" ") + 1, index - ans.IndexOf(" ") + 1);

            ans = ans.Insert(ans.IndexOf("From") + 6, from + " ");
            
            index = ans.IndexOf("To");
            
            while (ans[index] != '\n')
            {
                index++;
            }
            index++;

            ans = ans.Remove(index, ans.IndexOf("\r\n\r\n") - index);
            #region
            //index = ans.IndexOf("\r\n\r\n");
            //ans = ans.Remove(index, 4);
            //ans = ans.Remove(index, ans.IndexOf("\r\n\r\n") - index);


            /*
            index = ans.IndexOf("\r\n\r\n") + 5;
            while (ans[index] != '\n')
            {
                index++;
            }
            Console.Write(index + "    ");
            Console.Write(ans.IndexOf("\r\n.") + "\n\n");

            //index++;

            //ans = ans.Remove(index, ans.IndexOf("\r\n.") - index + 1);
            ans = ans.Remove(index, 3);

            ans = ans.Insert(0, "\n");

            //Console.Write(from);
            */
            #endregion
            return ans;
        }

        static string FromParser(string from)
        {
            int index = from.IndexOf("B?") + 2;
            from = from.Remove(0, index);
            from = from.Substring(0, from.Length - 3);

            var bytes = System.Convert.FromBase64String(from);
            from = System.Text.Encoding.UTF8.GetString(bytes);

            return from;
        }

        static void Main(string[] args)
        {
            try
            {
                byte[] bytes = new byte[40000];
                byte[] msg = { };
                int bytesRec;
                int bytesSent;
                string message = "";
                string answer = "";

                int port = 110;

                IPHostEntry ipHost = Dns.GetHostEntry("mail.eml.ru");
                IPAddress ipAddr = ipHost.AddressList[0];
                IPEndPoint ipEndPoint = new IPEndPoint(ipAddr, port);

                Socket socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                socket.Connect(ipEndPoint);

                ////CONNECT////
                bytesRec = socket.Receive(bytes);
                answer = Encoding.UTF8.GetString(bytes, 0, bytesRec);
                Console.WriteLine("\nS: {0}\n\n", answer);
                #region
                /*AUTO LOGIN
                        ////LOGIN////
                message = "user marmax@eml.ru\n";

                msg = Encoding.UTF8.GetBytes(message);
                bytesSent = socket.Send(msg);

                bytesRec = socket.Receive(bytes);
                answer = Encoding.UTF8.GetString(bytes, 0, bytesRec);
                Console.WriteLine("\nS: {0}\n\n", answer);

                      ////PASSWORD////
                message = "pass 556677\n";

                msg = Encoding.UTF8.GetBytes(message);
                bytesSent = socket.Send(msg);

                bytesRec = socket.Receive(bytes);
                answer = Encoding.UTF8.GetString(bytes, 0, bytesRec);
                Console.WriteLine("\nS: {0}\n\n", answer);
                */
                #endregion
                while (socket.Connected)
                {
                    Console.Write("C: ");
                    message = Console.ReadLine();

                    message += "\n";

                    msg = Encoding.UTF8.GetBytes(message);
                    bytesSent = socket.Send(msg);

                    bytesRec = socket.Receive(bytes);
                    answer = Encoding.UTF8.GetString(bytes, 0, bytesRec);
                    Console.WriteLine("\nS: {0}\n\n", answer);

                    if (answer.Contains("follow"))
                    {
                        bytesRec = socket.Receive(bytes);
                        answer = Encoding.UTF8.GetString(bytes, 0, bytesRec);

                        
                        answer = Parser(answer);
                        

                        Console.WriteLine("\nS: {0}\n\n", answer);
                    }

                    answer = "";
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

