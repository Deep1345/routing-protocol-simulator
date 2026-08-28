#include "RoutingTable.h"
#include <iostream>
void RoutingTable::addEntry(int destination, int nextHop, int cost) {

    auto it = entries.find(destination);

    if (it != entries.end()) {
        it->second = RoutingEntry(nextHop, cost);
    }
    else {
        entries.emplace(
            destination,
            RoutingEntry(nextHop, cost)
        );
    }
}

bool RoutingTable::hasRoute(int destination) const {

    return entries.find(destination) != entries.end();
}

const RoutingEntry&
RoutingTable::getEntry(int destination) const {

    return entries.at(destination);
}

void RoutingTable::removeEntry(int destination) {

    entries.erase(destination);
}

void RoutingTable::clear() {

    entries.clear();
}

const unordered_map<int, RoutingEntry>&
RoutingTable::getEntries() const {

    return entries;
}
void RoutingTable::printTable() const {

    cout << "Destination\tNext Hop\tCost" << endl;

    for (const auto& entry : entries) {

        int destination = entry.first;

        const RoutingEntry& route = entry.second;

        cout << destination << "\t\t"
             << route.nextHop << "\t\t"
             << route.cost << endl;
    }
}