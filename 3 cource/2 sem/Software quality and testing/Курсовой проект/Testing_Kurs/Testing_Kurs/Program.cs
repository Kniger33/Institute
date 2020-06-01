/*
 * using                2                       false       1
 * ;                    5
 * namespace            1
 * static               2
 * class                1
 * STAThread            1
 * [                    1
 * ]                    1
 * void                 1
 * Application          3
 * EnableVisualStyles   1
 * SetCompatibleTextRenderingDefault    1
 * Run                  1
 * new                  1
 * {                    3
 * }                    3
 * (                    5
 * )                    5
*/
using System;
using System.Windows.Forms;

namespace Testing_Kurs
{
    static class Program
    {
        /// <summary>
        /// Главная точка входа для приложения.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
}
