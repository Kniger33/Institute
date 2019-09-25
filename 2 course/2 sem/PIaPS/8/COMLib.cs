using System;
using System.Runtime.InteropServices;

namespace COMServer {
    [Guid("E5B23F96-411D-4A67-AFBA-B3DF6B3B0ACB")]
    [ComVisible(true)]
    public interface COMInterface {
        string Ping();

        double Min(double a, double b, double c);

        double Distance(double x1, double y1, double z1, double x2, double y2, double z2);

        int Randomize(int x);
    }

    [Guid("8C034F6A-1D3F-4DB8-BC99-B73873D8C297")]
    [ClassInterface(ClassInterfaceType.None)]
    [ComVisible(true)]
    public class COMServer : COMInterface {
        public string Ping() {
            return "Pong";
        }
        
        public double Min(double a, double b, double c) {
            return a < b ? a < c ? a : c : b < c ? b : c;
        }

        public double Distance(double x1, double y1, double z1, double x2, double y2, double z2) {
            return Math.Sqrt(Math.Pow(x2 - x1, 2) + Math.Pow(y2 - y1, 2) + Math.Pow(z2 - z1, 2));
        }

        public int Randomize(int x) {
            Random r = new Random();
            return r.Next(-x, 2 * x);
        }
    }
}