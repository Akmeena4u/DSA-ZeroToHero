### Heap Sort Algorithm

Heap sort is a comparison-based sorting technique that uses a binary heap data structure. It can be thought of as an improved selection sort that uses the heap data structure rather than a linear-time search to find the maximum or minimum element.

#### Key Steps in Heap Sort
1. **Build a Max Heap**:
   - Convert the array into a max heap, where the largest element is at the root.

2. **Heap Sort**:
   - Swap the root element (maximum) with the last element of the heap.
   - Reduce the heap size by one.
   - Heapify the root element to ensure the remaining elements are still a max heap.
   - Repeat the above steps until the heap size is reduced to one.

#### C++ Implementation

```cpp
#include <iostream>
using namespace std;

// Heapify function to maintain heap property
void heapify(int arr[], int n, int i) {
    int index = i;
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;
    int largest = index;

    if (leftIndex <= n && arr[largest] < arr[leftIndex]) {
        largest = leftIndex;
    }
    if (rightIndex <= n && arr[largest] < arr[rightIndex]) {
        largest = rightIndex;
    }

    if (largest != index) {
        // Swap the largest child with the current index
        swap(arr[largest], arr[index]);
        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Build Heap function
void buildHeap(int arr[], int n) {
    // Start from the first non-leaf node and apply heapify
    for (int i = n / 2; i > 0; i--) {
        heapify(arr, n, i);
    }
}

// Heap Sort function
void heapSort(int arr[], int n) {
    int index = n; // n is a valid index in 1-based indexing
    while (n != 1) {
        // Swap the root of the heap with the last element
        swap(arr[1], arr[index]);
        index--;
        n--;
        // Heapify the root element to maintain heap property
        heapify(arr, n, 1);
    }
}

int main() {
    int arr[] = {-1, 12, 15, 13, 11, 14}; // Array initialized with a dummy element at index 0
    int n = 5;

    // Building the heap from the array
    buildHeap(arr, n);
    cout << "Printing the heap" << endl;
    for (int i = 0; i <= n; i++) {
        cout << arr[i] << " ";
    }

    // Performing heap sort
    heapSort(arr, n);
    cout << endl << "Printing the sorted array" << endl;
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
```



### Key Points
- **Heapify** maintains the heap property by ensuring that each parent node is greater than its children in a max heap.
- **Build Heap** constructs a max heap from an unsorted array in O(n) time.
- **Heap Sort** sorts the array by repeatedly extracting the maximum element and maintaining the heap property, resulting in a sorted array in O(n log n) time.
- **In-Place Sorting**: Heap sort sorts the array without requiring additional storage, making it space-efficient.
- **Stable Sort**: Heap sort is not a stable sort because it may change the relative order of equal elements.

This implementation uses a 1-based index for the heap, with a dummy element at index 0 to simplify the arithmetic.
