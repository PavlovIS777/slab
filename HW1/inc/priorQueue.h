/*
                                ______________________________
                                |Priority Queue implementation|
                                ..............................
                                    Author: Ivan Pavlov
                                    Date: 11.09.2022

*/
/* 
                                @@@ Descriptoin @@@
        - pQueue:   Priority Queue based on stl::multimap. Templates first parameter is
                keyT - custom type of priority. Second - T-data of queue, user's data.
*/

/*
                                    TO USE IT:
        1)      Create class with your custom types
        2)      Use pop/push and etc. functions to store your data.
            Queue sort it by priority.
*/

#ifndef PQUEUE_H
#define PQUEUE_H

#include <map>
#include <array>

template<typename keyT, typename T>
class priorQueue
{
private:
    long long cacheSize_;
    std::multimap<keyT, T> pQueue;
public:
    using pQueueIt = typename std::multimap<keyT, T>::iterator;
    priorQueue(long long size);
    std::pair<pQueueIt, T> poppush(keyT prior, T data);
    pQueueIt push(keyT prior, T data);
    bool isFull() const;
    pQueueIt end() const;
    void erase(pQueueIt itToDel);
    long long size() const;
};

#include "priorQueue.inl"
#endif
