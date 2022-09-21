/*
                                ___________________________
                                |Ideal cache implementation|
                                ...........................
                                    Author: Ivan Pavlov
                                    Date: 11.09.2022

*/
/* 
                                @@@ Descriptoin @@@
        - cache:        Cache based on stl::vector. Templates parameter is
                    T-data - custom data.
        - request:  Based on stl::vector. Containts all user requests.
                                !!! WARNING !!!
                This is just a model of ideal cache. It realised very simple
                and works to slow for comfortable usage. This model can help
                  you to rate how good your cache is on some data sets.
*/

/*
                            TO USE IT (DO NOT USE IT):
        1) Use default ctor by passing user requests in std::vector.
        2) Then call "cacheLookupUpdate". Put in new data-request as argument.
        3) After all requests cache will calculate hits.
*/

#pragma once


#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <set>

struct idealCacheComparator
{
    bool operator()(const std::list<long long>& lhv, const std::list<long long>& rhv) const{
        return lhv.front() > rhv.front();
    }
};


template<typename T> 
class idealCache {
    private:
    
    using predictorIt = typename std::map<T, std::list<long long>>::iterator;
    using cacheIt = typename std::multimap<std::list<long long>, predictorIt, idealCacheComparator>::iterator;
    long long hits_;
    long long cacheSize_;
    long long curInDataIndex_;
    std::vector<T> requests;
    std::set<T> testSet;
    std::multimap<std::list<long long>, predictorIt, idealCacheComparator> cache;

    std::map<T, std::list<long long>> predictor;
    std::unordered_map<T, cacheIt> hashtab;
    public:

    idealCache(long long cacheSize, const std::vector<T>& requests);
    void cacheLookupUpdate();
    long long hits();
    int updatePredictor(T data);
    void updateCacheList(cacheIt it);
};

#include "idealCache.inl"
