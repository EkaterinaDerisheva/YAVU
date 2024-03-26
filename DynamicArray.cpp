//
// Created by deris on 13.03.2024.
//

#include "DynamicArray.h"
#include <iostream>
#include <cassert>
DynamicArray::DynamicArray() {
    size = 0;
    try {
        arrCapacity = 1;
        data = new int[arrCapacity];
    } catch (std::bad_alloc e) {
        arrCapacity = 0;
        throw e;
    }
}

DynamicArray::DynamicArray(size_t size) {
    assert((size >= 0) && "Error! Size shouldn't be negative");
    try {
        data = new int[arrCapacity];
    } catch (std::bad_alloc e) {
        arrCapacity = 0;
        this->size = 0;
        throw e;
    }
    this->size = size;
    arrCapacity = size;
    for (int i = 0; i < size; ++i) {
        data[i] = 0;
    }
}

DynamicArray::DynamicArray(size_t size, int n) {
    assert((size >= 0) && "Error! Size shouldn't be negative");
    try {
        data = new int[arrCapacity];
    } catch (std::bad_alloc e) {
        arrCapacity = 0;
        size = 0;
        throw e;
    }
    this->size = size;
    arrCapacity = size;
    for (int i = 0; i < size; ++i) {
        data[i] = n;
    }
}

DynamicArray::DynamicArray(size_t arrCapacity, size_t size) {
    assert((size >= 0) && "Error! Size shouldn't be negative");
    assert((arrCapacity >= size) && "Error! Capacity can't be less than size");
    try {
        data = new int[arrCapacity];
    } catch (std::bad_alloc e) {
        arrCapacity = 0;
        size = 0;
        throw e;
    }
    this->size = size;
    this->arrCapacity = arrCapacity;
    for (int i = 0; i < size; ++i) {
        data[i] = 0;
    }
}

DynamicArray::DynamicArray(DynamicArray const &arr) {
    assert((&arr != nullptr) && "Error! Arr is null");
    try {
        data = new int[arrCapacity];
    } catch (std::bad_alloc e) {
        arrCapacity = 0;
        size = 0;
        throw e;
    }
    size = arr.size;
    arrCapacity = arr.arrCapacity;
    for (int i = 0; i < size; ++i) {
        data[i] = arr.data[i];
    }
}

DynamicArray::DynamicArray(DynamicArray &&arr) {
    assert((&arr != nullptr) && "Error! Arr is null");
    size = arr.size;
    arrCapacity = arr.arrCapacity;
    data = arr.data;
    arr.data = nullptr;
    arr.size = 0;
    arr.arrCapacity = 0;
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
    else if (newSize < size) {
        for (int i = newSize; i < size; ++i) {
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

int& DynamicArray::operator[](int i) const {
    assert((i >= 0) && "Error! Index shouldn't be negative");
    assert((i < size) && "Error! Index is out of bound");
    return data[i];
}

DynamicArray &DynamicArray::operator=(const DynamicArray &rhs) {
    assert((&rhs != nullptr) && "Error! Arr is null");
    if (this != &rhs) {
        try {
            int* newData = new int[rhs.size];
            delete[] data;
            data = newData;
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
    if (size >= rhs.size) return false;
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



