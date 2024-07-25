
### Kth Largest Element in an Array

#### Problem Statement
Given an integer array `nums` and an integer `k`, return the `k`th largest element in the array. Note that it is the `k`th largest element in the sorted order, not the `k`th distinct element.

**Example 1:**
- Input: `nums = [3,2,1,5,6,4]`, `k = 2`
- Output: `5`

 
#### Approach 
1. **Heap Initialization:**
   - This creates a max-heap using `std::priority_queue`.
2. **Insert First `k` Elements:**
   - Insert the first `k` elements of the array into the heap. Since it's a max-heap, the largest element will be at the root.
3. **Process Remaining Elements:**
   - For each remaining element, compare it with the root of the heap (the largest element in the heap).
   - If the current element is larger than the root, remove the root and insert the current element. This ensures that the heap contains the `k` largest elements seen so far.
4. **Result Extraction:**
   - After processing all elements, the root of the heap is the `k`th largest element in the array.


#### Code
```cpp
#include <vector>
#include <queue>

class Solution {
public:
    int findKthLargest(std::vector<int>& arr, int k) {
        // Create a max heap
        int n = arr.size();
        std::priority_queue<int> pq;

        // Insert the first k elements of the array into the max heap
        for (int i = 0; i < k; i++) {
            pq.push(arr[i]);
        }

        // For remaining elements, insert into heap if the element is smaller than the max element in the heap
        for (int i = k; i < n; i++) {
            if (pq.top() < arr[i]) {
                pq.pop(); // Remove the largest element
                pq.push(arr[i]); // Insert the new element
            }
        }

        // The top of the heap is the Kth largest element
        return pq.top();
    }
};
```


### Complexity Analysis

- **Time Complexity:** `O(nlog k)`
  - Inserting an element into the heap and removing the root both take `O(log k)`.
  - Since we perform these operations for each of the `n` elements, the total time complexity is `O(nlog k)`.

- **Space Complexity:** `O(k)`
  - The heap contains at most `k` elements.

This approach is efficient and works well within the given constraints. It avoids the need to sort the entire array, making it suitable for large inputs.
