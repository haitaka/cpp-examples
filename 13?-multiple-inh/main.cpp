#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-pass-by-value"







#include <iostream>
#include <cassert>

class Individual {
public:
    Individual(std::string const & name) : name(name) {}
    std::string const & getName() const {
        return name;
    }
protected:
    std::string name;
};

class Man : virtual public Individual {
public:
    explicit Man(std::string name) : Individual(name) {}
};

int main() {
    return 0;
}












#pragma clang diagnostic pop