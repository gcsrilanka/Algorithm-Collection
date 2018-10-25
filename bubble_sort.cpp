#include <iostream>

void bubbleSort(int array[], int size) {
    int temp = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

void printArray(int array[], int size) {
    std::cout << "array = [ ";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << " ]" << std::endl;
}

int main() {
    int array[10] = {2,5,3,6,4,2,4,2,2,8};

    printArray(array, 10);

    bubbleSort(array, 10);

    printArray(array, 10);

    return 0;
}