//
// Created by deris on 08.03.2024.
//

#ifndef UNTITLED_CONTAINER_H
#define UNTITLED_CONTAINER_H

#include <vector>
#include <ostream>
#include "BoxClass.h"

namespace BoxContainerNamespace {

    class Container {
    private:
        std::vector<Box> boxes;
        int length;
        int width;
        int height;
        double maxWeight;
    public:
        Container(int length, int width, int height, double maxWeight) {
            Container::length = length;
            Container::width = width;
            Container::height = height;
            Container::maxWeight = maxWeight;
        }

        int addBox(Box box);
        void deleteBox(int i);
        int boxesCount();
        double sumWeight();
        int sumValue();
        Box getBox(int i);

        Box operator[](int i);

        friend std::ostream &operator<<(std::ostream &os, const Container &container);
        friend std::istream &operator>>(std::istream &in, Container &container);

        const std::vector<Box> &getBoxes() const;

        void setBoxes(const std::vector<Box> &boxes);

        int getLength() const;

        void setLength(int length);

        int getWidth() const;

        void setWidth(int width);

        int getHeight() const;

        void setHeight(int height);

        double getMaxWeight() const;

        void setMaxWeight(double maxWeight);

    };

} // BoxContainerNamespace

#endif //UNTITLED_CONTAINER_H
