#include "inc/LFU.h"
#include <iostream>
#include <string>
#include <chrono>
#include <fstream>

int main() {
    std::ifstream input( "testSys/randTests/test"+std::to_string(1)+".txt");
    long long testCnt, cacheSize;
    input >> cacheSize >> testCnt;
    LFU<std::string> cache(cacheSize);
    std::vector<std::string> req;
    std::string newTest;
    for (long long i = 0; i < testCnt; ++i) {
        input >> newTest;
        req.push_back(newTest);
    }
    auto begin = std::chrono::steady_clock::now();
    for (long long i = 0; i < testCnt; ++i)
    {
        cache.cacheLookupUpdate(req[i]);
    }
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << cache.hits() << " " << elapsed_ms.count();
    return 0;
}