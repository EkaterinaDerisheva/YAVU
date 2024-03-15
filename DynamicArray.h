//
// Created by deris on 13.03.2024.
//

#ifndef YAVU_LAB1_DYNAMICARRAY_H
#define YAVU_LAB1_DYNAMICARRAY_H


#include <cstddef>
#include <exception>
#include <iostream>

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
    DynamicArray& operator=(const DynamicArray& arr);
    DynamicArray& operator=(DynamicArray&& arr) noexcept;
    DynamicArray operator+(const DynamicArray& arr);

    bool operator==(const DynamicArray &rhs) const;
    bool operator!=(const DynamicArray &rhs) const;

    bool operator<(const DynamicArray &rhs) const;
    bool operator>(const DynamicArray &rhs) const;
    bool operator<=(const DynamicArray &rhs) const;
    bool operator>=(const DynamicArray &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const DynamicArray &array);

    class DifSizeException : public std::exception {
        const char *message;
    public:
        DifSizeException(const char *theMessage) : message(theMessage) {}
        const char *what() const noexcept { return message; }
    };
};

std::ostream &operator<<(std::ostream &os, const DynamicArray &array) {
    os << " size: " << array.size << " arrCapacity: " << array.arrCapacity << " data: ";
    for (int i = 0; i < array.size; ++i) {
        os << array.data[i] << " ";
    }
    return os;
}

std::istream &operator>>(std::istream &in, DynamicArray &array) {
    size_t size;
    int elem;
    std::cout << "Enter size: ";
    in >> size;
    array.resize(size);
    std::cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; ++i) {
        in >> elem;
        array[i] = elem;
    }
    return in;
}
#endif //YAVU_LAB1_DYNAMICARRAY_H
