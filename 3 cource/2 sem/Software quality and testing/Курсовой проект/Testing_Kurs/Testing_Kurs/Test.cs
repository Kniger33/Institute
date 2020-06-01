/*
 * using                5           groupBoxQuestion        2
 * static               1           radioAnswer1            1
 * namespace            1           radioAnswer2            1
 * public               2           radioButtonAnswer3      1
 * private              4           radioButtonAnswer4      1
 * partial              1           testQuestions           14
 * class                1           rightAnswersCount       2
 * Test                 2           questionsMarvel         1
 * Form                 1           labelTheme              3
 * List                 2           "Marvel"                1
 * QuestionClass        2           questionsDC             1
 * InitializeComponent  1           "DC"                    1
 * switch               1           Text                    10
 * case                 3           questionsSchool         1
 * ToList               3           "Школьная программа"    1
 * LoadQuestion         6           questionNumber          6
 * labelTheme           3           sender                  2
 * break                3           e                       2
 * void                 3           control                 3
 * int                  2           Controls                1
 * object               2           radioButton             3
 * EventArgs            2           Checked                 1
 * foreach              1           trueAnswerNumber        2
 * Control              1           TrueAnswer              1
 * in                   1           Answers                 5
 * if                   5           Question                1
 * is                   1           Count                   2
 * RadioButton          3           "Результат"             1
 * RemoveAt             1           result                  2
 * else                 2           0                       11
 * Result               2           1                       3
 * ShowDialog           1           2                       1
 * new                  1           3                       1
 * Close                2           
 * =                    17          
 * ==                   3           
 * -                    1           
 * ++                   1           
 * ;                    36          
 * {}                   14          
 * ()                   26          
 * []                   12          
 * 
*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
using static Testing_Kurs.Model;

namespace Testing_Kurs
{
    public partial class Test : Form
    {
        private List<QuestionClass> testQuestions = new List<QuestionClass>();
        public Test()
        {
            InitializeComponent();

            rightAnswersCount = 0;

            switch(testNumber)
            {
                case 1:
                    testQuestions = questionsMarvel.ToList();
                    labelTheme.Text = "Marvel";
                    LoadQuestion(0);
                    break;
                case 2:
                    testQuestions = questionsDC.ToList();
                    labelTheme.Text = "DC";
                    LoadQuestion(0);
                    break;
                case 3:
                    testQuestions = questionsSchool.ToList();
                    labelTheme.Text = "Школьная программа";
                    LoadQuestion(0);
                    break;
            }
        }

        private void LoadQuestion(int questionNumber)
        {
            groupBoxQuestion.Text = testQuestions[questionNumber].Question;
            radioAnswer1.Text = testQuestions[questionNumber].Answers[0];
            radioAnswer2.Text = testQuestions[questionNumber].Answers[1];
            radioButtonAnswer3.Text = testQuestions[questionNumber].Answers[2];
            radioButtonAnswer4.Text = testQuestions[questionNumber].Answers[3];
        }

        private void buttonNextQuestion_Click(object sender, EventArgs e)
        {
            // 1
            foreach (Control control in groupBoxQuestion.Controls)
            {
                // 2
                if (control is RadioButton)
                {
                    // 3
                    RadioButton radioButton = control as RadioButton;
                    
                    // 4
                    if (radioButton.Checked)
                    {
                        // 5
                        int trueAnswerNumber = testQuestions[0].TrueAnswer;
                        
                        // 6
                        if (radioButton.Text == testQuestions[0].Answers[trueAnswerNumber - 1])
                        {
                            // 7
                            rightAnswersCount++;
                        }   
                    }
                }
            }

            // 8
            testQuestions.RemoveAt(0);
            // 9
            if (testQuestions.Count == 1)
            {
                // 10
                LoadQuestion(0);
                buttonNextQuestion.Text = "Результат";
            }
            // 11
            else if (testQuestions.Count == 0)
            {
                // 12
                Result result = new Result();
                result.ShowDialog();
                Close();
            }
            // 13
            else
            {
                // 14
                LoadQuestion(0);
            }
        }

        private void buttonExitToMain_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
