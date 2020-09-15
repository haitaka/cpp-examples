// stack.h

#pragma once

class Stack {
public:
    static const int defaultSize = 42;

    Stack();
    Stack(int size);

    ~Stack();

    void push(int val);
    int pop();

private:
    int top;
    int * data;
};
