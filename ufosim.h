#ifndef UFOSIM_H
#define UFOSIM_H

using namespace std

class Ufosim {

  public:
    Ufosim();
    ~Ufosim();
    float getX() const;
    float getY() const;
    float getZ() const;
    int getV() const;
    float getDist() const;
    float getFtime() const;
    static void setSpeedup(int speedup);
    void flyTo(float xDest; float yDest; float zDest; int vFlight; int vPost) const;

}

#endif
