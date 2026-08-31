#ifndef LINK_STATE_ADVERTISEMENT_H
#define LINK_STATE_ADVERTISEMENT_H

#include <vector>
using namespace std;
struct LinkStateAdvertisement {
    int routerId;
    vector<pair<int, int>> neighbors;

    LinkStateAdvertisement(int routerId) : routerId(routerId) {}

    void addNeighbor(int neighborId, int cost) {
        neighbors.push_back({neighborId, cost});
    }
};

#endif