#include <iostream>
#include <atomic>
#include <mutex>
#include <thread>

class Stack {
public:
    Stack() : top(nullptr) {}
    Stack(Stack const & orig);
    Stack & operator=(Stack const & that);

    void pushAtomic(int value) {
        while (true) {
            Node * newNode = new Node(value, top.load(std::memory_order_relaxed));
            if (top.compare_exchange_weak(newNode->next, newNode, std::memory_order_release, std::memory_order_relaxed)) {
                return;
            }
        }
    }
    
    int popAtomic() {
        while (true) {
            Node * currTop = top.load(std::memory_order_relaxed);
            if (currTop == nullptr) {
                throw "empty stack";
            }
            if (top.compare_exchange_weak(currTop, currTop->next, std::memory_order_release, std::memory_order_relaxed)) {
                int value = currTop->value;
                delete currTop;
                return value;
            }
        }
    }

//    void push(int value) {
////        std::lock_guard<std::mutex> lock(mutex);
//        Node * newNode = new Node(value, top);
//        top = newNode;
//    }
//
//    int pop() {
////        std::lock_guard<std::mutex> lock(mutex);
//        Node * currTop = top;
//        if (currTop == nullptr) {
//            throw "empty stack";
//        }
//        top = currTop->next;
//        int value = currTop->value;
//        delete currTop;
//        return value;
//    }

    bool isEmpty() const {
        return top == nullptr;
    }

private:
    struct Node {
        int value;
        Node * next;
        Node(int value, Node * next) : value(value), next(next) {}
    };

    std::atomic<Node *> top;
//    Node * top;
    std::mutex mutex;
};


int main() {
    return 0;
}
