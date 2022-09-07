#include "../inc/LFU.h"
#ifndef LFU_INL
#define LFU_INL
template<typename T, typename keyT> LFU<T, keyT>::LFU(long long size)
{
    this->maxSize = size;
}

template<typename T, typename keyT> LFU<T, keyT>::~LFU()
{
}

template<typename T, typename keyT> bool LFU<T, keyT>::isFull() const{
    return this->maxSize == this->cash.size();
}

template<typename T, typename keyT> bool LFU<T, keyT>::cacheLookupUpdate(T data) {
    if (this->cash.size() < this->maxSize) {
        auto newIt {this->cash.emplace(cashData(1, data))};
        this->hash.emplace(std::pair(this->hash.size(), newIt));
    } else {
        auto start = this->cash.begin();
        auto end = this->cash.end();
        bool isInCash = false;
        while (start != end) {
            if (*start == data) {
                isInCash = true;
                break;
            } else ++start;
        }
        if (isInCash) {
            
        }
    }
}

template<typename T, typename keyT> void LFU<T, keyT>::stdOutHits() {
    std::array<int, 2> outArr = this->cache.outputHits();
    std::cout << "Hits: " << outArr[0] << " | MissHits: " << outArr[1]<< " |"; 
}


#endif