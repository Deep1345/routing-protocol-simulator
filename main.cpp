#include <iostream>
#include "Router.h"
using namespace std;
int main() {
    Router router(1);
    cout << "Router ID: "<< router.getId() << '\n';
    cout << "Router active: "<< router.isActive() << '\n';
    return 0;
}