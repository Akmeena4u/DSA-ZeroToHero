### Problem: K Closest Elements

**Description**:
Given a sorted array of unique elements in increasing order `arr[]` of `n` integers and a value `x`, find the `K` closest elements to `x` in `arr[]`. The solution must consider the following:
- If `x` is present in the array, it should not be considered.
- If two elements have the same difference from `x`, the greater element is prioritized.
- If sufficient elements are not present on one side of `x`, take elements from the other side.

**Example**:
- **Input**: `n = 13`, `arr = [12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56]`, `k = 4`, `x = 35`
- **Output**: `[39, 30, 42, 45]`
- **Explanation**:
  - First closest element to 35 is 39.
  - Second closest element to 35 is 30.
  - Third closest element to 35 is 42.
  - Fourth closest element to 35 is 45.

### Solution Approach

1. **Priority Queue (Max Heap)**:
   - Use a max heap to store the elements along with their absolute differences from `x`.
   - If two elements have the same difference, the greater element is prioritized by storing negative values in the heap.

2. **Insertion and Maintenance**:
   - Iterate over the array and skip if the element is equal to `x`.
   - Calculate the absolute difference for each element and add it to the heap.
   - If the heap size exceeds `k`, remove the element with the maximum absolute difference.

3. **Extract and Sort**:
   - Extract elements from the heap into a result vector.
   - Reverse the result vector to get the elements in ascending order.

### Implementation:

```cpp

class Solution {
public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // Create a max heap to store pairs of absolute differences and elements
        priority_queue<pair<int, int>> maxH;
        
        for (int i = 0; i < n; i++) {
            // Skip if the element is equal to x
            if (arr[i] == x)
                continue;

            // Calculate the absolute difference and add the pair to the max heap
            maxH.push({abs(arr[i] - x), -arr[i]});

            // If the size of the max heap exceeds k, remove the element with the maximum absolute difference
            if (maxH.size() > k)
                maxH.pop();
        }
        
        // Store the result in a vector
        vector<int> result;
        
        // Retrieve the top k elements from the max heap
        while (!maxH.empty()) {
            auto p = maxH.top();
            maxH.pop();
            // Add the negative value to the result vector
            result.push_back(-p.second);
        }
        
        // Reverse the result vector to get the closest numbers in ascending order
        reverse(result.begin(), result.end());
        
        return result;
    }
};

```

### Explanation of the Implementation:

1. **Heap Definition**:
   - The heap stores pairs where the first element is the absolute difference from `x` and the second element is the negative of the array element. This ensures that if two elements have the same distance, the greater element is prioritized due to the negative sign.

2. **Inserting into the Heap**:
   - For each element in the array, if it is not equal to `x`, calculate the absolute difference and push it onto the heap.
   - Maintain the heap size to `k` by popping the top element if the heap exceeds size `k`.

3. **Extracting and Sorting**:
   - Extract elements from the heap into a result vector.
   - Reverse the result vector to get the elements in ascending order.

### Complexity:
- **Time Complexity**: O(n log k), where `n` is the number of elements in the array. Each insertion and removal operation in the heap takes O(log k) time.
- **Space Complexity**: O(k), where `k` is the size of the heap, storing at most `k` elements.
