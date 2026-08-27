#include <iostream>

#include "Network.h"

using namespace std;

int main() {

    Network network;

    network.addRouter(1);
    network.addRouter(2);
    network.addRouter(3);

    network.addLink(1, 2, 5);
    network.addLink(2, 3, 3);
    network.addLink(1, 3, 10);

    cout << "Number of routers: "<< network.getRouters().size() << endl;

    cout << "Number of links: "<< network.getLinks().size() << endl;

    return 0;
}