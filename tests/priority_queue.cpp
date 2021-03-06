#include "../aidsen.hpp"

using namespace aidsen;

template <typename T = void>
struct Less {
    constexpr bool operator()(const T &lhs, const T &rhs) const {
        return lhs < rhs;
    }
};

template <typename T = void>
struct Greater {
    constexpr bool operator()(const T &lhs, const T &rhs) const {
        return lhs > rhs;
    }
};

template <typename T, class Compare = Less<T>>
struct Priority_Queue {
    List<T> list{};
    void push(T t) {
        if (list.size() == 0) {
            list.push_back(t);
            return;
        }
        for (ssize_t i{}; i<list.size(); ++i) {
            if (Compare()(t, list.at(i)->item)) {
                list.insert(i, t);
                return;
            }
        }
        list.push_back(t);
        return;
    }
    T pop() {
        if (list.size() > 1) {
            T result = list.tail->item;
            auto *tmp = list.tail;
            list.tail->prev->next = nullptr;
            list.tail = list.tail->prev;
            free(tmp);
            return result;
        } else if (list.size() == 1) {
            T result = list.tail->item;
            auto *tmp = list.tail;
            list.head = nullptr;
            list.tail = nullptr;
            free(tmp);

            return result;
        } else {
            panic("Nothing to pop");
        }
    }
    bool empty() const {
        return (0 == list.size()); 
    }
};

struct Person {
    String_View name{};
    int height{};
    int weight{};
};

Person people[] = {
    {"Alice"_sv,   160,  50},
    {"Bob"_sv,     180, 100},
    {"Charlie"_sv, 170,  60},
    {"Diana"_sv,   190,  59},
};
constexpr int people_size = sizeof(people) / sizeof(people[0]);

struct Less_By_Height {
    constexpr bool operator()(const Person &lhs, const Person &rhs) const {
        return lhs.height > rhs.height;
    }
};

struct Less_By_Weight {
    constexpr bool operator()(const Person &lhs, const Person &rhs) const {
        return lhs.weight > rhs.weight;
    }
};

void print1(FILE *stream, Person person) {
    print(stream, person.name, ' ', person.height, ' ', person.weight);
}

int main() {

    Priority_Queue<float> pq{};

    pq.push(4.1f);
    assert(1 == pq.list.size());
    pq.push(2.2f);
    assert(2 == pq.list.size());
    pq.push(8.3f);
    assert(3 == pq.list.size());
    pq.push(1.4f);
    assert(4 == pq.list.size());
    pq.push(7.5f);
    assert(5 == pq.list.size());
    pq.push(0.6f);
    assert(6 == pq.list.size());
    pq.push(9.7f);
    assert(7 == pq.list.size());

    println(stdout, "size == ", pq.list.size(), ' ');
    while (not pq.empty()) {
        println(stdout, pq.pop(), ' ');
    }
    println(stdout);
    {
        Priority_Queue<int, Greater<int>> pqg{};
        pqg.push(3);
        pqg.push(1);
        pqg.push(300);
        pqg.push(100);
        println(stdout, "size == ", pqg.list.size(), ' ');
        while (not pqg.empty()) {
            println(stdout, pqg.pop(), ' ');
        }
        println(stdout);
    }
    {
        Priority_Queue<Person, Less_By_Height> person_queue{};
        for (int i{}; i < people_size; ++i) {
            person_queue.push(people[i]);
        }    
        while (not person_queue.empty()) {
            println(stdout, person_queue.pop(), ' ');
        }
        println(stdout);
    }
    {
        Priority_Queue<Person, Less_By_Weight> person_queue{};
        for (int i{}; i < people_size; ++i) {
            person_queue.push(people[i]);
        }    
        while (not person_queue.empty()) {
            println(stdout, person_queue.pop(), ' ');
        }
        println(stdout);
    }
}
