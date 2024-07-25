### Problem:  Find K Closest Elements

**Description**:
Given a sorted integer array `arr`, and two integers `k` and `x`, return the `k` closest integers to `x` in the array. The result should be sorted in ascending order.

**Example**:
- **Input**: `arr = [1,2,3,4,5]`, `k = 4`, `x = 3`
- **Output**: `[1,2,3,4]`

### Explanation

To solve this problem, we can use a max heap to keep track of the `k` closest elements to `x`. The steps involve pushing elements into the heap based on their distance from `x` and then maintaining the heap size to `k`. Finally, we extract and sort the elements to get the desired result.

### Detailed Steps:

1. **Priority Queue (Max Heap)**:
   - Use a max heap to store the elements along with their absolute difference from `x`.

2. **Insertion and Maintenance**:
   - Insert each element along with its distance from `x` into the heap.
   - Ensure that the size of the heap does not exceed `k`. If it does, remove the top element (which is the farthest).

3. **Extract and Sort**:
   - Extract the elements from the heap into a result vector.
   - Sort the result vector to ensure the elements are in ascending order.

### Implementation:

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Define a max heap with custom comparator
        priority_queue<pair<int, int>> pq;

        // Insert elements into the max heap
        for (auto ele : arr) {
            pq.push(make_pair(abs(x - ele), ele));
            // Maintain heap size to k
            if (pq.size() > k) pq.pop();
        }

        // Extract elements from the heap into a result vector
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        // Sort the result vector
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;
    vector<int> result = sol.findClosestElements(arr, k, x);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}
```

4. **Complexity**:
   - Time complexity is O(n log k) due to heap operations for each element in the array.
   - Space complexity is O(k) for storing the `k` closest elements in the heap.

### Summary:
This solution efficiently finds the `k` closest elements to `x` using a max heap, maintaining the heap size, and then sorting the result for the final output. The approach leverages the properties of a priority queue to ensure optimal performance.
