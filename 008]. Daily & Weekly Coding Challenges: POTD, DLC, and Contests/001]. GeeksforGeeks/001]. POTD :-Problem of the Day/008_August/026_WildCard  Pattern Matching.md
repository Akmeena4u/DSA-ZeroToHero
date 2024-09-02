### Wildcard Pattern Matching

#### **Problem Explanation**
You are given a pattern and a string. The pattern can contain the following special characters:
- `?` which matches any single character.
- `*` which matches any sequence of characters (including an empty sequence).

The goal is to determine if the given pattern matches the given string.

#### **Approach**
To solve this problem, we use a recursive approach with memoization. We define a recursive function `help` that explores all possible matches between the pattern and the string. 

**Key Steps**:
1. **Base Cases**:
   - If both the pattern and the string are fully matched, return `1`.
   - If the pattern is exhausted but the string is not, return `0`.
   - If the string is exhausted and the current pattern character is `*`, try matching the remaining pattern with the same string index.
   - If the string is exhausted and the current pattern character is not `*`, return `0`.

2. **Character Matching**:
   - If the current characters do not match and the pattern character is neither `?` nor `*`, return `0`.

3. **Recursive Cases**:
   - If the pattern character is `*`, consider:
     - Matching `*` with zero characters by moving to the next pattern character.
     - Matching `*` with one or more characters by moving to the next character in the string.
   - If the pattern character is `?` or matches the current string character, proceed to match the remaining characters in both the pattern and the string.

4. **Memoization**:
   - Use a 2D array `dp` to store results of subproblems to avoid redundant computations.

#### **Code**

```cpp
int help(string pattern, string str, int i, int j, vector<vector<int>> &dp) {
    // If both pattern and string are fully matched, return 1 (true)
    if (i == pattern.length() && j == str.length()) return 1;
    
    // If pattern is exhausted but string is not, return 0 (false)
    if (i == pattern.length()) return 0;
    
    // If string is exhausted and the current pattern character is '*',
    // try to match the remaining pattern with the same string index
    if (j == str.length() && pattern[i] == '*') return help(pattern, str, i + 1, j, dp);
    
    // If string is exhausted and the pattern is not '*' or it is
    // the end of the pattern, return 0 (false)
    if (j == str.length()) return 0;
    
    // If the current pattern character is neither '?', '*' nor matches the current string character, return 0 (false)
    if (pattern[i] != '?' && pattern[i] != '*' && pattern[i] != str[j]) return 0;
    
    // If the result for this state is already computed, return it from the memoization table
    if (dp[i][j] != -1) return dp[i][j];
    
    // Initialize variables to store results of different recursive calls
    int a = 0, b = 0, c = 0;
    
    // If the current pattern character is '*', consider both possibilities:
    // 1. '*' matches zero characters (move to the next pattern character)
    // 2. '*' matches one or more characters (move to the next string character)
    if (pattern[i] == '*') {
        a = help(pattern, str, i + 1, j, dp); // Matching '*' with zero characters
        b = help(pattern, str, i, j + 1, dp); // Matching '*' with one or more characters
    }
    
    // If the current pattern character is '?' or matches the current string character,
    // proceed to match the remaining pattern and string characters
    c = help(pattern, str, i + 1, j + 1, dp);
    
    // Store the result in the memoization table and return it
    return dp[i][j] = a | b | c;
}

/* Main Function to check if the pattern matches the string */
int wildCard(string pattern, string str) {
    // Initialize the memoization table with -1 (indicating uncomputed states)
    vector<vector<int>> dp(pattern.length(), vector<int>(str.length(), -1));
    
    // Start the recursive function from the beginning of the pattern and string
    return help(pattern, str, 0, 0, dp);
}
```

#### **Dry Run**

**Example**:
- Pattern: `a*b`
- String: `aaab`

1. **Initial Call**: `help("a*b", "aaab", 0, 0, dp)`

2. **Matching `a` with `a`**:
   - Both match, move to the next pattern and string: `help("a*b", "aaab", 1, 1, dp)`

3. **Pattern Character `*`**:
   - Consider matching `*` with zero characters: `help("a*b", "aaab", 2, 1, dp)`
   - Consider matching `*` with one or more characters: `help("a*b", "aaab", 1, 2, dp)`

4. **Pattern Character `b`**:
   - Once `*` has matched all characters, try matching `b` with the last character in the string.

5. **Final Match**:
   - If the recursive calls lead to the end of the string and the pattern, return `1`.

#### **Complexity Analysis**

- **Time Complexity**:
  - The recursive function explores all combinations of pattern and string indices. With memoization, the time complexity is reduced to \(O(m \times n)\), where \(m\) is the length of the pattern and \(n\) is the length of the string.

- **Space Complexity**:
  - The space complexity is \(O(m \times n)\) due to the memoization table `dp` used to store results of subproblems.
