#ifndef THREAD_POOL
#define THREAD_POOL

#include <cstddef>
#include <vector>
#include <deque>
#include <functional>
#include <thread>
#include "blocking_queue.h"


#define Task std::function<void()>

class StaticThreadPool {
    public:
        StaticThreadPool(size_t workers);
        void Submit(Task task);
        void Join();
    private:
        void StartWorkerThreads(size_t count);
        void WorkerRoutine();
        std::vector<std::thread> workers_;
        BlockingQueue<Task> tasks_;
};


#endif