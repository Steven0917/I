#pragma once

#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <future>
#include <condition_variable>
#include <functional>
#include <stdexcept>

using std::queue;
using std::vector;
using std::future;
using std::thread;
using std::function;
using std::mutex;
using std::condition_variable;
using std::result_of;
using std::unique_lock;

namespace PUMA {
namespace Kernel {

class ThreadPool
{
public:
    ThreadPool(size_t);
    ~ThreadPool();

    template<class F, class... Args>
    auto enqueue(F&& f, Args&&... args)
        ->future<typename result_of<F(Args...)>::type>;

private:

    vector<thread> workers;
    queue<function<void()>> tasks;

    mutex queue_mutex;
    condition_variable condition;
    bool stop;
};

inline ThreadPool::ThreadPool(size_t threads) : stop(false)
{
    for (size_t i = 0; i < threads; ++i)
        workers.emplace_back(
            [this]
    {
        for (;;)
        {
            function<void()> task;

            {
                unique_lock<mutex> lock(this->queue_mutex);
                this->condition.wait(lock,
                    [this] { return this->stop || !this->tasks.empty(); });
                if (this->stop && this->tasks.empty())
                    return;
                task = move(this->tasks.front());
                this->tasks.pop();
            }

            task();
        }
    }
    );
}

inline ThreadPool::~ThreadPool()
{
    {
        unique_lock<mutex> lock(queue_mutex);
        stop = true;
    }
    condition.notify_all();
	for (thread &worker : workers)
	{
        worker.join();
	}
}

template<class F, class... Args>
auto ThreadPool::enqueue(F&& f, Args&&... args)
-> future<typename result_of<F(Args...)>::type>
{
    using return_type = typename result_of<F(Args...)>::type;

    auto task = make_shared<packaged_task<return_type()> >(
        bind(forward<F>(f), forward<Args>(args)...)
        );

    future<return_type> res = task->get_future();
    {
        unique_lock<mutex> lock(queue_mutex);

        if (stop)
            throw runtime_error("enqueue on stopped ThreadPool");

        tasks.emplace([task]() { (*task)(); });
    }
    condition.notify_one();
    return res;
}


}  // namespace Kernel
}  // namespace PUMA