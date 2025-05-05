#include <functional>
#include "vertical.h"

using namespace std;

class Route {

  private:
    const vector<pair<float, float>>* destinations;   // the floats, pairs etc in here cannot be const, just like any vector content-type-definition
    float height;
    const function<float(float, float, float, float, float)> dist; //function template for any method/function that takes in 5 floats and returns 1 float
  public:
    Route(const float pHeight, const function<float(float, float, float, float, float)> pDist);  // Constructor 1 
    Route(Route& route);                               // Constructor 2 - Use more than 1 constructor via constructor overloading, which constructor is chosen depends on the Uebergabe-parameter given to it. Here the second
                                                       // Constructor will only be called if a copy of the instance of this class is created, e.g. via Route route2 = route1; or something. This is called copy-constructor
    ~Route();
    void add(const float destX, const float destY);
    const vector<pair<float, float>>& getDestinations();
    const float getHeight() const;
    void setHeight(const float pHeight);
    void setDist(function<float(float, float, float, float, float)> pDist);
    const float distance() const;
    const Route shortestRoute();
};
