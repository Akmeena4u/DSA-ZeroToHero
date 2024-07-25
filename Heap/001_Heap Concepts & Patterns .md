

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
---

### Priority Queue in C++

A priority queue is a type of container adapter in C++ that allows for the storage of elements such that the element with the highest (or lowest) priority is always at the front and can be accessed in constant time. The `std::priority_queue` class template provides a way to implement such a container.

#### Characteristics of `std::priority_queue`

- **Ordering**: By default, the `std::priority_queue` is implemented as a max-heap, meaning the largest element is always at the top. However, it can be customized to work as a min-heap.
- **Underlying Container**: Typically implemented using a vector (`std::vector`) as the underlying container.
- **Efficiency**: Insertion and deletion operations are logarithmic in complexity, i.e., O(log n).

#### Syntax and Usage

Here is a detailed explanation of how to use `std::priority_queue` in C++:

##### Include Header
To use `std::priority_queue`, you need to include the `<queue>` header.

```cpp
#include <queue>
```

##### Basic Operations
- **Push**: Adds an element to the priority queue.
- **Pop**: Removes the highest-priority element.
- **Top**: Accesses the highest-priority element without removing it.
- **Empty**: Checks if the priority queue is empty.
- **Size**: Returns the number of elements in the priority queue.

##### Example: Max-Heap (Default Behavior)
```cpp
#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> pq;

    // Insert elements
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(1);

    // Access the top element
    std::cout << "Top element: " << pq.top() << std::endl; // Output: 30

    // Remove elements
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    // Output: 30 20 10 5 1

    return 0;
}
```

##### Custom Comparator: Min-Heap
To implement a min-heap, you can use `std::greater` as the comparison function.

```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <functional> // for std::greater

int main() {
    // Min-heap using priority_queue
    std::priority_queue<int, std::vector<int>, std::greater<int>> minPq;

    // Insert elements
    minPq.push(10);
    minPq.push(30);
    minPq.push(20);
    minPq.push(5);
    minPq.push(1);

    // Access the top element
    std::cout << "Top element: " << minPq.top() << std::endl; // Output: 1

    // Remove elements
    while (!minPq.empty()) {
        std::cout << minPq.top() << " ";
        minPq.pop();
    }
    // Output: 1 5 10 20 30

    return 0;
}
```

##### Using Custom Comparator
You can also define a custom comparator for more complex priority rules.
```cpp
#include <iostream>
#include <queue>
#include <vector>

// Custom comparator
struct CustomCompare {
    bool operator()(const int& lhs, const int& rhs) {
        return lhs > rhs; // Min-heap
    }
};

int main() {
    std::priority_queue<int, std::vector<int>, CustomCompare> customPq;

    // Insert elements
    customPq.push(10);
    customPq.push(30);
    customPq.push(20);
    customPq.push(5);
    customPq.push(1);

    // Access the top element
    std::cout << "Top element: " << customPq.top() << std::endl; // Output: 1

    // Remove elements
    while (!customPq.empty()) {
        std::cout << customPq.top() << " ";
        customPq.pop();
    }
    // Output: 1 5 10 20 30

    return 0;
}
```

#### Key Points
- `std::priority_queue` is a convenient way to manage a collection of elements where the highest (or lowest) priority element is always accessible.
- By default, it functions as a max-heap, but you can customize it to behave as a min-heap using `std::greater` or a custom comparator.
- Common operations like insertion, deletion, and access to the top element are efficient, with logarithmic time complexity.

Using `std::priority_queue` in C++ allows you to leverage the power of heap data structures for managing prioritized elements efficiently.

---
### Heap Usage Patterns in Problem Solving

Heaps are a powerful data structure used to solve various types of problems efficiently. Here, we categorize heap problems into four main patterns and provide detailed notes on each, along with links to relevant LeetCode problems.

#### 1. Top K Pattern
This pattern involves finding the top K elements in a dataset. Problems in this category often require maintaining a heap of size K to keep track of the largest or smallest elements encountered so far.

