#include "./testSys/idealCache/idealCache.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>

int main (int argc, char* argv[]) {
    long long testCnt, cacheSize;
    std::cin >> cacheSize >> testCnt;
    std::vector<std::string> req;
    std::string newTest;
    for (long long j = 0; j < testCnt; ++j){
        std::cin >> newTest;
        req.push_back(newTest);
    }
    iCache::idealCache<std::string> cache(cacheSize, req);
    auto begin = std::chrono::steady_clock::now();
    long long hits = 0;
    for (int k = 0; k < testCnt; ++k) {
        if (cache.cacheLookupUpdate())
            ++hits;
    }
    auto end = std::chrono::steady_clock::now();
    std::string flag = "-t";
    if (argc > 1 and std::string(argv[1]) == flag) {
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        std::cout << "Test #1    ||    Elapsed Time:    " << elapsed_ms.count() << "    ||    Hits:    " << hits << std::endl;
    } else {
        std::cout << hits << std::endl;
    }
    return 0;
}