#include <cassert>
#include "dynamic-array.h"

DynamicArray::DynamicArray() : DynamicArray(defaultInitialSize) {}

DynamicArray::DynamicArray(int initialSize) {
    size = initialSize;
    data = new int[size];
}

DynamicArray::DynamicArray(DynamicArray const & that) {
    initFrom(that);
}

DynamicArray::~DynamicArray() {
    free();
}

DynamicArray & DynamicArray::operator=(DynamicArray const & that) {
    if (this != &that) {
        free();
        initFrom(that);
    }
    return *this;
}

int & DynamicArray::operator[](int idx) {
    assert(idx >= 0);
    if (idx >= size) {
        grow();
    }
    return <#initializer#>;
}

int DynamicArray::operator[](int idx) const {
    return 0;
}

void DynamicArray::initFrom(const DynamicArray &that) {

}

void DynamicArray::free() {

}

void DynamicArray::grow() {

}
