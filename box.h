//
// Created by deris on 04.03.2024.
//
#ifndef UNTITLED_BOX_H
#define UNTITLED_BOX_H

#include <iostream>
#include <cassert>
using namespace std;

struct Box {
    int length;
    int width;
    int height;
    double weight;
    int value;
    Box(int pLength = 0, int pWidth = 0, int pHeight = 0, double pWeight = 0, int pValue = 0){
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
    bool operator ==(const Box &box) const {
        return (length == box.length && width == box.width && height == box.height && value == box.value);
    }
};
int sumValue(Box*, size_t);
bool lessThan(Box*, size_t, int);
double maxWeight(Box*, size_t, int);
void bubbleSort(Box*, size_t);
bool canFit(Box*, size_t);
ostream & operator << (ostream &out, const Box &box);
istream & operator >> (istream &in, Box &box);
#endif //UNTITLED_BOX_H

