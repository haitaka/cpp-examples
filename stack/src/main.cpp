#include <iostream>
#include "stack.h"

Stack replaceSomeValues(Stack & s) {
    s.pop();
    s.pop();
    s.pop();

    s.push(16);
    s.push(23);
    s.push(42);
    return s;
}

int main() {
    Stack s(23);

    s.push(4);
    s.push(8);
    s.push(15);

    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;

    return 0;
}
