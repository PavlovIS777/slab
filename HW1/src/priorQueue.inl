#ifndef PQUEUE_INL
#define PQUEUE_INL

#include "../inc/priorQueue.h"


template<typename T> priorQueue<T>::priorQueue(long long size): cacheSize(size){}

template<typename T> priorQueue<T>::~priorQueue() {}

template<typename T> std::pair<typename priorQueue<T>::pQueueIt, typename priorQueue<T>::pQueueIt> priorQueue<T>::push(long long prior, T data) {
    bool erased = false;
    auto erasedIt = this->pQueue.begin();
    if (this->isFool()) {
        this->pQueue.erase(this->pQueue.begin());
        erased = true;
    }
    auto pos = this->pQueue.emplace(prior, data);
    return std::pair<pQueueIt, pQueueIt>(pos, erased? erasedIt: this->pQueue.end());
}

template<typename T> bool priorQueue<T>::isFool() const {
    if (this->cacheSize < this->pQueue.size()) {
        std::cout << "wrong cache size";
        return 1;
    }
    return this->cacheSize == this->pQueue.size();
}

template<typename T> typename priorQueue<T>::pQueueIt priorQueue<T>::end() {
    return this->pQueue.end();
}

template<typename T> void priorQueue<T>::erase(priorQueue<T>::pQueueIt itToDel) {
    this->pQueue.erase(itToDel);    
}

template<typename T> long long priorQueue<T>::size() const {
    return this->pQueue.size();
}

#endif
