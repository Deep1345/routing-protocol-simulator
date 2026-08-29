#include "Dijkstra.h"
#include <queue>
#include <limits>

using namespace std;

DijkstraResult runDijkstra(const Network& network, int source) {

    DijkstraResult result;

    const int INF = numeric_limits<int>::max();

    // Step 1: Initialize distances
    for (const auto& [routerId, router] : network.getRouters()) {

        result.distance[routerId] = INF;
    }

    // Source has distance 0
    result.distance[source] = 0;

    // Min-heap:
    // pair<distance, routerId>
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
    pq.push({0, source});

    // Step 2: Dijkstra
    while (!pq.empty()) {
        auto [currentDistance, currentRouter] = pq.top();
        pq.pop();
        // Ignore outdated priority queue entry
        if (currentDistance != result.distance[currentRouter]) {
            continue;
        }
        // Look at all neighbors
        for (const Neighbor& neighbor :
             network.getNeighbors(currentRouter)) {

            int nextRouter = neighbor.routerId;
            int edgeCost = neighbor.cost;

            int newDistance =
                currentDistance + edgeCost;

            // Relaxation
            if (newDistance < result.distance[nextRouter]) {

                result.distance[nextRouter] = newDistance;

                result.parent[nextRouter] = currentRouter;

                pq.push({
                    newDistance,
                    nextRouter
                });
            }
        }
    }
    return result;
}