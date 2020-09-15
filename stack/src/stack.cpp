// stack.cpp

#include <cstdlib>
#include "stack.h"

Stack::Stack() : Stack(defaultSize) {}

Stack::Stack(int size) {
    data = new int[size];
    top = 0;
}

Stack::~Stack() {
    delete[] data;
}

void Stack::push(int val) {
    data[top] = val;
    top++;
}

int Stack::pop() {
    if (top == 0) exit(1);
    return data[--top];
}
