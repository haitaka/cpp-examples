#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <array>
#include <iostream>
#include <set>


struct S {
    int x;
    int y;

    S(int x, int y) : x(x), y(y) {}

    friend std::ostream & operator<<(std::ostream & out, S const & s) {
        out << s.x << " " << s.y;
        return out;
    }
};

int main() {
    std::multiset<int> s;
    s.insert(23);
    s.insert(23);
    s.insert(23);
    s.insert(42);


    for (auto x : s) {
        std::cout << x << std::endl;
    }

    return 0;
}
