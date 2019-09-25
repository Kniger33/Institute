using System;
using Nwc.XmlRpc;


namespace XMLRPCServer
{
    class Server
    {
        const int PORT = 5050;

        static void Main(string[] args)
        {
            XmlRpcServer server = new XmlRpcServer(PORT);
            server.Add("sample", new Server());
            Console.WriteLine("Web Server Running on port {0} ... Press ^C to Stop...", PORT);
            server.Start();
        }

        public DateTime Ping()
        {
            Console.WriteLine("Ping\n");
            return DateTime.Now;
        }

        public String Echo(String arg)
        {
            Console.WriteLine("Echo\n");
            return arg;
        }

        public void ConvertMatrix(int size, string strMatrix) {
            int[,] matrix = new int[size, size];
            string[] strArray = strMatrix.Split('\n');

            for (int i = 0; i < size; i++) {
                string[] rowArray = strArray[i].Split(' ');

                for (int j = 0; j < size; j++) {
                    matrix[i, j] = Convert.ToInt32(rowArray[j]);
                }
            }
            
            int minValue = matrix[0,0];
            int minI = 0, minJ = 0;

            for (int i = 0; i < size; i++) {                
                if (minValue > matrix[i, i]) {
                    minValue = matrix[i, i];
                    minI = minJ = i;                 
                }
            }
            
            for (int i = size - 1; i >= 0; i--) {               
                if (minValue > matrix[i, size - i - 1]) {                        
                    minValue = matrix[i, size - i - 1];
                    minI = i;
                    minJ = size - i - 1;
                }               
            }

            Console.WriteLine();
            Console.WriteLine("Min value: {0} [{1}][{2}]", minValue, minI, minJ);

            if (minI == minJ) {
                for (int i = 0; i < size; i++) {
                    matrix[i, i] = 0;
                }
                
                for (int i = 1; i < size; i++) {
                    for (int j = 0; j < i; j++) {
                        matrix[i, j] *= matrix[i, j];
                    }
                }                
            } else if (minI + minJ == size - 1) {               
                for (int i = size - 1; i >= 0; i--) {                    
                     matrix[i, size - i - 1] = 0;                    

                }
                
                for (int i = 1; i < size; i++) {
                    for (int j = size - 1; j > size - i - 1; j--) {                        
                        matrix[i, j] *= matrix[i, j];                        
                    }                       
                }
            }

            Console.WriteLine("Result");
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    Console.Write("{0} \t", matrix[i, j]);
                }
                Console.WriteLine();
            }
        }
    }
}
