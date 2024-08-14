### Longest Common Substring

#### Problem Statement
Given two strings `str1` and `str2`, the task is to find the length of the longest common substring between the two strings.

- **Input**: Two strings, `str1` and `str2`.
- **Output**: Length of the longest common substring.

#### Example

- **Input**: 
  - `str1 = "ABCDGH"`
  - `str2 = "ACDGHR"`
- **Output**: `4`
  - **Explanation**: The longest common substring is `"CDGH"`, which has a length of `4`.

#### Problem Pattern
This problem can be solved using Dynamic Programming (DP), specifically the pattern of solving problems related to substrings or subsequences in two strings.

The idea is to create a 2D DP table where:
- `dp[i][j]` represents the length of the longest common substring ending at `str1[i-1]` and `str2[j-1]`.

### Intuition
To solve this problem, we need to explore all possible substrings of the given two strings. However, instead of generating all substrings and checking for commonality (which would be inefficient), we can use dynamic programming to build up the solution incrementally.

### Algorithm
1. **Initialize DP Table**: Create a 2D DP table `dp` with dimensions `(n+1) x (m+1)` where `n` is the length of `str1` and `m` is the length of `str2`. Initialize all values in `dp` to `0`. Also, initialize a variable `maxi` to keep track of the maximum length of the common substring found.

2. **Iterate through Strings**: Loop through each character of `str1` and `str2` using indices `i` and `j`.

3. **DP Relation**: 
   - If `str1[i-1]` is equal to `str2[j-1]`, then the characters match, and we can extend the common substring by 1. This is captured by `dp[i][j] = 1 + dp[i-1][j-1]`.
   - If the characters don't match, we reset the value of `dp[i][j]` to `0` since a common substring can't continue.

4. **Update Maximum Length**: Update `maxi` with the maximum value found in `dp[i][j]`.

5. **Return Result**: After filling the DP table, `maxi` will hold the length of the longest common substring.

### Code Implementation

```cpp
int longestCommonSubstr(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();
    int maxi = 0;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                maxi = max(maxi, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return maxi;
}
```

##### Let's go through a detailed dry run of the code using the given example:

### Dry Run Example

**Input:**
- `str1 = "ABCDGH"`
- `str2 = "ACDGHR"`

We need to find the length of the longest common substring between `str1` and `str2`.

### Step-by-Step Execution

1. **Initialization:**
   - `n = 6` (length of `str1`)
   - `m = 6` (length of `str2`)
   - `maxi = 0` (to keep track of the maximum length of the common substring)
   - `dp = vector<vector<int>>(7, vector<int>(7, 0))` (a 7x7 table initialized with zeros)

   Initially, the `dp` table looks like this:

   ```
       0  A  C  D  G  H  R
     0 0  0  0  0  0  0  0
   A 0 0  0  0  0  0  0  0
   B 0 0  0  0  0  0  0  0
   C 0 0  0  0  0  0  0  0
   D 0 0  0  0  0  0  0  0
   G 0 0  0  0  0  0  0  0
   H 0 0  0  0  0  0  0  0
   ```

2. **First Iteration (`i = 1`):**
   - Comparing `str1[0] = 'A'` with each character of `str2`.
   - `j = 1`: `str1[0] == str2[0]` → Both are `'A'`.
     - `dp[1][1] = 1 + dp[0][0] = 1`
     - `maxi = max(maxi, dp[1][1]) = max(0, 1) = 1`
   - `j = 2` to `j = 6`: Characters do not match, so `dp[1][2]` to `dp[1][6]` remain `0`.

   After the first iteration, the `dp` table is:

   ```
       0  A  C  D  G  H  R
     0 0  0  0  0  0  0  0
   A 0 1  0  0  0  0  0  0
   B 0 0  0  0  0  0  0  0
   C 0 0  0  0  0  0  0  0
   D 0 0  0  0  0  0  0  0
   G 0 0  0  0  0  0  0  0
   H 0 0  0  0  0  0  0  0
   ```

3. **Second Iteration (`i = 2`):**
   - Comparing `str1[1] = 'B'` with each character of `str2`.
   - `j = 1`: `str1[1] != str2[0]` → `'B'` is not equal to `'A'`.
   - `j = 2` to `j = 6`: Characters do not match, so `dp[2][1]` to `dp[2][6]` remain `0`.

   After the second iteration, the `dp` table remains unchanged:

   ```
       0  A  C  D  G  H  R
     0 0  0  0  0  0  0  0
   A 0 1  0  0  0  0  0  0
   B 0 0  0  0  0  0  0  0
   C 0 0  0  0  0  0  0  0
   D 0 0  0  0  0  0  0  0
   G 0 0  0  0  0  0  0  0
   H 0 0  0  0  0  0  0  0
   ```

