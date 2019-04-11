using System;
using Nwc.XmlRpc;

namespace XMLRPCClient
{
    class ServersideObject
    {
        XmlRpcRequest client;
        String host = "http://127.0.0.1:5050";

        public ServersideObject(String host)
        {
            this.host = host;
            client = new XmlRpcRequest();
        }

        public void SendMatrix(int size, int[,] matrix) {
            XmlRpcResponse response;
            client.MethodName = "sample.ConvertMatrix";
            client.Params.Clear();
            client.Params.Add(size);

            string str = "";

            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    if (j == size - 1) {
                        str += matrix[i, j].ToString();
                        break;
                    }
                    
                    str += matrix[i, j].ToString() + ' ';
                }
                
                if (i == size - 1)
                    break;
                str += '\n';
            }

            client.Params.Add(str);
            Console.WriteLine(client);
            response = client.Send(host);

            if (response.IsFault) {
                Console.WriteLine("Fault {0}: {1}", response.FaultCode, response.FaultString);
                return;
            } else {
                Console.WriteLine("OK!");
            }
        }
    }
}
