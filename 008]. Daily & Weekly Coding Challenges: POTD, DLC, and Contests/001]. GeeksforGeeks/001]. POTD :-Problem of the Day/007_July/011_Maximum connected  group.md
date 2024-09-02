
### Problem Explanation:
You're given a square binary grid where each cell is either 0 or 1. You can change at most one '0' to '1' to maximize the size of the connected group of '1's in the grid. Two cells are considered connected if they are adjacent vertically or horizontally and have the same value.

### Example Walkthrough:
**Example 1:**
Input:
```
[1, 1]
[0, 1]
```
Output: 4

Explanation:
By changing cell (2,1) from '0' to '1', you can form a connected group of 4 '1's:
```
[1, 1]
[1, 1]
```

**Example 2:**
Input:
```
[1, 0, 1]
[1, 0, 1]
[1, 0, 1]
```
Output: 7

Explanation:
By changing cell (3,2) from '0' to '1', you can form a connected group of 7 '1's:
```
[1, 0, 1]
[1, 0, 1]
[1, 1, 1]
```
### Intuition
The intuition behind this solution revolves around using Depth-First Search (DFS) to explore and count connected components of '1's in the grid, then leveraging this information to determine the maximum size of connected groups achievable by changing one '0' to '1'.

### Solution Approach:
1. **DFS for Connected Components:** We use Depth-First Search (DFS) to find all connected components of '1's in the grid. Each component is assigned a unique index starting from 2.
   
2. **Store Component Sizes:** As we traverse the grid, we use a map (`mp`) to store the size of each connected component indexed by its assigned index.

3. **Check Adjacent '0's:** For every '0' found in the grid, we check its adjacent '1's using a set (`s`) to avoid counting the same connected component multiple times. We sum up the sizes of all unique adjacent components and add 1 (to count the '0' itself).

4. **Track Maximum Size:** Throughout the process, we keep track of the maximum size of connected components that can be achieved by changing one '0' to '1'.

### Detailed Code Explanation:
```cpp
class Solution {
public:
    // Helper function for DFS to calculate size of connected component
    int dfs(vector<vector<int>>& grid, int i, int j, int index) {
        int n = grid.size();
        // Base case for out of bounds or non-1 cell
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) {
            return 0;
        }
        // Mark the cell as visited (by changing it to 'index')
        grid[i][j] = index;
        // Recursively count this cell and its connected neighbors
        int count = dfs(grid, i + 1, j, index) +
                    dfs(grid, i - 1, j, index) +
                    dfs(grid, i, j + 1, index) +
                    dfs(grid, i, j - 1, index);
        // Include the current cell in the count
        return count + 1;
    }
    
    // Helper function to find unique connected neighbors of a '0' cell
    void neighbours(vector<vector<int>>& grid, int i, int j, set<int>& s) {
        int n = grid.size();
        // Check all four directions and insert the connected component index into set
        if (i > 0) {
            s.insert(grid[i - 1][j]);
        }
        if (j > 0) {
            s.insert(grid[i][j - 1]);
        }
        if (i < n - 1) {
            s.insert(grid[i + 1][j]);
        }
        if (j < n - 1) {
            s.insert(grid[i][j + 1]);
        }
    }
    
    // Main function to calculate the maximum connected group size
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = 0;
        int index = 2; // Start index for connected components
        
        // Map to store size of each connected component
        map<int, int> mp;
        
        // Step 1: DFS to find all connected components and store their sizes
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    mp[index] = dfs(grid, i, j, index);
                    res = max(res, mp[index]);
                    ++index; // Increment index for next component
                }
            }
        }
        
        // Step 2: Check each '0' cell and find the maximum connected group size by changing it to '1'
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    set<int> s;
                    neighbours(grid, i, j, s);
                    int count = 1; // Start count with 1 (for the '0' cell itself)
                    for (int idx : s) {
                        count += mp[idx]; // Add size of each unique connected component
                    }
                    res = max(res, count);
                }
            }
        }
        
        return res;
    }
};
```

### Summary:
This solution efficiently uses DFS to explore and count connected components of '1's in the grid. It then checks each '0' cell to compute the maximum connected group size achievable by changing it to '1', ensuring all constraints and edge cases are handled within the specified time and space complexities.
