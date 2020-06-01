/*
 * using                    3           Question            3
 * namespace                1           Answers             3
 * class                    2           TrueAnswer          3
 * Model                    1           question            2
 * QuestionClass            5           answers             2
 * public                   12          trueAnswer          2
 * string                   6           "Q: "               1
 * get                      3           "A: "               1
 * set                      3           "TA: "              1
 * private                  3           answer              2
 * List                     5           userName            1
 * int                      4           testNumber          1
 * ToList                   1           rightAnswersCount   1
 * Console.WriteLine        3           questionsMarvel     1
 * $                        3           questionsDC         1
 * foreach                  1           questionsSchool     1   
 * in                       1
 * ;                        21 
 * =                        3
 * {}                       12
 * ()                       7
 * */
using System;
using System.Collections.Generic;
using System.Linq;


namespace Testing_Kurs
{
    class Model
    {
        public class QuestionClass
        {
            public string Question { get; private set; }
            public List<string> Answers { get; private set; }
            public int TrueAnswer { get; private set; }
            public QuestionClass(string question, List<string> answers, int trueAnswer)
            {
                Question = question;
                Answers = answers.ToList();
                TrueAnswer = trueAnswer;
            }

            public void PrintQuestion()
            {
                Console.WriteLine($"Q: {Question}");
                foreach(string answer in Answers)
                {
                    Console.WriteLine($"A: {answer}");
                }
                Console.WriteLine($"TA: {TrueAnswer}");
            }
        }

        public static string userName;
        public static int testNumber;
        public static int rightAnswersCount;

        public static List<QuestionClass> questionsMarvel;
        public static List<QuestionClass> questionsDC;
        public static List<QuestionClass> questionsSchool;

    }
}
