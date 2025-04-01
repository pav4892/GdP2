#ifndef VERTICAL_H
#define VERTICAL_H

#include <string>
#include <vector>
#include "ufosim.h"
#include "ufo.h"

using namespace std;


//Here Ballistic inherits an Ufo class that gives me access to the ... idk 

class Vertical : virtual public Ufo {            //Vertical inherits Ufo in order to be able to override the flyToDest function
  
  public:
    //Constructors and destructors don't have a return value ever so making anything const here besides the paramters passed in doesnt make sense....
    //Vertical(const string& pld);
    Vertical();
    ~Vertical();
    void flyToDest(const float x, const float y, const float height, const int speed) const override;
};

#endif
