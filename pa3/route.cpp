#include <functional>
#include "route.h"

using namespace std;

Route::Route(const float pHeight, const function<float(float, float, float, float, float)> pDist) {
  setHeight(pHeight);
  setDist(pDist);
};

Route::Route(Route& route) {
  setHeight(route.height);
  setDist(route.dist);
};

Route::~Route(){};

void Route::add(const float destX, const float destY) {
  const vector<pair<float, float>> elem; // Here we cannot just use <float, float> but need <pair<float,float>> becauuuuuse
  destinations.push_back(elem); // Add element to end of destinations vector
};

const vector<pair<float, float>>& Route::getDestinations() {
  return destinations;
};

const float Route::getHeight() const {
  return height;
};

void Route::setHeight(const float pHeight) {
  height = pHeight;
};

function<float(float, float, float, float, float)> Route::getDist() const {
  return dist;
};

void Route::setDist(function<float(float, float, float, float, float)> pDist) {
  dist = pDist;
};

const float Route::distance() const { // not same as in vertical... check ich nicht, fix later. This is supposed to return the total distance that it will take to sequentially go through the destinations vector not just from point 
                               // A to B like distance() of vertical.cpp but the total route from start to finish that is saved in the destinations vector
  float distanceTotal = 0;

  int destinationsArrLength = sizeof(destinations)/sizeof(destinations[0]);

  if(destinationsArrLength > 0) {
    distanceTotal = Vertical::distance(0.0, 0.0, destinations[0][0], destinations[0][1], getHeight()); //calc startflight

    if(destinationsArrLength > 1) {
      for(int i = 0; i <= destinationsArrLength - 1; i++) {
        distanceTotal += Vertical::distance(destinations[i][0], destinations[i][1], destinations[i+1][0], destinations[i+1][1], getHeight()); 
      }
    }

    //calc backflight
    distanceTotal += Vertical::distance(destinations.back()[0], destinations.back()[1], 0.0, 0.0, getHeight()); 
  } else {
    distanceTotal = 0.0;
  }

  return distanceTotal;
};

const Route Route::shortestRoute() {
  //Reorder destinations vector to optimize for shortest flight time. Do this via bruteforce-approach
  
  float lowestDistance = 10000000000000;

  int destinationsArrLength = sizeof(destinations)/sizeof(destinations[0]);

  sort(destinations->begin(), destinations->end());

  while(std::next_permutation(destinations->begin(), destinations->end())) {
    if(distance() < lowestDistance) {
      lowestDistance = distance();
    }
  }

  Route idealRoute = new Route(getHeight(), dist);

  for(int i = 0; i <= destinationsArrLength - 1; i++) {
    idealRoute.add(idealDestinationsArray[i][0], idealDestinationsArray[i][1]);
  }

  return idealRoute; //Kopie von Route object mit destinations object in idealer Ordnung
};
