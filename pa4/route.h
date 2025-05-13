#include <functional>
#include <vector>

using namespace std;

class Route {
private:
    vector<pair<float, float>>* destinations;
    float height;
    function<float(float, float, float, float, float)> dist;

public:
    Route(float pHeight, function<float(float, float, float, float, float)> pDist); // Constructor 1 
    Route(const Route& route); // Copy constructor
    ~Route();

    void add(const float destX, const float destY);
    const vector<pair<float, float>>& getDestinations() const;
    float getHeight() const;
    void setHeight(const float pHeight);
    void setDist(function<float(float, float, float, float, float)> pDist);
    float distance() const;
    const Route shortestRoute() const;
};

