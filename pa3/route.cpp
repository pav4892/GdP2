#include "route.h"
#include <functional>

using namespace std;

Route::Route(const float pHeight, const function<float(float, float, float, float, float)> pDist) {
  height = pHeight;
  dist = pDist;
};

Route::Route(Route& route) {
  height = route.height;
  dist = route.dist;
};

Route::~Route(){};

void add(const float destX, const float destY) const {
  const vector<float x, float y> elem;
  destinations.push_back(elem); // Add element to end of destinations vector
};

const vector<pair<float, float>>& getDestinations() const {
  return destinations;
};

const float getHeight() const {
  return height;
};

void setHeight(const float pHeight) const {
  height = pHeight;
};

void setDist(function<float(float, float, float, float, float)> pDist) const {
  dist = pDist;
};

const float distance() const { // not same as in vertical... check ich nicht, fix later. This is supposed to return the total distance that it will take to sequentially go through the destinations vector not just from point 
                               // A to B like distance() of vertical.cpp but the total route from start to finish that is saved in the destinations vector
  const float distanceTotal = 0;


};

const Route shortestRoute() const {
  //Reorder destinations vector to optimize for shortest flight time. Do this via bruteforce-approach
  
  float lowestDistance = 10000000000000;

  sort(destinations->begin(), destinations->end());

  while(std::next_permutation(destinations->begin(), destinations->end())) {
    if(distance() < lowestDistance) {
      lowestDistance = distance();
    }
  }

  return ; //Kopie von Router object mit destinations object in idealer Ordnung
};
