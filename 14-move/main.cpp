#include <iostream>

class Array {
public:
    static Array of(int x, int y, int z) {
        Array arr(3);
        arr[0] = x;
        arr[1] = y;
        arr[2] = z;
        return arr;
    }

    explicit Array(int size) : size(size), data(new int[size]) {}
    ~Array() {
        delete[] data;
    }
    Array(Array const & that) {
        size = that.size;
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = data[i];
        }
    }
    Array(Array && that) noexcept {
        this->size = that.size;
        this->data = that.data;
        that.data = nullptr;
    }
    Array & operator=(Array const & that) {
        if (this != &that) {
            delete[] data;
            size = that.size;
            data = new int[size];
            for (int i = 0; i < size; ++i) {
                data[i] = data[i];
            }
        }
        return *this;
    }
    Array & operator=(Array && that) {
        size = that.size;
        std::swap(data, that.data);
        return *this;
    }

    int & operator[](int idx) {
        checkIndex(idx);
        return data[idx];
    }
    int operator[](int idx) const {
        checkIndex(idx);
        return data[idx];
    }

    Array operator+(Array const & that) const {
        Array sum(size + that.size);
        for (int i = 0; i < size; ++i) {
            sum[i] = (*this)[i];
        }
        for (int i = 0; i < that.size; ++i) {
            sum[size + i] = that[i];
        }
        return sum;
    }
    int getSize() const {
        return size;
    }
private:
    void checkIndex(int idx) const {
        if (idx < 0 || idx >= size) {
            throw std::out_of_range("Index out of bounds");
        }
    }

    int size;
    int * data;
};

int main() {
    Array * c;

    {
        Array a = Array::of(4, 8, 15);
        Array b = Array::of(16, 23, 42);
        c = new Array(a + b);
    }

    for (int i = 0; i < c->getSize(); ++i) {
        std::cout << (*c)[i] << std::endl;
    }

    return 0;
}
