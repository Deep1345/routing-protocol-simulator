#include "Link.h"

Link::Link(int router1, int router2, int cost)
    : router1(router1),
      router2(router2),
      cost(cost),
      active(true) {
}

int Link::getRouter1() const {
    return router1;
}

int Link::getRouter2() const {
    return router2;
}

int Link::getCost() const {
    return cost;
}

bool Link::isActive() const {
    return active;
}