##### Problems:
- **[LC #215 - Kth largest number in an array](https://leetcode.com/problems/kth-largest-element-in-an-array/)**
- **[LC #973 - K closest points to origin](https://leetcode.com/problems/k-closest-points-to-origin/)**
- **[LC #347 - Top k frequent elements/numbers](https://leetcode.com/problems/top-k-frequent-elements/)**
- **[LC #692 - Top k frequent words](https://leetcode.com/problems/top-k-frequent-words/)**
- **[LC #264 - Ugly Number II](https://leetcode.com/problems/ugly-number-ii/)**
- **[LC #451 - Frequency Sort](https://leetcode.com/problems/sort-characters-by-frequency/)**
- **[LC #703 - Kth largest number in a stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/)**
- **[LC #767 - Reorganize String](https://leetcode.com/problems/reorganize-string/)**
- **[LC #358 - Rearrange string K distance apart](https://leetcode.com/problems/rearrange-string-k-distance-apart/)**
- **[LC #1439 - Kth smallest sum of a matrix with sorted rows](https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/)**

#### 2. Merge K Sorted Pattern
This pattern deals with merging multiple sorted lists into a single sorted list. A heap is used to efficiently track the smallest (or largest) elements across all lists.

##### Problems:
- **[LC #23 - Merge K sorted lists](https://leetcode.com/problems/merge-k-sorted-lists/)**
- **[LC #373 - K pairs with the smallest sum](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/)**
- **[LC #378 - K smallest numbers in M-sorted lists](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)**

#### 3. Two Heaps Pattern
This pattern is useful when you need to manage two types of elements separately but still need to perform efficient operations between them, such as finding the median of a stream of numbers.

##### Problems:
- **[LC #295 - Find median from a data stream](https://leetcode.com/problems/find-median-from-data-stream/)**
- **[LC #480 - Sliding window median](https://leetcode.com/problems/sliding-window-median/)**
- **[LC #502 - Maximize Capital/IPO](https://leetcode.com/problems/ipo/)**

#### 4. Minimum Number Pattern
Problems in this category require finding the minimum number of operations or resources to achieve a certain goal. A heap can help efficiently manage the resources or operations required.

##### Problems:
- **[LC #1167 - Minimum cost to connect sticks/ropes](https://leetcode.com/problems/minimum-cost-to-connect-sticks/)**
- **[LC #253 - Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/)**
- **[LC #759 - Employee free time](https://leetcode.com/problems/employee-free-time/)**
- **[LC #857 - Minimum cost to hire K workers](https://leetcode.com/problems/minimum-cost-to-hire-k-workers/)**
- **[LC #621 - Minimum number of CPU (Task scheduler)](https://leetcode.com/problems/task-scheduler/)**
- **[LC #871 - Minimum number of refueling stops](https://leetcode.com/problems/minimum-number-of-refueling-stops/)**

### Detailed Notes

#### Top K Pattern
- **Concept**: Use a heap to keep track of the top K elements. Often, a min-heap of size K is used to ensure that the root of the heap always contains the Kth largest element.
- **Common Operations**: 
  - Insert elements into the heap.
  - If the heap exceeds size K, remove the smallest element.
  - The root of the heap gives the Kth largest element.
- **Example**: To find the Kth largest element in an array, maintain a min-heap of size K. As you traverse the array, keep adding elements to the heap. If the heap size exceeds K, remove the smallest element. At the end, the root of the heap is the Kth largest element.

#### Merge K Sorted Pattern
- **Concept**: Use a heap to efficiently merge multiple sorted lists. The heap helps track the smallest elements across all lists.
- **Common Operations**:
  - Insert the first element of each list into the heap.
  - Extract the smallest element from the heap and add the next element from the same list to the heap.
  - Continue until all lists are exhausted.
- **Example**: To merge K sorted lists, initialize a min-heap with the first element of each list. Extract the smallest element from the heap and insert the next element from the corresponding list. Repeat until all elements are merged.

#### Two Heaps Pattern
- **Concept**: Use two heaps (a max-heap and a min-heap) to manage two different sets of elements. This is useful for problems that require finding the median of a dynamic set of numbers.
- **Common Operations**:
  - Insert elements into the appropriate heap.
  - Balance the heaps to ensure that the max-heap contains the smaller half of the numbers and the min-heap contains the larger half.
  - The median can be found based on the sizes of the heaps.
- **Example**: To find the median from a data stream, use a max-heap for the lower half of the numbers and a min-heap for the upper half. If the total number of elements is odd, the median is the root of the max-heap. If even, the median is the average of the roots of both heaps.

#### Minimum Number Pattern
- **Concept**: Use a heap to manage resources or operations efficiently to minimize the total cost or number of steps.
- **Common Operations**:
  - Insert elements into the heap.
  - Extract the smallest element and perform necessary operations.
  - Insert new elements resulting from operations back into the heap.
- **Example**: To connect sticks with minimum cost, use a min-heap to always connect the two smallest sticks. Insert the new stick back into the heap and repeat until only one stick remains.

### Conclusion
Mastering these patterns by solving the listed problems will help you become proficient in using heaps for a variety of scenarios. Each pattern highlights a different use case, and understanding these will enable you to recognize when and how to use heaps effectively.

---



