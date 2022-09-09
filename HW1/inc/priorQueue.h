#ifndef PQUEUE_H
#define PQUEUE_H

#include <map>
#include <array>

template<typename keyT, typename T>
class priorQueue
{
private:
    long long cacheSize;
    std::multimap<keyT, T> pQueue;
public:
    using pQueueIt = typename std::multimap<keyT, T>::iterator;
    priorQueue(long long size);
    ~priorQueue();
    std::pair<pQueueIt, T> poppush(keyT prior, T data);
    pQueueIt push(keyT prior, T data);
    bool isFool() const;
    pQueueIt end();
    void erase(pQueueIt itToDel);
    long long size() const;
};

#include "../src/priorQueue.inl"
#endif
