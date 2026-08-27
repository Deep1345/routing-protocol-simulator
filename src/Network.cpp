#include "Network.h"

bool Network::addRouter(int id) {

    if (routers.find(id) != routers.end()) {
        return false;
    }

    routers.emplace(id, Router(id));

    return true;
}

bool Network::addLink(int router1, int router2, int cost) {

    if (!hasRouter(router1) || !hasRouter(router2)) {
        return false;
    }

    links.emplace_back(router1, router2, cost);

    return true;
}

bool Network::hasRouter(int id) const {

    return routers.find(id) != routers.end();
}
//Getter Implementations
const unordered_map<int, Router>& Network::getRouters() const {
    return routers;
}
const vector<Link>& Network::getLinks() const {
    return links;
}