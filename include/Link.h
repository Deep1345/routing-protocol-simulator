#pragma once

class Link {
private:
    int router1;
    int router2;
    int cost;
    bool active;
public:
    Link(int router1, int router2, int cost);
    int getRouter1() const;
    int getRouter2() const;
    int getCost() const;
    bool isActive() const;
};