#ifndef UFO_H
#define UFO_H

#include <string>
#include <vector>
#include "ufosim.h"

using namespace std;

class Ufo {
  
  private:
    string id;
  protected:          // Weil # in Klassendiagram
    Ufosim* sim;
  
  public:
    //Constructors and destructors don't have a return value ever so making anything const here besides the paramters passed in doesnt make sense....
    Ufo(const string& pld);
    virtual ~Ufo();
    //The first const means that it will return a const string and the one at the end means that the function wont modify the class or object it i s part of 
    const string& getId() const;
    const vector<float> getPosition() const;
    float getFtime() const;
    //This will then be inherited and overwritten by ufo class I think. Yes it is virtual so we dont define it in ufo.cpp but simply override it in vertical.cpp because
    //the virtical class inherits the Ufo class in vertical.h
    virtual void flyToDest(const float x, const float y, const float height, const int speed) const = 0;
    static const vector<float> wayPoint(const float x1, const float y1, const float x2, const float y2, const float h, const float phi);
};

#endif
