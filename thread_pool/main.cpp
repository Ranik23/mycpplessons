#include "thread_pool.h"
#include <iostream>


int main() {

    StaticThreadPool pool{4};

    int shared_counter = 0;

    for (size_t i = 0; i < 100501; ++i) {
        pool.Submit([&]() {
            ++shared_counter;
        });
    }

    pool.Join();

    std::cout << shared_counter << std::endl;

    return 0;
}