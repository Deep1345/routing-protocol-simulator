#pragma once

#include "Network.h"
#include <unordered_map>

struct DijkstraResult {
    unordered_map<int, int> distance;
    unordered_map<int, int> parent;
};

DijkstraResult runDijkstra(const Network& network, int source);