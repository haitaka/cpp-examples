#include "queue.h"

void Queue::put(int x) {
    std::lock_guard<std::recursive_mutex> lock(mutex);
    list.push_front(x);
}

int Queue::get() {
    std::unique_lock<std::recursive_mutex> lock(mutex);

    if (isEmpty()) {
        return -1;
    }

    int x =  list.back();
    list.pop_back();

    return x;
}

bool Queue::isEmpty() {
    std::lock_guard<std::recursive_mutex> lock(mutex);
    return list.empty();
}
