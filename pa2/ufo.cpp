#include "vertical.h"
#include "ufo.h"
#include <string>
#include <vector>
#include <cmath>

using namespace std;

Ufo::Ufo(const string& pld) {
  id = pld;
  Ufosim::setSpeedup(4);
  sim = new Ufosim();
}

Ufo::~Ufo() {
  delete sim;
};

const string& Ufo::getId() const {
  return id;
}

const vector<float> Ufo::getPosition() const {
  vector<float> coord(3);
  coord[0] = sim->getX();
  coord[1] = sim->getY();
  coord[2] = sim->getZ();

  return coord;
}

float Ufo::getFtime() const {
  const float ftime = sim->getFtime();
  return ftime;
}

const vector<float> Ufo::wayPoint(const float x1, const float y1, const float x2, const float y2, const float h, const float phi) {

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
