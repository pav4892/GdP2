#include "vertical.h"
#include "ufo.h"
#include <string>
#include <vector>
#include <cmath>
using namespace std;

//Vertical::Vertical(const string& pld) {};
Vertical::Vertical(){};
Vertical::~Vertical() {
  delete sim;
};

//Macht keinen Sinn das das noch da ist

void Vertical::flyToDest(const float x, const float y, const float height, const int speed) const {
  sim->flyTo(sim->getX(), sim->getY(), height, speed, 0);
  sim->flyTo(x, y, height, speed, 0);
  sim->flyTo(x, y, 0.0, speed, 0);
};
