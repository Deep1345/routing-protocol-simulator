#include "Router.h"

Router::Router(int id)
    : id(id),
      active(true),
      lsaSequenceNumber(0) {
}
int Router::getId() const {

    return id;
}

bool Router::isActive() const {

    return active;
}

RoutingTable& Router::getRoutingTable() {

    return routingTable;
}

const RoutingTable& Router::getRoutingTable() const {

    return routingTable;
}
LinkStateDatabase& Router::getLinkStateDatabase() {
    return linkStateDatabase;
}

const LinkStateDatabase& Router::getLinkStateDatabase() const {
    return linkStateDatabase;
}
int Router::getNextLSASequenceNumber() {

    lsaSequenceNumber++;

    return lsaSequenceNumber;
}