#include "Network.h"

bool Network::addRouter(int id) {

    if (routers.find(id) != routers.end()) {
        return false;
    }

    routers.emplace(id, Router(id));
    adjacencyList[id] = {};

    return true;
}

bool Network::addLink(int router1, int router2, int cost) {

    if (!hasRouter(router1) || !hasRouter(router2)) {
        return false;
    }

    if (router1 == router2) { //same router is not allowed
        return false;
    }

    if (cost < 0) { // negative weight is not allowed 
        return false;
    }

    if (hasLink(router1, router2)) { // if already have link re writing is not allowed
        return false;
    }

    links.emplace_back(router1, router2, cost);
    adjacencyList[router1].emplace_back(router2, cost);
    adjacencyList[router2].emplace_back(router1, cost);



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
const unordered_map<int, vector<Neighbor>>&Network::getAdjacencyList() const {
    return adjacencyList;
}// adjaceny List adress without copying thats what & means

bool Network::hasLink(int router1, int router2) const {
    for (const Link& link : links) {
        if ((link.getRouter1() == router1 &&
             link.getRouter2() == router2) ||

            (link.getRouter1() == router2 &&
             link.getRouter2() == router1)) {

            return true;
        }
    }
    return false;
}
const vector<Neighbor>& Network::getNeighbors(int routerId) const {

    return adjacencyList.at(routerId); // at checks that the key exists ??
}