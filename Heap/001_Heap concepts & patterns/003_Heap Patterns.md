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
