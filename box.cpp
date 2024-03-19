#include "box.h"
#include <iostream>
#include <cassert>

using namespace std;

int sumValue(Box* boxes, size_t size){
    assert((boxes != nullptr) && "Error! Boxes is null");
    assert((size > 0) && "Error! Size should be positive");
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += boxes[i].value;
    }
    return sum;
}

bool lessThan(Box* boxes, size_t size, int p){
    assert((boxes != nullptr) && "Error! Boxes is null");
    assert((size > 0) && "Error! Size should be positive");
    assert((p > 0) && "Error! p should be positive");
    for (int i = 0; i < size; ++i) {
        if (boxes[i].height + boxes[i].length + boxes[i].width > p) return false;
    }
    return true;
}

double maxWeight(Box* boxes, size_t size, int maxV){
    assert((boxes != nullptr) && "Error! Boxes is null");
    assert((size > 0) && "Error! Size should be positive");
    assert((maxV > 0) && "Error! maxV should be positive");
    double maxWeight = 0;
    for (int i = 0; i < size; ++i) {
        if (boxes[i].height * boxes[i].length * boxes[i].width <= maxV) {
            if (boxes[i].weight > maxWeight) {
                maxWeight = boxes[i].weight;
            }
        }
    }
    return maxWeight;
}
void bubbleSort(Box* boxes, size_t size) {
    assert((boxes != nullptr) && "Error! Boxes is null");
    assert((size > 0) && "Error! Size should be positive");
    while(size--) {
        bool swapped = false;
        for (int i = 0; i < size; ++i) {
            if (boxes[i].length * boxes[i].width * boxes[i].height < boxes[i + 1].length * boxes[i + 1].width * boxes[i + 1].height) {
                swap(boxes[i], boxes[i + 1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}

bool canFit(Box* boxes, size_t size){
    assert((boxes != nullptr) && "Error! Boxes is null");
    assert((size > 0) && "Error! Size should be positive");
    bubbleSort(boxes, size);
    for (int i = 0; i < size - 1; ++i) {
        if (boxes[i].height <= boxes[i + 1].height
        || boxes[i].width <= boxes[i + 1].width
        || boxes[i].length <= boxes[i + 1].length) {
            return false;
        }
    }
    return true;
}

ostream & operator << (ostream &out, const Box &box) {
    out << "Height: " << box.height << ", width: " << box.width
    << ", length: " << box.length << ", weight: " << box.weight
    << ", value: " << box.value << endl;
    return out;
}

istream & operator >> (istream &in, Box &box) {
    cout << "Height: ";
    in >> box.height;
    assert((box.length > 0) && "Error! Length should be positive");
    cout << "Width: ";
    in >> box.width;
    assert((box.width > 0) && "Error! Width should be positive");
    cout << "Length: ";
    in >> box.length;
    assert((box.height > 0) && "Error! Height should be positive");
    cout << "Weight: ";
    in >> box.weight;
    assert((box.weight > 0) && "Error! Weight should be positive");
    cout << "Value: ";
    in >> box.value;
    assert((box.value >= 0) && "Error! Value shouldn't be negative");
    return in;
}
