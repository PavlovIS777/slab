#include "inc/LFU.h"
#include <iostream>
#include <string>
#include <chrono>
#include <fstream>

int main() {
    std::string newTest;
    long long testCnt, cacheSize;
    std::cin >> cacheSize >> testCnt;
    LFU<std::string> cache(cacheSize);
    auto begin = std::chrono::steady_clock::now();
    for (long long i = 0; i < testCnt; ++i) {
        std::cin >> newTest;
        cache.cacheLookupUpdate(newTest);
    }
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "Test #1    ||   Elapsed Time:    " << elapsed_ms.count() << "     ||     Hits:    " << cache.hits() << std::endl;
    return 0;
}