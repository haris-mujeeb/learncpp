#ifndef THREAD_SAFE_QUEUE_HPP
#define THREAD_SAFE_QUEUE_HPP

#include <queue>
#include <mutex>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    std::queue<T> m_queue;
    mutable std::mutex m_mutex;
    std::condition_variable m_cond;

public:
    ThreadSafeQueue() = default;

    // TODO: 1. Implement push
    // - Lock the mutex.
    // - Push 'value' into m_queue.
    // - Notify one waiting thread (m_cond.notify_one()).
    void push(T value) {
        // Your code here
    }

    // TODO: 2. Implement wait_and_pop
    // - Lock the mutex (use std::unique_lock).
    // - Wait on the condition variable until the queue is NOT empty.
    //   (Hint: m_cond.wait(lock, [this]{ return !m_queue.empty(); }); )
    // - Get the front value.
    // - Pop from the queue.
    // - Return the value.
    T wait_and_pop() {
        // Your code here
        return T(); // Placeholder
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_queue.empty();
    }
};

#endif // THREAD_SAFE_QUEUE_HPP