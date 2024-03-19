//
// Created by deris on 08.03.2024.
//

#include "Container.h"
#include "OverweightException.h"

namespace BoxContainerNamespace {

    int Container::addBox(Box box) {
        assert((&box != nullptr) && "Box can't be null");
        if (sumWeight() + box.getWeight() > maxWeight) {
            throw OverweightException("You can't put the box in container due to overweight");
        }
        boxes.push_back(box);
        return boxes.size() - 1;
    }

    void Container::deleteBox(int i){
        assert((i >= 0) && "index can't be less than 0!");
        boxes.erase(boxes.begin()+i);
    }

    int Container::boxesCount() {
        return boxes.size();
    }

    int Container::sumValue() {
        int sum = 0;
        for (int i = 0; i < boxes.size(); ++i) {
            sum += boxes[i].getValue();
        }
        return sum;
    }

    double Container::sumWeight() {
        double sum = 0;
        for (int i = 0; i < boxes.size(); ++i) {
            sum += boxes[i].getWeight();
        }
        return sum;
    }

    Box Container::getBox(int i) {
        assert((i >= 0) && "index can't be less than 0!");
        return boxes[i];
    }

    const std::vector<Box> &Container::getBoxes() const {
        return boxes;
    }

    void Container::setBoxes(const std::vector<Box> &boxes) {
        assert((&boxes != nullptr) && "Boxes can't be null");
        Container::boxes = boxes;
    }

    int Container::getLength() const {
        return length;
    }

    void Container::setLength(int length) {
        assert((length > 0) && "Error! Length should be positive");
        Container::length = length;
    }

    int Container::getWidth() const {
        return width;
    }

    void Container::setWidth(int width) {
        assert((width > 0) && "Error! Width should be positive");
        Container::width = width;
    }

    int Container::getHeight() const {
        return height;
    }

    void Container::setHeight(int height) {
        assert((height > 0) && "Error! Height should be positive");
        Container::height = height;
    }

    double Container::getMaxWeight() const {
        return maxWeight;
    }

    void Container::setMaxWeight(double maxWeight) {
        assert((maxWeight > 0) && "Error! Weight should be positive");
        Container::maxWeight = maxWeight;
    }

    Box Container::operator[](int i) {
        assert((i >= 0) && "index can't be less than 0!");
        return boxes[i];
    }

    std::ostream &operator<<(std::ostream &os, const Container &container) {
        os <<  " length: " << container.length << " width: " << container.width
           << " height: " << container.height << " maxWeight: " << container.maxWeight;
        return os;
    }

    std::istream &operator>>(std::istream &in, Container &container) {
        std::cout << "Height: ";
        int height;
        in >> height;
        container.setHeight(height);
        std::cout << "Width: ";
        int width;
        in >> width;
        container.setWidth(width);
        std::cout << "Length: ";
        int length;
        in >> length;
        container.setLength(length);
        std::cout << "Weight: ";
        double maxWeight;
        in >> maxWeight;
        container.setMaxWeight(maxWeight);
        return in;
    }
} // BoxContainerNamespace