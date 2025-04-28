#include <iostream>
#include <string>
#include "vertical.h"
#include "ballistic.h"
#include "ufo.h"

using namespace std;

int main() {
  Vertical* vert = new Vertical("vert");
  Ballistic* ball = new Ballistic("ball", 30.0, 50.0);
  vector<Ufo*> ufos = {vert, ball};

  cout<<"0 or 1" << endl;
  int input = 2;
  cin>>input;
  if(input == 0 || input == 1) {
    ufos[input]->flyToDest(10.0, 10.0, 10.0, 10.0); 
  }
  return 0;
}
