#pragma once

#include "Network.h"

void buildRoutingTable(Network& network, int source);
void buildAllRoutingTables(Network& network);
void generateLSA(Network& network, int routerId);

void generateAllLSAs(Network& network);