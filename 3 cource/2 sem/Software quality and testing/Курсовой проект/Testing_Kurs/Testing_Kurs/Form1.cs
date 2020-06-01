/*
 * using                2           sender          4
 * namespace            1           e               4
 * public               2           userName        1
 * partial              1           Text            1
 * class                1           testingThemes   1
 * Form1                2
 * InitializeComponent  1
 * private              4
 * void                 4
 * object               4
 * LoadQuestions        1
 * Model                1
 * TestingThemes        2
 * ShowDialog           1
 * Close                1
 * EventArgs            4
 * {}                   7
 * ()                   10
 * ;                    8
 * new                  1
 */
using System;
using System.Windows.Forms;

namespace Testing_Kurs
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            LoadQuestions.LoadAllQuestions();
        }

        private void buttoEnterName_Click(object sender, EventArgs e)
        {
            Model.userName = textBoxUserName.Text;
        }

        private void buttonStartTesting_Click(object sender, EventArgs e)
        {
            TestingThemes testingThemes = new TestingThemes();
            testingThemes.ShowDialog();
        }

        private void buttonExit_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
