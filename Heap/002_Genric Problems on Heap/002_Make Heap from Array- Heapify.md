### Heap Data Structure: Building and Heapifying

#### Concepts
1. **Heapify**:
   - A process to maintain the heap property in a tree, ensuring that every parent node is greater than (in a max heap) or less than (in a min heap) its child nodes.
   - When an element is out of place, it swaps with the largest (for max heap) or smallest (for min heap) child, and this process is recursively applied until the heap property is restored.

2. **Building a Heap**:
   - The process of creating a heap from an unsorted array.
   - Start from the first non-leaf node and apply heapify in a bottom-up manner to ensure all subtrees are valid heaps.

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

int main() {
    int arr[] = {-1, 12, 15, 13, 11, 14};
    int n = 5;

    // Building the heap from the array
    buildHeap(arr, n);

    // Printing the heap
    cout << "Printing the heap" << endl;
    for (int i = 0; i <= n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
```

### Explanation

1. **Heapify Function**:
   - Takes an array `arr`, size `n`, and index `i` to heapify.
   - Determines the largest element among the parent node at index `i` and its left and right children.
   - If the largest element is not the parent, it swaps the parent with the largest child and recursively calls `heapify` on the affected subtree.

2. **Build Heap Function**:
   - Converts an array into a heap by starting from the first non-leaf node and applying `heapify`.
   - Non-leaf nodes are all nodes from `n/2` to `1`.

3. **Main Function**:
   - Defines an array `arr` and its size `n`.
   - Calls `buildHeap` to transform the array into a heap.
   - Prints the resulting heap.

### Key Points
- **Heapify** ensures that a subtree satisfies the heap property by comparing parent and child nodes and swapping if necessary.
- **Building a Heap** is performed in a bottom-up manner, starting from the first non-leaf node and moving upwards, ensuring that each subtree is a valid heap.
- **Time Complexity**: The time complexity for building a heap is O(n), where n is the number of elements in the array.
- **Heap Property**: For a max heap, every parent node is greater than or equal to its child nodes. For a min heap, every parent node is less than or equal to its child nodes.
