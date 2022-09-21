#include <iostream>
#include <fstream>
#include <string>
#include "LFU.h"

int main() {
    for (int i = 1; i <= 2; ++i){
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