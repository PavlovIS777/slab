#ifndef PQUEUE_INL
#define PQUEUE_INL

#include "../inc/priorQueue.h"


template<typename keyT, typename T> priorQueue<keyT, T>::priorQueue(int size)
{
    this->cashSize = size;
}

template<typename keyT, typename T> priorQueue<keyT, T>::~priorQueue()
{
}

template<typename keyT, typename T> void priorQueue<keyT, T>::push(keyT prior, T data) {
    if (this->isFool()) {
        this->pQueue.clear(this->pQueue.front());
    }
    auto pos = {this->pQueue.emplace(1, data)};
    return pos;
}

template<typename keyT, typename T> bool priorQueue<keyT, T>::isFool() const {
    if (this->cashSize < this->pQueue.size()) {
        std::cout << "wrong cache size";
        return 1;
    }
    return this->cashSize == this->pQueue.size();
}

template<typename keyT, typename T> priorQueue<keyT, T>::pQueueIt priorQueue<keyT, T>::findByValue(T data) const {
    for (const auto &it: this->pQueue) {
        if (it->second == data)
            return it;
    }
    return this->pQueue.end();
}

template<typename keyT, typename T> priorQueue<keyT, T>::pQueueIt priorQueue<keyT, T>::cacheLookupUpdate(T data) {
    auto it = this->pQueue.findByValue(data);
    if (it == this->pQueue.end()) {
        this->missHits++;
        return this->push(1, data);
    } else {
        this->hits++;
        long long newPrior = it->first++;
        this->pQueue.clear(it->first);
        return this->pQueue.push(newPrior, data); 
    }
}

template<typename keyT, typename T> std::array<int, 2> priorQueue<keyT, T>::outputHits() const {
    std::array<imt, 2> output;
    output.push_back(this->hits);
    output.push_back(this->missHits);
    return output;
}

#endif