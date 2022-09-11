#ifndef ICACHE_INL
#define ICACHE_INL

#include "./idealCache.h"

template<typename T> void idealCache<T>::push(long long index, T data) {
    if (this->cacheSize_ == this->cache.size()) {
        this->cache.emplace(data, index);
    }
}

template<typename T> idealCache<T>::idealCache(long long cacheSize, std::vector<T> requests): hits_(0), cacheSize_(cacheSize), 
curInDataIndex(0), requests(requests) {}

template<typename T> idealCache<T>::~idealCache() {}

template<typename T> void idealCache<T>::cacheLookupUpdate(T data) {
    long long index = 0;
    if (this->cache.size() < this->cacheSize_)
    {
        this->cache.push_back(requests[this->curInDataIndex]);
        this->curInDataIndex++;
    }
    else if ((index = this->findData(data)) != -1) {
        this->curInDataIndex++;
        this->hits_++;
    } else {
        this->curInDataIndex++;
        long long repeatDataIndex = -1;
        if ((repeatDataIndex = this->findDataInRequests(data)) == -1)
            return;
        this->curInDataIndex--;
        std::pair<long long, long long> dataToDel = {-1ll, -1ll};
        for (long long i = 0; i < this->cacheSize_; ++i) {
            long long delIndex = -1;
            if (dataToDel.first < (delIndex = this->findDataInRequests(this->cache[i]))) {
                dataToDel.first = delIndex;
                dataToDel.second = i;
            }
        }
        this->curInDataIndex++;
        if (repeatDataIndex > dataToDel.first) {
            
            return;
        }
        this->cache[dataToDel.second] = data;
        //this->curInDataIndex++;
    }
}
template<typename T> long long idealCache<T>::findData(T data) {
    for (long long i = 0; i < this->cacheSize_; ++i) {
        if (this->cache[i] == data) 
            return i;
    }
    return -1;
}

template<typename T> long long idealCache<T>::findDataInRequests(T data){
    for (long long i = this->curInDataIndex; i < this->requests.size(); ++i) {
        if (this->requests[i] == data)
            return i;
    }
    return -1;
}

template<typename T> long long idealCache<T>::hits() {
    return this->hits_;
}



#endif
