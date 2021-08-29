#pragma once

/**
 * Poor man's linked list implementation.
 */
class List {
public:
    static List * nil();
    static List * copy(List * orig);

    List(int head, List * tail);
    ~List();

    List(List & that) = delete;
    List & operator=(List & that) = delete;

    int operator[](int idx);

    int getHead();
    List * getTail();

private:
    int const head;
    List * const tail;
};

