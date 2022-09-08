#include <list>
#include <unordered_map>
#include <queue>
#include "./priorQueue.h"

#ifndef LFU_H
#define LFU_H

template<typename T> 
class LFU
{
private:
    long long hits;
    using queueIt = typename std::multimap<long long, T>::iterator;
    priorQueue<T> cache;
    using cacheData = typename std::pair<long long, T>;
    std::unordered_map<T, queueIt> hashTab;
public:
    LFU(long long size);
    ~LFU();
    bool isFull() const;
    void cacheLookupUpdate(T data);
    void stdOutHits();
    void eraseByCacheIt(queueIt erasedIt);
};
#include "../src/LFU.inl"
#endif