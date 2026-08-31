#include "RoutingManager.h"
#include "Dijkstra.h"
#include <limits>
#include <queue>
using namespace std;
void generateLSA(Network& network, int routerId) {

    int sequenceNumber =network.getRouter(routerId).getNextLSASequenceNumber();

    LinkStateAdvertisement lsa(
        routerId,
        sequenceNumber
    );

    const vector<Neighbor>& neighbors =
        network.getNeighbors(routerId);

    for (const Neighbor& neighbor : neighbors) {

        lsa.addNeighbor(
            neighbor.routerId,
            neighbor.cost
        );
    }

    Router& router = network.getRouter(routerId);

    router.getLinkStateDatabase().addLSA(lsa);
}
void generateAllLSAs(Network& network) {

    for (const auto& [routerId, router] : network.getRouters()) {

        generateLSA(network, routerId);
    }
}
void floodLSA(
    Network& network,
    int sourceRouter,
    const LinkStateAdvertisement& lsa) {

    queue<int> q;

    // The router that originally created the LSA
    // already has it.
    q.push(sourceRouter);

    while (!q.empty()) {

        int currentRouter = q.front();
        q.pop();

        const vector<Neighbor>& neighbors =
            network.getNeighbors(currentRouter);

        for (const Neighbor& neighbor : neighbors) {

            int neighborId = neighbor.routerId;

            Router& neighborRouter =
                network.getRouter(neighborId);

            bool isNew = neighborRouter.getLinkStateDatabase().addLSA(lsa);

            if (!isNew) {
                continue;
            }

            // This router received a new LSA,
            // so it must propagate it.
            q.push(neighborId);
        }
    }
}
void floodAllLSAs(Network& network) {

    for (const auto& [routerId, router] : network.getRouters()) {

        const LinkStateAdvertisement* lsa =
            network.getRouter(routerId)
                   .getLinkStateDatabase()
                   .getLSA(routerId);

        if (lsa != nullptr) {

            floodLSA(
                network,
                routerId,
                *lsa
            );
        }
    }
}
unordered_map<int, vector<Neighbor>>
buildTopologyFromLSDB(const Router& router) {

    unordered_map<int, vector<Neighbor>> topology;

    const auto& lsas =
        router.getLinkStateDatabase().getAllLSAs();

    for (const auto& [routerId, lsa] : lsas) {

        // Make sure this router exists in the topology
        topology[routerId];

        for (const auto& [neighborId, cost] : lsa.neighbors) {

            topology[routerId].emplace_back(
                neighborId,
                cost
            );
        }
    }

    return topology;
}

void buildAllRoutingTables(Network& network) {

    for (const auto& [routerId, router] : network.getRouters()) {

        buildRoutingTable(network, routerId);
    }
}

void buildRoutingTable(Network& network, int source) {

    // Get the source router
    const Router& sourceRouter =
        network.getRouter(source);

    // Build topology from this router's LSDB
    unordered_map<int, vector<Neighbor>> topology =
        buildTopologyFromLSDB(sourceRouter);

    // Run Dijkstra on the LSDB-derived topology
    DijkstraResult result =
        runDijkstra(topology, source);

    // Get the actual router so we can modify
    // its routing table
    Router& router =
        network.getRouter(source);

    // Remove old routing information
    router.getRoutingTable().clear();

    // Process every destination
    for (const auto& [destination, distance] :
         result.distance) {

        // Unreachable router
        if (distance ==
            numeric_limits<int>::max()) {

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

            current =
                result.parent.at(current);
        }

        int nextHop = current;

        router.getRoutingTable().addEntry(
            destination,
            nextHop,
            distance
        );
    }
}