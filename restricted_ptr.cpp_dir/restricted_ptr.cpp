#include <iostream>


void addArrays(int* restrict result, int* restrict arr1, int* restrict arr2, int size) {
    for (int i = 0; i < size; ++i) {
        result[i] = arr1[i] + arr2[i];
    }
}



int main() {

    const int size = 5;

    int array1[size] = {1, 2, 3, 4, 5};

    int array2[size] = {5, 4, 3, 2, 1};

    int result[size];

    addArrays(result, array1, array2, size);

    return 0;
}

