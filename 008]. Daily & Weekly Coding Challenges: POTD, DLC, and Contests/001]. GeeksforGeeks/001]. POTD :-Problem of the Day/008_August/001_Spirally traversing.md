### Spirally Traversing a Matrix

**Problem Statement:**
You are given a rectangular matrix. Your task is to return an array while traversing the matrix in spiral form.

**Examples:**

- **Input:** 
  ``` 
  matrix[][] = [
                [1, 2, 3, 4],
                [5, 6, 7, 8],
                [9, 10, 11, 12],
                [13, 14, 15, 16]
               ]
  ```
- **Output:** 
  ```
  [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]
  ```

### Intuition
The idea is to simulate the spiral order traversal by using four boundaries (top, bottom, left, right) and progressively moving these boundaries inward as we traverse the matrix in a spiral manner.

### Algorithm

1. **Define Result Array:**
   - Create an empty array `ans` to store the spiral order of elements.

2. **Initialize Pointers:**
   - `top`: Initially set to 0 (first row).
   - `bottom`: Initially set to `n-1` (last row).
   - `left`: Initially set to 0 (first column).
   - `right`: Initially set to `m-1` (last column).

3. **Traverse the Matrix:**
   - Use a loop that continues until `top` exceeds `bottom` or `left` exceeds `right`.
   - Traverse from left to right along the top boundary, then move the top boundary downwards.
   - Traverse from top to bottom along the right boundary, then move the right boundary leftwards.
   - If the top boundary is still within the bottom boundary, traverse from right to left along the bottom boundary, then move the bottom boundary upwards.
   - If the left boundary is still within the right boundary, traverse from bottom to top along the left boundary, then move the left boundary rightwards.

### Implementation

```cpp
#include <iostream>
#include <vector>

std::vector<int> spirallyTraverse(const std::vector<std::vector<int>>& matrix) {
    std::vector<int> ans;
    
    int n = matrix.size();    // Number of rows
    int m = matrix[0].size(); // Number of columns
    
    // Initialize pointers required for traversal.
    int top = 0, left = 0, bottom = n - 1, right = m - 1;
    
    // Loop until all elements are not traversed.
    while (top <= bottom && left <= right) {
        
        // For moving left to right
        for (int i = left; i <= right; i++)
            ans.push_back(matrix[top][i]);
        
        top++;
        
        // For moving top to bottom
        for (int i = top; i <= bottom; i++)
            ans.push_back(matrix[i][right]);
        
        right--;
        
        // For moving right to left
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                ans.push_back(matrix[bottom][i]);
            
            bottom--;
        }
        
        // For moving bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                ans.push_back(matrix[i][left]);
            
            left++;
        }
    }
    
    return ans;
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    
    std::vector<int> result = spirallyTraverse(matrix);
    
    for (int x : result)
        std::cout << x << " ";
    
    return 0;
}
```

### Complexity Analysis

- **Time Complexity:** O(m * n)
  - Each element is visited exactly once in a single pass through the matrix, making the traversal linear with respect to the total number of elements.

- **Space Complexity:** O(1) (excluding the space required for the result)
  - We only use a fixed amount of extra space for the pointers (`top`, `bottom`, `left`, `right`), so the space complexity is constant relative to the input size. However, the result array itself will take O(m * n) space to store all elements of the matrix.

By following the above approach, we can effectively traverse any rectangular matrix in spiral order and collect the elements in the desired sequence.
