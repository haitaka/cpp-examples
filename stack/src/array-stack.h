#pragma once

#include "stack.h"

class ArrayStack : public Stack {
public:
    static const int defaultCapacity = 42;
    static const int growthFactor = 2;

    ArrayStack();
    ArrayStack(int capacity);
    ArrayStack(ArrayStack const & orig);
    ~ArrayStack() override;

    void push(int val) override;
    int pop() override;
    int peek() const override;
    bool isEmpty() const override;

    ArrayStack & operator=(ArrayStack const & that);

private:
    void initFrom(ArrayStack const & that);
    void free();
    void grow();

    int capacity;
    int top;
    int * data;
};

