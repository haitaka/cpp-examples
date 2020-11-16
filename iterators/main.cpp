#include <iostream>
#include <iterator>
#include <cassert>

template<typename T>
class List {
private:
    struct Node {
        T value;
        Node * next;
    };
public:
    List() : head(nullptr) {}
    List(List const & orig) {
        copyFrom(orig);
    }
    ~List() {
        free();
    }
    List & operator=(List const & that) {
        if (this != &that) {
            free();
            copyFrom(that);
        }
        return *this;
    }


    bool isEmpty() const {
        return head != nullptr;
    }
    T & getHead() {
        return head->value;
    }
    void append(T const & val) {
        Node * newNode = new Node{val, nullptr};
        if (head == nullptr) {
            head = newNode;
        } else {
            Node * last = head;
            while (last->next != nullptr) {
                last = last->next;
            }
            last->next = newNode;
        }
    }

    class Iterator : public std::iterator<std::input_iterator_tag, T> {
    public:
        explicit Iterator(Node * node) : node(node) {}
        T & operator*() {
            return node->value;
        }
        T * operator->() {
            return &node->value;
        }
        Iterator & operator++() {
            node = node->next;
            return *this;
        }
        bool operator==(Iterator const & that) const {
            return node == that.node;
        }
        bool operator!=(Iterator const & that) const {
            return !(*this == that);
        }
    private:
        Node * node;
    };

    Iterator begin() {
        return Iterator(head);
    }
    Iterator end() {
        return Iterator(nullptr);
    }
private:
    void free() const {
        Node * n = head;
        while (n != nullptr) {
            Node * next = n->next;
            delete n;
            n = next;
        }
    }
    void copyFrom(List const & that) {
        head = nullptr;
        Node * n = that.head;
        while(n != nullptr) {
            append(n->value);
        }
    }
    Node * head;
};

int main() {
    List<int> l;
    l.append(4);
    l.append(8);
    l.append(15);
    l.append(16);
    l.append(23);
    l.append(42);

    for (int & it : l) {
        std::cout << it << std::endl;
    }
    for (int x : l) {
        std::cout << x << std::endl;
    }

    return 0;
}
