#ifndef PQUEUE_H
#define PQUEUE_H

#include <map>
#include <array>
#include <iterator>
#include <iostream>

template<typename T>
class priorQueue
{
private:
    long long cacheSize;
    std::multimap<long long, T> pQueue;
public:
    using pQueueIt = typename std::multimap<long long, T>::iterator;
    priorQueue(long long size);
    ~priorQueue();
    std::pair<pQueueIt, pQueueIt> push(long long prior, T data);
    bool isFool() const;
    pQueueIt end();
    void erase(pQueueIt itToDel);
    long long size() const;
};

#include "../src/priorQueue.inl"
#endif
