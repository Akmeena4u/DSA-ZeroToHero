In Data Structures and Algorithms (DSA), a heap is a specialized complete binary tree-based data structure that satisfies the heap property. The heap property varies depending on the type of heap:

### Types of Heaps
1. **Max Heap**:
   - In a max heap, for any given node `i`, the value of `i` is greater than or equal to the values of its children. This ensures that the largest element is always at the root.
   
2. **Min Heap**:
   - In a min heap, for any given node `i`, the value of `i` is less than or equal to the values of its children. This ensures that the smallest element is always at the root.

3. ![image](https://github.com/user-attachments/assets/b6f8a83d-f3c2-406c-96a3-8e95898c35a4)

---

### Key Characteristics
- **Complete Binary Tree**: Heaps are typically implemented as complete binary trees, meaning all levels are fully filled except possibly the last level, which is filled from left to right.
- **Heap Property**: Ensures efficient access to the maximum or minimum element.

---

### Applications
- **Priority Queues**: Heaps are commonly used to implement priority queues because they allow efficient retrieval of the highest (or lowest) priority element.
- **Heap Sort**: A comparison-based sorting technique that uses a binary heap.
- **Graph Algorithms**: Used in algorithms like Dijkstra's and Prim's for efficient retrieval of the next vertex to process.

---

### Implementations in different languages and Complexity analysis 

**Table 1: Implementations**

| Language    | API                       |
|-------------|---------------------------|
| C++         | `std::priority_queue`     |
| Java        | `java.util.PriorityQueue` |
| Python      | `heapq`                   |
| JavaScript  | N/A                       |

**Table 2: Time Complexity**

| Operation                                             | Big-O    |
|-------------------------------------------------------|----------|
| Find max/min                                          | O(1)     |
| Insert                                                | O(log(n))|
| Remove                                                | O(log(n))|
| Heapify (create a heap out of given array of elements)| O(n)     |

---

### Implementation Details
Heaps are often implemented using arrays rather than pointers, taking advantage of the complete binary tree structure:
- **0 based indexing** if the parent index=i then leftchild=2i+1 , rightchild index= 2i+2
- **1 based indexing** if the parent index=i then leftchild index= 2i , rightchild index=2i+1

---

### Common Operations
1. **Insertion**:
   - Add the element at the end of the tree (next available position).
   - Restore the heap property by comparing the added element with its parent and swapping if necessary (this is called "heapifying up" or "bubble up").

2. **Deletion** (Specifically, deleting the root element, often used in heap-based priority queues):
   - Remove the root element.
   - Replace the root with the last element in the tree.
   - Restore the heap property by comparing the new root with its children and swapping if necessary (this is called "heapifying down" or "bubble down").

3. **Peek**:
   - Simply return the root element (maximum for max heap, minimum for min heap) without removing it.

```cpp
#include <iostream>
using namespace std;
class Heap
{
public:
    int arr[101];
    int size;
    Heap()
    {
        size = 0;
    }
    void insert(int value)
    {
        // Insert at correct index
        size = size + 1;
        int index = size;
        arr[index] = value;
        // Place the value at correct position
        while (index > 1)
        {
            // greater than 1 as then parent of index = 1 will be 0 but it is not a valid element
            int parentIndex = index / 2;
            if (arr[parentIndex] < arr[index])
            {
                // Swap
                swap(arr[parentIndex], arr[index]);
                // Update index so that we get out of loop somewhere
                index = parentIndex;
            }
            else
            {
                // Do nothing
                break;
            }
        }
    }


    // Deletion
    // We can delete the root node only
    int deleteValue()
    {
        int ans = arr[1];
        // Replace root node and the last node
        arr[1] = arr[size];
        size--; // Delete the last value
        // Now make sure heap property is satisfied
        int index = 1;
        while (index < size)
        {
            int left = 2 * index;
            int right = 2 * index + 1;
            // Now find maximum value among parent and child
            int largest = index;
            if (left <= size && arr[largest] < arr[left])
            {
                largest = left;
            }
            if (right <= size && arr[largest] < arr[right])
            {
                largest = right;
            }
            // Swap with the maximum value
            if (largest == index)
            {
                // Value is at correct place
                break;
            }
            else
            {
                swap(arr[index], arr[largest]);
                // update index
                index = largest;
            }
        }
        return ans;
    }
};
int main()
{
    Heap h;
    h.arr[0] = -1;
    h.arr[1] = 100;
    h.arr[2] = 50;
    h.arr[3] = 60;
    h.arr[4] = 40;
    h.arr[5] = 45;
    h.size = 5;
    cout << "Printing the heap" << endl;
    for (int i = 0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    h.insert(110);
    cout << endl
         << "Printing the heap" << endl;
    for (int i = 0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    h.deleteValue();
    cout << endl
         << "Printing the heap" << endl;
    for (int i = 0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    return 0;
}
```

---
---

jjj
