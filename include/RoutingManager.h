#pragma once

#include "Network.h"
#include <queue>
#include "Neighbor.h"
void buildRoutingTable(Network& network, int source);
void buildAllRoutingTables(Network& network);
void generateLSA(Network& network, int routerId);

void generateAllLSAs(Network& network);
void floodLSA(Network& network, int sourceRouter, const LinkStateAdvertisement& lsa);
void floodAllLSAs(Network& network);
unordered_map<int, vector<Neighbor>> buildTopologyFromLSDB(
    const Router& router
);