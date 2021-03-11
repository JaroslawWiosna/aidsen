#include "../aidsen.hpp"

using namespace aidsen;

struct Widget {
    int i{};
    ~Widget() {
        println(stdout, __FILE__, ':', __LINE__, ' ',  __PRETTY_FUNCTION__); 
    }
};

template
<typename T>
struct Shared_Ptr {
    T *t{};
    int *ref_cnt{};

    static Shared_Ptr<T> make_shared(T t) {
        println(stdout, __FILE__, ':', __LINE__, ' ',  __PRETTY_FUNCTION__); 
        auto sp = Shared_Ptr<T>{};
        sp.t = (T*)malloc(sizeof(T));
        *sp.t = t;
        sp.ref_cnt = (int*)malloc(sizeof(int));
        *(sp.ref_cnt) += 1;
        assert(1 == *(sp.ref_cnt));
        return sp;
    };

    Shared_Ptr() {
        println(stdout, __FILE__, ':', __LINE__, ' ',  __PRETTY_FUNCTION__); 
    }
    Shared_Ptr(T *that) {
        println(stdout, __FILE__, ':', __LINE__, ' ',  __PRETTY_FUNCTION__); 
        t = that;
        ref_cnt = (int*)malloc(sizeof(int));
        *ref_cnt += 1;
        assert(1 == *ref_cnt);
    }
    Shared_Ptr(Shared_Ptr &that) {
        println(stdout, __FILE__, ':', __LINE__, ' ',  __PRETTY_FUNCTION__); 
        t = that.t;
        *(that.ref_cnt) += 1;
        ref_cnt = that.ref_cnt;
    }
    ~Shared_Ptr() {
        println(stdout, __FILE__, ':', __LINE__, ' ',  __PRETTY_FUNCTION__, " *ref_cnt == ", *ref_cnt); 
        *ref_cnt -= 1;
        if (0 == *ref_cnt) {
            println(stdout, __FILE__, ':', __LINE__, ' ',  __PRETTY_FUNCTION__, " *ref_cnt == ", *ref_cnt); 
            t->~T();
            free(t);
        }
    }
};


int main() {
    // auto sp1 = Shared_Ptr<Widget>::make_shared(Widget{42});
    auto *widget = (Widget*)malloc(sizeof(Widget));
    widget->i = 44;;
    {
        Shared_Ptr<Widget> sp1{widget};
        println(stdout, "ref_cnt == ", *sp1.ref_cnt);
        {
            auto sp2{sp1};
            println(stdout, "ref_cnt == ", *sp1.ref_cnt);
            {
                auto sp3{sp1};
                println(stdout, "ref_cnt == ", *sp1.ref_cnt);
            }
            println(stdout, "ref_cnt == ", *sp1.ref_cnt);
        }
        println(stdout, "ref_cnt == ", *sp1.ref_cnt);
    }
    return 0;
}


