/*
 * using                    3           Text                5
 * static                   1           userName            1
 * namespace                1           "Ваш результат, :"  1
 * public                   2           rightAnswersCount   6
 * partial                  1           "Плохо, Вы ответили правильно менее, чем на 60% вопросов"               1
 * class                    1           "Удовлетворительно, Вы ответили правильно более, чем на 60% вопросов"   1
 * Result                   2           "Хорошо, Вы ответили правильно более, чем на 70% вопросов"              1
 * Form                     1           "Отлично, Вы ответили правильно более, чем на 80% вопросов"             1
 * InitializeComponent      1           5                   1
 * label1                   1           6                   1
 * if                       4           7                   1
 * else                     3           8                   2
 * labelResult              4           9                   1
 * private                  1           sender              1
 * void                     1           e                   1
 * object                   1
 * EventArgs                1
 * Close                    1
 * <                        3
 * >                        3
 * ;                        10
 * =                        5
 * $                        1
 * {}                       9
 * ()                       8
 * &&                       2
 */
using System;
using System.Windows.Forms;
using static Testing_Kurs.Model;


namespace Testing_Kurs
{
    public partial class Result : Form
    {
        public Result()
        {
            InitializeComponent();
            label1.Text = $"Ваш результат, {userName}:";
            
            if (rightAnswersCount < 6)
            {
                labelResult.Text = "Плохо, Вы ответили правильно менее, чем на 60% вопросов";
            }
            else if (rightAnswersCount > 5
                    && rightAnswersCount < 8)
            {
                labelResult.Text = "Удовлетворительно, Вы ответили правильно более, чем на 60% вопросов";
            }
            else if (rightAnswersCount > 7
                    && rightAnswersCount < 9)
            {
                labelResult.Text = "Хорошо, Вы ответили правильно более, чем на 70% вопросов";
            }
            else if (rightAnswersCount > 8)
            {
                labelResult.Text = "Отлично, Вы ответили правильно более, чем на 80% вопросов";
            }
        }

        private void buttonExit_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
