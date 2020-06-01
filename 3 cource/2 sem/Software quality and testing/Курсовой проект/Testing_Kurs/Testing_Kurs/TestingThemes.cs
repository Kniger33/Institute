/*
 * using                    2       sender          4
 * namespace                1       e               4
 * public                   2       1               1
 * partial                  1       testNumber      3
 * class                    1       test            6
 * TestingThemes            2       2               1
 * Form                     1       3               1
 * InitializeComponent      1
 * private                  4
 * void                     4
 * object                   4
 * EventArgs                4
 * Model                    3
 * Test                     6
 * new                      3
 * =                        6
 * ShowDialog               3
 * Close                    1
 * {}                       7
 * ()                       13
 * ;                        13
 */

using System;
using System.Windows.Forms;

namespace Testing_Kurs
{
    public partial class TestingThemes : Form
    {
        public TestingThemes()
        {
            InitializeComponent();
        }

        private void buttonMarvel_Click(object sender, EventArgs e)
        {
            Model.testNumber = 1;
            Test test = new Test();
            test.ShowDialog();
        }

        private void buttonDC_Click(object sender, EventArgs e)
        {
            Model.testNumber = 2;
            Test test = new Test();
            test.ShowDialog();
        }

        private void buttonSchool_Click(object sender, EventArgs e)
        {
            Model.testNumber = 3;
            Test test = new Test();
            test.ShowDialog();
        }

        private void buttonBack_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
