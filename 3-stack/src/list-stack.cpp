#include <cassert>
#include "list-stack.h"

ListStack::ListStack() : data(List::nil()) {}

ListStack::ListStack(ListStack const & orig) : data(nullptr) {
    *this = orig;
}

ListStack::~ListStack() {
    delete data;
}

bool ListStack::isEmpty() const {
    return data == List::nil();
}

void ListStack::push(int val) {
    data = new List(val, data);
}

int ListStack::pop() {
    int val = peek();
    data = data->getTail();
    return val;
}

int ListStack::peek() const {
    assert(!isEmpty());
    return data->getHead();
}

ListStack & ListStack::operator=(ListStack const & that) {
    if (this != &that) {
        delete data;
        data = List::copy(that.data);
    }
    return *this;
}

