#include <iostream>
#include <fstream>
#include <string>
#include "./inc/LFU.h"

int main() {
    for (int i = 1; i <= 30; ++i){
        std::ifstream input( "./tests/test"+std::to_string(i)+".txt");
        //std::ofstream output( "./tests/result"+std::to_string(i)+".txt");
        long long testCnt, cacheSize;
        input >> testCnt >> cacheSize;
        LFU<std::string> testCache(cacheSize);
        std::string newTest;
        for (long long i = 0; i < testCnt; ++i){
            input >> newTest;
            //std::cout << newTest;
            testCache.cacheLookupUpdate(newTest);
        }
        std::cout << "Test#" + std::to_string(i) << " ";    testCache.stdOutHits();
        std::cout << std::endl;
        input.close();
        //output.close();
    }
    return 0;
}