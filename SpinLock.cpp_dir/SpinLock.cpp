#include <atomic>
#include <utility>
#include <thread>
#include <vector>
#include <iostream>

class TASSpinLock {
public:
    void Lock()
    {
        while (locked_.exchange(true))
        {
            // в спинлоке мы просто крутимся, а в mutex мы говорим планировщику, чтобы он не тратил ресурсы процессора на этот поток
            // std::this_thread::yield();
            // wait
        }
    }

    void UnLock()
    {
        locked_.store(false);
    }

private:
    std::atomic<bool> locked_{false};
};

class Mutex {
public:
    void Lock()
    {
        while (locked_.exchange(true))
        {
            std::this_thread::yield();
        }
    }

    void UnLock()
    {
        locked_.store(false);
    }

private:
    std::atomic<bool> locked_{false};
};

int main()
{

    return 0;
}
