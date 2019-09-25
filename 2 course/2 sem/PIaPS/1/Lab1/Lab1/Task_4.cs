using System;

namespace Lab1

{
    public static class Task_4
    {
        public static void PrintFactorial() {
            Console.Write("Write factorial number: ");
            int maxFact = Convert.ToInt32(Console.ReadLine());
            int fact = 1;

            for (int var = 1; var <= maxFact; var++) {
                fact *= var;
            }
            
            Console.WriteLine(fact);
        }
    }
}