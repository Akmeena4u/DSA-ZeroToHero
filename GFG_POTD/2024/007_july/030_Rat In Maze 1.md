
### Problem Statement
Given a rat placed at the top-left corner (0, 0) of an N x N matrix, the rat needs to reach the bottom-right corner (N-1, N-1). The matrix contains:
- `1` indicating the cell is open and the rat can move through it.
- `0` indicating the cell is blocked.

The rat can move in four possible directions: Up (U), Down (D), Left (L), and Right (R). The goal is to find all possible paths the rat can take to reach the destination, ensuring no cell is visited more than once, and print these paths in lexicographical order.

### Examples

**Example 1:**
- **Input:**
  ```cpp
  N = 4
  m[][] = {{1, 0, 0, 0},
           {1, 1, 0, 1}, 
           {1, 1, 0, 0},
           {0, 1, 1, 1}}
  ```
- **Output:**
  ```
  DDRDRR DRDDRR
  ```

- **Recurssive tree**
- ![image](https://github.com/user-attachments/assets/f14f21d0-8888-44a9-b58b-3c4f80db0f7b)

- **For  “DDRDRR”**
- ![image](https://github.com/user-attachments/assets/96b7ccc9-cf66-45e0-b805-1bde770235d4)


**Example 2:**
- **Input:**
  ```cpp
  N = 2
  m[][] = {{1, 0},
           {1, 0}}
  ```
- **Output:**
  ```
  No path exists and the destination cell is blocked.
  ```

### Solution Approach: Recursion

#### Intuition
Recursion is an ideal approach for solving this problem because it allows exploring all possible paths by trying all directions from each cell recursively.

#### Detailed Steps
1. **Starting Point**: Begin from the source (0, 0) with an empty path string.
2. **Directions**: Try moving in lexicographical order: Down (D), Left (L), Right (R), Up (U).
3. **Visited Array**: Use a 2D array `visited` to keep track of cells that are part of the current path to avoid revisiting them.
4. **Base Condition**: If the rat reaches the destination (N-1, N-1), add the path to the result.
5. **Backtracking**: After exploring a direction, backtrack by unmarking the cell in the `visited` array.


### Code Implementation
Here's the C++ code to solve the problem:

```cpp
class Solution {
  // Helper function to find paths recursively
  void findPathHelper(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, vector<vector<int>> &vis) {
    // If the destination is reached, add the current path to the answer list
    if (i == n - 1 && j == n - 1) {
      ans.push_back(move);
      return;
    }

    // Try moving downward
    if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1) {
      vis[i][j] = 1; // Mark the cell as visited
      findPathHelper(i + 1, j, a, n, ans, move + 'D', vis); // Recur with 'D' added to the path
      vis[i][j] = 0; // Unmark the cell as visited (backtracking)
    }

    // Try moving left
    if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1) {
      vis[i][j] = 1; // Mark the cell as visited
      findPathHelper(i, j - 1, a, n, ans, move + 'L', vis); // Recur with 'L' added to the path
      vis[i][j] = 0; // Unmark the cell as visited (backtracking)
    }

    // Try moving right
    if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1) {
      vis[i][j] = 1; // Mark the cell as visited
      findPathHelper(i, j + 1, a, n, ans, move + 'R', vis); // Recur with 'R' added to the path
      vis[i][j] = 0; // Unmark the cell as visited (backtracking)
    }

    // Try moving upward
    if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1) {
      vis[i][j] = 1; // Mark the cell as visited
      findPathHelper(i - 1, j, a, n, ans, move + 'U', vis); // Recur with 'U' added to the path
      vis[i][j] = 0; // Unmark the cell as visited (backtracking)
    }
  }
  
public:
  // Main function to find all paths from source to destination
  vector<string> findPath(vector<vector<int>> &m) {
    vector<string> ans; // Vector to store the result paths
    int n = m.size(); // Size of the matrix
    vector<vector<int>> vis(n, vector<int>(n, 0)); // Visited matrix to track visited cells

    // If the starting cell is not blocked, start the path finding
    if (m[0][0] == 1) findPathHelper(0, 0, m, n, ans, "", vis);
    return ans; // Return the list of paths
  }
};
```

### Complexity Analysis
- **Time Complexity**: `O(4^(N^2))` because in the worst case, each cell tries 4 different directions.
- **Space Complexity**: `O(N^2)` for the recursion stack and visited array.

This approach ensures that all possible paths are explored, and paths are printed in lexicographical order due to the order of direction checks.
