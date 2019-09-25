using System;

namespace Lab1

{
    public static class Task_3
    {
        public static void PrintFibDigits() {
            int fib1 = 0;
            int fib2 = 1;
            int res = 0;
            
            Console.Write("Write max fibonacci: ");
            int maxFib = Convert.ToInt32(Console.ReadLine());
               
            Console.WriteLine(fib1 + "\n" + fib2);
            while (res <= maxFib) {
                res = fib2 + fib1;
                if (res > maxFib)
                    return;
                Console.WriteLine(res);

                fib1 = fib2;
                fib2 = res;
            }
        }
    }
}