#include <iostream>
#include <string>
#include "vertical.h"
#include "ballistic.h"
#include "ufo.h"

using namespace std;

int main() {
  Vertical* vert = new Vertical("vert");
  Ballistic* ball = new Ballistic("ball", 30.0, 60.0);
  vector<Ufo*> ufos = {vert, ball};

  cout<<"0(vert) or 1(ball)" << endl;
  int input = 2;
  cin>>input;
  if(input == 0 || input == 1) {
    ufos[input]->flyToDest(15.0, -30.0, 8.0, 10.0); 
  }
  return 0;
}
