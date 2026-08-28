#pragma once
#include <unordered_map>
#include <vector>
#include "Router.h"
#include "Link.h"
#include <utility>
#include "Neighbor.h"
using namespace std;
class Network {
private:
    unordered_map<int, Router> routers;
    vector<Link> links;
    unordered_map<int, vector<Neighbor>> adjacencyList;
public:
    bool addRouter(int id);
    bool addLink(int router1, int router2, int cost);

    bool hasRouter(int id) const;
    bool hasLink(int router1, int router2) const; // helper function for checking thelink already exists.

    const unordered_map<int, Router>& getRouters() const; 
    /*
This looks complicated, but we'll break it down.
unordered_map<int, Router>
We're returning the router collection.
&
We're returning a reference, rather than copying the entire map.
const
The caller isn't allowed to modify the map through this function.
*/
    
    const vector<Link>& getLinks() const;
    const unordered_map<int, vector<Neighbor>>& getAdjacencyList() const;
    // getter function for dijkstrato access this graph
    const vector<Neighbor>& getNeighbors(int routerId) const;
    Router& getRouter(int id);
    const Router& getRouter(int id) const;
};
