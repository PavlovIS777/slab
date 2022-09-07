#ifndef PQUEUE_H
#define PQUEUE_H

#include <map>
#include <array>


template<typename keyT, typename T>
class priorQueue
{
private:
    int cashSize;
    long long hits;
    long long missHits;
    std::map<keyT, T> pQueue;
public:
    using pQueueIt = typename std::map<keyT, T>::iterator;
    priorQueue(int size);
    ~priorQueue();
    void push(keyT prior, T data);
    pQueueIt findByValue(T data) const;
    pQueueIt cacheLookupUpdate(T data);
    bool isFool() const;
    std::array<int, 2> outputHits() const;
};

#endif
