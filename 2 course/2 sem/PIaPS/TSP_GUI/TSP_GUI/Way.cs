using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TSP_GUI {
    public class Way {
        public int startTown;
        public int endTown;
    
        public float distance;
    
        public bool active;
    
        public Way(int town1, int town2, int d) {
            startTown = town1;
            endTown = town2;
            distance = d;
            active = false;
        }
    
        public Way(int town1, int town2) {
            startTown = town1;
            endTown = town2;
            active = false;
        }
    }
}
