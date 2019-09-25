using System;

namespace Lab1 {
    
    public static class Task_5 {
        public static void PrintSimpleNumbers() {
            Console.Write("Write max simple number: ");
            int maxNumber = Convert.ToInt32(Console.ReadLine());
            
            int[] numbers = new int[maxNumber + 1];
            for (int i = 0; i < maxNumber + 1; i++) {
                numbers[i] = i;
            }

            int x = 2;
            for (int i = 2; i < maxNumber + 1; i++) {
                if (numbers[i] != 0) {
                    Console.WriteLine(numbers[i]);
                    for (int j = i * i; j < maxNumber + 1; j += i) {
                        numbers[j] = 0;
                    }
                }
            }
        }
    }
}