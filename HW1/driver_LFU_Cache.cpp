#include "inc/LFU.h"
#include <iostream>
#include <string>
#include <chrono>
#include <fstream>

int main() {
    std::cout << "Enter test count: ";
    int tcnt = 0;
    std::cin >> tcnt;
    for (int i = 1; i <= tcnt; ++i) {
        std::ifstream input( "../testSys/randTests/test"+std::to_string(i)+".txt");
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
        std::cout << "Test #"<< std::to_string(i)<< " | Elapsed Time: " << elapsed_ms.count() << " | Hits" << " " << cache.hits() << std::endl;
    }
    return 0;
}