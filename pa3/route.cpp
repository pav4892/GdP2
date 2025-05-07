#include "route.h"
#include "vertical.h"
#include <algorithm>
#include <limits>

using namespace std;

Route::Route(const float pHeight, const function<float(float, float, float, float, float)> pDist) {
  height = pHeight;
  dist = pDist;
};

Route::Route(const Route& route) {
  destinations = route.destinations;
  height = route.height;
  dist = route.dist;
};

Route::~Route() {};

void Route::add(const float destX, const float destY) {
  destinations.emplace_back(destX, destY);
};

const vector<pair<float, float>>& Route::getDestinations() const {
  return destinations;
};

const float Route::getHeight() const {
  return height;
};

void Route::setHeight(const float pHeight) {
  height = pHeight;
};

void Route::setDist(const function<float(float, float, float, float, float)> pDist) {
  dist = pDist;
};


const float Route::distance() const {
    float distanceTotal = 0.0;
    int distanceArrLength = destinations.size(); // Get arrayLength for iteratior later...

    if(distanceArrLength > 0) {

        // Start flight from origin to first
        distanceTotal += dist(0.0, 0.0, destinations[0].first, destinations[0].second, height);

        if(distanceArrLength > 1) {
            // Intermediate flights
            for (int i = 0; i < distanceArrLength - 1; ++i) {
                distanceTotal += dist(destinations[i].first, destinations[i].second, destinations[i + 1].first, destinations[i + 1].second, height);
            }
        }

        // Return flight
        distanceTotal += dist(destinations.back().first, destinations.back().second, 0.0, 0.0, height);
    } else {
        distanceTotal = 0.0;
    }

    return distanceTotal;
}

const Route Route::shortestRoute() const {
    if (destinations.empty()) return *this;

    vector<pair<float, float>> perm = destinations;
    vector<pair<float, float>> bestPerm;
    float bestDist = numeric_limits<float>::max();

    sort(perm.begin(), perm.end());

    do {
        float tempDist = 0.0f;

        tempDist += dist(0.0f, 0.0f, perm[0].first, perm[0].second, height);
        for (size_t i = 0; i < perm.size() - 1; ++i) {
            tempDist += dist(
                perm[i].first, perm[i].second,
                perm[i + 1].first, perm[i + 1].second,
                height
            );
        }
        tempDist += dist(perm.back().first, perm.back().second, 0.0f, 0.0f, height);

        if (tempDist < bestDist) {
            bestDist = tempDist;
            bestPerm = perm;
        }
    } while (next_permutation(perm.begin(), perm.end()));

    Route best(height, dist);
    for (const auto& p : bestPerm) {
        best.add(p.first, p.second);
    }

    return best;
}

