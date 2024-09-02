
### Problem Summary
Given a two-dimensional integer array `arr` of dimensions `n x n`, consisting solely of zeros and ones, identify the row or column where all elements form a palindrome. The solution should prioritize palindromes in rows over those in columns. If multiple palindromes are identified, the one with the smaller index takes precedence. The output should be the index followed by either 'R' or 'C'. If no palindrome is found, return the string `-1`.

### Key Points
- **Palindrome Check**: A sequence is a palindrome if it reads the same backward as forward.
- **Priority**: Rows are prioritized over columns.
- **Index Precedence**: The smallest index palindrome is chosen.

### Constraints
- Array size `1 <= arr.size <= 50`
- Elements `0 <= arr[i][j] <= 1`
- Expected Time Complexity: `O(n^2)`
- Expected Auxiliary Space: `O(1)`

### Approach
1. **Palindrome Function**: 
   - Check if a given array of integers is a palindrome.
   - Iterate from the start to the middle of the array and compare elements symmetrically.

2. **Row Check**:
   - Iterate through each row.
   - Extract the row into a temporary array.
   - Use the palindrome function to check if the row is a palindrome.
   - If a palindrome is found, return the index with 'R'.

3. **Column Check**:
   - Iterate through each column.
   - Extract the column into a temporary array.
   - Use the palindrome function to check if the column is a palindrome.
   - If a palindrome is found, return the index with 'C'.

4. **No Palindrome**:
   - If no palindrome is found in either rows or columns, return `-1`.

### Implementation
Here's the complete implementation in C++:

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool palindrome(int arr[], int n) {
        for (int i = 0; i < n / 2; i++) {
            if (arr[i] != arr[n - 1 - i]) {
                return false;
            }
        }
        return true;
    }

    string pattern(vector<vector<int>> &arr) {
        int n = arr.size();
        string ans = "-1";
        
        // Check rows for palindrome
        for (int i = 0; i < n; i++) {
            int currRow[n];
            for (int j = 0; j < n; j++) {
                currRow[j] = arr[i][j];
            }
            if (palindrome(currRow, n)) {
                return to_string(i) + " R";
            }
        }
        
        // Check columns for palindrome
        for (int j = 0; j < n; j++) {
            int currCol[n];
            for (int i = 0; i < n; i++) {
                currCol[i] = arr[i][j];
            }
            if (palindrome(currCol, n)) {
                return to_string(j) + " C";
            }
        }
        
        return ans;
    }
};

int main() {
    int t, n, i, j;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
```

### Explanation
- **Palindrome Function**: `palindrome(int arr[], int n)` checks if an array `arr` of length `n` is a palindrome.
- **Pattern Function**: `pattern(vector<vector<int>> &arr)` checks each row first, then each column for palindromes, and returns the appropriate index and character.
- **Main Function**: Handles multiple test cases, reads input, and calls the pattern function.

This solution ensures that the problem constraints are met and prioritizes rows over columns and smaller indices as required.
