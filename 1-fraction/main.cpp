#include <iostream>
#include <fstream>
#include <numeric>

class Fraction {
public:
    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
        if (denominator == 0) exit(1);
    }

    Fraction() : Fraction(1, 2) {}

    Fraction(Fraction const & that) = default;

    int getNumerator() const {
        return this->numerator;
    }

    int getDenominator() const {
        return denominator;
    }

    void reduce() {
        int gcd = std::gcd(std::abs(numerator), denominator); // since C++17
        numerator /= gcd;
        denominator /= gcd;
    }
    Fraction & operator++() {
        ++numerator;
        return *this;
    }

    friend std::ostream & operator<<(std::ostream & out, Fraction const & f);

private:
    int numerator;
    int denominator;
};

std::ostream & operator<<(std::ostream & out, Fraction const & f) {
    out << f.numerator << "/" << f.denominator;
    return out;
}

int main() {
    Fraction f(15, 10);
    std::cout << f << std::endl;
    f.reduce();
    std::cout << f << std::endl;
    return 0;
}
