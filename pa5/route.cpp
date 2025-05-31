#include "route.h"
#include "vertical.h"
#include <algorithm>

using namespace std;

Route::Route(const float pHeight, const function<float(float, float, float, float, float)> pDist) {
    height = pHeight;
    dist = pDist;
    //Set destinations to an empty vector of correct dataype, we need this because of the destinations-to-pointer rewrrite thing and it will cause a segfault if we try to call it...(something smoething pointers)
    destinations = new vector<pair<float, float>>;
};

// Move constructor
Route::Route(Route&& other) noexcept {
    printf("heyyyyy");
    height = other.height;
    dist = std::move(other.dist);
    destinations = other.destinations;
    other.destinations = nullptr;
};

Route::Route(const Route& route) {
    printf("heyyyyy");
    height = route.height;
    dist = route.dist;
    // Derefererenece the pointer to get the actual object and then save it to destinations after "casting" it
    destinations = new vector<pair<float, float>>(*route.destinations);
};

Route::~Route() {
    delete destinations;
    destinations = nullptr;
};

void Route::add(const float destX, const float destY) {
    destinations->emplace_back(destX, destY);
};

const vector<pair<float, float>>& Route::getDestinations() const {
    return *destinations;
}

float Route::getHeight() const {
    return height;
}

void Route::setHeight(const float pHeight) {
    height = pHeight;
}

void Route::setDist(const function<float(float, float, float, float, float)> pDist) {
    dist = pDist;
}

float Route::distance() const {
    float distanceTotal = 0.0f;
    int destinationsArrLength = (*destinations).size();

    if(destinationsArrLength == 0) {
        return 0.0;
    }

    // From origin to first destination
    distanceTotal += dist(0.0f, 0.0f, (*destinations)[0].first, (*destinations)[0].second, height);

    if(destinationsArrLength > 1) {
        // Intermediate flights
        for (int i = 0; i < destinationsArrLength - 1; i++) {
            distanceTotal += dist((*destinations)[i].first, (*destinations)[i].second,(*destinations)[i + 1].first, (*destinations)[i + 1].second, height);
        }
    }

    // Return to origin
    distanceTotal += dist(destinations->back().first, destinations->back().second, 0.0f, 0.0f, height);

    return distanceTotal;
}

const Route Route::shortestRoute() const {
    if (destinations->empty()) return *this;

    vector<pair<float, float>> bestDestinations;
    float bestDist = 10000000000;

    vector<pair<float, float>> currentDestinations = *destinations;
    sort(currentDestinations.begin(), currentDestinations.end());

    while (next_permutation(currentDestinations.begin(), currentDestinations.end())) {
        float tempDist = 0.0f;
        tempDist += dist(0.0f, 0.0f, currentDestinations[0].first, currentDestinations[0].second, height);

        for (size_t i = 0; i < currentDestinations.size() - 1; ++i) {
            tempDist += dist(currentDestinations[i].first, currentDestinations[i].second, currentDestinations[i + 1].first, currentDestinations[i + 1].second, height);
        }

        tempDist += dist(currentDestinations.back().first, currentDestinations.back().second, 0.0f, 0.0f, height);

        if (tempDist < bestDist) {
            bestDist = tempDist;
            bestDestinations = currentDestinations;
        }
    } 

    /*
    Route best(height, dist);
    for (const auto& p : bestDestinations) {
        best.add(p.first, p.second);
    };
    */

    Route best(move(*this)); // use copy(Move constructor now because of pa5-a)  is more efficent  ) constructor instead of doing the loop thing because I think he want's me to do it that way...

    (*best.destinations) = bestDestinations;

    return best;
}

