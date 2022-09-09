#include <list>
#include <unordered_map>
#include <queue>
#include "priorQueue.h"

#ifndef LFU_H
#define LFU_H

template<typename T> 
class LFU
{
private:
    long long hits;
    long long cacheSize;
    long long requestIndex;
    using queueIt = typename std::multimap<std::pair<long long, long long>, T>::iterator;
    priorQueue<std::pair<long long, long long>, T> cache;
    using cacheData = typename std::pair<long long, T>;
    std::unordered_map<T, queueIt> hashTab;
public:
    LFU(long long size);
    ~LFU();
    bool isFull() const;
    void cacheLookupUpdate(T data);
    void stdOutHits();
};
#include "../src/LFU.inl"
#endif