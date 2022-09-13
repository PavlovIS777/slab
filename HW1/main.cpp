#include "LFU.h"
#include <iostream>
#include <string>

int main() {
    long long n;
    std::cin >> n;
    LFU<std::string> cache(n);
    std::string str;
    long long requests;
    std::cin >> requests;
    for (long long i = 0; i < requests; ++i)
    {
        std::cin >> str;

        cache.cacheLookupUpdate(str);
    }
    std::cout << cache.hits();
    return 0;
}