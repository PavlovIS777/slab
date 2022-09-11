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




#include <vector>

#ifndef ICACHE_H
#define ICACHE_H

template<typename T> 
class idealCache {
    private:
    long long hits_;
    long long cacheSize_;
    long long curInDataIndex;
    std::vector<T> requests;
    std::vector<T> cache;
    public:
    idealCache(long long cacheSize, std::vector<T> requests);
    ~idealCache();
    void push(long long index, T data);
    long long findData(T data);
    void cacheLookupUpdate(T data);
    long long findDataInRequests(T data);
    long long hits();
};

#include "./idealCache.inl"
#endif