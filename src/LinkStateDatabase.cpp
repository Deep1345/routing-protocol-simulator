#include "LinkStateDatabase.h"

bool LinkStateDatabase::addLSA(
    const LinkStateAdvertisement& lsa) {

    auto it = lsas.find(lsa.routerId);

    // No LSA from this router yet
    if (it == lsas.end()) {

        lsas.emplace(lsa.routerId, lsa);

        return true;
    }

    // Incoming LSA is newer
    if (lsa.sequenceNumber >
        it->second.sequenceNumber) {

        it->second = lsa;

        return true;
    }

    // Incoming LSA is old or duplicate
    return false;
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