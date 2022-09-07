#include <list>
#include <unordered_map>
#include <queue>
#include "./priorQueue.h"

#ifndef LFU_H
#define LFU_H

template<typename T, typename keyT = int> 
class LFU
{
private:
    long long hits;
    using queueIt = typename std::multimap<keyT, T>::iterator;
    priorQueue<keyT, T> cache;
    using cacheData = typename std::pair<long long, T>;
    std::unordered_map<keyT, queueIt> hashTab;
public:
    LFU(long long size);
    ~LFU();
    bool isFull() const;
    void cacheLookupUpdate(T data);
    void stdOutHits();
};
#include "../src/LFU.inl"
#endif