#ifndef VERTICAL_H
#define VERTICAL_H

#include <string>
#include <vector>
#include "ufosim.h"
#include "ufo.h"

using namespace std;

class Vertical : virtual public Ufo {
  
  public:
    //Constructors and destructors don't have a return value ever so making anything const here besides the paramters passed in doesnt make sense....
    Vertical(const string& pld);
    ~Vertical();
    void flyToDest(const float x, const float y, const float height, const int speed) override const;
};

#endif
