#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-exception-baseclass"
#include <iostream>
#include <vector>
#include <memory>



struct MyStruct {
    int x;
    explicit MyStruct(int x) : x(x) {
        std::cout << "default constr " << x << std::endl;
    }
    MyStruct(MyStruct const & s) : x(s.x) {
        std::cout << "copy constr " << x << std::endl;
    }
    ~MyStruct() {
        std::cout << "destr " << x << std::endl;
    }
    MyStruct & operator=(MyStruct const & s) {
        x = s.x;
        std::cout << "assign " << x << std::endl;
        return *this;
    }
    friend std::ostream & operator<<(std::ostream & out, MyStruct const & that) {
        out << that.x << std::endl;
        return out;
    }
};

template<typename T>
class Ptr {
public:
    Ptr(T * data) : data(data), count(new int(1)) {
//        std::cout << "pointer constr " << data << std::endl;
    }
    Ptr(Ptr const & orig) : data(orig.data), count(orig.count) {
        ++(*count);
//        std::cout << "pointer constr " << data  << " " << *count << std::endl;
    }
    ~Ptr() {
        destr();
    }
    Ptr & operator=(Ptr const & that) {
        if (this != &that) {
            destr();
            data = that.data;
            count = that.count;
            ++(*count);
//            std::cout << "pointer assign " << data  << " " << *count << std::endl;
        }
        return *this;
    }
    T & operator*() {
        return *data;
    }
    T * operator->() {
        return data;
    }
private:
    void destr() {
        --(*count);
//        std::cout << "pointer destr " << data  << " " << *count << std::endl;
        if (*count == 0) {
            delete data;
            delete count;
//            std::cout << "pointer destr finally " << data  << std::endl;
        }
    }
    T * data;
    int * count;
};


Ptr<MyStruct> makeStruct(int x) {
    Ptr<MyStruct> s = new MyStruct(x);
    return s;
}


int main() {
    return 0;
}

#pragma clang diagnostic pop