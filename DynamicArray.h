//
// Created by deris on 13.03.2024.
//

#ifndef YAVU_LAB1_DYNAMICARRAY_H
#define YAVU_LAB1_DYNAMICARRAY_H


#include <cstddef>
#include <exception>
#include <iostream>
#include <cassert>

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

    int getSize() const;


    void reserve(int n);
    int capacity() const;
    void resize(size_t newSize);
    void pushBack(int x);
    int popBack();

    DynamicArray operator[](int i) const;
    DynamicArray& operator=(const DynamicArray& arr);
    DynamicArray& operator=(DynamicArray&& rhs) noexcept;
    DynamicArray operator+(const DynamicArray& arr);

    bool operator==(const DynamicArray &rhs) const;
    bool operator!=(const DynamicArray &rhs) const;

    bool operator<(const DynamicArray &rhs) const;
    bool operator>(const DynamicArray &rhs) const;
    bool operator<=(const DynamicArray &rhs) const;
    bool operator>=(const DynamicArray &rhs) const;

    class DifSizeException : public std::exception {
        const char *message;
    public:
        DifSizeException(const char *theMessage) : message(theMessage) {}
        const char *what() const noexcept { return message; }
    };
};

std::ostream &operator<<(std::ostream &os, const DynamicArray *array) {
    assert((array != nullptr));
    os << " size: " << array->getSize() << " arrCapacity: " << array->capacity() << " data: ";
    for (int i = 0; i < array->getSize(); ++i) {
        os << &array[i] << " ";
    }
    return os;
}

std::istream &operator>>(std::istream &in, DynamicArray *array) {
    assert((array != nullptr) && "Error! Arr is null");
    size_t size;
    int elem;
    std::cout << "Enter size: ";
    in >> size;
    array->resize(size);
    std::cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; ++i) {
        in >> elem;
        array[i] = elem;
    }
    return in;
}
#endif //YAVU_LAB1_DYNAMICARRAY_H
