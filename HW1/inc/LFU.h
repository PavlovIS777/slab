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

#include <list>
#include <unordered_map>
#include <queue>
#include "priorQueue.h"

#ifndef LFU_H
#define LFU_H

template<typename T> 
class LFU
{
private:
    long long hits_;
    long long cacheSize;
    long long requestIndex;
    using queueIt = typename std::multimap<std::pair<long long, long long>, T>::iterator;
    priorQueue<std::pair<long long, long long>, T> cache;
    using cacheData = typename std::pair<long long, T>;
    std::unordered_map<T, queueIt> hashTab;
public:
    LFU(long long size);
    ~LFU();
    bool isFull() const;
    void cacheLookupUpdate(T data);
    long long hits() const;
};
#include "../src/LFU.inl"
#endif
