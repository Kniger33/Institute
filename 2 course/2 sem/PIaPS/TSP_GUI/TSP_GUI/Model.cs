using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TSP_GUI {
    public class Model {
        public char firstTown = 'A';
        public int[,] wayMatrix;
        public int townCount;
        
        public int inf = int.MaxValue;
        public int[] startTowns;
        public int[] endTowns;

        public List<Way> wayLines;

        public Model() {
            wayLines = new List<Way>();
        }
    }
}
