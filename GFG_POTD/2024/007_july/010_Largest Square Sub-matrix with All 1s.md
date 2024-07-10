### Finding the Largest Square Sub-matrix with All 1s

#### Problem Statement:
Given a binary matrix `mat` of size `n * m`, find out the maximum length of a side of a square sub-matrix with all 1s.

#### Example:
Input: 
```cpp
n = 6, m = 5
mat = [[0, 1, 1, 0, 1], 
       [1, 1, 0, 1, 0],
       [0, 1, 1, 1, 0],
       [1, 1, 1, 1, 0],
       [1, 1, 1, 1, 1],
       [0, 0, 0, 0, 0]]
```
Output: 
```
3
```
Explanation: The maximum length of a side of the square sub-matrix is 3 where every element is 1.

#### Solution:
We will use a dynamic programming approach to solve this problem. The idea is to create a 2D `dp` array where `dp[i][j]` represents the size of the largest square sub-matrix ending at cell `(i, j)`.

1. **Base Case**:
   - If `i` or `j` are out of bounds, return 0.
   
2. **Recursive Case**:
   - Calculate the size of the largest square sub-matrix by exploring the right, diagonal, and down cells.
   - If the current cell `mat[i][j]` is 1, the size of the square sub-matrix ending at `(i, j)` is 1 plus the minimum of the sizes from the right, diagonal, and down cells.
   - Update the maximum size (`maxi`) of the square.

3. **Memoization**:
   - Use a 2D `dp` array to store the results of subproblems to avoid redundant computations.

#### Code with Comments:

```cpp
// Function to solve the problem of finding the largest square of 1s in the matrix
int solve(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp) {
    // Base case: If the indices are out of bounds, return 0
    if(i >= mat.size() || j >= mat[0].size()) {
        return 0;
    }

    // If the result for this cell is already computed, return it
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    // Recursive case: Compute the size of the largest square by exploring right, diagonal, and down cells
    int right = solve(mat, i, j + 1, maxi, dp);
    int diagonal = solve(mat, i + 1, j + 1, maxi, dp);
    int down = solve(mat, i + 1, j, maxi, dp);

    // If the current cell is 1, calculate the size of the square
    if(mat[i][j] == 1) {
        dp[i][j] = 1 + min(right, min(diagonal, down));
        // Update the maximum size of the square
        maxi = max(maxi, dp[i][j]);
        return dp[i][j];
    } else {
        // If the current cell is 0, it can't be part of a square, so return 0
        return dp[i][j] = 0;
    }
}

// Function to find the largest square of 1s in the matrix
int maxSquare(int n, int m, vector<vector<int>> mat) {
    // Initialize the maximum size to 0
    int maxi = 0;
    // Initialize the dp array with -1 (indicating uncomputed results)
    vector<vector<int>> dp(n, vector<int>(m, -1));
    // Call the solve function starting from the top-left cell
    solve(mat, 0, 0, maxi, dp);
    // Return the maximum size of the square
    return maxi;
}
```

### Explanation of the Code:

1. **Base Case**:
   - The base case checks if the indices `i` or `j` are out of bounds. If so, it returns 0 because no square sub-matrix can be formed.

2. **Memoization**:
   - Before performing any computation, we check if the value for `dp[i][j]` is already computed. If it is, we return that value.

3. **Recursive Case**:
   - We recursively calculate the size of the largest square sub-matrix by exploring the cells to the right (`j + 1`), diagonal (`i + 1, j + 1`), and down (`i + 1`).
   - If the current cell `mat[i][j]` is 1, we update `dp[i][j]` to be 1 plus the minimum of the values from the right, diagonal, and down cells.
   - We also update the maximum size (`maxi`) of the square found so far.

4. **Main Function**:
   - We initialize the `dp` array with -1 to indicate that no values have been computed yet.
   - We call the `solve` function starting from the top-left cell `(0, 0)`.
   - Finally, we return the maximum size of the square found.

This approach ensures that we efficiently compute the largest square sub-matrix with all 1s in the given binary matrix using dynamic programming.
