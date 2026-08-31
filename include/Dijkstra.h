#pragma once

#include "Neighbor.h"

#include <unordered_map>
using namespace std;
#include <vector>

struct DijkstraResult {

    unordered_map<int, int> distance;

    unordered_map<int, int> parent;
};

DijkstraResult runDijkstra(
    const unordered_map<int, vector<Neighbor>>& topology,
    int source
);