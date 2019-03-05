using System;

namespace Lab1

{
    public static class Task_2
    {
        public static void IsYears()
        {
            for (int year = 1900; year <= 2000; year++) {
                Console.Write(year + " ");
                
                if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
                    Console.WriteLine("YES");
                } else {
                    Console.WriteLine("NO");
                }
            }
        }
    }
}