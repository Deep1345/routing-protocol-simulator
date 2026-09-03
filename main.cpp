#include <iostream>

#include "Network.h"
#include "RoutingManager.h"

using namespace std;

int main() {

    Network network;

    // -------------------------------------------------
    // Create Routers
    // -------------------------------------------------

    for (int i = 1; i <= 7; i++) {
        network.addRouter(i);
    }

    // -------------------------------------------------
    // Create Complicated Network Topology
    // -------------------------------------------------

    // Main connections
    network.addLink(1, 2, 4);
    network.addLink(1, 3, 2);
    network.addLink(1, 4, 9);

    // Middle section
    network.addLink(2, 3, 1);
    network.addLink(2, 5, 7);
    network.addLink(2, 6, 6);

    network.addLink(3, 4, 3);
    network.addLink(3, 6, 5);

    network.addLink(4, 5, 2);
    network.addLink(4, 6, 1);

    // Lower/right section
    network.addLink(5, 6, 3);
    network.addLink(5, 7, 8);

    network.addLink(6, 7, 2);

    // Extra long alternate path
    network.addLink(4, 7, 10);

    // -------------------------------------------------
    // STEP 1
    // Every router generates its own LSA
    // -------------------------------------------------

    generateAllLSAs(network);

    // -------------------------------------------------
    // STEP 2
    // Flood every LSA through the network
    // -------------------------------------------------

    floodAllLSAs(network);

    // -------------------------------------------------
    // STEP 3
    // Verify Link-State Databases
    // -------------------------------------------------

    cout << "\n========================================\n";
    cout << "LINK-STATE DATABASE VERIFICATION\n";
    cout << "========================================\n";

    for (const auto& [routerId, router] :
         network.getRouters()) {

        const auto& lsas =
            router.getLinkStateDatabase()
                  .getAllLSAs();

        cout << "\nRouter " << routerId
             << " has "
             << lsas.size()
             << " LSAs\n";

        for (const auto& [lsaRouterId, lsa] :
             lsas) {

            cout << "  LSA from Router "
                 << lsaRouterId
                 << " | Sequence: "
                 << lsa.sequenceNumber
                 << "\n";
        }
    }

    // -------------------------------------------------
    // STEP 4
    // Build routing tables from LSDB
    // -------------------------------------------------

    buildAllRoutingTables(network);

    // -------------------------------------------------
    // STEP 5
    // Print routing tables
    // -------------------------------------------------

    cout << "\n\n========================================\n";
    cout << "LINK-STATE ROUTING TABLES\n";
    cout << "========================================\n";

    for (const auto& [routerId, router] :
         network.getRouters()) {

        cout << "\n----------------------------------------\n";
        cout << "Routing Table for Router "
             << routerId
             << "\n";
        cout << "----------------------------------------\n";

        network.getRouter(routerId)
               .getRoutingTable()
               .printTable();
    }

    return 0;
}
