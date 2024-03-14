//
// Created by deris on 13.03.2024.
//

#ifndef YAVU_LAB1_DYNAMICARRAY_H
#define YAVU_LAB1_DYNAMICARRAY_H


#include <cstddef>

class DynamicArray {
private:
    int* data;
    size_t size;
    size_t arrCapacity;
public:
    DynamicArray();
    DynamicArray(size_t size);
    DynamicArray(size_t size, int n);
    DynamicArray(size_t arrCapacity, size_t size);
    DynamicArray(DynamicArray const &arr);
    DynamicArray(DynamicArray&& arr);
    ~DynamicArray();

    int getSize();

    void reserve(int n);
    int capacity();
    void resize(size_t newSize);
    void pushBack(int x);
    int popBack();

    DynamicArray operator[](int i) const;
    DynamicArray& operator=(DynamicArray& arr);
};




#endif //YAVU_LAB1_DYNAMICARRAY_H
