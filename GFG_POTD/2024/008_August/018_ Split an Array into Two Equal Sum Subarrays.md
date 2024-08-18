### Problem: Split an Array into Two Equal Sum Subarrays

#### Problem Explanation:
You are given an array of integers, and your goal is to determine if it is possible to split the array into two non-overlapping subarrays such that their sums are equal. The elements of the array cannot be reordered. If it is possible, return `true`, otherwise, return `false`.

#### Example:

- **Input:** `arr = [1, 2, 3, 4, 5, 5]`
- **Output:** `true`
  
  **Explanation:** The array can be split into two subarrays `[1, 2, 3, 4]` and `[5, 5]`, both of which have the sum `10`. Hence, the function should return `true`.

#### Constraints:
- The array should not be reordered.
- The split must be such that the sum of the elements in both subarrays is equal.

---

### Approach 1: Prefix and Suffix Sum Method

#### Algorithm:
1. **Calculate the total sum** of the array.
2. **Iterate through the array**:
   - Maintain two sums: `sum1` for the left part (prefix sum) and `sum2` for the right part (suffix sum).
   - At each index `i`, update `sum1` by adding the current element and decrease `sum2` by the same element.
   - Check if `sum1` is equal to `sum2` at any index.
3. If the condition is met, return `true`. If the loop ends without finding such a split, return `false`.

#### Code:
```cpp
bool canSplit(vector<int>& arr) {
    int n = arr.size();
    int sum1 = 0, sum2 = 0;
    
    // Calculate the total sum (sum2)
    for(int j = 0; j < n; j++){
        sum2 += arr[j];
    }
    
    // Traverse the array and update sum1 and sum2
    for(int i = 0; i < n; i++) {
        sum1 += arr[i];
        sum2 -= arr[i];
        
        // Check if both sums are equal
        if(sum1 == sum2) {
            return true;
        }
    }
    return false;
}
```

#### Time Complexity:
- **O(n)**: The array is traversed twice. The first loop calculates the total sum, and the second loop checks for the possible split.
  
#### Space Complexity:
- **O(1)**: Constant extra space is used.

#### Edge Cases:
1. **Single Element Array**: If the array contains only one element, it is impossible to split it into two subarrays.
   - Example: `[5]`
2. **Empty Array**: No possible split in an empty array.
   - Example: `[]`
3. **Array with Equal Elements**: If all elements in the array are equal, the function will check if there’s a valid split.
   - Example: `[5, 5, 5, 5]`

---

### Approach 2: Two Pointer Approach

#### Algorithm:
1. **Use two pointers** to traverse the array: one starting from the left (`i`) and the other from the right (`j`).
2. **Maintain two sums**: `leftSum` for the left part and `rightSum` for the right part.
3. **Move the pointers** towards each other:
   - If `leftSum` is smaller, increment `i` and add the current element to `leftSum`.
   - If `rightSum` is smaller, decrement `j` and add the current element to `rightSum`.
4. Stop when the pointers meet or when the difference between the pointers is 1. Check if `leftSum` equals `rightSum` at the end.
5. Return `true` if both sums are equal; otherwise, return `false`.

#### Code:
```cpp
bool canSplit(vector<int>& arr) {
    if(arr.size() == 1) {
        return false;  // Cannot split a single element array
    }
    
    int leftSum = arr[0];
    int rightSum = arr[arr.size() - 1];
    int i = 0;
    int j = arr.size() - 1;
    
    // Use a while loop to move pointers towards each other
    while(i < j && j - i != 1) {
        if(leftSum >= rightSum) {
            j--;  // Move the right pointer left
            rightSum += arr[j];
        } else {
            i++;  // Move the left pointer right
            leftSum += arr[i];
        }
    }
    
    // Final check if the two sums are equal
    return leftSum == rightSum;
}
```

#### Time Complexity:
- **O(n)**: The array is traversed from both ends using the two pointers.

#### Space Complexity:
- **O(1)**: Only a constant amount of extra space is used for the pointers and sums.

#### Edge Cases:
1. **Array with one element**: If the array has only one element, return `false` since it is impossible to split it.
2. **Array with equal left and right sums from the start**: The function should immediately detect if the split is possible without moving the pointers.
3. **Array with no valid split**: If no valid split is possible, the function should handle this case and return `false`.

---

### Detailed Comparison of Approaches:

| Approach                   | Time Complexity | Space Complexity | Description                                             |
|-----------------------------|-----------------|------------------|---------------------------------------------------------|
| Prefix and Suffix Sum Method | O(n)            | O(1)             | Uses prefix and suffix sums to check for possible split. |
| Two Pointer Approach         | O(n)            | O(1)             | Uses two pointers to calculate left and right sums.      |

### Edge Case Analysis:
- **Single Element**: Both approaches handle single-element arrays by returning `false`, as it is impossible to split one element into two subarrays.
- **Equal Left and Right Sums Early**: Both approaches efficiently detect early splits if possible.
- **Large Input Arrays**: Since both methods work in linear time, they are suitable for larger arrays.

---

### Conclusion:
Both the **Prefix and Suffix Sum Method** and the **Two Pointer Approach** are efficient solutions for the problem. The two-pointer approach is more intuitive in terms of simulating a split, while the prefix-suffix approach offers a clear understanding of the sum calculations. Both methods have linear time complexity and constant space complexity, making them optimal for solving the problem.
