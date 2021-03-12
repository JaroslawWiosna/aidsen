#include "../aidsen.hpp"

using namespace aidsen;

template <typename Item>
struct List {
    struct Node {
        Item item{};
        Node *next{};
    };
    Node *node{};

    void print() {
        Node *curr{node};
        while (curr != nullptr) {
            ::aidsen::print(stdout, curr->item, ' ');
            curr = curr->next;
        }
        println(stdout);
    }

    void push_back(Item that) {
        if (nullptr == node) {
            node = (Node*)malloc(sizeof(Node));
            node->item = that;
        } else {
            Node *curr = node;
            while (nullptr != curr->next) {
                curr = curr->next;
            }
            curr->next = (Node*)malloc(sizeof(Node));
            curr->next->item = that;
        }
    }
};

int main() {
    List<int> list;
    list.push_back(42);
    list.push_back(43);
    list.push_back(44);
    list.push_back(45);
    list.print();

    return 0;
}