4. **Third Iteration (`i = 3`):**
   - Comparing `str1[2] = 'C'` with each character of `str2`.
   - `j = 2`: `str1[2] == str2[1]` → Both are `'C'`.
     - `dp[3][2] = 1 + dp[2][1] = 1`
     - `maxi = max(maxi, dp[3][2]) = max(1, 1) = 1`
   - `j = 3` to `j = 6`: Characters do not match, so `dp[3][3]` to `dp[3][6]` remain `0`.

   After the third iteration, the `dp` table updates as:

   ```
       0  A  C  D  G  H  R
     0 0  0  0  0  0  0  0
   A 0 1  0  0  0  0  0  0
   B 0 0  0  0  0  0  0  0
   C 0 0  1  0  0  0  0  0
   D 0 0  0  0  0  0  0  0
   G 0 0  0  0  0  0  0  0
   H 0 0  0  0  0  0  0  0
   ```

5. **Fourth Iteration (`i = 4`):**
   - Comparing `str1[3] = 'D'` with each character of `str2`.
   - `j = 3`: `str1[3] == str2[2]` → Both are `'D'`.
     - `dp[4][3] = 1 + dp[3][2] = 2`
     - `maxi = max(maxi, dp[4][3]) = max(1, 2) = 2`
   - `j = 4` to `j = 6`: Characters do not match, so `dp[4][4]` to `dp[4][6]` remain `0`.

   After the fourth iteration, the `dp` table updates as:

   ```
       0  A  C  D  G  H  R
     0 0  0  0  0  0  0  0
   A 0 1  0  0  0  0  0  0
   B 0 0  0  0  0  0  0  0
   C 0 0  1  0  0  0  0  0
   D 0 0  0  2  0  0  0  0
   G 0 0  0  0  0  0  0  0
   H 0 0  0  0  0  0  0  0
   ```

6. **Fifth Iteration (`i = 5`):**
   - Comparing `str1[4] = 'G'` with each character of `str2`.
   - `j = 4`: `str1[4] == str2[3]` → Both are `'G'`.
     - `dp[5][4] = 1 + dp[4][3] = 3`
     - `maxi = max(maxi, dp[5][4]) = max(2, 3) = 3`
   - `j = 5` to `j = 6`: Characters do not match, so `dp[5][5]` to `dp[5][6]` remain `0`.

   After the fifth iteration, the `dp` table updates as:

   ```
       0  A  C  D  G  H  R
     0 0  0  0  0  0  0  0
   A 0 1  0  0  0  0  0  0
   B 0 0  0  0  0  0  0

  0
   C 0 0  1  0  0  0  0  0
   D 0 0  0  2  0  0  0  0
   G 0 0  0  0  3  0  0  0
   H 0 0  0  0  0  0  0  0
   ```

7. **Sixth Iteration (`i = 6`):**
   - Comparing `str1[5] = 'H'` with each character of `str2`.
   - `j = 5`: `str1[5] == str2[4]` → Both are `'H'`.
     - `dp[6][5] = 1 + dp[5][4] = 4`
     - `maxi = max(maxi, dp[6][5]) = max(3, 4) = 4`
   - `j = 6`: `str1[5] != str2[5]` → `'H'` is not equal to `'R'`.

   After the sixth iteration, the `dp` table updates as:

   ```
       0  A  C  D  G  H  R
     0 0  0  0  0  0  0  0
   A 0 1  0  0  0  0  0  0
   B 0 0  0  0  0  0  0  0
   C 0 0  1  0  0  0  0  0
   D 0 0  0  2  0  0  0  0
   G 0 0  0  0  3  0  0  0
   H 0 0  0  0  0  4  0  0
   ```
```
### Final Result:
- The length of the longest common substring is `maxi = 4`, corresponding to the substring `"CDGH"`.

This dry run shows how the dynamic programming table is filled step by step and how the `maxi` variable is updated to reflect the length of the longest common substring found so far.


### Complexity Analysis

- **Time Complexity**: `O(n * m)` where `n` is the length of `str1` and `m` is the length of `str2`. We are iterating over every cell in the DP table.
  
- **Space Complexity**: `O(n * m)` for storing the DP table. 

This approach efficiently finds the length of the longest common substring by using dynamic programming, making it a robust solution for this problem.
