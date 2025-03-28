#include <iostream>
#include "vertical.h"
#include "ufosim.h"
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

string Vertical::type = "vertical";

string Vertical::getType() {
  return type;
}

string Vertical::getId() const {
  return id;
}

vector<float> Vertical::getPosition() const {
  vector<float> coord(3);
  coord[0] = sim->getX();
  coord[1] = sim->getY();
  coord[2] = sim->getZ();

  return coord;
}

float Vertical::getFtime() const {
  float ftime = sim->getFtime();
  return ftime;
}

void Vertical::flyToDest(float x, float y, float height, int speed) const {
  sim->flyTo(sim->getX(), sim->getY(), height, speed, 0);
  sim->flyTo(x, y, height, speed, 0);
  sim->flyTo(x, y, 0.0, speed, 0);
};

/*
vector<float> Vertical::wayPoint(float x1, float y1, float x2, float y2, float h, float phi) {
  float phi_rad = phi * M_PI / 180.0;
  
  vector<float> coord(2);


  float<vector> A = coord(2);
  coord[0] = x1;
  coord[1] = y1;

  float<vector> D = coord(2);
  coord[0] = x2;
  coord[1] = y2;

  float<vector> Richtung = coord(2);



  //Ziel: B(coord float vector hier) so setzen das mit dem angewendeten h sich der Winkel phi ergibt

    coord[0] = x1 + h * cos(phi_rad);  // x-Koordinate von B
    coord[1] = y1 + h * sin(phi_rad);  // y-Koordinate von B


  return coord;
}
*/
vector<float> Vertical::wayPoint(float x1, float y1, float x2, float y2, float h, float phi) {

  vector<float> coord(2);


  float phi_rad = phi * M_PI / 180.0;

  // Direction vector AD
  float dx = x2 - x1;
  float dy = y2 - y1;

  // Normalize direction
  float length = sqrt(dx * dx + dy * dy);
  float ux = dx / length;
  float uy = dy / length;

  // Length of AB from height and angle
  float AB = h / tan(phi_rad);

  // Compute point B = A + AB * normalized direction
  float bx = x1 + AB * ux;
  float by = y1 + AB * uy;

  //Ziel: B(coord float vector hier) so setzen das mit dem angewendeten h sich der Winkel phi ergibt

  coord[0] = bx;  // x-Koordinate von B
  coord[1] = by;  // y-Koordinate von B

  
  return coord;

}


/*
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

