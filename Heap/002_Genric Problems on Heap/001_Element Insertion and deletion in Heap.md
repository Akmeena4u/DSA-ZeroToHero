### Heap Data Structure: Common Operations and Implementation in C++

#### Common Operations
1. **Insertion**:
   - Add the element at the end of the tree (next available position).
   - Restore the heap property by comparing the added element with its parent and swapping if necessary (this is called "heapifying up" or "bubble up").

2. **Deletion** (Specifically, deleting the root element, often used in heap-based priority queues):
   - Remove the root element.
   - Replace the root with the last element in the tree.
   - Restore the heap property by comparing the new root with its children and swapping if necessary (this is called "heapifying down" or "bubble down").

3. **Peek**:
   - Simply return the root element (maximum for max heap, minimum for min heap) without removing it.

#### C++ Implementation

```cpp
#include <iostream>
using namespace std;

class Heap {
public:
    int arr[101];
    int size;

    Heap() {
        size = 0;
    }

    void insert(int value) {
        // Insert at correct index
        size = size + 1;
        int index = size;
        arr[index] = value;

        // Place the value at correct position (heapify up)
        while (index > 1) {
            int parentIndex = index / 2;
            if (arr[parentIndex] < arr[index]) {
                // Swap
                swap(arr[parentIndex], arr[index]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    // Deletion (root node only)
    int deleteValue() {
        int ans = arr[1];
        arr[1] = arr[size];
        size--;

        // Ensure heap property is satisfied (heapify down)
        int index = 1;
        while (index < size) {
            int left = 2 * index;
            int right = 2 * index + 1;
            int largest = index;

            if (left <= size && arr[largest] < arr[left]) {
                largest = left;
            }
            if (right <= size && arr[largest] < arr[right]) {
                largest = right;
            }

            if (largest == index) {
                break;
            } else {
                swap(arr[index], arr[largest]);
                index = largest;
            }
        }
        return ans;
    }
};

int main() {
    Heap h;
    h.arr[0] = -1;
    h.arr[1] = 100;
    h.arr[2] = 50;
    h.arr[3] = 60;
    h.arr[4] = 40;
    h.arr[5] = 45;
    h.size = 5;

    cout << "Printing the heap" << endl;
    for (int i = 0; i <= h.size; i++) {
        cout << h.arr[i] << " ";
    }

    h.insert(110);
    cout << endl << "Printing the heap after insertion" << endl;
    for (int i = 0; i <= h.size; i++) {
        cout << h.arr[i] << " ";
    }

    h.deleteValue();
    cout << endl << "Printing the heap after deletion" << endl;
    for (int i = 0; i <= h.size; i++) {
        cout << h.arr[i] << " ";
    }

    return 0;
}
```

### Explanation

1. **Insertion**:
   - We start by placing the new value at the end of the heap.
   - We then "heapify up" by comparing the inserted value with its parent and swapping if the heap property is violated.
   - This process continues until the heap property is restored or the root is reached.

2. **Deletion**:
   - The root value is removed and returned.
   - The last element in the heap is moved to the root position.
   - We then "heapify down" by comparing the new root with its children and swapping with the larger child if necessary.
   - This process continues until the heap property is restored or a leaf node is reached.

3. **Peek**:
   - Simply return the root element (in a max heap, this is the maximum element).

This implementation uses an array to store the heap elements and manages the heap size to ensure efficient insertions and deletions.
