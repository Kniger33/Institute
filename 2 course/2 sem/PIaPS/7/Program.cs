using System;
using Word = Microsoft.Office.Interop.Word;

namespace Program {
    internal class Program {
        public static void Main(string[] args) {
            Word.Document doc = null;
            Console.Write("Введите название документа: ");
            string name = Console.ReadLine();
            Console.Write("Введите номер лабораторной работы: ");
            string numberOfWork = Console.ReadLine();
            Console.Write("Введите тему: ");
            string theme = Console.ReadLine();
            Console.Write("Введите задание: ");
            string task = Console.ReadLine();
            Console.Write("Введите вопросы: ");
            string questions = Console.ReadLine();
            Console.Write("Введите код: ");
            string code = Console.ReadLine();

            try {
                Word.Application word = new Word.Application();
                string path = @"C:\\Users\\serge\\OneDrive\\Рабочий стол\\Secret folder\\University\\ProjArch";
                doc = word.Documents.Open(path + "\\" + "template.docx");
                doc.Activate();
            
                doc.Bookmarks["numberOfWork"].Range.Text = numberOfWork;
                doc.Bookmarks["theme"].Range.Text = theme;
                doc.Bookmarks["taskText"].Range.Text = task;
                doc.Bookmarks["questions"].Range.Text = questions;
                doc.Bookmarks["code"].Range.Text = code;

                doc.SaveAs(path + "\\" + name + ".docx");
            
                doc.Close();
                doc = null;
            }
            catch (Exception e) {
                doc = null;
            }
        } 
    }
}