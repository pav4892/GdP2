#include <iostream>
#include <string>
#include "vertical.h"
#include "ballistic.h"
#include "ufo.h"

using namespace std;

int main() {
  Vertical* vert = new Vertical("vert");
  Ballistic* ball = new Ballistic("ball", 4.0, 4.0); // takeoffAngle, landingAngle
  vector<Ufo*> ufos = {vert, ball};

  cout<<"0(vert) or 1(ball)" << endl;
  int input = 2;
  cin>>input;
  if(input == 0 || input == 1) {
    ufos[input]->flyToDest(0.0, 10.5, 10.5, 1.0); //x, y, height, speed
  }
  return 0;
}
