//
// Created by deris on 13.03.2024.
//

#include "DynamicArray.h"
#include <iostream>
#include <cassert>
DynamicArray::DynamicArray() : size(0), arrCapacity(1) {
    try {
        data = new int[arrCapacity];
    } catch (std::bad_alloc e) {
        throw e;
    }
}

DynamicArray::DynamicArray(size_t size) : size(size), arrCapacity(size) {
    assert((size >= 0) && "Error! Size shouldn't be negative");
    try {
        data = new int[arrCapacity];
    } catch (std::bad_alloc e) {
        throw e;
    }
    for (int i = 0; i < size; ++i) {
        data[i] = 0;
    }
}

DynamicArray::DynamicArray(size_t size, int n) : size(size), arrCapacity(size) {
    assert((size >= 0) && "Error! Size shouldn't be negative");
    try {
        data = new int[arrCapacity];
    } catch (std::bad_alloc e) {
        throw e;
    }
    for (int i = 0; i < size; ++i) {
        data[i] = n;
    }
}

DynamicArray::DynamicArray(size_t arrCapacity, size_t size) : arrCapacity(arrCapacity), size(size) {
    assert((arrCapacity >= 0) && "Error! Capacity shouldn't be negative");
    assert((size >= 0) && "Error! Size shouldn't be negative");
    assert((arrCapacity >= size) && "Error! Capacity can't be less than size");
    try {
        data = new int[arrCapacity];
    } catch (std::bad_alloc e) {
        throw e;
    }
    for (int i = 0; i < size; ++i) {
        data[i] = 0;
    }
}

DynamicArray::DynamicArray(DynamicArray const &arr) : size(arr.size), arrCapacity(arr.arrCapacity) {
    assert((&arr != nullptr) && "Error! Arr is null");
    try {
        data = new int[arrCapacity];
    } catch (std::bad_alloc e) {
        throw e;
    }
    for (int i = 0; i < size; ++i) {
        data[i] = arr.data[i];
    }
}

DynamicArray::DynamicArray(DynamicArray &&arr) : size(arr.size), arrCapacity(arr.arrCapacity), data(arr.data) {
    assert((&arr != nullptr) && "Error! Arr is null");
    data = nullptr;
    size = 0;
    arrCapacity = 0;
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

int DynamicArray::getSize() const{
    return size;
}

void DynamicArray::reserve(int n) {
    assert((n >= 0) && "Error! Can't reserve less then 0");
    if (size + n > arrCapacity) {
        arrCapacity = size + n;
        try {
            int* newData = new int[arrCapacity];
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        } catch (std::bad_alloc e) {
            throw e;
        }
    }
}

int DynamicArray::capacity() const{
    return arrCapacity;
}

void DynamicArray::resize(size_t newSize) {
    assert((newSize >= 0) && "Error! Size shouldn't be negative");
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
    assert((i >= 0) && "Error! Index shouldn't be negative");
    assert((i < size) && "Error! Index is out of bound");
    return data[i];
}

DynamicArray &DynamicArray::operator=(const DynamicArray &rhs) {
    assert((&rhs != nullptr) && "Error! Arr is null");
    if (this != &rhs) {
        delete[] data;
        try {
            data = new int[rhs.size];
        } catch (std::bad_alloc e) {
            throw e;
        }
        std::copy(rhs.data, rhs.data + rhs.size, data);
        size = rhs.size;
    }
    return *this;
}

DynamicArray &DynamicArray::operator=(DynamicArray &&rhs) noexcept {
    assert((&rhs != nullptr) && "Error! Arr is null");
    if (this != &rhs) {
        delete[] data;
        data = rhs.data;
        size = rhs.size;

        rhs.size = 0;
        rhs.data = nullptr;
    }
    return *this;
}

DynamicArray DynamicArray::operator+(const DynamicArray &rhs) {
    assert((&rhs != nullptr) && "Error! Arr is null");
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
    assert((&rhs != nullptr) && "Error! Arr is null");
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
    assert((&rhs != nullptr) && "Error! Arr is null");
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



