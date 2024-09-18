

## Problem: Largest Number

### Problem Statement
You are given an array of non-negative integers. The task is to arrange them such that they form the largest possible number. Return this number as a string. Since the result can be very large, return it as a string.

### Examples
1. **Input:** `[3, 30, 34, 5, 9]`  
   **Output:** `"9534330"`

2. **Input:** `[10, 2]`  
   **Output:** `"210"`

3. **Input:** `[1, 20, 23, 4, 8]`  
   **Output:** `"8423201"`

### Approach

#### Greedy Approach
Initially, sorting the numbers in descending order might seem like a solution, but it doesn't always yield the largest number. For example, sorting `[3, 30, 34, 5, 9]` in descending order gives `"9534303"`, but the correct result is `"9534330"`.

#### Brute Force Approach
Generating all possible permutations of the numbers and finding the maximum concatenated result is not feasible for large arrays due to factorial growth in the number of permutations.

#### Optimal Approach
The optimal approach involves using a custom sorting mechanism:
1. **Convert Numbers to Strings:** To handle concatenation and comparison, convert each number to a string.
2. **Custom Comparator:** Define a comparator to decide the order of two numbers based on their concatenated result.
   - For two numbers represented as strings `s1` and `s2`, compare the concatenated results of `s1+s2` and `s2+s1`.
   - The order should be determined by which concatenation yields a larger number.
3. **Sort the Array:** Use the custom comparator to sort the array in the desired order.
4. **Concatenate Results:** Combine the sorted numbers to form the largest number.
5. **Handle Edge Cases:** Specifically, if the array contains only zeros, the result should be `"0"`.

### Implementation

#### LeetCode Version
```cpp
class Solution {
public:
    static bool myFunction(int a, int b) {
        string s1 = to_string(a);
        string s2 = to_string(b);
        
        // Compare concatenated results
        return (s1 + s2) > (s2 + s1);
    }

    string largestNumber(vector<int>& nums) {
        // Sort using custom comparator
        sort(nums.begin(), nums.end(), myFunction);
        
        // Edge case: if the largest number is 0
        if (nums[0] == 0) return "0";

        // Concatenate results
        string result = "";
        for (int i : nums) {
            result += to_string(i);
        }
        return result;
    }
};
```
- **Time Complexity:** `O(n log n)` (due to sorting)
- **Space Complexity:** `O(1)` (ignoring the space used by the result string)

#### GFG Version
```cpp
class Solution {
public:
    string printLargest(int n, vector<string> &arr) {
        // Custom comparator lambda function
        auto myComparator = [](string &s1, string &s2) {
            return (s1 + s2) > (s2 + s1);
        };
        
        // Sort using custom comparator
        sort(begin(arr), end(arr), myComparator);
        
        // Concatenate results
        string result = "";
        for (string &s : arr) {
            result += s;
        }
        return result;
    }
};
```
- **Time Complexity:** `O(n log n)` (due to sorting)
- **Space Complexity:** `O(1)` (ignoring the space used by the result string)

### Summary
The largest number problem requires sorting numbers based on a custom comparator that compares concatenated strings. The solutions from both LeetCode and GFG use similar approaches with custom sorting to solve the problem efficiently.

