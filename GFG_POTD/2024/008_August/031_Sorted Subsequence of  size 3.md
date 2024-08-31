### Problem Explanation

**Problem Statement:**

You are given an array `arr` of integers, and you need to find any three elements in the array such that:
1. `arr[i] < arr[j] < arr[k]`
2. `i < j < k`

In simple terms, you need to find a subsequence of three elements in the array where the first element is smaller than the second, and the second is smaller than the third, with their respective indices also in increasing order.

**Output:**

- Return the subsequence if found, otherwise return an empty array.
- If the subsequence is found, the driver code will print `1`.
- If the subsequence is not in the correct format (i.e., not in the form `arr[i] < arr[j] < arr[k]`), the driver code will print `-1`.

### Example

**Input:** `arr = [1, 2, 1, 1, 3]`

**Output:** `1` (since the subsequence `1 2 3` exists)

### Approach 1: Brute Force

#### Algorithm

1. **Iterate through the array with three nested loops:**
   - Use the first loop to pick the first element `arr[i]`.
   - Use the second loop to pick the second element `arr[j]` such that `j > i` and `arr[j] > arr[i]`.
   - Use the third loop to pick the third element `arr[k]` such that `k > j` and `arr[k] > arr[j]`.

2. **Check if the condition `arr[i] < arr[j] < arr[k]` holds true.**
   - If yes, return the subsequence `{arr[i], arr[j], arr[k]}`.
   - If no valid subsequence is found, return an empty array.

#### Code

```cpp
vector<int> find3Numbers(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] >= arr[j]) continue;
            for (int k = j + 1; k < n; k++) {
                if (arr[k] <= arr[j]) continue;
                else return {arr[i], arr[j], arr[k]};
            }
        }
    }
    return {};
}
```

#### Time Complexity

- **Time Complexity:** `O(n^3)`  
  Three nested loops iterate over the array, leading to cubic time complexity.

- **Space Complexity:** `O(1)`  
  Only a few variables are used; no additional space is required.

### Approach 2: Optimized Approach Using Auxiliary Arrays

#### Algorithm

1. **Initialize Two Arrays:**
   - `leftSmall[i]`: Stores the smallest element on the left side of index `i`.
   - `rightLarge[i]`: Stores the largest element on the right side of index `i`.

2. **Fill the `leftSmall` Array:**
   - Traverse from left to right, keeping track of the smallest element so far.

3. **Fill the `rightLarge` Array:**
   - Traverse from right to left, keeping track of the largest element so far.

4. **Find the Valid Triplet:**
   - Traverse through the array and for each element `arr[i]`, check if it satisfies `leftSmall[i-1] < arr[i] < rightLarge[i+1]`.
   - If such a triplet is found, return it.

5. **If No Valid Triplet is Found:**
   - Return an empty array.

#### Code

```cpp
vector<int> find3Numbers(vector<int> &arr) {
    int n = arr.size();
    vector<int> leftSmall(n, 0);
    vector<int> rightLarge(n, 0);

    leftSmall[0] = arr[0];
    rightLarge[n-1] = arr[n-1];

    // Fill leftSmall array
    for (int i = 1; i < n; i++) {
        leftSmall[i] = min(arr[i], leftSmall[i-1]);
    }

    // Fill rightLarge array
    for (int i = n-2; i >= 0; i--) {
        rightLarge[i] = max(arr[i], rightLarge[i + 1]);
    }

    // Find and return the valid triplet
    for (int i = 1; i <= n-2; i++) {
        if (arr[i] > leftSmall[i-1] && arr[i] < rightLarge[i+1]) {
            return {leftSmall[i-1], arr[i], rightLarge[i+1]};
        }
    }

    return {};
}
```

#### Time Complexity

- **Time Complexity:** `O(n)`  
  The array is traversed three times: twice to fill the `leftSmall` and `rightLarge` arrays, and once to find the triplet.

- **Space Complexity:** `O(n)`  
  Two auxiliary arrays of size `n` are used.

### Conclusion

- **Brute Force Approach:** This approach is simple to understand but inefficient with a time complexity of `O(n^3)`.
- **Optimized Approach:** This approach reduces the time complexity to `O(n)` by leveraging auxiliary arrays, making it more suitable for larger input sizes. However, it comes at the cost of additional space.
