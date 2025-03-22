#ifndef VERTICAL_H
#define VERTICAL_H

#include <string>
#include <vector>
using namespace std;

class Vertical {
  
  private:
    static string type;
    string id;
    //Ufosim* sim;
  
  public:
    Vertical(const string& pld);
    ~Vertical();
    static string getType();
    string getId() const;
    vector<float> getPosition() const;
    float getFtime() const;
    void flyToDest(float x, float y, float height, int speed) const;
    static vector<float> waypoint(float x1, float y1, float x2, float y2, float h, float phi);
};

#endif
