#include "LFU.h"
#include <iostream>
#include <array>

namespace PAGE {
    struct page_t {
        int id;
        std::array<char, 60> data;
    };
    page_t page;

    std::array<char, 60> slow_get_page(int id) {
        return page.data;
    }
}

int main (int argc, char* argv[]) {
    long long cacheSize, testCnt;
    std::cin >> cacheSize >> testCnt;
    Cache::LFU<std::array<char, 60>, int> cache(cacheSize);
    std::string newStr;
    long long hits = 0;
    for (long long i = 0; i < testCnt; ++i) {
        std::cin >> PAGE::page.id;
        std::cin >> newStr;
        std::copy(newStr.begin(), newStr.end(), PAGE::page.data.data());
        if (cache.cacheLookupUpdate(PAGE::page.id, PAGE::slow_get_page)) {
            ++hits;
        }
    }
    std::cout << hits << std::endl;
    return 0;
}