#ifndef PQUEUE_INL
#define PQUEUE_INL

#include <iostream>

template<typename keyT, typename T> priorQueue<keyT, T>::priorQueue(long long size): cacheSize_(size){}

template<typename keyT, typename T> std::pair<typename priorQueue<keyT, T>::pQueueIt, T> priorQueue<keyT, T>::poppush(keyT prior, T data) {
    T erasedData = pQueue.begin()->second;
    pQueue.erase(this->pQueue.begin());
    auto pos = pQueue.emplace(prior, data);
    return std::pair<pQueueIt, T>(pos, erasedData);
}

template<typename keyT, typename T> typename priorQueue<keyT, T>::pQueueIt priorQueue<keyT, T>::push(keyT prior, T data) {
    return pQueue.emplace(prior, data);
}

template<typename keyT, typename T> bool priorQueue<keyT, T>::isFull() const {
    if (cacheSize_ < pQueue.size()) {
        std::cout << "wrong cache size";
        return 1;
    }
    return cacheSize_ == pQueue.size();
}

template<typename keyT, typename T> typename priorQueue<keyT, T>::pQueueIt priorQueue<keyT, T>::end() const {
    return pQueue.end();
}

template<typename keyT, typename T> void priorQueue<keyT, T>::erase(priorQueue<keyT, T>::pQueueIt itToDel) {
    pQueue.erase(itToDel);    
}

template<typename keyT, typename T> long long priorQueue<keyT, T>::size() const {
    return pQueue.size();
}

#endif
