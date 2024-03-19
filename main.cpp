#include "main.h"
#include "box.h"
#include "BoxClass.h"
#include "Container.h"
#include <iostream>

using namespace std;

int main() {
    const int size = 3;
    Box box1 (10, 15, 20, 12.5, 250);
    Box box2 (12, 16, 21, 3, 170);
    Box box3 (9, 11, 13, 3.5, 120);
    Box box4;
    cin >> box4;
    cout << box4;
    Box *boxes = new Box[size];
    boxes[0] = box1;
    boxes[1] = box2;
    boxes[2] = box3;

    int boxesSumValue = sumValue(boxes, 3);
    bool boxesLessThan = lessThan(boxes, 3, 50);
    double boxesMaxWeight = maxWeight(boxes, 3, 15);
    bool boxesCanFit = canFit(boxes, 3);
    bool equals = (box1 == box2);
     cout << boxesSumValue << endl << boxesLessThan << endl
     << boxesMaxWeight << endl << boxesCanFit << endl << equals;

    BoxContainerNamespace::Box box5 (10, 15, 20, 12.5, 250);
    BoxContainerNamespace::Box box6 (12, 16, 21, 3, 170);
    BoxContainerNamespace::Box box7 (9, 11, 13, 3.5, 120);
    BoxContainerNamespace::Box box8;
    cin >> box8;
    cout << box8;

    BoxContainerNamespace::Container container (100, 100, 100, 55.5);
    int index5 = container.addBox(box5);
    int index6 = container.addBox(box6);
    int index7 = container.addBox(box7);
    int index8 = container.addBox(box8);
    container.deleteBox(3);
    int count = container.boxesCount();
    double sumW = container.sumWeight();
    int sumV = container.sumValue();
}




