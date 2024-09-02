### Edit Distance Problem

**Problem Statement:**
Given two strings, `str1` and `str2`, return the minimum number of operations required to convert `str1` to `str2`. The possible operations are:
1. Insert a character at any position of the string.
2. Remove any character from the string.
3. Replace any character from the string with any other character.

**Examples:**
- Input: `str1 = "geek"`, `str2 = "gesek"`
  - Output: `1`
  - Explanation: One operation is required, inserting 's' between the two 'e's.

### Intuition
To solve this problem, we need to consider how we can transform `str1` into `str2` step by step, using the fewest number of operations. We can use Dynamic Programming (DP) to keep track of the minimum operations required for each substring of `str1` and `str2`.

### Algorithm

1. **Define Subproblems:**
   - Let `dp[i][j]` be the minimum number of operations required to convert the first `i` characters of `str1` to the first `j` characters of `str2`.

2. **Base Cases:**
   - `dp[0][j] = j`: If `str1` is empty, we need `j` insertions to form `str2` (insert all characters of `str2`).
   - `dp[i][0] = i`: If `str2` is empty, we need `i` deletions to form an empty string (remove all characters of `str1`).

3. **Recurrence Relation:**
   - If the last characters of the current substrings are the same (`str1[i-1] == str2[j-1]`), then no new operation is needed for the last character. Hence, `dp[i][j] = dp[i-1][j-1]`.
   - Otherwise, we consider three possible operations and take the minimum:
     1. **Insert:** `dp[i][j-1] + 1`
     2. **Remove:** `dp[i-1][j] + 1`
     3. **Replace:** `dp[i-1][j-1] + 1`

4. **Implementation:**

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int editDistanceUtil(const std::string& str1, const std::string& str2, int pos1, int pos2, std::vector<std::vector<int>>& dp) {
    if (pos1 == 0) {
        return pos2;
    }
    
    if (pos2 == 0) {
        return pos1;
    }
    
    if (dp[pos1][pos2] != -1) {
        return dp[pos1][pos2];
    }
    
    if (str1[pos1 - 1] == str2[pos2 - 1]) {
        return dp[pos1][pos2] = editDistanceUtil(str1, str2, pos1 - 1, pos2 - 1, dp);
    }
    
    return dp[pos1][pos2] = std::min(editDistanceUtil(str1, str2, pos1 - 1, pos2, dp), 
               std::min(editDistanceUtil(str1, str2, pos1, pos2 - 1, dp), editDistanceUtil(str1, str2, pos1 - 1, pos2 - 1, dp))) + 1;
}

int editDistance(const std::string& str1, const std::string& str2) {
    int m = str1.size();
    int n = str2.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, -1));
    
    return editDistanceUtil(str1, str2, m, n, dp);
}

int main() {
    std::string str1 = "geek";
    std::string str2 = "gesek";
    std::cout << "Minimum Edit Distance: " << editDistance(str1, str2) << std::endl;
    return 0;
}
```

### Complexity Analysis

- **Time Complexity:** O(m * n)
  - The algorithm solves each subproblem exactly once, and there are `m * n` subproblems, where `m` is the length of `str1` and `n` is the length of `str2`.

- **Space Complexity:** O(m * n)
  - The DP table `dp` requires `m * n` space to store the results of subproblems.

By using the above algorithm, we can efficiently compute the minimum number of operations required to convert one string to another, making it a powerful approach for various text processing applications.
