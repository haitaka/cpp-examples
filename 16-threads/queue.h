#pragma once

#include <list>
#include <mutex>

class Queue {
public:
    Queue() = default;
    void put(int x);
    int get();
    bool isEmpty();
private:
    std::list<int> list;
    std::recursive_mutex mutex;
};

