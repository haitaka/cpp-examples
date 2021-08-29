#pragma once

class Stack {
public:
    virtual ~Stack() = 0;
    virtual void push(int i) = 0;
    virtual int pop() = 0;
    virtual int peek() const = 0;
    virtual bool isEmpty() const = 0;
};

