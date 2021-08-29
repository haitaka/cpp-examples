#include <iostream>
#include <vector>
#include <functional>

struct Filter {
    int n;

    bool operator()(int x) const {

        std::function<bool(int)> filter = [this](int x) { return x > this->n; };

        return filter(x);
    }
};

void printFiltered(std::vector<int> const & data, std::function<bool(int)> const & filter) {
    for (int x : data) {
        if (filter(x)) {
            std::cout << x << std::endl;
        }
    }
}

bool isEven(int x) {
    return x % 2 == 0;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> data = {4, 8, 15, 16, 23, 42};

    std::function<bool(int)> filter = [n](int x) { return x > n; };

    n = 23;

    printFiltered(data, filter);

    return 0;
}
