#include "../aidsen.hpp"
#include <pthread.h>
#include <unistd.h>

using namespace aidsen;

//#define PRINTF_DEBUG() println(stdout, __FUNCTION__, '\t', __FILE__, ':', __LINE__)
#define PRINTF_DEBUG(x) println(stdout, __FUNCTION__, '\t', __FILE__, ':', __LINE__, ' ', #x)

#if 0
  // https://en.cppreference.com/w/cpp/thread/future
  // future from a packaged_task
    std::packaged_task<int()> task([]{ return 7; }); // wrap the function
    std::future<int> f1 = task.get_future();  // get a future
    std::thread t(std::move(task)); // launch on a thread
 
    // future from an async()
    std::future<int> f2 = std::async(std::launch::async, []{ return 8; });
 
    // future from a promise
    std::promise<int> p;
    std::future<int> f3 = p.get_future();
    std::thread( [&p]{ p.set_value_at_thread_exit(9); }).detach();
 
    std::cout << "Waiting..." << std::flush;
    f1.wait();
    f2.wait();
    f3.wait();
    std::cout << "Done!\nResults are: "
              << f1.get() << ' ' << f2.get() << ' ' << f3.get() << '\n';
    t.join();
#endif

typedef int (*func_t)();

template <typename T>
struct Future {
    struct Data {
        T (*pfun0)(){};
        int arg_cnt{};
        T value{};
    };
    using func_t0 = T (*)(); // 0 stands for 0 arguments
    template<typename T1>
    using func_t1 = T (*)(T1); 
    Data data{};
    // https://stackoverflow.com/a/20031237
    static void *foo(void* arg) {
        PRINTF_DEBUG("foo - start");
        Data *data = (Data*)arg;
        data->value = data->pfun0();
        pthread_exit(NULL);
    };
    pthread_mutex_t mutex{};
    pthread_cond_t cond_thread_done{};
    pthread_t thread{};

    Future(func_t0 p = nullptr) {
        data.pfun0 = p;
    }
    void start() {
        PRINTF_DEBUG("start() - start");
        pthread_mutex_lock(&mutex);
        pthread_create(&thread, nullptr, foo, (void *)&data);
        PRINTF_DEBUG("before 50'000");
        usleep(50'000);
        PRINTF_DEBUG("after  50'000");
        pthread_mutex_unlock(&mutex);
        PRINTF_DEBUG("start() - end");
    //    pthread_cond_signal(&cond_thread_done);
    }
    void wait() {
        PRINTF_DEBUG("wait() - start");
        PRINTF_DEBUG("before 1'000");
        usleep(1'000);
        PRINTF_DEBUG("after  1'000");
        pthread_mutex_lock(&mutex);
    //    pthread_cond_wait(&cond_thread_done, &mutex);
        pthread_join(thread, nullptr);
        pthread_mutex_unlock(&mutex);
    }
    T get() {
        PRINTF_DEBUG("get() - start");
        pthread_join(thread, nullptr);
        return data.value;
    }
};

int main() {
    auto forty_two = [](){
        PRINTF_DEBUG("before 700'000");
        usleep(700'000);
        PRINTF_DEBUG("after  700'000");
        return 42;
    };
    Future<int> f1{};
    f1.data.pfun0 = forty_two; 
    Future<float> f2{[](){return 3.3f;}}; 
    f1.start();
    f2.start();
    f1.wait();
    f2.wait();
    println(stdout, f1.get());
    println(stdout, f2.get());
    return 0;
}


