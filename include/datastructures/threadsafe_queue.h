#include <queue>
#include <mutex>
#include <memory>
#include <condition_variable>

template<typename T>
struct qnode{
    qnode *head, *last;
    T data;  
};

template<typename T>
class my_queue
{
    qnode<T> que;
public:
    my_queue() {}
    ~my_queue() {}

    void push(T new_value)
    {
        
    }
};

template<typename T>
class threadsafe_queue
{
    std::queue<T> que;
    mutable std::mutex mx;
    std::condition_variable data_cond;
public:
    threadsafe_queue() {}
    ~threadsafe_queue() {}
    threadsafe_queue(const threadsafe_queue&) = delete;

    void push(T new_value)
    {
        std::lock_guard<std::mutex> lock(mx);
        que.push(std::move(new_value));
        data_cond.notify_one();
    }

    void wait_and_pop(T &value)
    {
        std::unique_lock<std::mutex> lock(mx);
        data_cond.wait(lock,[this]{!return !que.empty();});
        value = std::move(que.front());
        que.pop();
    }

    bool try_pop(T & value)
    {
        std::lock_guard<std::mutex> lock(mx);
        if(que.empty()) return false;
        value = std::move(que.front());
        que.pop();
        return true;

    }
    

    void empty() const
    {
        std::lock_guard<std::mutex> lock(mx);
        return que.empty();
    }


};