#include "array-stack.h"

#include <cassert>

ArrayStack::ArrayStack() : ArrayStack(defaultCapacity) {}

ArrayStack::ArrayStack(int capacity)
    : capacity(capacity)
    , data(new int[capacity])
    , count(0) {}

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

    count = that.count;
    capacity = that.capacity;
    data = new int[capacity];
    for (int i = 0; i < capacity; ++i) {
        this->data[i] = that.data[i];
    }
}

void ArrayStack::grow() {
    int newCapacity = capacity * 2;
    int * newData = new int[newCapacity];
    for (int i = 0; i < count; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

bool ArrayStack::isEmpty() const {
    return count == 0;
}

void ArrayStack::push(int val) {
    if (count == capacity) {
        grow();
    }
    data[count++] = val;
}

int ArrayStack::pop() {
    int topValue = peek();
    count -= 1;
    return topValue;
}

int ArrayStack::peek() const {
    assert(!isEmpty());
    return data[count - 1];
}

