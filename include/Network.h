#pragma once
#include <unordered_map>
#include <vector>
#include "Router.h"
#include "Link.h"
using namespace std;
class Network {
private:
    unordered_map<int, Router> routers;
    vector<Link> links;
public:
    bool addRouter(int id);
    bool addLink(int router1, int router2, int cost);

    bool hasRouter(int id) const;

    const unordered_map<int, Router>& getRouters() const; 
    
    const vector<Link>& getLinks() const;
};


/*
This looks complicated, but we'll break it down.
unordered_map<int, Router>
We're returning the router collection.
&
We're returning a reference, rather than copying the entire map.
const
The caller isn't allowed to modify the map through this function.
*/