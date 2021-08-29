#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
#include "queue.h"

using namespace std::chrono_literals;

Queue queue;

void pusherBody(bool zero) {
    for (int i = 0; i < 100000; ++i) {
        if (zero) {
            queue.put(0);
        } else {
            queue.put(i);
        }
    }
}

void stackExample() {
    std::thread pusher(pusherBody, true);
    std::thread pusher2(pusherBody, false);

    while (queue.isEmpty());

    while (!queue.isEmpty()) {
        int x = queue.get();
        std::cout << x << std::endl;
    }

    pusher.join();
    pusher2.join();
}

std::mutex m;
std::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;

void condVarWorker() {
    // Wait until main thread sends data
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk, [] { return ready; });

    // after the wait, we own the lock.
    std::cout << "Worker thread is processing data\n";
    data += " after processing";

    // Send data back to main()
    processed = true;
    std::cout << "Worker thread signals data processing completed\n";

    // Manual unlocking is done before notifying, to avoid waking up
    // the waiting thread only to block again (see notify_one for details)
    lk.unlock();
    cv.notify_all();
}

void condVarExample() {
    std::thread worker(condVarWorker);

    data = "Example data";
    // send data to the worker thread
    {
        std::lock_guard<std::mutex> lk(m);
        ready = true;
        std::cout << "main() signals data ready for processing\n";
    }
    cv.notify_one();

    // wait for the worker
    {
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, [] { return processed; });
    }
    std::cout << "Back in main(), data = " << data << '\n';

    worker.join();
}

void threadBody() {
    for (int i = 0; i < 1000000; ++i) {
        std::cout << "hello" << std::endl;
    }
}

void notSoMainThread() {
    std::thread printer(threadBody);
    printer.detach();
    std::cerr << "world" << std::endl;
}

int main() {
    std::thread t(notSoMainThread);
    t.join();
    return 0;
}
