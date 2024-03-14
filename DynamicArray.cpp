//
// Created by deris on 13.03.2024.
//

#include "DynamicArray.h"
#include <iostream>
DynamicArray::DynamicArray() : size(0), arrCapacity(1) {
    data = new int[arrCapacity];
}

DynamicArray::DynamicArray(size_t size) : size(size), arrCapacity(size * 2) {
    data = new int[arrCapacity];
    for (int i = 0; i < size; ++i) {
        data[i] = 0;
    }
}

DynamicArray::DynamicArray(size_t size, int n) : size(size), arrCapacity(size * 2) {
    data = new int[arrCapacity];
    for (int i = 0; i < size; ++i) {
        data[i] = n;
    }
}

DynamicArray::DynamicArray(size_t arrCapacity, size_t size) : arrCapacity(arrCapacity), size(size) {
    data = new int[arrCapacity];
}

DynamicArray::DynamicArray(DynamicArray const &arr) : size(arr.size), arrCapacity(arr.arrCapacity) {
    data = new int[arrCapacity];
    for (int i = 0; i < size; ++i) {
        data[i] = arr.data[i];
    }
}

DynamicArray::DynamicArray(DynamicArray &&arr) : size(arr.size), arrCapacity(arr.arrCapacity), data(arr.data) {
    data = nullptr;
    size = 0;
    arrCapacity = 0;
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

int DynamicArray::getSize() {
    return size;
}

DynamicArray DynamicArray::operator[](int i) const {
    return data[i];
}

void DynamicArray::reserve(int n) {
    if (size + n > arrCapacity) {
        arrCapacity = size + n;
        int* newData = new int[arrCapacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
}

int DynamicArray::capacity() {
    return arrCapacity;
}

void DynamicArray::resize(size_t newSize) {
    reserve(newSize-size);
    size = newSize;
}

void DynamicArray::pushBack(int x) {
    if (size + 1 < capacity()) {
        resize(size+1);
    }
    data[size] = x;
}

int DynamicArray::popBack() {
    int elem = data[size];
    data[size] = 0;
    resize(size-1);
    return elem;
}



