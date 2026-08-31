#include "LinkStateDatabase.h"

void LinkStateDatabase::addLSA(const LinkStateAdvertisement& lsa) {
    auto it = lsas.find(lsa.routerId);

    if (it != lsas.end()) {
        it->second = lsa;
    }
    else {
        lsas.emplace(lsa.routerId, lsa);
    }
}

bool LinkStateDatabase::hasLSA(int routerId) const {
    return lsas.find(routerId) != lsas.end();
}

const LinkStateAdvertisement*
LinkStateDatabase::getLSA(int routerId) const {

    auto it = lsas.find(routerId);

    if (it == lsas.end()) {
        return nullptr;
    }

    return &it->second;
}

void LinkStateDatabase::clear() {
    lsas.clear();
}

const std::unordered_map<int, LinkStateAdvertisement>&
LinkStateDatabase::getAllLSAs() const {
    return lsas;
}