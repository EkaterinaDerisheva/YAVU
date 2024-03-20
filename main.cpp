#include <iostream>
#include "DynamicArray.h"

DynamicArray f(DynamicArray arr) {
    DynamicArray res(arr.getSize() + 1);
    return res;
}
int main() {
    DynamicArray arr1;
    DynamicArray arr2(5);
    DynamicArray arr3(10, 1);
    DynamicArray arr4(20, (size_t)10);
    DynamicArray arr5(arr1);
    DynamicArray arr6 = f(arr2);
    DynamicArray arr7 = arr4 + arr3;

    arr3.pushBack(10);
    std::cout << arr3.popBack() << std::endl;
    std::cout << (arr2 == arr6) << std::endl;

}
