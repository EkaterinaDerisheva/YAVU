//
// Created by deris on 08.03.2024.
//

#include "BoxClass.h"

namespace BoxContainerNamespace {

    int Box::getLength() const {
        return length;
    }

    void Box::setLength(int length) {
        assert((length > 0) && "Error! Length should be positive");
        Box::length = length;
    }

    int Box::getWidth() const {
        return width;
    }

    void Box::setWidth(int width) {
        assert((width > 0) && "Error! Width should be positive");
        Box::width = width;
    }

    int Box::getHeight() const {
        return height;
    }

    void Box::setHeight(int height) {
        assert((height > 0) && "Error! Height should be positive");
        Box::height = height;
    }

    double Box::getWeight() const {
        return weight;
    }

    void Box::setWeight(double weight) {
        assert((weight > 0) && "Error! Weight should be positive");
        Box::weight = weight;
    }

    int Box::getValue() const {
        return value;
    }

    void Box::setValue(int value) {
        assert((value >= 0) && "Error! Value shouldn't be negative");
        Box::value = value;
    }

    std::ostream &operator<<(std::ostream &os, const Box &box) {
        os << "length: " << box.length << " width: " << box.width << " height: " << box.height << " weight: "
           << box.weight << " value: " << box.value;
        return os;
    }

    std::istream & operator >> (std::istream &in, Box &box) {
        std::cout << "Height: ";
        int height;
        in >> height;
        box.setHeight(height);
        std::cout << "Width: ";
        int width;
        in >> width;
        box.setWidth(width);
        std::cout << "Length: ";
        int length;
        in >> length;
        box.setLength(length);
        std::cout << "Weight: ";
        double weight;
        in >> weight;
        box.setWeight(weight);
        std::cout << "Value: ";
        int value;
        in >> value;
        box.setValue(value);
        return in;
    }
} // BoxContainerNamespace