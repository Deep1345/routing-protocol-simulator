#include <iostream>

#include "Network.h"
#include "RoutingManager.h"

using namespace std;

int main() {

    Network network;

    // Add routers 1 to 12
    for (int i = 1; i <= 12; i++) {
        network.addRouter(i);
    }

    // -------------------------------------------------
    // Complex topology
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
    // Generate LSA for Router 1
    // -------------------------------------------------

    generateAllLSAs(network);


    // -------------------------------------------------
    // Print Router 1's LSA
    // -------------------------------------------------

    const LinkStateAdvertisement* lsa =
        network.getRouter(1)
               .getLinkStateDatabase()
               .getLSA(1);

    if (lsa == nullptr) {

        cout << "LSA not found!" << endl;
        return 1;
    }

    cout << "\n========================================\n";
    cout << "Link-State Advertisement for Router 1\n";
    cout << "========================================\n";

    cout << "Router ID: "
         << lsa->routerId
         << "\n\n";

    cout << "Neighbors:\n";

    for (const auto& neighbor : lsa->neighbors) {

        cout << "Router "
             << neighbor.first
             << " -> Cost "
             << neighbor.second
             << endl;
    }

    return 0;
}