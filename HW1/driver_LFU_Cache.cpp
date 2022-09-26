#include "inc/LFU.h"
#include <iostream>
#include <string>
#include <chrono>
#include <fstream>



std::string slow_get_page(std::string key) {
    return key;
}

int main(int argc, char* argv[]) {
    std::string newTest;
    long long testCnt, cacheSize;
    std::cin >> cacheSize >> testCnt;
    Cache::LFU<std::string, std::string> cache(cacheSize);
    auto begin = std::chrono::steady_clock::now();
    unsigned long long hits = 0;
    for (long long i = 0; i < testCnt; ++i) {
        std::cin >> newTest;
        if (cache.cacheLookupUpdate<std::string (std::string)>(newTest, slow_get_page)) {
            ++hits;
        }
    }
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::string flag = "-t";
    if (argc > 1 and std::string(argv[1]) == flag) {
        std::cout << "Test #1    ||   Elapsed Time:    " << elapsed_ms.count() << "     ||    Hits:    " << hits << std::endl;
    } else {
        std::cout << hits << std::endl;
    }
    return 0;
}