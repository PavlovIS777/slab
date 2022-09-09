#ifndef PQUEUE_INL
#define PQUEUE_INL

#include "../inc/priorQueue.h"
#include <iostream>

template<typename keyT, typename T> priorQueue<keyT, T>::priorQueue(long long size): cacheSize(size){}

template<typename keyT, typename T> priorQueue<keyT, T>::~priorQueue() {}

template<typename keyT, typename T> std::pair<typename priorQueue<keyT, T>::pQueueIt, T> priorQueue<keyT, T>::poppush(keyT prior, T data) {
    T erasedData = this->pQueue.begin()->second;
    this->pQueue.erase(this->pQueue.begin());
    auto pos = this->pQueue.emplace(prior, data);
    return std::pair<pQueueIt, T>(pos, erasedData);
}

template<typename keyT, typename T> typename priorQueue<keyT, T>::pQueueIt priorQueue<keyT, T>::push(keyT prior, T data) {
    return this->pQueue.emplace(prior, data);
}

template<typename keyT, typename T> bool priorQueue<keyT, T>::isFool() const {
    if (this->cacheSize < this->pQueue.size()) {
        std::cout << "wrong cache size";
        return 1;
    }
    return this->cacheSize == this->pQueue.size();
}

template<typename keyT, typename T> typename priorQueue<keyT, T>::pQueueIt priorQueue<keyT, T>::end() {
    return this->pQueue.end();
}

template<typename keyT, typename T> void priorQueue<keyT, T>::erase(priorQueue<keyT, T>::pQueueIt itToDel) {
    this->pQueue.erase(itToDel);    
}

template<typename keyT, typename T> long long priorQueue<keyT, T>::size() const {
    return this->pQueue.size();
}

#endif
