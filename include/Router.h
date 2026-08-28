#pragma once
#include "RoutingTable.h"
class Router {
private: // here ID and active is private because we dont want other functions changing that 
    int id;
    bool active;
    RoutingTable routingTable;
public:
    Router(int id);
    int getId() const; // const means This function promises not to modify the Router object.
    bool isActive() const;
    RoutingTable& getRoutingTable();
    const RoutingTable& getRoutingTable() const;
};