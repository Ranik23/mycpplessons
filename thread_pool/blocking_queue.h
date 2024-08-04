
#ifndef BLOCKING_QUEUE
#define BLOCKING_QUEUE

#include <mutex>
#include <deque>
#include <chrono>
#include <condition_variable>

using namespace std::chrono_literals;

template<typename T>
class BlockingQueue {
  public:

    void Put(T value) {
        std::lock_guard guard(mutex_);
        buffer_.push_back(std::move(value));
        not_empty_.notify_one();
    }

    T Take() {
        std::unique_lock lock(mutex_);
        while (buffer_.empty()) {
            not_empty_.wait(lock);
        }
        return TakeLocked();
    }


  private:

    T TakeLocked() {
        T front = std::move(buffer_.front());
        buffer_.pop_front();
        return front;
    }

  private:
    std::deque<T> buffer_; // Guarded By mutex_
    std::mutex mutex_;
    std::condition_variable not_empty_;
};


#endif

