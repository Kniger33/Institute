using System;

namespace Lab_1
{
    class Program
    {
        static double RowSum(double x)
        {
            double sum = 0;
            int d = 1;

            for (int i = 0; i < 15; i++)
            {
                sum += 1.0 / (d * Math.Pow(x, d));
                d += 2;
            }

            return sum;
        }
        
        static void Main(string[] args)
        {
            while (true)
            {
                double x = 0;
                Console.WriteLine("Enter X: ");
                x = Convert.ToDouble(Console.ReadLine());
                
                if(Math.Abs(x) < 1 || Math.Abs(x) > 3) { break;}

                Console.WriteLine($"Row sum: {RowSum(x)}");
            }
        }
    }
}