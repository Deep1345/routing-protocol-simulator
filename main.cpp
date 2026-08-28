#include <iostream>
#include "Network.h"

using namespace std;

int main() {

    Network network;

    network.addRouter(1);
    network.addRouter(2);
    network.addRouter(3);
    network.addRouter(4);

    network.addLink(1, 2, 5);
    network.addLink(1, 3, 2);
    network.addLink(2, 4, 3);

    const auto& graph = network.getAdjacencyList();

    for (const auto& [routerId, neighbors] : graph) {

        cout << "Router " << routerId << ": ";

        for (const Neighbor& neighbor : neighbors) {

            cout << "("
                 << neighbor.routerId
                 << ", cost=" 
                 << neighbor.cost
                 << ") ";
        }

        cout << endl;
    }
    return 0;
}