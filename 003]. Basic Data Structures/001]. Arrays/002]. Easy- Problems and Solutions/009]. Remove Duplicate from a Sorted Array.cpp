
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

/*
 * Brute Force Approach
 * 
 * 1. Use a set to store unique elements from the array.
 * 2. Iterate through the array and insert each element into the set.
 * 3. Copy elements from the set back to the array.
 * 4. Return the size of the set, which represents the number of unique elements.
 */
int removeDuplicatesBruteForce(int arr[], int n) {
    set<int> uniqueElements(arr, arr + n); // Step 1 and 2: Insert all elements into the set
    int k = uniqueElements.size(); // Step 3: Get the size of the set
    copy(uniqueElements.begin(), uniqueElements.end(), arr); // Step 4: Copy elements back to the array
    return k; // Return the number of unique elements
}

/*
 * Optimal Approach (Two Pointers)
 * 
 * 1. Initialize pointer `i` to 0.
 * 2. Use pointer `j` to iterate from 1 to the end of the array.
 * 3. If `arr[j]` is different from `arr[i]`, increment `i` and update `arr[i]` with `arr[j]`.
 * 4. Return `i + 1`, the number of unique elements.
 */
int removeDuplicatesOptimal(int arr[], int n) {
    int i = 0; // Pointer for the position of the last unique element
    for (int j = 1; j < n; j++) { // Iterate through the array with pointer `j`
        if (arr[j] != arr[i]) { // If a new unique element is found
            i++; // Move the unique element pointer `i`
            arr[i] = arr[j]; // Update the position with the new unique element
        }
    }
    return i + 1; // Return the number of unique elements
}

int main() {
    int arr[] = {1, 1, 2, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Using Brute Force Approach
    int k = removeDuplicatesBruteForce(arr, n);
    cout << "Brute Force Approach: The array after removing duplicates is: ";
    for (int i = 0; i < k; i++) cout << arr[i] << " ";
    cout << endl;
    
    // Reset array for Optimal Approach
    int arrOptimal[] = {1, 1, 2, 2, 3, 3};
    k = removeDuplicatesOptimal(arrOptimal, n);
    cout << "Optimal Approach: The array after removing duplicates is: ";
    for (int i = 0; i < k; i++) cout << arrOptimal[i] << " ";
    cout << endl;
    
    return 0;
}
