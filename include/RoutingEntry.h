#pragma once
struct RoutingEntry {
    int nextHop;
    int cost;
    RoutingEntry(int nextHop, int cost)
        : nextHop(nextHop),
          cost(cost) {}
};