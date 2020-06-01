using System;

namespace Testing_Lab_4.Model
{
    class Task
    {
        public string TaskType { get; private set; }
        public string Theme { get; private set; }
        public int Difficulty { get; private set; }
        public Task(string type, string theme, int difficulty)
        {
            TaskType = type;
            Theme = theme;
            Difficulty = difficulty;
        }
        public Task() { throw new NotImplementedException(); }
        public void PrintTask()
        {
            Console.WriteLine($"TaskType: {TaskType}    " + $"Theme: {Theme}    " + $"Difficulty: {Difficulty}    ");
        }

    }
}
