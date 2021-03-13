#include "../aidsen.hpp"

using namespace aidsen;

int main() {
    List<int> list;
    list.push_back(42);
    list.push_back(43);
    list.push_back(44);
    list.push_back(45);

    list.print();
    println(stdout, "size == ", list.size());
    println(stdout, "1st  == ", list.at(0)->item);

    println(stdout);

    list.push_front(41);
    list.push_front(40);

    list.print();
    println(stdout, "size == ", list.size());
    println(stdout, "1st  == ", list.at(0)->item);

    auto item_4th = list.at(3);
    assert(43 == item_4th->item);
    list.insert(3, {10});

    list.print();
    println(stdout, "size == ", list.size());
    println(stdout, "1st  == ", list.at(0)->item);

    return 0;
}
