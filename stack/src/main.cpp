#include <iostream>
#include "stack.h"

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
