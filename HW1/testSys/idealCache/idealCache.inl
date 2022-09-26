#pragma once
#include <list>

template<typename T> idealCache<T>::idealCache(long long cacheSize, const std::vector<T>& requests_): cacheSize_(cacheSize), 
curInDataIndex_(0), requests(requests_) {
    for (long long i = 0; i < requests.size(); ++i)
        predictor[requests[i]].push_back(i);
}

template<typename T> int idealCache<T>::updatePredictor(T data) {
    while (predictor[data].size() > 0 and predictor[data].front() <= curInDataIndex_) {
        predictor[data].pop_front();
    }
    if (predictor[data].size() == 0) {
        auto pIt = predictor.find(data);
        hashtab.erase(data);
        cache.erase(pIt->second);
        predictor.erase(data);
        return 0;
    }
    return 1;
}

template<typename T> void idealCache<T>::updateCacheList(typename idealCache<T>::cacheIt it) {
    auto cpyDataIt = it->second;
    hashtab.erase(hashtab.find(cpyDataIt->first));
    cache.erase(it);
    auto pIt = predictor.find(cpyDataIt->first);
    auto nHashIt = cache.emplace(pIt->second, pIt);
    hashtab[cpyDataIt->first] = nHashIt;
}

template<typename T> bool idealCache<T>::cacheLookupUpdate() {
    auto data = requests[curInDataIndex_];
    auto hashIt = hashtab.find(data);
    if (hashIt != hashtab.end()) {
        if(updatePredictor(data))
            updateCacheList(hashIt->second);
        ++curInDataIndex_;
        return true;
    }
    else if (cache.size() < cacheSize_)
    {
        updatePredictor(data);
        if (predictor[data].front() != INT64_MAX) {
        auto pIt = predictor.find(data);
        auto cIt = cache.emplace(pIt->second, pIt);
        hashtab[pIt->first] = cIt;
        }
    }
    else if (updatePredictor(data)) {
        long long maxDist = predictor[data].front();
        auto maxDistIt = cache.end();
        if (cache.begin()->first.front() > maxDist) {
            maxDistIt = cache.begin();
        }
        if (maxDistIt != cache.end()) {
            hashtab.erase(hashtab.find(cache.begin()->second->first));
            cache.erase(maxDistIt);
            auto pIt = predictor.find(data);
            auto cIt = cache.emplace(pIt->second, pIt);
            hashtab[pIt->first] = cIt;
        }
    }
    ++curInDataIndex_;
    return false;
}
