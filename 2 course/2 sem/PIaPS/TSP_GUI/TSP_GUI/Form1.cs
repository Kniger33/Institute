using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TSP_GUI {
    public partial class Form1 : Form {
        public View view;
        public Model model;
        
        private bool EqualWay(Way left, int start, int end) {
            if ((left.startTown == start) && (left.endTown == end) ||
                     (left.startTown == end) && (left.endTown == start)) {
                return true;
            }
            else {
                return false;
            }
        }

        public Form1() {
            InitializeComponent();

            view = new View(this);
            model = new Model();
        }
        
        static long Factorial(long x) {
            return (x == 0) ? 1 : x * Factorial(x - 1);
        }

        private void CountOKButton_MouseClick(object sender, MouseEventArgs e) {
            model.townCount = view.GetTownCount();
            
            int wayCount = (int)Factorial(model.townCount / (2 * Factorial(model.townCount - 2)));

            for (int i = 0; i < model.townCount; i++) {
                for (int j = i + 1; j < model.townCount; j++) {
                    string way = (char)(model.firstTown + i) + "-" + (char)(model.firstTown + j);
                    string[] row = { way, "" };
                    WayLengthTable.Rows.Add(row);
                }
            }
        }
        

        private void FindWayButton_MouseClick(object sender, MouseEventArgs e) {
            model.wayMatrix = new int[model.townCount + 1, model.townCount + 1];
            int row = 0;

            for (int i = 0; i < model.townCount; i++) {
                for (int j = 0; j < model.townCount; j++) {
                    if (i < j) {
                        object str = WayLengthTable[1, row].Value;
                        if (str.ToString() == string.Empty) {
                            model.wayMatrix[i, j] = model.wayMatrix[j, i] = model.inf;
                        }
                        else {
                            model.wayMatrix[i, j] = model.wayMatrix[j, i] = int.Parse(str.ToString());
                            model.wayLines.Add(new Way(i, j, int.Parse(str.ToString())));
                        }
                        row++;
                    }
                    else if (i == j) {
                        model.wayMatrix[i, j] = model.inf;
                    }
                }
            }

            for (int i = 0; i < model.townCount; i++) {
                for (int j = 0; j < model.townCount; j++) {
                    Console.Write(model.wayMatrix[i, j] + " ");
                }
                Console.WriteLine();
            }

            model.startTowns = new int[model.townCount];
            model.endTowns = new int[model.townCount];
            
            for (int i = 0; i < model.townCount; i++) {
                FindWay(i);
            }

            int[] path = CreatePath(model.startTowns, model.endTowns);
            string p = new string((char)(model.firstTown + path[0]), 1);

            for (int i = 1; i < model.townCount + 1; i++) {
                p += "-" + new string((char)(model.firstTown + path[i]), 1);
            }

            view.SetPath(p);

            view.SetPathLength(FindActiveWays(model.startTowns, model.endTowns));

            view.DrawGraph();
        }
        
        private void FindWay(int iteration) {
            int[] di = new int[model.townCount];
            int[] dj = new int[model.townCount];

            int[,] wayMarks = new int[model.townCount, model.townCount];

            int i, j;

            for (i = 0; i < model.townCount; i++) {
                for (j = 0; j < model.townCount; j++) {
                    wayMarks[i, j] = -1;
                }
            }
            
            int rowMin = model.inf, columnMin = model.inf;

            #region reduxing
            for (i = 0; i < model.townCount; i++) {
                rowMin = model.inf;

                for (j = 0; j < model.townCount; j++) {
                    if (model.wayMatrix[i, j] != model.inf && model.wayMatrix[i, j] < rowMin) {
                        rowMin = model.wayMatrix[i, j];
                    }
                }

                di[i] = rowMin;

                for (j = 0; j < model.townCount; j++) {
                    if (model.wayMatrix[i, j] != model.inf) {
                        model.wayMatrix[i, j] -= rowMin;
                    }
                }
            }
            
            for (j = 0; j < model.townCount; j++) {
                columnMin = model.inf;
                for (i = 0; i < model.townCount; i++) {
                    if (model.wayMatrix[i, j] != model.inf && model.wayMatrix[i, j] < columnMin) {
                        columnMin = model.wayMatrix[i, j];
                    }
                }

                dj[j] = columnMin;

                for (i = 0; i < model.townCount; i++) {
                    if (model.wayMatrix[i, j] != model.inf) {
                        model.wayMatrix[i, j] -= columnMin;
                    }
                }
            }
            #endregion

            #region marking
            for (i = 0; i < model.townCount; i++) {
                for (j = 0; j < model.townCount; j++) {
                    if (model.wayMatrix[i, j] == 0) {
                        rowMin = columnMin = model.inf;

                        for (int j1 = 0; j1 < model.townCount; j1++) {
                            if (j1 != j && model.wayMatrix[i, j1] != model.inf && model.wayMatrix[i, j1] < rowMin) {
                                rowMin = model.wayMatrix[i, j1];
                            }
                        }

                        for (int i1 = 0; i1 < model.townCount; i1++) {
                            if (i1 != i && model.wayMatrix[i1, j] != model.inf && model.wayMatrix[i1, j] < columnMin) {
                                columnMin = model.wayMatrix[i1, j];
                            }
                        }

                        int mark;
                        if (rowMin == model.inf || columnMin == model.inf ) {
                            mark = model.inf;
                        }
                        else {
                            mark = rowMin + columnMin;
                        }
                        
                        wayMarks[i, j] = mark;
                    }
                }
            }
            #endregion

            #region findMaxMark
            int maxMark = -1;
            int maxI = -1, maxJ = -1;

            for (i = 0; i < model.townCount; i++) {
                for (j = 0; j < model.townCount; j++) {
                    if (wayMarks[i, j] >= maxMark) {
                        maxMark = wayMarks[i, j];
                        maxI = i;
                        maxJ = j;
                    }
                }
            }
            #endregion

            Console.WriteLine("Way: " + maxI + " - " + maxJ);

            model.startTowns[iteration] = maxI;
            model.endTowns[iteration] = maxJ;

            for (i = 0; i < model.townCount; i++) {
                model.wayMatrix[i, maxJ] = model.inf;
            }
            for (j = 0; j < model.townCount; j++) {
                model.wayMatrix[maxI, j] = model.inf;
            }

            model.wayMatrix[maxJ, maxI] = model.inf;
        }

        private int[] CreatePath(int[] starts, int[] ends) {
            Console.WriteLine("Path: ");
            int[] path = new int[model.townCount + 1];

            path[0] = starts[0];
            path[1] = ends[0];
            int lastEndPoint = ends[0];

            for (int i = 2; i < model.townCount + 1; i++) {
                path[i] = ends[Array.IndexOf(starts, lastEndPoint)];
                lastEndPoint = path[i];
            }

            for (int i = 0; i < model.townCount + 1; i++) {
                Console.WriteLine(path[i] + " ");
            }

            return path;
        }

        private int FindActiveWays(int[] starts, int[] ends) {
            int sum = 0;

            for (int i = 0; i < starts.Length; i++) {
                for (int j = 0; j < model.wayLines.Count; j++) {
                    if (EqualWay(model.wayLines[j], starts[i], ends[i]) == true) {
                        model.wayLines[j].active = true;
                        sum += (int)model.wayLines[j].distance;
                        break;
                    }
                }
            }

            return sum;
        }

        

        private void RestartButton_Click(object sender, EventArgs e) {
            WayLengthTable.Rows.Clear();
            PathTextBox.Clear();
            LengthTextBox.Clear();
            GraphPanel.Refresh();
            view.townCircles.Clear();
            model.wayLines.Clear();
        }
    }
}
