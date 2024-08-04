#include "thread_pool.h"

StaticThreadPool::StaticThreadPool(size_t count) {
   StartWorkerThreads(count);
}


void StaticThreadPool::Submit(Task task) {
    tasks_.Put(std::move(task));
}

void StaticThreadPool::StartWorkerThreads(size_t count) {
    for (size_t i = 0; i < count; i++) {
        workers_.emplace_back([this]() {
            WorkerRoutine();
        });
    }
}


void StaticThreadPool::WorkerRoutine() {
    while (true) {
        auto task = tasks_.Take();
        if (!task) {
            break;
        }
        task();
    }
}


void StaticThreadPool::Join() {
    for (auto& worker: workers_) {
        tasks_.Put({});
    }

    for (auto& worker : workers_) {
        worker.join();
    }
}