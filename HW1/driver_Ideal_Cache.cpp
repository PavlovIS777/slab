#include "idealCache.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>

int main () {
    std::cout << "Enter test count: ";
    int tcnt = 0;
    std::cin >> tcnt;
    for (int i = 1; i <= tcnt; ++i){
        std::ifstream input( "../testSys/randTests/test"+std::to_string(i)+".txt");
        long long testCnt, cacheSize;
        input >> cacheSize >> testCnt;
        std::vector<std::string> req;
        std::string newTest;
        for (long long j = 0; j < testCnt; ++j){
            input >> newTest;
            req.push_back(newTest);
        }
        idealCache<std::string> cache(cacheSize, req);
        auto begin = std::chrono::steady_clock::now();
        for (int k = 0; k < testCnt; ++k) {
            cache.cacheLookupUpdate();
        }
        auto end = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        std::cout << "Test #"<< std::to_string(i)<< " | Elapsed Time: " << elapsed_ms.count() << " | Hits" << " " << cache.hits() << std::endl;
    }
    return 0;
}