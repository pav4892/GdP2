#include "vertical.h"
#include "ufo.h"
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

  // Ziel der funktion: Punkt B (vector<float> coord(2) hier) so setzen das mit dem angewendeten h sich der Winkel phi ergibt. Es wird also die 2 Waypoints(einer pro aufrauf) berechnet die das Ufo bei der Flugsimulation ansteuert bevor
  // er das Ziel erreicht. Quelle der Funktion: Teilweise durch Internetquellen unterstuetzt
  //
  // Der Punkt B liegte auf der Strecke A(x1,y1) und D(x2, y2) und er soll so bestimmt und returned werden, dass das Dreieck ABh den Winkel 'phi' und die Hoehe 'h' hat.

  vector<float> coord(2); // Vector indem der Punkt B gespeichert und dann returned wird.

  const float phi_rad = phi * M_PI / 180.0;  // Uebergabe-Winkel phi(der aus den Funktionsparamtern) in Bogenmass umrechnen

  // Vektoren Berechnen die von A(Vektor dx, zeigt grade nach rechts kinda) nach D(Vektor dy, zeigt grade nach unten kinda). Zusammen bilden die einen Vektor v der der Richtung von AB entspricht
  const float dx = x2 - x1;
  const float dy = y2 - y1;

  // Normalize direction
  const float length = sqrt(dx * dx + dy * dy); // Laenge des Richtungsvektors von AB (dx, dy)
  const float ux = dx / length;                 // Normalize den Richtungsvektor, also wir machen ihn unabhaengig von der Laenge von AB das wir ihn roh verwenden koennen.
  const float uy = dy / length;                 // -||-

  // Laenge von AB berechnen sodass 'h' und 'phi' den Werten entsprechen die der Funktion uebergeben wurden.
  const float AB = h / tan(phi_rad);

  // Finale Werte des Punktes B: Wird berechnet indem wir zu unserer jetzigen Position den Richungsvektor*Laenge von AB dazuaddieren
  const float bx = x1 + AB * ux;
  const float by = y1 + AB * uy;

  coord[0] = bx;  // x-Koordinate von B
  coord[1] = by;  // y-Koordinate von B
  
  return coord;
};
