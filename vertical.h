#ifndef VERTICAL_H
#define VERTICAL_H

#include <string>
#include <vector>
#include "ufosim.h"

using namespace std;

class Vertical {
  
  private:
    static string type;
    string id;
    Ufosim* sim;
  
  public:
    Vertical(const string& pld);
    ~Vertical();
    static string getType();
    string getId() const;
    vector<float> getPosition() const;
    float getFtime() const;
    void flyToDest(const float x, const float y, const float height, const int speed) const;
    static vector<float> wayPoint(const float x1, const float y1, const float x2, const float y2, const float h, const float phi);
};

#endif
