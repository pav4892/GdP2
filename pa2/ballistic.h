#include <vector>
#include <string>
#include "ufo.h"

using namespace std;

//Here Ballistic inherits an Ufo class that gives me access to the Ufosim* sim from ufo.h 

class Ballistic : virtual public Ufo {
  private: 
    //Can't be const because we will be re-setting it later 
    float takeOffAngle;
    float landingAngle;
    vector<float> initialPosPreWaypointMove = {0.0f, 0.0f};

  public: 
    Ballistic(const string& pld, const float pTakeOffAngle, const float pLandingAngle);
    ~Ballistic();
    const float getTakeOffAngle() const;
    const float getLandingAngle() const;
    void flyToDest(const float x, const float y, const float height, const int speed) const;
    const vector<float> firstWaypoint(const float x, const float y, const float height) const;
    const vector<float> secondWaypoint(const float x, const float y, const float height) const;
};
