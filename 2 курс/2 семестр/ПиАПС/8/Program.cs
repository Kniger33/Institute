using System;

namespace COMClient {
    internal class Program {
        public static void Main(string[] args) {
            COMServer.COMServer com = new COMServer.COMServer();
            Console.WriteLine("Ping: " + com.Ping());

            Console.WriteLine("Random: " + com.Randomize(10));
            Console.WriteLine("Distance: " + com.Distance(1, 1, 1, 0, 0, 0));
            Console.WriteLine("Min: " + com.Min(55, 22, 13));
        }
    }
}