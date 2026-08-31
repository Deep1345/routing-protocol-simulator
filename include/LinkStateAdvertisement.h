#pragma once

#include <vector>

using namespace std;

struct LinkStateAdvertisement {

    int routerId;

    int sequenceNumber;

    vector<pair<int, int>> neighbors;


    LinkStateAdvertisement(
        int routerId,
        int sequenceNumber
    )
        : routerId(routerId),
          sequenceNumber(sequenceNumber) {
    }


    void addNeighbor(int neighborId, int cost) {

        neighbors.push_back({
            neighborId,
            cost
        });
    }
};