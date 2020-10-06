#include "array-stack.h"

#include <cassert>

ArrayStack::ArrayStack() : ArrayStack(defaultCapacity) {}

ArrayStack::ArrayStack(int capacity)
    : capacity(capacity)
    , data(new int[capacity])
    , top(0) {}

ArrayStack::ArrayStack(const ArrayStack & orig) : data(nullptr) {
    initFrom(orig);
}

ArrayStack::~ArrayStack() {
    free();
}

void ArrayStack::free() {
    delete[] data;
    data = nullptr;
}

ArrayStack & ArrayStack::operator=(ArrayStack const & that) {
    if (this != &that) {
        free();
        initFrom(that);
    }
    return *this;
}

void ArrayStack::initFrom(ArrayStack const & that) {
    assert(data == nullptr);

    top = that.top;
    capacity = that.capacity;
    data = new int[capacity];
    for (int i = 0; i < capacity; ++i) {
        this->data[i] = that.data[i];
    }
}

void ArrayStack::grow() {
    int newCapacity = capacity * growthFactor;
    int * newData = new int[newCapacity];
    for (int i = 0; i < top; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

bool ArrayStack::isEmpty() const {
    return top == 0;
}

void ArrayStack::push(int val) {
    if (top == capacity) {
        grow();
    }
    data[top++] = val;
}

int ArrayStack::pop() {
    int topValue = peek();
    top -= 1;
    return topValue;
}

int ArrayStack::peek() const {
    assert(!isEmpty());
    return data[top - 1];
}

