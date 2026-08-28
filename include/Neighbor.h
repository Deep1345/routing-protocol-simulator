#pragma once

struct Neighbor {
    int routerId;
    int cost;

    Neighbor(int routerId, int cost)
        : routerId(routerId), cost(cost) {}
};