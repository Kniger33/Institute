using System;
using System.Collections.Generic;


namespace Testing_Lab_4.Model
{
    class Ticket
    {
        public int Number { get; private set; }
        public List<Task> Tasks { get; private set; }
        public Ticket(int number, List<Task> tasks) { Tasks = tasks; Number = number; }
        public void PrintTicket()
        {
            Console.WriteLine($"Number: {Number}");
            foreach (var task in Tasks) { task.PrintTask(); }
            Console.WriteLine();
        }

    }
}
