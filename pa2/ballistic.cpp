#include "ballistic.h"
#include "ufo.h"
#include "ufosim.h"
#include <vector>
#include <iostream>

using namespace std;

//If a class inherits another class the Constructor of the class that is inherited needs to be noted here as follows
Ballistic::Ballistic(const string& pld, const float pTakeOffAngle, const float pLandingAngle) : Ufo(pld) { 

  if(0 < pTakeOffAngle && pTakeOffAngle <= 90) {
    takeOffAngle = pTakeOffAngle;
  } else {
    takeOffAngle = 45.0;
  }

  if(0 < pLandingAngle && pLandingAngle <= 90) {
    landingAngle = pLandingAngle;
  } else {
    landingAngle = 45.0;
  }
};

Ballistic::~Ballistic(){};

const float Ballistic::getTakeOffAngle() const {
  return takeOffAngle;
};

const float Ballistic::getLandingAngle() const {
    return landingAngle;
};

const vector<float> Ballistic::firstWaypoint(const float x, const float y, const float height) const {
  return wayPoint(sim->getX(), sim->getY(), x, y, height, takeOffAngle); 
};

const vector<float> Ballistic::secondWaypoint(const float x, const float y, const float height) const {
  return wayPoint(sim->getX(), sim->getY(), x, y, height, landingAngle); 
};

void Ballistic::flyToDest(const float x, const float y, const float height, const int speed) const {
  float x1 = firstWaypoint(x, y, height)[0];
  float y1 = firstWaypoint(x, y, height)[1];
  float x2 = secondWaypoint(x, y, height)[0];
  float y2 = secondWaypoint(x, y, height)[1];
  sim->flyTo(x1, y1, height, speed, speed);
  sim->flyTo(x2, y2, height, speed, speed);
  sim->flyTo(x, y, 0.0f, speed, speed);
};

