#include "./inc/LFU.h"
#include <iostream>
#include <string>

int main() {
    std::cout << "Enter cache max size: ";
    long long n;
    std::cin >> n;
    LFU<std::string> cache(n);
    std::string str;
    std::cout << "Enter requests count: ";
    long long requests;
    std::cin >> requests;
    for (long long i = 0; i < requests; ++i)
    {
        std::cin >> str;

        cache.cacheLookupUpdate(str);
    }
    cache.stdOutHits();
    return 0;
}