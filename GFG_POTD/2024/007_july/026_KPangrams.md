### K-Pangrams Problem

**Problem Statement:**
Given a string `str` and an integer `k`, determine if the string can be transformed into a pangram after performing at most `k` operations. A pangram is a sentence that contains every letter of the English alphabet at least once. Each operation consists of swapping an existing alphabetic character with any other alphabetic character.

**Examples:**
1. **Input:** `str = "the quick brown fox jumps over the lazy dog", k = 0`
   **Output:** `true`
   **Explanation:** The sentence already contains all 26 characters and is a pangram.

**Intuition:**
To determine if the given string can become a pangram with up to `k` character swaps, we need to:
1. Count the distinct alphabetic characters in the string.
2. Calculate how many unique characters are missing to form a complete set of 26 letters.
3. Check if the allowed number of swaps (`k`) is sufficient to introduce the missing characters.

**Algorithm:**
1. **Initialize Variables:**
   - `len` to count the number of alphabetic characters in the string.
   - `mp` (unordered_map) to store the frequency of each character in the string.

2. **Populate the Map:**
   - Traverse through the string.
   - For each alphabetic character (excluding spaces), increment its count in the map and increase the `len` counter.

3. **Check Conditions:**
   - If `len` is less than 26, return `false` (not enough characters to form a pangram).
   - If the map size (`mp.size()`) is 26, return `true` (already a pangram).
   - Calculate the number of missing characters (`req`) needed to make it a pangram: `req = 26 - mp.size()`.

4. **Determine Feasibility:**
   - If the number of possible swaps (`len - mp.size()`) is greater than or equal to `req` and `req` is less than or equal to `k`, return `true`.
   - Otherwise, return `false`.

**Code:**
```cpp
bool kPangram(string str, int k) {
    int len = 0;
    unordered_map<char, int> mp;

    // Count frequency of each character and total alphabetic characters
    for (auto c : str) {
        if (c != ' ') {
            mp[c]++;
            len++;
        }
    }

    // If less than 26 alphabetic characters, can't form a pangram
    if (len < 26) return false;

    // If all 26 characters are already present, it's a pangram
    if (mp.size() == 26) return true;

    // Calculate required characters to form a pangram
    int req = 26 - mp.size();

    // Check if we can make the string a pangram with at most k swaps
    if ((len - mp.size() >= req) && (req <= k)) return true;

    return false;
}
```

**Complexity Analysis:**
- **Time Complexity:** `O(n)`, where `n` is the length of the string. This is due to a single pass through the string to count characters.
- **Space Complexity:** `O(1)`, since the size of the unordered map is fixed (at most 26 characters).

**Pattern:**
- **Hashing Pattern:** This problem uses a hash map (unordered_map) to count the frequency of characters and track distinct characters efficiently.
- **Greedy Algorithm:** The approach determines the minimum number of swaps needed and checks if it is within the allowed limit (`k`).

This detailed breakdown ensures a clear understanding of the problem, the logic behind the solution, the step-by-step algorithm, and the complexity involved.
