#include <iostream>

static int arr1[5] = { 1, 2, 3, 4, 5 }; // Example values in arr1
static int arr2[5] = { 0 }; // Initialize arr2 with empty values

void insertAndMultiply(int arr1[], int arr2[], int size) {
    for (int i = 0; i < size; ++i) {
        arr2[i] = -arr1[size - 1 - i];
    }
}

int main() {
    const int size = 5; // Change the size accordingly
    insertAndMultiply(arr1, arr2, size);

    // Displaying the result
    std::cout << "arr1: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr1[i] << " ";
    }

    std::cout << "\narr2 after insertion and multiplication: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr2[i] << " ";
    }

    return 0;
}
