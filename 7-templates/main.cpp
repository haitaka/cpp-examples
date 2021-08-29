#include <iostream>

template<typename T, int N>
class Array {
public:
    Array() {}
    Array(Array const & that) : data(nullptr) {
        *this = that;
    }
    Array & operator=(Array const & that) {
        if (this != &that) {
            for (int i = 0; i < N; ++i) {
                this->data[i] = that.data[i];
            }
        }
        return *this;
    }

    int getSize() const {
        return N;
    }
    T & operator[](int idx) {
        return data[idx];
    }
    T operator[](int idx) const {
        return data[idx];
    }
private:
    void checkIndex(int idx) {
        if (idx < 0 || idx >= N) {
            std::cout << "Index out of bounds " << idx << std::endl;
            exit(1);
        }
    }
    T data[N];
};

int main() {
    Array<int, 42> arr;
    Array<double, 3> arrd;
    return 0;
}
