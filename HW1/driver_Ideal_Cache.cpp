#include "idealCache.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>

int main () {
    long long testCnt, cacheSize;
    std::cin >> cacheSize >> testCnt;
    std::vector<std::string> req;
    std::string newTest;
    for (long long j = 0; j < testCnt; ++j){
        std::cin >> newTest;
        req.push_back(newTest);
    }
    idealCache<std::string> cache(cacheSize, req);
    auto begin = std::chrono::steady_clock::now();
    for (int k = 0; k < testCnt; ++k) {
        cache.cacheLookupUpdate();
    }
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "Test #1    ||    Elapsed Time:    " << elapsed_ms.count() << "    ||    Hits:    " << cache.hits() << std::endl;
    return 0;
}