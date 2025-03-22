#include <iostream>
#include "vertical.h"
#include <string>
#include <vector>
using namespace std;

Vertical::Vertical(const string& pld) {
  id = pld;
}

Vertical::~Vertical() {};

string Vertical::type = "vertical";

string Vertical::getType() {
  return type;
}

string Vertical::getId() const {
  return id;
}

vector<float> Vertical::getPosition() const {
  vector<float> coord(3);
  coord[0] = 0.0;
  coord[1] = 0.0;
  coord[2] = 0.0;

  return coord;
}

float Vertical::getFtime() const {
  float ftime = 0.0;
  return ftime;
}

void Vertical::flyToDest(float x, float y, float height, int speed) const {};

vector<float> Vertical::waypoint(float x1, float y1, float x2, float y2, float h, float phi) {
  vector<float> coord(2);
  coord[0] = 0.0;
  coord[1] = 0.0;

  return coord;
}

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
    cout << vertA.waypoint(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)[i];
  }
  return 0;
}
