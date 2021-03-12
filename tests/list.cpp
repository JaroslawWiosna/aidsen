#include "../aidsen.hpp"

using namespace aidsen;

int main() {
    List<int> list;
    list.push_back(42);
    list.push_back(43);
    list.push_back(44);
    list.push_back(45);
    list.print();

    list.push_front(41);
    list.push_front(40);
    list.print();

    return 0;
}
