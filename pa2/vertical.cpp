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

void Vertical::flyToDest(const float x, const float y, const float height, const int speed) const {
  sim->flyTo(sim->getX(), sim->getY(), height, speed, 0);
  sim->flyTo(x, y, height, speed, 0);
  sim->flyTo(x, y, 0.0, speed, 0);
};
