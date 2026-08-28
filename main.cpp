#include <iostream>

#include "Network.h"

using namespace std;

int main() {

    Network network;

    network.addRouter(1);
    network.addRouter(2);
    network.addRouter(3);

    network.addLink(1, 2, 5);
    network.addLink(1, 3, 2);

    Router& router1 = network.getRouter(1);

    router1.getRoutingTable().addEntry(1, 1, 0);
    router1.getRoutingTable().addEntry(2, 2, 5);
    router1.getRoutingTable().addEntry(3, 3, 2);

    cout << "Routing Table for Router "
         << router1.getId()
         << endl;

    router1.getRoutingTable().printTable();

    return 0;
}