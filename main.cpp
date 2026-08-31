#include <iostream>

#include "Network.h"
#include "RoutingManager.h"

using namespace std;

int main() {

    Network network;

    // -------------------------------------------------
    // Create Routers
    // -------------------------------------------------

    for (int i = 1; i <= 12; i++) {
        network.addRouter(i);
    }


    // -------------------------------------------------
    // Create Network Topology
    // -------------------------------------------------

    network.addLink(1, 2, 4);
    network.addLink(1, 3, 2);
    network.addLink(1, 4, 9);

    network.addLink(2, 4, 3);
    network.addLink(2, 5, 7);
    network.addLink(2, 6, 6);

    network.addLink(3, 4, 2);
    network.addLink(3, 6, 5);
    network.addLink(3, 7, 8);

    network.addLink(4, 5, 2);
    network.addLink(4, 6, 1);
    network.addLink(4, 7, 6);

    network.addLink(5, 8, 4);
    network.addLink(5, 9, 7);

    network.addLink(6, 7, 2);
    network.addLink(6, 8, 3);
    network.addLink(6, 9, 5);

    network.addLink(7, 9, 2);
    network.addLink(7, 10, 6);

    network.addLink(8, 9, 1);
    network.addLink(8, 11, 5);

    network.addLink(9, 10, 2);
    network.addLink(9, 11, 3);

    network.addLink(10, 12, 4);
    network.addLink(11, 12, 1);


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
    // Verify LSDB
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

        for (const auto& [lsaRouterId, lsa] : lsas) {

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