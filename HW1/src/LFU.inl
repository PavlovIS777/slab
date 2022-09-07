#include "../inc/LFU.h"
#include <iostream>
#ifndef LFU_INL
#define LFU_INL
template<typename T, typename keyT> LFU<T, keyT>::LFU(long long size): cache(size), hits(0){}

template<typename T, typename keyT> LFU<T, keyT>::~LFU(){}

template<typename T, typename keyT> bool LFU<T, keyT>::isFull() const {
    return this->maxSize == this->cache.size();
}

template<typename T, typename keyT> void LFU<T, keyT>::cacheLookupUpdate(T data) {
    auto qIt = this->cache.findByValue(data);
    if (qIt == this->cache.end()) {
        this->cache.push(1, data);
    } else {
        long long newPrior = qIt->first + 1;
        this->cache.erase(qIt);
        this->cache.push(newPrior, data);
        this->hits++;
    }
}

template<typename T, typename keyT> void LFU<T, keyT>::stdOutHits() {
    std::cout << "Hits: " << this->hits << " |"; 
}


#endif