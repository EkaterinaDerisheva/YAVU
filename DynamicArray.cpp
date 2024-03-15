//
// Created by deris on 13.03.2024.
//

#include "DynamicArray.h"
#include <iostream>
DynamicArray::DynamicArray() : size(0), arrCapacity(1) {
    data = new int[arrCapacity];
}

DynamicArray::DynamicArray(size_t size) : size(size), arrCapacity(size) {
    data = new int[arrCapacity];
    for (int i = 0; i < size; ++i) {
        data[i] = 0;
    }
}

DynamicArray::DynamicArray(size_t size, int n) : size(size), arrCapacity(size) {
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
    if (newSize > size) {
        for (int i = size; i < newSize; ++i) {
            data[i] = 0;
        }
    }
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

DynamicArray DynamicArray::operator[](int i) const {
    return data[i];
}

DynamicArray &DynamicArray::operator=(const DynamicArray &arr) {
    if (this != &arr) {
        delete[] data;
        data = new int[arr.size];
        std::copy(arr.data, arr.data + arr.size, data);
        size = arr.size;
    }
    return *this;
}

DynamicArray &DynamicArray::operator=(DynamicArray &&arr) noexcept {
    if (this != &arr) {
        delete[] data;
        data = arr.data;
        size = arr.size;

        arr.size = 0;
        arr.data = nullptr;
    }
    return *this;
}

DynamicArray DynamicArray::operator+(const DynamicArray &rhs) {
    DynamicArray res(size + rhs.size);
    for (int i = 0; i < size; ++i) {
        res.data[i] = data[i];
    }
    for (int i = size; i < res.size; ++i) {
        res.data[i] = rhs.data[i];
    }
    return res;
}

bool DynamicArray::operator==(const DynamicArray &rhs) const {
    if (size != rhs.size) throw DifSizeException("Error! Sizes shouldn't be different");
    for (int i = 0; i < size; ++i) {
        if (data[i] != rhs.data[i]) return false;
    }
    return true;
}

bool DynamicArray::operator!=(const DynamicArray &rhs) const {
    return !(rhs == *this);
}

bool DynamicArray::operator<(const DynamicArray &rhs) const {
    size_t minSize = std::min(size, rhs.size);
    for (int i = 0; i < minSize; ++i) {
        if(data[i] >= rhs.data[i]) return false;
    }
    return true;
}

bool DynamicArray::operator>(const DynamicArray &rhs) const {
    return rhs < *this;
}

bool DynamicArray::operator<=(const DynamicArray &rhs) const {
    return !(rhs < *this);
}

bool DynamicArray::operator>=(const DynamicArray &rhs) const {
    return !(*this < rhs);
}



