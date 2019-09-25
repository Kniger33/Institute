using System;

namespace Lab1
{
    public static class Task_1
    {
        public static void PrintArgs(String[] args)
        {
            if (args.Length == 0) {
                Console.WriteLine("No args");
                return;
            }
            
            foreach (string var in args) {
                Console.WriteLine(var);
            }
        }
    }
}