### Problem Statement: Convert 1D Array Into 2D Array

You are given a 0-indexed 1-dimensional (1D) integer array `original`, and two integers `m` and `n`. The goal is to create a 2-dimensional (2D) array with `m` rows and `n` columns using all the elements from `original`.

The construction of the 2D array should be done as follows:
- Elements from indices `0` to `n - 1` (inclusive) of `original` form the first row of the 2D array.
- Elements from indices `n` to `2 * n - 1` (inclusive) form the second row of the 2D array.
- Continue this pattern until the array is filled.

If it is not possible to construct such a 2D array, return an empty 2D array.

**Example 1:**

**Input:**
```plaintext
original = [1, 2, 3, 4], m = 2, n = 2
```

**Output:**
```plaintext
[[1, 2], [3, 4]]
```

**Explanation:**
The constructed 2D array should contain 2 rows and 2 columns:
- The first `n=2` elements of `original`, `[1, 2]`, become the first row.
- The next `n=2` elements of `original`, `[3, 4]`, become the second row.

### Approach 1: Using Nested Loops

**Description:**
- Utilizes two nested loops to iterate over the rows and columns of the 2D array.
- Maintains an index `idx` to access elements sequentially from the 1D array.

**Code:**
```cpp
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> result(m, vector<int>(n));
        int l = original.size();

        if (m * n != l) {
            return {}; // If the total number of elements doesn't match m * n, return an empty array
        }

        int idx = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = original[idx];
                idx++;
            }
        }

        return result;
    }
};
```

**Time Complexity:** `O(m * n)`

**Space Complexity:** `O(m * n)` (for the result array)

### Approach 2: Using Single Loop with Division/Modulus

**Description:**
- Utilizes a single loop and calculates the row index as `i / n` and the column index as `i % n` to place elements directly into the 2D array.

**Code:**
```cpp
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> result(m, vector<int>(n));
        int l = original.size();

        if (m * n != l) {
            return {}; // If the total number of elements doesn't match m * n, return an empty array
        }

        for (int i = 0; i < l; i++) {
            result[i / n][i % n] = original[i];
        }

        return result;
    }
};
```

**Time Complexity:** `O(m * n)`

**Space Complexity:** `O(m * n)` (for the result array)

### Key Points to Remember:

- **Validation:** Both approaches start by checking if the total number of elements in `original` matches `m * n`. If not, an empty 2D array is returned.
- **Efficiency:** The first approach uses nested loops for iteration, while the second approach uses a single loop with mathematical operations, which can be more efficient.
- **Complexity:** Both methods have the same time and space complexity of `O(m * n)` due to the need to traverse and fill the result array.

