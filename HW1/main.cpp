#include <iostream>
#include <string>
#include "inc/LFU.h"

int main() {
    long long queries;
    std::cin >> queries;
    LFU<std::string> cache(queries);
    for (long long i = 0; i < queries; ++i) {
        std::string newPage;
        std::cin >> newPage;
        cache.cacheLookupUpdate(newPage);
    }
    cache.stdOutHits();
    return 0;
}