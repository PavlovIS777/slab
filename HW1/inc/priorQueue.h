#ifndef PQUEUE_H
#define PQUEUE_H

#include <map>
#include <array>
#include <iterator>
#include <iostream>

template<typename keyT, typename T>
class priorQueue
{
private:
    long long cacheSize;
    std::multimap<keyT, T> pQueue;
public:
    using pQueueIt = typename std::multimap<keyT, T>::iterator;
    using const_pQueueIt = typename std::multimap<keyT, T>::const_iterator;
    priorQueue(long long size);
    ~priorQueue();
    pQueueIt push(keyT prior, T data);
    pQueueIt findByValue(T data);
    bool isFool() const;
    pQueueIt end();
    void erase(pQueueIt itToDel);
};
#include "../src/priorQueue.inl"
#endif
