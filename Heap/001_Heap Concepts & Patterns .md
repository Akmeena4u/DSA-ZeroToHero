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
Heaps are often implemented using arrays rather than pointers, taking advantage of the complete binary tree structure. Parent and child nodes can be accessed with indices:
- **0 based indexing** if the parent index=i then leftchild=2i+1 , rightchild index= 2i+2
- **1 based indexing** if the parent index=i then leftchild index= 2i , rightchild index=2i+1

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
