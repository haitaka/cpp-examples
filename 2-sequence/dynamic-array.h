#pragma once

class DynamicArray {
public:
    static int const defaultInitialSize = 42;
    static int const growthFactor = 2;

    DynamicArray();
    DynamicArray(int initialSize);
    DynamicArray(DynamicArray const & that);
    ~DynamicArray();

    DynamicArray & operator=(DynamicArray const & that);

    int & operator[](int idx);
    int operator[](int idx) const;

private:
    void initFrom(DynamicArray const & that);
    void free();
    void grow();

    int size;
    int * data;
};
