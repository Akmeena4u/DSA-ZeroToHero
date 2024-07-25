
# Heap Data Structures in Data Structures and Algorithms (DSA)

A heap is a specialized complete binary tree-based data structure that satisfies the heap property. The heap property varies depending on the type of heap:

### Types of Heaps

1. **Max Heap**:
   - In a max heap, for any given node `i`, the value of `i` is greater than or equal to the values of its children. This ensures that the largest element is always at the root.
   
2. **Min Heap**:
   - In a min heap, for any given node `i`, the value of `i` is less than or equal to the values of its children. This ensures that the smallest element is always at the root.

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

### Implementations in Different Languages and Complexity Analysis 

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

Heaps are often implemented using arrays rather than pointers, taking advantage of the complete binary tree structure. Parent and child nodes can be accessed with indices:
- **0-based indexing**: if the parent index = `i`, then left child index = `2i+1`, right child index = `2i+2`.
- **1-based indexing**: if the parent index = `i`, then left child index = `2i`, right child index = `2i+1`.


---

### Implementing Min Heap and Max Heap using STL

The C++ Standard Template Library (STL) provides powerful tools for implementing heaps. By default, the heap operations in STL are designed for max heaps. However, with a few modifications, you can implement both min heaps and max heaps.

#### Max Heap
A max heap is a binary tree where the parent node is always greater than or equal to the child nodes. In STL, this is the default behavior.

#### Min Heap
A min heap is a binary tree where the parent node is always less than or equal to the child nodes. To implement a min heap, you can use `std::greater` as the comparison function.

### Explanation

1. **`std::make_heap`**: Converts a range of elements into a heap. For a max heap, this is the default. For a min heap, you use `std::greater<int>()` as the comparison function.

2. **`std::push_heap`**: Adds a new element to the heap and maintains the heap property. Again, for a min heap, you need to specify `std::greater<int>()`.

3. **`std::pop_heap`**: Removes the largest (for max heap) or smallest (for min heap) element from the heap and moves it to the end of the range. You then need to remove this element from the container.

4. **Heap Comparison Function**:
    - **Max Heap**: Uses the default `std::less<int>()` comparison.
    - **Min Heap**: Uses `std::greater<int>()` to reverse the default ordering.

### Complete Example with Both Min Heap and Max Heap

Here’s a complete example that demonstrates both min heap and max heap in one program:

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

void printHeap(const std::vector<int>& heap) {
    for(int val : heap) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Max Heap
    std::vector<int> maxHeap = {10, 20, 30, 5, 15};
    std::make_heap(maxHeap.begin(), maxHeap.end());

    std::cout << "Max Heap: ";
    printHeap(maxHeap);

    maxHeap.push_back(25);
    std::push_heap(maxHeap.begin(), maxHeap.end());
    std::cout << "After adding 25: ";
    printHeap(maxHeap);

    std::pop_heap(maxHeap.begin(), maxHeap.end());
    maxHeap.pop_back();
    std::cout << "After removing max element: ";
    printHeap(maxHeap);

    // Min Heap
    std::vector<int> minHeap = {10, 20, 30, 5, 15};
    std::make_heap(minHeap.begin(), minHeap.end(), std::greater<int>());

    std::cout << "Min Heap: ";
    printHeap(minHeap);

    minHeap.push_back(25);
    std::push_heap(minHeap.begin(), minHeap.end(), std::greater<int>());
    std::cout << "After adding 25: ";
    printHeap(minHeap);

    std::pop_heap(minHeap.begin(), minHeap.end(), std::greater<int>());
    minHeap.pop_back();
    std::cout << "After removing min element: ";
    printHeap(minHeap);

    return 0;
}
```

### Key Points
- **Max Heap**: Use default heap functions with `std::make_heap`, `std::push_heap`, and `std::pop_heap`.
- **Min Heap**: Use `std::greater<int>()` with `std::make_heap`, `std::push_heap`, and `std::pop_heap`.

This example shows how to create, manipulate, and print both max heaps and min heaps using STL heap functions.

