#pragma once

#include <iostream>

class Stack {
public:
    static const int defaultCapacity = 42;
    static const int growthFactor = 2;

    Stack();
    Stack(int capacity);
    Stack(Stack const & orig);

    ~Stack();

    void push(int val);
    int pop();
    int peek() const;

    Stack & operator=(Stack const & that);

private:
    void initFrom(Stack const & that);
    void free();
    void expand();

    int capacity;
    int top;
    int * data;
};

