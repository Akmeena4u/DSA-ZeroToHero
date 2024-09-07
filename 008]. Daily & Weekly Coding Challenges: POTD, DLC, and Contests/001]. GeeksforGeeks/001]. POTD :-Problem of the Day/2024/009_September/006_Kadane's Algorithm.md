### Problem: Kadane's Algorithm

#### Problem Statement
Given an integer array `arr[]`, the task is to find the contiguous subarray (containing at least one number) that has the maximum sum and return its sum.

#### Example
- **Input:** `arr[] = [1, 2, 3, -2, 5]`
- **Output:** `9`

  **Explanation:**
  - The maximum sum subarray is `[1, 2, 3, -2, 5]`, and the sum is `9`.

#### Concept: Kadane's Algorithm
Kadane's Algorithm is an efficient way to solve the Maximum Subarray Sum problem. The main idea behind the algorithm is to look for all positive contiguous segments of the array (subarrays) and keep track of the maximum sum encountered so far. If the sum of the current subarray becomes negative, it is discarded, and the algorithm starts fresh with the next element.

#### Approach

1. **Initialization:**
   - Initialize two variables: `maxiSum` to store the maximum sum encountered so far, and `sum` to store the sum of the current subarray.
   - Set `maxiSum` to a very small value (e.g., `LONG_MIN`) to ensure any sum will be greater than it initially.
   - Initialize `sum` to `0`.

2. **Iteration through the Array:**
   - Traverse the array from the first element to the last:
     - Add the current element `arr[i]` to `sum`.
     - Update `maxiSum` if `sum` is greater than `maxiSum`.
     - If `sum` becomes negative, reset `sum` to `0`, effectively discarding the current subarray as it won't contribute to a maximum sum.

3. **Final Result:**
   - After traversing the array, `maxiSum` will contain the maximum sum of any contiguous subarray.

#### Code Implementation
```cpp
long long maxSubarraySum(vector<int> &arr) {
    int n = arr.size();
    long long maxiSum = LONG_MIN;  // Maximum sum encountered so far
    long long sum = 0;             // Sum of the current subarray

    for (int i = 0; i < n; i++) {
        sum += arr[i];  // Add current element to the sum

        if (sum > maxiSum) {
            maxiSum = sum;  // Update maximum sum if current sum is greater
        }

        if (sum < 0) {
            sum = 0;  // Reset sum if it becomes negative
        }
    }

    return maxiSum;
}
```

#### Explanation of the Code

1. **Initialization:**
   - `maxiSum` is initialized to `LONG_MIN` to store the maximum subarray sum found during the iteration.
   - `sum` is initialized to `0` to track the sum of the current subarray.

2. **Iterating Over the Array:**
   - For each element in the array, the current element `arr[i]` is added to `sum`.
   - If `sum` exceeds `maxiSum`, then `maxiSum` is updated to `sum`.
   - If `sum` becomes negative, it is reset to `0` because continuing with a negative sum would not lead to a maximum subarray sum.

3. **Final Result:**
   - After completing the iteration, `maxiSum` contains the sum of the maximum subarray.

#### Example Walkthrough
For `arr[] = [1, 2, 3, -2, 5]`:
- Start with `sum = 0` and `maxiSum = LONG_MIN`.
- Iterate through the array:
  - Add `1` to `sum`, making `sum = 1`. Update `maxiSum = 1`.
  - Add `2` to `sum`, making `sum = 3`. Update `maxiSum = 3`.
  - Add `3` to `sum`, making `sum = 6`. Update `maxiSum = 6`.
  - Add `-2` to `sum`, making `sum = 4`. `maxiSum` remains `6`.
  - Add `5` to `sum`, making `sum = 9`. Update `maxiSum = 9`.
- The final value of `maxiSum` is `9`, which is the maximum sum of any subarray.

#### Complexity Analysis

- **Time Complexity:** O(n)
  - The array is traversed once, so the time complexity is linear with respect to the number of elements in the array.
  
- **Space Complexity:** O(1)
  - The algorithm uses only a fixed amount of extra space, regardless of the input size.

#### Summary
Kadane's Algorithm provides an efficient method to find the maximum sum of a contiguous subarray. The algorithm works by maintaining a running sum of the current subarray and updating the maximum sum found so far. If the running sum becomes negative, it is reset, as it cannot contribute to a maximum sum. This approach ensures an optimal solution with linear time complexity.
