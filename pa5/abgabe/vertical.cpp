#include "vertical.h"
#include <string>
#include <vector>
#include <cmath>

using namespace std;

//If a class inherits another class the Constructor of the class that is inherited needs to be noted here as follows
Vertical::Vertical(const string& pld) : Ufo(pld) {};


Vertical::~Vertical() {};

void Vertical::flyToDest(const float x, const float y, const float height, const int speed) const {
  sim->flyTo(sim->getX(), sim->getY(), height, speed, 0);
  sim->flyTo(x, y, height, speed, 0);
  sim->flyTo(x, y, 0.0, speed, 0);
};

float Vertical::distance(const float x1, const float y1, const float x2, const float y2, const float h) {
  float distanzGesamt = 0;
  distanzGesamt += h; // Flugabschnitt 1  
  distanzGesamt += sqrt(pow(abs(x2-x1),2) + pow(abs(y2-y1),2)); // Flugabschnitt 2   -- Phytagoras?? c^2 = a^2+b^2  | Wir brauchen c also c=sqrt(a^2+b^2) --> distanzGesamt = sqrt((x2-x1)**2+(y2-y1)**2)  - Wir brauchen ja
                                                                // die strecke X und Y also diff berechnen... https://moodle.thi.de/pluginfile.php/652211/mod_resource/content/11/cx3_praktikum.pdf Seite 2 hilft. Wir brauchen
                                                                // die Strecke, kann aber schraeg sein, deswegen pytagoras. 'abs' gibt absoluten value, also dass es egal ist in welche richtung das fliegt, auch rueckwaerts...
  distanzGesamt += h; // Flugabschnitt 3
  return distanzGesamt;
};
