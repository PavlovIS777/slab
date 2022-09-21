#pragma once
#include <iostream>

template<typename T> LFU<T>::LFU(long long size): cache(size), hits_(0), cacheSize_(size), requestIndex_(0){}

template<typename T> bool LFU<T>::isFull() const {
    return cacheSize_ == cache.size();
}

template<typename T> void LFU<T>::cacheLookupUpdate(T data) {
    auto isInCache = hashTab.find(data);
    if (isInCache == hashTab.end()) {
        if (cache.size() == cacheSize_) {
            auto pushResultPair = cache.poppush(std::pair<long long, long long>(1ll, requestIndex_), data);
            hashTab.erase(pushResultPair.second);
            hashTab.emplace(data, pushResultPair.first);
        } else {
            auto pushResultPair = cache.push(std::pair<long long, long long>(1ll, requestIndex_), data);
            hashTab.emplace(data, pushResultPair);
        }
        requestIndex_++;
    } else {
        auto qIt = isInCache->second;
        long long newPrior = (qIt->first).first + 1;
        long long index = (qIt->first).second;
        cache.erase(qIt);
        auto newDataIt = cache.push(std::pair<long long, long long>(newPrior, index), data);
        hashTab.erase(data);
        hashTab.emplace(data, newDataIt);
        hits_++;
    }
}

template<typename T> long long LFU<T>::hits() const{
    return hits_;
}
