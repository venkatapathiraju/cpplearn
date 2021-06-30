#include <exception>
#include <stack>
#include <mutex>
#include <memory>

struct empty_stack: std::exception{
    const char* what() { return "Empty Stack";}
};

template<typename T>
class threadsafe_stack
{
    std::stack<T> data;
    mutable std::mutex m;
public:
    threadsafe_stack()
    {

    }
    ~threadsafe_stack()
    {

    }

    //Setup a lock on the stack that is copying over. 
    //Lock on local data is not needed at the time of creation
    threadsafe_stack(const threadsafe_stack& other)
    {
        std::lock_guard<std::mutex> guard(other.m);
        data = other.data;
    }
    threadsafe_stack& operator=(const threadsafe_stack &other) = delete;

    //Lock on the mutex
    void push(T new_value)
    {
        std::lock_guard<std::mutex> guard(m);
        data.push(std::move(new_value));
    }

    //Pop needs a lock
    std::shared_ptr<T> pop()
    {
        std::lock_guard<std::mutex> guard(m);
        if(data.empty()) throw empty_stack();
        std::shared_ptr<T> t =  std::make_shared<T>(std::move(data.top()));
        data.pop();
        return t;
    }

    void empty()
    {
        std::lock_guard<std::mutex> lock(m);
        data.empty();
    }

};