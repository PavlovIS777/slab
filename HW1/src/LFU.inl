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
            auto pushResultPair = cache.poppush({1ll, requestIndex_}, {data, key});
            hashTab.erase(pushResultPair.second.second);
            hashTab.emplace(key, pushResultPair.first);
        } else {
            auto pushResultPair = cache.push({1ll, requestIndex_}, {data, key});
            hashTab.emplace(key, pushResultPair);
        }
        requestIndex_++;
    } else {
        auto qIt = isInCache->second;
        T data = qIt->second.first;
        long long newPrior = (qIt->first).first + 1;
        long long index = (qIt->first).second;
        cache.erase(qIt);
        auto newDataIt = cache.push({newPrior, index}, {data, key});
        hashTab.erase(key);
        hashTab.emplace(key, newDataIt);
        return true;
    }
    return false;
}
