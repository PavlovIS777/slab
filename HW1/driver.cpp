#include <iostream>
#include <fstream>
#include <string>
#include "LFU.h"
#define iCache
#ifdef TEST
int main() {
    for (int i = 1; i <= 30; ++i){
        std::ifstream input( "./testSys/randTests/test"+std::to_string(i)+".txt");
        //std::ofstream output( "./tests/result"+std::to_string(i)+".txt");
        long long testCnt, cacheSize;
        input >> cacheSize >> testCnt;
        LFU<std::string> testCache(cacheSize);
        std::string newTest;
        for (long long i = 0; i < testCnt; ++i){
            input >> newTest;
            //std::cout << newTest;
            testCache.cacheLookupUpdate(newTest);
        }
        std::cout << "Test#" + std::to_string(i) << " " << testCache.hits();
        std::cout << std::endl;
        input.close();
        //output.close();
    }
    return 0;
}
#else
#include <vector>
#include "./testSys/idealCache/idealCache.h"
int main() {
    int testInCnt = 0;
    std::cout << "Enter test count: ";
    std::cin >> testInCnt;
    std::cout << std::endl;
    std::cout << "LFU-implementation | Ideal Cache";
    std::cout << std::endl;
    for (int i = 1; i <= testInCnt; ++i){
        std::ifstream input( "./testSys/randTests/test"+std::to_string(i)+".txt");
        //if (input == nullptr)
        long long testCnt, cacheSize;
        std::vector<std::string> fileData;
        input >> cacheSize >> testCnt;
        LFU<std::string> testCache(cacheSize);
        std::string newTest;
        for (long long i = 0; i < testCnt; ++i) {
            input >> newTest;
            fileData.push_back(newTest);
        }
        idealCache<std::string> idealCache(cacheSize, fileData);
        for (long long i = 0; i < testCnt; ++i){
            //std::cout << newTest;
            testCache.cacheLookupUpdate(fileData[i]);
            idealCache.cacheLookupUpdate(fileData[i]);
        }
        std::string space = i/10 == 0? "         " : "        ";
        std::cout << "Test#" + std::to_string(i) << space << testCache.hits() << " | " << idealCache.hits();
        std::cout << std::endl;
        input.close();
        //output.close();
    }
    return 0;
}
#endif