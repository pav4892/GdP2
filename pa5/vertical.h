#ifndef VERTICAL_H
#define VERTICAL_H

#include "ufosim.h"
#include "ufo.h"

using namespace std;


//Here Vertical inherits the Ufo class

class Vertical : virtual public Ufo {            //Vertical inherits Ufo in order to be able to override the flyToDest function
  
  public:
    //Constructors and destructors don't have a return value ever so making anything const here besides the paramters passed in doesnt make sense....
    //Vertical(const string& pld);
    Vertical(const string& pld);
    ~Vertical();
    //This will then be inherited and overwritten by ufo class I think
    void flyToDest(const float x, const float y, const float height, const int speed) const override;
    static float distance(const float x1, const float y1, const float x2, const float y2, const float h);
};

#endif
