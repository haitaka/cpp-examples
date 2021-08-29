#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-equals-delete"
#pragma ide diagnostic ignored "NotImplementedFunctions"
#include <iostream>

class Number {
public:
    Number();
    virtual ~Number() = 0;

    Number & operator=(Number const & that);

    virtual void foo();
    virtual Number operator+(Number const & that) const;
    bool operator<(Number const & that) const;
    Number & operator[](int idx);
};

class Complex : public Number {
public:
    Complex();
    ~Complex() override {
        delete[] parts;
    }

    Complex & operator=(Complex const & that);

    void foo() override;
    Number operator+(Number const & that) const;
    bool operator<(Number const & that) const;
    Number & operator[](int idx);
private:
    int * parts;
};

void foo(Number * n) {
    // + do something
    delete n;
}


int main() {
    Number * n = new Complex();
    delete n;

    return 0;
}

#pragma clang diagnostic pop