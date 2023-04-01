/*
                                ___________________
                                |LFU implementation|
                                ...................
                                Author: Ivan Pavlov
                                Date: 11.09.2022

*/
/* 
                                @@@ Descriptoin @@@
        - cache:    Cache based on priority Queue. Templates first parameter is
                pair of priority and incoming time. Second - data.
        - hashTab:  Based on stl::unordered_map. Containts pair data (key) and
                queue iterator (value).
*/

/*
                                    TO USE IT:
        1) First create LFU-class with template. You should specify datatype
        2) Then call "cacheLookupUpdate". Put in new data-request as argument
        3) After all requests cache will calculate hits.
*/
#pragma once
#include <list>
#include <unordered_map>
#include <queue>
#include "priorQueue.h"

namespace Cache {

template<typename T, typename keyT = int> 
class LFU
{
private:
    long long cacheSize_;
    long long requestIndex_;
    using queueIt = typename std::multimap<std::pair<long long, long long>, std::pair<T, keyT>>::iterator;
    priorQueue<std::pair<long long, long long>, std::pair<T, keyT>> cache;
    std::unordered_map<keyT, queueIt> hashTab;
public:
    LFU(long long size);
    bool isFull() const;
    template<typename F> bool cacheLookupUpdate(keyT key, F slow_get_page);
};
#include "LFU.inl"
}
