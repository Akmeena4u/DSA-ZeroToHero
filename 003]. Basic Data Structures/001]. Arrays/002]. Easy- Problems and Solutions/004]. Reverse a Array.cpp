#include <iostream>
using namespace std;

// Function to reverse an array
void reverse(int arr[], int n) {
    int start = 0;
    int end = n - 1;

    while (start < end) {
        swap(arr[start], arr[end]); // Swap elements at start and end indices
        start++;
        end--;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Print each element followed by a space
    }
    cout << endl; // Newline after printing the array
}

int main() {
    // Test arrays
    int arr[6] = {1, 4, 0, 5, -2, 15};
    int brr[5] = {2, 6, 3, 9, 4};

    // Reverse and print the arrays
    reverse(arr, 6);
    reverse(brr, 5);

    cout << "Reversed array arr: ";
    printArray(arr, 6);

    cout << "Reversed array brr: ";
    printArray(brr, 5);

    return 0;
}
