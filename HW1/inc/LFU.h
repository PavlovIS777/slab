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
    using queueIt = typename priorQueue::iterator;
    long long maxSize;
    priorQueue<keyT, T> cache;
    using cashData = typename std::pair<long long, T>;
    std::unordered_map<keyT, queueIt> hashTab;
public:
    LFU(long long size);
    ~LFU();
    bool isFull() const;
    bool cacheLookupUpdate(T data);
    void stdOutHits();
};
#include "../src/LFU.inl"
#endif