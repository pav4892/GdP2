#include "vertical.h"
#include <string>
#include <vector>
#include <cmath>
using namespace std;

Vertical::Vertical(const string& pld) {
  id = pld;
  Ufosim::setSpeedup(4);
  sim = new Ufosim();
}

Vertical::~Vertical() {
  delete sim;
};

const string Vertical::type = "vertical";

const string Vertical::getType() {
  return type;
}

const string& Vertical::getId() const {
  return id;
}

const vector<float> Vertical::getPosition() const {
  vector<float> coord(3);
  coord[0] = sim->getX();
  coord[1] = sim->getY();
  coord[2] = sim->getZ();

  return coord;
}

const float Vertical::getFtime() const {
  const float ftime = sim->getFtime();
  return ftime;
}

const void Vertical::flyToDest(const float x, const float y, const float height, const int speed) const {
  sim->flyTo(sim->getX(), sim->getY(), height, speed, 0);
  sim->flyTo(x, y, height, speed, 0);
  sim->flyTo(x, y, 0.0, speed, 0);
};

const vector<float> Vertical::wayPoint(const float x1, const float y1, const float x2, const float y2, const float h, const float phi) {

    //Ziel der funktion: B(coord float vector hier) so setzen das mit dem angewendeten h sich der Winkel phi ergibt

  vector<float> coord(2);


  const float phi_rad = phi * M_PI / 180.0;

  // Direction vector AD
  const float dx = x2 - x1;
  const float dy = y2 - y1;

  // Normalize direction
  const float length = sqrt(dx * dx + dy * dy);
  const float ux = dx / length;
  const float uy = dy / length;

  // Length of AB from height and angle
  const float AB = h / tan(phi_rad);

  // Calc the bx and by via offset + dir vector thing
  const float bx = x1 + AB * ux;
  const float by = y1 + AB * uy;

  coord[0] = bx;  // x-Koordinate von B
  coord[1] = by;  // y-Koordinate von B

  
  return coord;
}


/* Commented out because else the unit tests won't run. This is a old version that doesnt do any ufosim stuff yet, just tested class functionality before I knew how to use the boost stuff
int main() {
  Vertical vertA("stringo");
  cout << vertA.getType() << "\n"; 
  cout << vertA.getId() << "\n"; 
  for(int i = 0; i < 3; i++) {
    cout << vertA.getPosition()[i];
  }
  cout << "\n";
  cout << vertA.getFtime();
  cout << "\n";
  for(int i = 0; i < 2; i++) {
    cout << vertA.wayPoint(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)[i];
  }
  return 0;
}
*/

