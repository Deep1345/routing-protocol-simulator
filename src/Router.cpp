#include "Router.h"

Router::Router(int id) {
    this->id = id;
    this->active = true;
}

int Router::getId() const {
    return id;
}

bool Router::isActive() const {
    return active;
}