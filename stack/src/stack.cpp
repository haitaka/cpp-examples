#include "stack.h"

#include <iostream>
#include <cassert>

Stack::Stack() : Stack(defaultCapacity) {}

Stack::Stack(int capacity)
    : capacity(capacity)
    , data(new int[capacity])
    , top(0) {}

Stack::Stack(const Stack & orig) : data(nullptr) {
    initFrom(orig);
}

Stack::~Stack() {
    free();
}

void Stack::free() {
    delete[] data;
    data = nullptr;
}

Stack & Stack::operator=(Stack const & that) {
    if (this != &that) {
        free();
        initFrom(that);
    }
    return *this;
}

void Stack::initFrom(Stack const & that) {
    assert(data == nullptr);

    top = that.top;
    capacity = that.capacity;
    data = new int[capacity];
    for (int i = 0; i < capacity; ++i) {
        this->data[i] = that.data[i];
    }
}

void Stack::grow() {
    int newCapacity = capacity * growthFactor;
    int * newData = new int[newCapacity];
    for (int i = 0; i < top; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

void Stack::push(int val) {
    if (top == capacity) {
        grow();
    }
    data[top++] = val;
}

int Stack::pop() {
    int topValue = peek();
    top -= 1;
    return topValue;
}

int Stack::peek() const {
    assert(top > 0);
    return data[top];
}

