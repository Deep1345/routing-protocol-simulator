#include "RoutingManager.h"
#include "Dijkstra.h"
#include <limits>
using namespace std;

void buildAllRoutingTables(Network& network) {

    for (const auto& [routerId, router] : network.getRouters()) {

        buildRoutingTable(network, routerId);
    }
}

void buildRoutingTable(Network& network, int source) {

    // Run Dijkstra from this router
    DijkstraResult result = runDijkstra(network, source);

    // Get the source router
    Router& router = network.getRouter(source);

    // Remove old routing information
    router.getRoutingTable().clear();

    // Process every destination
    for (const auto& [destination, distance] : result.distance) {

        // Unreachable router
        if (distance == numeric_limits<int>::max()) {
            continue;
        }

        // Source itself
        if (destination == source) {

            router.getRoutingTable().addEntry(
                destination,
                source,
                0
            );

            continue;
        }

        // Find the first hop
        int current = destination;

        while (result.parent.at(current) != source) {

            current = result.parent.at(current);
        }

        int nextHop = current;

        router.getRoutingTable().addEntry(
            destination,
            nextHop,
            distance
        );
    }
}