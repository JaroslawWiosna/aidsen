#include "../aidsen.hpp"

using namespace aidsen;

template <typename Item>
struct List {
    struct Node {
        Item item{};
        Node *next{};
        Node *prev{};
    };
    Node *head{};
    Node *tail{};

    void print() {
        Node *curr{head};
        while (curr != nullptr) {
            ::aidsen::print(stdout, curr->item, ' ');
            curr = curr->next;
        }
        println(stdout);
    }

    void push_back(Item that) {
        if (nullptr == head && nullptr == tail) {
            head = (Node*)malloc(sizeof(Node));
            head->item = that;
            tail = head;
        } else {
            assert(nullptr == tail->next);
            tail->next = (Node*)malloc(sizeof(Node));
            tail->next->item = that;
            tail->next->prev = tail;
            tail = tail->next;
        }
    }
    void push_front(Item that) {
        if (nullptr == head && nullptr == tail) {
            head = (Node*)malloc(sizeof(Node));
            head->item = that;
            tail = head;
        } else {
            assert(nullptr == head->prev);
            head->prev = (Node*)malloc(sizeof(Node));
            head->prev->item = that;
            head->prev->next = head;
            head = head->prev;
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

    list.push_front(41);
    list.push_front(40);
    list.print();

    return 0;
}
