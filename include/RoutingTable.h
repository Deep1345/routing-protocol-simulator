#pragma once

#include <unordered_map>
#include "RoutingEntry.h"

using namespace std;

class RoutingTable {

private:
    unordered_map<int, RoutingEntry> entries;

public:
    void addEntry(int destination, int nextHop, int cost);

    bool hasRoute(int destination) const;

    const RoutingEntry& getEntry(int destination) const;

    void removeEntry(int destination);

    void clear();
    void printTable() const;
    const unordered_map<int, RoutingEntry>& getEntries() const;
};