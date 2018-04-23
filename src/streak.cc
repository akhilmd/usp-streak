#include <cstdint>
#include <iostream>

uint64_t streak(uint64_t N) {
    uint64_t K=1;

    if(N == 1) {
        std::cout << "Streak not defined or N=1!\n";
        return -1;
    } else if(N%2 == 0)
        return 1;
    else {
        if((N+2)%(3) != 0)
            return 2;

        while((N+K)%(K+1) == 0)
            K++;

        return K;
    }
}