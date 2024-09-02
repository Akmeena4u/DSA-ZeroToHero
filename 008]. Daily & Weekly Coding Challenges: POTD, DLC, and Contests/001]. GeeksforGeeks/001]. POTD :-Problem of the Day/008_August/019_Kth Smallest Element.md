### Problem: Find the Kth Smallest Element

Given an array `arr[]` of distinct elements and an integer `k` (where `k` is smaller than the size of the array), the task is to find the `k`th smallest element in the array without using the built-in sorting function.

#### Approach

To solve the problem efficiently, we can utilize a **max-heap** (`priority_queue<int>`) for the first `k` elements, and then compare the remaining elements in the array to maintain the smallest `k` elements. After processing the entire array, the `k`th smallest element will be at the top of the max-heap.

### Steps:
1. **Step 1: Initialize a Max-Heap**
   - Use a max-heap (C++ `priority_queue<int>`) to store the first `k` elements of the array.
   - The largest element will be at the top of the heap, making it easier to compare and maintain only the smallest `k` elements.
   
2. **Step 2: Process the Remaining Elements**
   - For every element in the array after the first `k`, compare it with the top of the max-heap.
   - If the current element is smaller than the top of the heap, pop the top (largest) element and push the current element into the heap.
   - This ensures that only the smallest `k` elements are stored in the heap.

3. **Step 3: Return the Result**
   - After iterating through the array, the top element of the max-heap will be the `k`th smallest element.

### Code Implementation:

```cpp
#include <vector>
#include <queue>
#include <iostream>

int kthSmallest(std::vector<int>& arr, int k) {
    // Step 1: Create a max-heap (priority queue)
    std::priority_queue<int> pq;

    // Step 2: Insert the first 'k' elements into the max-heap
    for(int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    // Step 3: Process the remaining elements
    for(int i = k; i < arr.size(); i++) {
        // If the current element is smaller than the largest in the heap
        if(arr[i] < pq.top()) {
            pq.pop();         // Remove the largest element from the heap
            pq.push(arr[i]);  // Add the current smaller element
        }
    }

    // Step 4: Return the top of the heap (kth smallest element)
    return pq.top();
}

int main() {
    std::vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    std::cout << "The " << k << "rd smallest element is " << kthSmallest(arr, k) << std::endl;
    return 0;
}
```

### Explanation of the Code:

1. **Max-Heap (`priority_queue<int>`)**:
   - We use a max-heap (`std::priority_queue`) to maintain the smallest `k` elements.
   - The largest element of the current heap will always be at the top (root of the heap).
   
2. **Insertion of First `k` Elements**:
   - The first `k` elements are pushed into the heap using `pq.push(arr[i])`.
   - This guarantees that the heap contains `k` elements initially.

3. **Processing the Remaining Elements**:
   - For elements from index `k` onwards, each element is compared with the top of the heap (`pq.top()`).
   - If the current element is smaller than the heap’s largest element (i.e., `pq.top()`), the largest element is removed from the heap (`pq.pop()`) and the smaller element is added (`pq.push(arr[i])`).

4. **Result**:
   - After processing the entire array, the `k` smallest elements remain in the heap, and the `k`th smallest element will be the top element (`pq.top()`).

### Time and Space Complexity:

1. **Time Complexity**:
   - Constructing the initial heap with `k` elements takes `O(k log k)`.
   - For each element after the `k`th, the time complexity to compare and update the heap (if needed) is `O(log k)`.
   - Hence, the overall time complexity is: `O(klog k + (n - k)log k) = O(nlog k)`
     
   - Where `n` is the total number of elements in the array.

2. **Space Complexity**:
   - The space complexity is `O(k)` since the heap will store at most `k` elements at any given time.

### Example:

**Input:**

```cpp
arr[] = [7, 10, 4, 3, 20, 15]
k = 3
```

**Execution Steps:**

1. Insert first `k` elements into the max-heap:
   - Heap after inserting `[7, 10, 4]`: `[10, 7, 4]`

2. Process the remaining elements:
   - `arr[3] = 3`: Since `3 < 10`, remove `10` and insert `3`. Heap becomes `[7, 3, 4]`.
   - `arr[4] = 20`: `20 > 7`, so no change to the heap.
   - `arr[5] = 15`: `15 > 7`, so no change to the heap.

3. The top of the heap is `7`, which is the 3rd smallest element.

**Output:**

```
7
```

### Conclusion:
This approach efficiently finds the `k`th smallest element without sorting the array. It leverages the properties of a max-heap to keep track of the smallest `k` elements in the array, ensuring an optimized solution with `O(n log k)` complexity.
