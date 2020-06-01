/*
 * using                    7           path                        8
 * static                   3           "..\..\Tests\Marvel.txt"    1
 * namespace                1           questionsMarvel             1
 * class                    1           "..\..\Tests\DC.txt"        1
 * public                   2           questionsDC                 1
 * void                     1           "..\..\Tests\School.txt"    1
 * LoadAllQuestions         1           questionsSchool             1
 * GetQuestions             3           questions                   3
 * string                   10          sr                          8
 * ToList                   3           question                    2
 * List                     5           answer1                     2
 * QuestionClass            5           answer2                     2
 * new                      3           answer3                     2
 * StreamReader             2           answer4                     2
 * Encoding.UTF8            1           trueAnswer                  2
 * while                    1           answers                     2
 * ReadLine                 6           questionClass               2
 * Convert.ToInt32          1
 * Add                      1
 * return                   1
 * ;                        23
 * {}                       7
 * ()                       22
 * @                        3
 * =                        16
 * <>                       5
 * 
 */
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using static Testing_Kurs.Model;

namespace Testing_Kurs
{
    class LoadQuestions
    {
        public static void LoadAllQuestions()
        {
            string path = @"..\..\Tests\Marvel.txt";
            questionsMarvel = GetQuestions(path).ToList();

            path = @"..\..\Tests\DC.txt";
            questionsDC = GetQuestions(path).ToList();

            path = @"..\..\Tests\School.txt";
            questionsSchool = GetQuestions(path).ToList();

        }
        public static List<QuestionClass> GetQuestions(string path)
        {
            // 1
            List<QuestionClass> questions = new List<QuestionClass>();
            
            // 2
            using (StreamReader sr = new StreamReader(path, Encoding.UTF8))
            {
                // 3
                while (!sr.EndOfStream)
                {
                    // 4
                    string question = sr.ReadLine();
                    string answer1 = sr.ReadLine();
                    string answer2 = sr.ReadLine();
                    string answer3 = sr.ReadLine();
                    string answer4 = sr.ReadLine();
                    string trueAnswer = sr.ReadLine();

                    // 5
                    List<string> answers = new List<string>() { answer1, answer2, answer3, answer4 };

                    // 6
                    QuestionClass questionClass = new QuestionClass(question, answers, Convert.ToInt32(trueAnswer));
                    questions.Add(questionClass);
                }
            }
            // 7
            return questions;
        }
    }
}
