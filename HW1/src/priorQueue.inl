#ifndef PQUEUE_INL
#define PQUEUE_INL

#include "../inc/priorQueue.h"


template<typename keyT, typename T> priorQueue<keyT, T>::priorQueue(long long size): cacheSize(size){}

template<typename keyT, typename T> priorQueue<keyT, T>::~priorQueue() {}

template<typename keyT, typename T> typename priorQueue<keyT, T>::pQueueIt priorQueue<keyT, T>::push(keyT prior, T data) {
    if (this->isFool()) {
        this->pQueue.erase(this->pQueue.begin());
    }
    auto pos = this->pQueue.emplace(prior, data);
    return pos;
}

template<typename keyT, typename T> bool priorQueue<keyT, T>::isFool() const {
    if (this->cacheSize < this->pQueue.size()) {
        std::cout << "wrong cache size";
        return 1;
    }
    return this->cacheSize == this->pQueue.size();
}

template<typename keyT, typename T> typename priorQueue<keyT, T>::pQueueIt priorQueue<keyT, T>::findByValue(T data) {
    for (auto it = this->pQueue.begin(); it != this->pQueue.end(); ++it) {
        if (it->second == data)
            return it;
    }
    return this->pQueue.end();
}
template<typename keyT, typename T> typename priorQueue<keyT, T>::pQueueIt priorQueue<keyT, T>::end() {
    return this->pQueue.end();
}

template<typename keyT, typename T> void priorQueue<keyT, T>::erase(priorQueue<keyT, T>::pQueueIt itToDel) {
    this->pQueue.erase(itToDel);    
}

#endif
