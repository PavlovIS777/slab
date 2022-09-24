#pragma once
#include <iostream>

template<typename T, typename keyT> Cache::LFU<T, keyT>::LFU(long long size): cache(size), cacheSize_(size), requestIndex_(0){}

template<typename T, typename keyT> bool Cache::LFU<T, keyT>::isFull() const {
    return cacheSize_ == cache.size();
}

template<typename T, typename keyT> template<typename F> bool  Cache::LFU<T, keyT>::cacheLookupUpdate(keyT key, F slow_get_page) {
    auto isInCache = hashTab.find(key);
    if (isInCache == hashTab.end()) {
        T data = slow_get_page(key);
        if (cache.size() == cacheSize_) {
            auto pushResultPair = cache.poppush(std::pair<long long, long long>(1ll, requestIndex_), data);
            hashTab.erase(pushResultPair.second);
            hashTab.emplace(key, pushResultPair.first);
        } else {
            auto pushResultPair = cache.push(std::pair<long long, long long>(1ll, requestIndex_), data);
            hashTab.emplace(key, pushResultPair);
        }
        requestIndex_++;
    } else {
        auto qIt = isInCache->second;
        T data = qIt->second;
        long long newPrior = (qIt->first).first + 1;
        long long index = (qIt->first).second;
        cache.erase(qIt);
        auto newDataIt = cache.push(std::pair<long long, long long>(newPrior, index), data);
        hashTab.erase(key);
        hashTab.emplace(key, newDataIt);
        return true;
    }
    return false;
}
