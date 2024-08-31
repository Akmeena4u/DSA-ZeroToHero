
#include <iostream>
using namespace std;

// Function to search for an element in an array
// Algorithm: Linear Search
int search(int arr[], int n, int x) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == x)
            return i; // Return index if element is found
    }
    return -1; // Return -1 if element is not found
}

int main() {
    int arr[] = {20, 5, 7, 25}; // Array to search
    int x = 5; // Element to search for
    cout << "Searched Index = " << search(arr, 4, x) << endl; // Output result
}

// Time Complexity: O(n) - In the worst case, each element is checked once.
// Space Complexity: O(1) - Uses a constant amount of extra space.
