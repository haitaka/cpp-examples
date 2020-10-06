#pragma once

#include "list.h"
#include "stack.h"

class ListStack : public Stack {
public:
    ListStack();
    ListStack(ListStack const & orig);
    ~ListStack() override;

    void push(int val) override;
    int pop() override;
    int peek() const override;
    bool isEmpty() const override;

    ListStack & operator=(ListStack const & that);

private:
    List * data;
};

