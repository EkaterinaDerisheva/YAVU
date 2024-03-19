//
// Created by deris on 08.03.2024.
//

#ifndef UNTITLED_BOXCLASS_H
#define UNTITLED_BOXCLASS_H

#include <cassert>
#include <iostream>

namespace BoxContainerNamespace {

    class Box {
    private:
        int length;
        int width;
        int height;
        double weight;
        int value;
    public:
        Box(int pLength = 0, int pWidth = 0, int pHeight = 0, double pWeight = 0, int pValue = 0) {
            assert((pLength >= 0) && "Error! Length should be positive");
            assert((pWidth >= 0) && "Error! Width should be positive");
            assert((pHeight >= 0) && "Error! Height should be positive");
            assert((pWeight >= 0) && "Error! Weight should be positive");
            assert((pValue >= 0) && "Error! Value shouldn't be negative");
            length = pLength;
            width = pWidth;
            height = pHeight;
            weight = pWeight;
            value = pValue;
        }

        bool operator==(const Box &box) const {
            assert((&box != nullptr) && "Box can't be null");
            return (length == box.length && width == box.width && height == box.height && value == box.value);

        }

        int getLength() const;

        void setLength(int length);

        int getWidth() const;

        void setWidth(int width);

        int getHeight() const;

        void setHeight(int height);

        double getWeight() const;

        void setWeight(double weight);

        int getValue() const;

        void setValue(int value);

    };
    std::ostream & operator << (std::ostream &os, const Box &box);
    std::istream & operator >> (std::istream &in, Box &box);
} // BoxContainerNamespace

#endif //UNTITLED_BOXCLASS_H
