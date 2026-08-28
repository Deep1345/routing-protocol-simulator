#pragma once

#include <limits>

struct RoutingEntry {

    int destination;
    int nextHop;
    int cost;

    RoutingEntry(
        int destination,
        int nextHop,
        int cost
    )
        : destination(destination),
          nextHop(nextHop),
          cost(cost) {}
};