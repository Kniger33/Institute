using System;

namespace Lab1
{
    public static class Menu
    {
        public static void PrintMenu(String[] args)
        {
            while (true)
            {
                Console.WriteLine("1 - Task 1");
                Console.WriteLine("2 - Task 2");
                Console.WriteLine("3 - Task 3");
                Console.WriteLine("4 - Task 4");
                Console.WriteLine("5 - Task 5");
                Console.WriteLine("0 - Exit");
                Console.Write("Write command: ");
                int command = Convert.ToInt32(Console.ReadLine());
                
                switch (command)
                {
                    case 1: {
                        Task_1.PrintArgs(args);
                        Console.ReadKey();
                        Console.Clear();
                        break;
                    }

                    case 2: {
                        Task_2.IsYears();
                        Console.ReadKey();
                        Console.Clear();
                        break;
                    }

                    case 3: {
                        Task_3.PrintFibDigits();
                        Console.ReadKey();
                        Console.Clear();
                        break;
                    }
                    
                    case 4: {
                        Task_4.PrintFactorial();
                        Console.ReadKey();
                        Console.Clear();
                        break;
                    }
                    
                    case 5: {
                        Task_5.PrintSimpleNumbers();
                        Console.ReadKey();
                        Console.Clear();
                        break;
                    }

                    case 0: {
                        Environment.Exit(0);
                        break;
                    }

                    default: {
                        Console.WriteLine("Write correct command");
                        break;   
                    }
                }  
            }
        }
    }
}