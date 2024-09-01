### Problem: Max Sum Path in Two Arrays

#### Problem Statement:
You are given two sorted arrays of distinct integers, `arr1` and `arr2`. Each array may have some elements in common with the other array. The task is to find the maximum sum of a path from the beginning of any array to the end of any array. You are allowed to switch from one array to the other only at common elements, and when switching, you must include the common element only once in the result.

#### Example:
**Input:** 
- `arr1 = [2, 3, 7, 10, 12]`
- `arr2 = [1, 5, 7, 8]`

**Output:** 
- `35`

**Explanation:**
- The path to achieve the maximum sum is `1 + 5 + 7 + 10 + 12 = 35`. Here, elements `1` and `5` come from `arr2`, `7` is common, so we switch to `arr1` and then add `10` and `12`.

#### Approach:
To solve this problem, we can use a two-pointer technique while traversing both arrays. The basic idea is to keep track of two potential sums: one from `arr1` and the other from `arr2`. When we encounter a common element, we add the maximum of the two sums to the result and reset the sums. After processing all common elements, we add any remaining sum from either array to the result.

#### Detailed Steps:
1. **Initialize Pointers and Sums:**
   - Let `i = 0` be the pointer for `arr1`.
   - Let `j = 0` be the pointer for `arr2`.
   - `sum1` will keep track of the sum of elements from `arr1`.
   - `sum2` will keep track of the sum of elements from `arr2`.
   - `res` will store the final result.

2. **Traverse Both Arrays:**
   - If `arr1[i] < arr2[j]`, add `arr1[i]` to `sum1` and move the pointer `i` to the next element.
   - If `arr1[i] > arr2[j]`, add `arr2[j]` to `sum2` and move the pointer `j` to the next element.
   - If `arr1[i] == arr2[j]`, add the maximum of `sum1` and `sum2` to `res` (including the common element once), reset `sum1` and `sum2`, and move both pointers to the next element.

3. **Add Remaining Elements:**
   - After traversing one array completely, add the remaining elements of the other array to the corresponding sum.
   - Add the maximum of `sum1` and `sum2` to `res`.

4. **Return the Result:**
   - The final value of `res` will be the maximum sum of the path.

#### Code Implementation:
```cpp
int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
    int i = 0, j = 0;
    int n = arr1.size(), m = arr2.size();
    int sum1 = 0, sum2 = 0;
    int res = 0;

    // Traverse both arrays simultaneously
    while(i < n && j < m) {
        // Add elements to sum1 from arr1 if arr1[i] is smaller
        if(arr1[i] < arr2[j]) {
            sum1 += arr1[i++];
        }
        // Add elements to sum2 from arr2 if arr2[j] is smaller
        else if(arr1[i] > arr2[j]) {
            sum2 += arr2[j++];
        }
        // When common element is found
        else {
            res += max(sum1, sum2) + arr1[i];
            sum1 = 0; // Reset sum1
            sum2 = 0; // Reset sum2
            i++;
            j++;
        }
    }

    // Add remaining elements of arr1
    while(i < n) {
        sum1 += arr1[i++];
    }

    // Add remaining elements of arr2
    while(j < m) {
        sum2 += arr2[j++];
    }

    // Add the maximum of the remaining sums to the result
    res += max(sum1, sum2);

    return res;
}
```

#### Complexity Analysis:
- **Time Complexity:** `O(n + m)` where `n` is the length of `arr1` and `m` is the length of `arr2`, as we traverse each array exactly once.
- **Space Complexity:** `O(1)` as no additional space is used besides a few variables.

This solution is efficient and handles the problem in linear time, making it suitable for large inputs.
