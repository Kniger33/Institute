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
    public class View {
        Form1 form;

        Graphics g;
        Pen blackPen;
        Pen redPen;
        Pen bluePen;
        Font drawFont;
        SolidBrush blackBrush;
        SolidBrush whiteBrush;

        public List<Point> townCircles;

        public View(Form1 f) {
            form = f;

            blackPen = new Pen(Color.Black, 2);
            redPen = new Pen(Color.Red, 2);
            bluePen = new Pen(Color.Blue, 2);
            drawFont = new Font("Arial", 16);
            blackBrush = new SolidBrush(Color.Black);
            whiteBrush = new SolidBrush(Color.White);

            townCircles = new List<Point>();

            g = form.GraphPanel.CreateGraphics();
        }

        public int GetTownCount() {
            return (int)form.TownCountSelector.Value;
        }

        public void SetPath(string path)
        {
            form.PathTextBox.Text = path;
        }

        public void SetPathLength(int length)
        {
            form.LengthTextBox.Text = length.ToString();
        }

        public void DrawGraph() {
            form.GraphPanel.Refresh();
            float angle = 360 / form.model.townCount;
            int x0 = 200, y0 = 200;
            int radius = 175;

            Console.WriteLine("Angle: " + angle);

            for (int i = 0; i < form.model.townCount; i++) {
                float fi = -i * angle * (float)Math.PI / 180;
                int x = (int)(x0 + radius * Math.Cos(fi));
                int y = (int)(y0 - radius * Math.Sin(fi));

                townCircles.Add(new Point(x, y));
            }

            foreach (Way way in form.model.wayLines) {
                Point start = townCircles[way.startTown];
                Point end = townCircles[way.endTown];

                if (way.active) {
                    g.DrawLine(bluePen, start.X, start.Y, end.X, end.Y);
                }
                else {
                    g.DrawLine(blackPen, start.X, start.Y, end.X, end.Y);
                }

                g.DrawString(way.distance.ToString(), drawFont, new SolidBrush(Color.Red), (start.X + end.X) / 2, (start.Y + end.Y) / 2);
            }

            for (int i = 0; i < townCircles.Count; i++) {
                g.FillEllipse(whiteBrush, townCircles[i].X - 15, townCircles[i].Y - 15, 30, 30);
                g.DrawEllipse(blackPen, townCircles[i].X - 15, townCircles[i].Y - 15, 30, 30);
                g.DrawString(new string((char)(form.model.firstTown + i), 1), drawFont, blackBrush, townCircles[i].X - 10, townCircles[i].Y - 10);
            }
        }
    }
}
