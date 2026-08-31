#ifndef LINK_STATE_DATABASE_H
#define LINK_STATE_DATABASE_H

#include "LinkStateAdvertisement.h"
#include <unordered_map>

using namespace std;

class LinkStateDatabase {
private:
    unordered_map<int, LinkStateAdvertisement> lsas;

public:
    void addLSA(const LinkStateAdvertisement& lsa);

    bool hasLSA(int routerId) const;

    const LinkStateAdvertisement* getLSA(int routerId) const;

    void clear();

    const unordered_map<int, LinkStateAdvertisement>& getAllLSAs() const;
};

#endif