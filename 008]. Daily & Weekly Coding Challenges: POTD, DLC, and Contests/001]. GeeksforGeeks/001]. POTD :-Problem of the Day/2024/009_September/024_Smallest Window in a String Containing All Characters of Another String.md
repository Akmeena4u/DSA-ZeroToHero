### Problem: **Smallest Window in a String Containing All Characters of Another String**

You are given two strings, `s` and `p`. The task is to find the smallest window (substring) in string `s` that contains all the characters of string `p` (including duplicates). If no such window exists, return `-1`. If there are multiple windows of the same length, return the one that starts at the smallest index.

### Key Points:
1. The window must contain **all characters** of string `p`, including duplicates.
2. The goal is to find the **smallest window**.
3. If no such window is found, return `-1`.

### Approach:

To solve the problem, we can use a **sliding window approach** with two pointers. The idea is to expand the window by moving the right pointer and to shrink it from the left until we find a valid window containing all characters of `p`.

### Steps:
1. **Hashing for Character Frequency:**
   - We'll maintain frequency counts for both the characters in string `p` and the current window of `s`.
   
2. **Sliding Window Logic:**
   - Expand the window by moving the right pointer and adding characters to the window.
   - Once the window contains all characters of `p`, try to shrink the window from the left to get the smallest valid window.
   
3. **Edge Case:**
   - If `p` is longer than `s`, return `-1` because it's impossible to find such a window.

### Code Explanation:

```cpp
string smallestWindow (string s, string p) {
    // Step 1: Edge case check - if p is longer than s, return "-1"
    if (p.length() > s.length()) return "-1";
    
    int n = s.length(), m = p.length();    // n: length of s, m: length of p
    int start = -1, end = -1;              // To store the start and end of the smallest window
    int len = INT_MAX;                     // Store the length of the smallest window
    int uniqueCharsInP = 0, matchCount = 0;// uniqueCharsInP: distinct chars in p, matchCount: chars matched in the window
    int left = 0;                          // Left pointer of the window
    
    // Step 2: Frequency maps for characters in s and p (only lowercase letters)
    vector<int> freqS(26, 0), freqP(26, 0);
    
    // Step 3: Fill the frequency map for string p
    for (int i = 0; i < m; i++) {
        freqP[p[i] - 'a']++;
        if (freqP[p[i] - 'a'] == 1) uniqueCharsInP++;  // Count distinct characters in p
    }
    
    // Step 4: Sliding window approach to find the smallest window
    for (int right = 0; right < n; right++) {
        // Expand the window by adding the current character s[right] to freqS
        freqS[s[right] - 'a']++;
        
        // If the current character count in window matches the frequency in p, increment matchCount
        if (freqS[s[right] - 'a'] == freqP[s[right] - 'a']) matchCount++;
        
        // When the window has all characters of p (matchCount == uniqueCharsInP)
        if (matchCount == uniqueCharsInP) {
            // Try to minimize the window by moving the left pointer
            while (freqS[s[left] - 'a'] > freqP[s[left] - 'a']) {
                freqS[s[left] - 'a']--;    // Decrease the count of the character and move the left pointer
                left++;
            }
            
            // Step 5: Update the result if the current window is smaller
            if (len > right - left + 1) {
                start = left;
                end = right;
                len = right - left + 1;
            }
        }
    }
    
    // Step 6: If no valid window is found, return "-1". Otherwise, return the smallest window substring
    if (start == -1) return "-1";
    return s.substr(start, len);
}
```

### Code Comments:

1. **Initial Edge Case:**
   - Check if `p` is longer than `s`. If yes, return `-1` since it's impossible to find a window.

2. **Frequency Maps:**
   - `freqP` stores the frequency of each character in `p`.
   - `freqS` tracks the frequency of characters in the current window of `s`.
   - The size of the frequency array is 26 since all characters are lowercase.

3. **Count of Unique Characters:**
   - `uniqueCharsInP`: Stores the count of distinct characters in `p` that we need to match in the window.
   - `matchCount`: Keeps track of how many characters from `p` are fully matched in the window.

4. **Expanding and Shrinking the Window:**
   - The right pointer expands the window by adding characters to `freqS`.
   - The left pointer tries to shrink the window to ensure it's the smallest possible valid window.

5. **Updating the Smallest Window:**
   - If the current window is valid (i.e., contains all characters of `p`), check if it's smaller than the previously found windows. If yes, update the starting and ending indices.

6. **Returning the Result:**
   - If no valid window is found (`start == -1`), return `-1`. Otherwise, return the substring starting at `start` with the length `len`.

### Time Complexity:
- **O(n)** where `n` is the length of `s`. We traverse the string `s` once with the sliding window technique.
  
### Space Complexity:
- **O(1)** because we are using fixed-size arrays of length 26 for character frequencies.

### Example Walkthrough:

**Example 1:**
```plaintext
Input: s = "timetopractice", p = "toc"
Output: "toprac"
Explanation: "toprac" is the smallest window that contains all characters of "toc".
```

In this example:
- We move the right pointer, expanding the window until it contains all characters of `p`.
- Then, we try to shrink the window from the left to minimize its length while ensuring it still contains all characters of `p`.

---

This approach effectively handles the problem using a sliding window technique with a time complexity of O(n), which is optimal for this type of problem.
