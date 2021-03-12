#include "../aidsen.hpp"

using namespace aidsen;

template <typename Item>
struct List {
    struct Node {
        Item item{};
        Node *next{};
    };
    Node *node{};

    void push(Item that) {
        if (nullptr == node) {
            node = (Node*)malloc(sizeof(Node));
            node->item = that;
        } else {
            Node *curr{};
            curr = node->next;
            while (nullptr != curr) {
                curr = curr->next;
            }
            curr = (Node*)malloc(sizeof(Node));
            curr->item = that;
        }
    }
};

int main() {
    List<int> list;
    list.push(42);
    list.push(43);

    return 0;
}
