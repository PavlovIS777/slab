#include "../inc/LFU.h"
#include <iostream>
#ifndef LFU_INL
#define LFU_INL
template<typename T> LFU<T>::LFU(long long size): cache(size), hits(0){}

template<typename T> LFU<T>::~LFU(){}

template<typename T> bool LFU<T>::isFull() const {
    return this->maxSize == this->cache.size();
}

template<typename T> void LFU<T>::eraseByCacheIt(LFU<T>::queueIt erasedIt) {
    for (auto it = this->hashTab.begin(); it != this->hashTab.end(); ++it) {
        if (it->second == erasedIt) {
            this->hashTab.erase(it);
            return;
        }
    }
}

template<typename T> void LFU<T>::cacheLookupUpdate(T data) {
    auto isInCache = this->hashTab.find(data);
    if (isInCache == this->hashTab.end()) {
        auto pushResultPair = this->cache.push(1, data);
        if (pushResultPair.second != this->cache.end()) {
            this->eraseByCacheIt(pushResultPair.second);
        }
        this->hashTab.emplace(data, pushResultPair.first);
    } else {
        auto qIt = isInCache->second;
        long long newPrior = qIt->first + 1;
        this->cache.erase(qIt);
        auto pushResultPair = this->cache.push(newPrior, data);
        this->hits++;
    }
}

template<typename T> void LFU<T>::stdOutHits() {
    std::cout << "Hits: " << this->hits << " |"; 
}


#endif