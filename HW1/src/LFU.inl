#include <iostream>
#ifndef LFU_INL
#define LFU_INL
// Default LFU-ctor. Initialize variables by zero.
template<typename T> LFU<T>::LFU(long long size): cache(size), hits_(0), cacheSize_(size), requestIndex_(0){}

template<typename T> LFU<T>::~LFU(){}

template<typename T> bool LFU<T>::isFull() const {
    return cacheSize_ == cache.size();
}

template<typename T> void LFU<T>::cacheLookupUpdate(T data) {
    auto isInCache = this->hashTab.find(data);
    if (isInCache == this->hashTab.end()) {
        if (this->cache.size() == this->cacheSize_) {
            auto pushResultPair = this->cache.poppush(std::pair<long long, long long>(1ll, this->requestIndex_), data);
            this->hashTab.erase(pushResultPair.second);
            this->hashTab.emplace(data, pushResultPair.first);
        } else {
            auto pushResultPair = this->cache.push(std::pair<long long, long long>(1ll, this->requestIndex_), data);
            this->hashTab.emplace(data, pushResultPair);
        }
        this->requestIndex_++;
    } else {
        auto qIt = isInCache->second;
        long long newPrior = (qIt->first).first + 1;
        long long index = (qIt->first).second;
        this->cache.erase(qIt);
        auto newDataIt = this->cache.push(std::pair<long long, long long>(newPrior, index), data);
        this->hashTab.erase(data);
        this->hashTab.emplace(data, newDataIt);
        this->hits_++;
    }
}

template<typename T> long long LFU<T>::hits() const{
    return hits_;
}

#endif
