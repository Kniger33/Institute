using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
using System.Xml;
using System.Xml.Linq;

namespace Testing_Lab_4
{
    public partial class Form1 : Form
    {
        private List<Model.Task> tasks;

        public Form1()
        {
            InitializeComponent();
            string path = "../../Model/tasks.xml";
            //CreateTasks(path);
            tasks = GetTasksFromXML(path);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            listBoxTickets.Items.Clear();
            GenerateTickets();
        }

        private void buttonExit_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void GenerateTickets()
        {
            List<Model.Task> tasksLocal = tasks.ToList();
            List<Model.Ticket> tickets = new List<Model.Ticket>();
            int ticketNumber = 1;
            var random = new Random();
            
            while (true)
            {
                List<Model.Task> ticketTasks = new List<Model.Task>(); 
                int randomTask = random.Next(tasksLocal.Count);
                
                // Add first task (any, any, any)
                ticketTasks.Add(tasksLocal[randomTask]);
                tasksLocal.RemoveAt(randomTask);

                randomTask = random.Next(tasksLocal.Count);
                List<Model.Task> copyTasks = tasksLocal.ToList();
                
                // Add 2rd task (!such in 1st task, !such in 1st task, sum == 4)
                while (true)
                {
                    if (copyTasks[randomTask].TaskType != ticketTasks[0].TaskType
                        && copyTasks[randomTask].Theme != ticketTasks[0].Theme
                        && copyTasks[randomTask].Difficulty + ticketTasks[0].Difficulty == 4
                    )
                    {
                        ticketTasks.Add(copyTasks[randomTask]); 
                        tasksLocal.Remove(copyTasks[randomTask]);
                        break;
                    }
                    copyTasks.RemoveAt(randomTask);
                    if (copyTasks.Count == 0)
                    {
                        break;
                    }
                    randomTask = random.Next(copyTasks.Count);
                }

                tickets.Add(new Model.Ticket(ticketNumber, ticketTasks));
                
                if (tasksLocal.Count == 2)
                {
                    ticketNumber++;
                    ticketTasks = tasksLocal.ToList();
                    tickets.Add(new Model.Ticket(ticketNumber, ticketTasks));
                    break;
                }
                if (tasksLocal.Count == 0)
                { 
                    break; 
                }
                ticketNumber++;
            }

            //listBoxTickets.Items.AddRange(tickets);
            //Console.WriteLine("Tickets");
            foreach (var ticket in tickets) 
            {
                //ticket.PrintTicket();
                string ticketNum = "Номер:   " + ticket.Number + "    ";
                string ticketTasks = "";
                foreach (var task in ticket.Tasks)
                {
                    ticketTasks += $"Тип: {task.TaskType}     " +
                                    $"Тема: {task.Theme}     " +
                                    $"Сложность: {task.Difficulty}     ";
                }
                //string ticketTask0 = $"Задание1:    " +
                //                    $"Тип: {ticket.Tasks[0].TaskType}     " +
                //                    $"Тема: {ticket.Tasks[0].Theme}     " +
                //                    $"Сложность: {ticket.Tasks[0].Difficulty}     ";
                //string ticketTask1 = $"Задание2:      " +
                //                    $"Тип: {ticket.Tasks[1].TaskType}     " +
                //                    $"Тема: {ticket.Tasks[1].Theme}     " +
                //                    $"Сложность: {ticket.Tasks[1].Difficulty}     ";

                string ticketFull = ticketNum + ticketTasks;
                listBoxTickets.Items.Insert(0, ticketFull);
            }
        }

        public void CreateTasks(string pathToSave)
        {
            string[] themes = { "theme1", "theme2", "theme3", "theme4" };
            int[] difficulties = { 1, 2, 3 };
            string[] taskTypes = { "theory", "practice" };
            XDocument xDocument = new XDocument();
            XElement tasks = new XElement("tasks");
            foreach (var theme in themes)
            {
                foreach (var difficulty in difficulties)
                {
                    foreach (var taskType in taskTypes)
                    {
                        XElement xeTask = new XElement("task");
                        XElement xeTaskType = new XElement("taskType", taskType);
                        XElement xeTheme = new XElement("theme", theme);
                        XElement xeDifficulty = new XElement("difficulty", difficulty);
                        xeTask.Add(xeTaskType);
                        xeTask.Add(xeTheme);
                        xeTask.Add(xeDifficulty);
                        tasks.Add(xeTask);
                    }
                }
            }
            xDocument.Add(tasks);
            xDocument.Save(pathToSave);
        }
        private List<Model.Task> GetTasksFromXML(string pathToLoad)
        {          
            List<Model.Task> tasks = new List<Model.Task>();
            XmlDocument xmlDocument = new XmlDocument();
            xmlDocument.Load(pathToLoad);
            XmlElement xRoot = xmlDocument.DocumentElement;
            string taskType = "";
            string theme = "";
            int difficulty = 0;
            
            foreach (XmlNode xmlNode in xRoot)
            {
                foreach (XmlNode childNode in xmlNode.ChildNodes)
                {
                    taskType = (childNode.Name == "taskType") ? childNode.InnerText : taskType;
                    theme = (childNode.Name == "theme") ? childNode.InnerText : theme;
                    difficulty = (childNode.Name == "difficulty") ? Convert.ToInt32(childNode.InnerText) : difficulty;
                }
                tasks.Add(new Model.Task(taskType, theme, difficulty));
            }
            return tasks;
        }

    }
}
