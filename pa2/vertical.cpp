#include "vertical.h"
#include <string>
#include <vector>

using namespace std;

//If a class inherits another class the Constructor of the class that is inherited needs to be noted here as follows
Vertical::Vertical(const string& pld) : Ufo(pld) {
  string a = pld;
};


Vertical::~Vertical() {
//  delete sim;
};


//Macht keinen Sinn das das noch da ist

void Vertical::flyToDest(const float x, const float y, const float height, const int speed) const {
  sim->flyTo(sim->getX(), sim->getY(), height, speed, 0);
  sim->flyTo(x, y, height, speed, 0);
  sim->flyTo(x, y, 0.0, speed, 0);
};
