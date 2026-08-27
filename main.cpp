#include <iostream>

#include "Router.h"
#include "Link.h"

using namespace std;

int main() {

    Router router1(1);
    Router router2(2);

    Link link(1, 2, 5);

    cout << "Router 1 ID: "
         << router1.getId() << endl;

    cout << "Router 2 ID: "
         << router2.getId() << endl;

    cout << "Link: "
         << link.getRouter1()
         << " <-> "
         << link.getRouter2() << endl;

    cout << "Cost: "
         << link.getCost() << endl;

    cout << "Link active: "
         << link.isActive() << endl;

    return 0;
}