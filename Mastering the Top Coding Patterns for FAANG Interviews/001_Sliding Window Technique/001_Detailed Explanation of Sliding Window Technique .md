## Coding Patterns

All software engineers should learn coding patterns like Sliding Window, Two Pointers, Two Heaps, and more. Whether you're a beginner or seasoned coder, these patterns will empower you to tackle complex problems with confidence and precision. Let's dive in and discover the key to success in FAANG interviews!

## The Sliding Window Pattern

### Sliding Window Technique Explanation and Example





### Introduction
- The sliding window technique is a powerful tool used in computational problems, especially in coding interviews. It helps in efficiently solving problems involving arrays, linked lists, and sometimes strings. The technique involves using a window that slides over the data to perform computations, making it more efficient than brute force approaches.
- The Sliding Window pattern is an extension of the two-pointer approach using left and right pointers to create a "window." This pattern is used to find the maximum or minimum subrange that satisfies a given condition by expanding and contracting our "window" to find the optimal range.
-  It helps reduce the time complexity of algorithms from O(N²) or O(N³) to O(N) by converting two nested loops into a single loop.
-  



### Real-Life Analogy
Imagine you have a rusty iron chain that you want to paint. One inefficient way is to pour paint over the entire chain, wasting a lot of paint. A better approach is to use a paintbrush to paint sections of the chain, one at a time. This method is akin to the sliding window technique where a fixed-size window (paintbrush) is used to process the data (chain).

## Key Applications

1. **Running Average**: Efficiently calculate the average of a fixed-size window as new elements arrive in a data stream.
2. **Formulating Adjacent Pairs**: Process adjacent pairs of elements in an ordered data structure, allowing easy access and operation on neighboring elements.
3. **Target Value Identification**: Find a specific target value or combination of values in an array by adjusting the window size and searching efficiently.
4. **Longest/Shortest/Most Optimal Sequence**: Find the longest, shortest, or most optimal sequence that satisfies a given condition in a collection.

### Types of Problems Well-Suited for Sliding Window
The Sliding Window pattern is particularly effective for problems that require the examination of a continuous subset of elements within an array or string, where the subset size is either fixed or variable but defined by certain constraints. This pattern helps to optimize the solution, often reducing the time complexity from O(N²) to O(N). Here are types of problems that are well-suited for the sliding window approach:

1. **Maximum/Minimum Subarray Problems**: Problems that ask for the maximum or minimum sum/value of subarrays of a fixed size.
   - Example: "Find the maximum sum of any contiguous subarray of size k."

2. **Subarray/Substring with Given Sum/Condition**: Finding a contiguous subarray or substring that meets a specific condition, like a certain sum.
   - Example: "Find the longest substring with at most k distinct characters."

3. **String Permutation/Subsequence Problems**: Checking if a string contains a permutation or subsequence of another string.
   - Example: "Check if a string has all the characters of another string (anagram)."

4. **Optimal Utilization Problems**: Problems where you need to find the optimal utilization of resources within a range.
   - Example: "Find the longest subarray with a sum less than or equal to k."

5. **Character Counting Problems in Strings**: Problems that involve counting characters within a substring and meeting certain constraints.
   - Example: "Find the smallest substring containing all characters of another string."

6. **K-sized Window Problems**: Problems that specifically mention a window of size k.
   - Example: "Find the average of all contiguous subarrays of size k."

7. **Dynamic Window Problems**: Where the window size isn't fixed and changes dynamically based on certain conditions.
   - Example: "Find the longest substring without repeating characters."

The sliding window technique is powerful because it often allows for a single linear scan of the data, avoiding nested loops and redundant computations. It's a method of incrementally processing the data, updating the answer with each movement of the window, which makes it efficient for the mentioned types of problems.

### Thought Process
1. **Define the condition** to stop expanding the window.
2. **Expand the window** by moving the right pointer and processing the right element.
3. **Process the current window** when the condition is met.
4. **Contract the window** by moving the left pointer and processing the left element.
5. **Handle edge cases** at the end.

## Techniques Involved
- **Hashing**: Quickly look up the presence of an element in the window using a hash table.
- **Two Pointers**: Track the start and end of the window efficiently.
- **Sliding Window Optimization**: Combine hashing and two pointers to enhance performance.

## Types of Sliding Window Problems

### 1. Fixed Window Size

In fixed window problems, the window size remains constant throughout the problem-solving process.

**Template for Fixed Window:**
```cpp
void fixed_window() {
    int low = 0, high = 0, windowsize = k;
    while (i < sizeofarray) {
        if (high - low + 1 < windowsize) {
            high++;
        } else {
            // Process the window
            sum += v[high];
            cout << sum << endl;
            sum -= v[low];
            low++;
            high++;
        }
    }
}
```

**Example Problem:**
Calculate the sum of all subarrays of size K.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int i = 0, j = 0;
    int sum = 0;

    while (j < n) {
        if (j - i + 1 < k) {
            sum += v[j];
            j++;
        } else {
            sum += v[j];
            cout << sum << endl;
            sum -= v[i];
            i++;
            j++;
        }
    }
}
```

### 2. Variable Window Size

In variable window problems, the window size changes dynamically based on certain conditions or criteria.

**Template for Variable Window:**
```cpp
void variable_window() {
    int start = 0, end = 0;
    while (end < n) {
        if (end - start + 1 < k) {
            end++;
        } else if (end - start + 1 == k) {
            // Process the window
            end++;
        } else if (end - start + 1 > k) {
            while (end - start + 1 > k) {
                start++;
            }
            if (end - start + 1 == k) {
                // Process the window
            }
            end++;
        }
    }
}
```

**Example Problem:**
Longest Substring Without Repeating Characters.

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, ans = 0;
        map<char, int> m;

        while (j < s.size()) {
            m[s[j]]++;
            int windowSize = j - i + 1;

            if (m.size() == windowSize) {
                ans = max(ans, windowSize);
                j++;
            } else {
                while (m.size() < windowSize) {
                    m[s[i]]--;
                    if (m[s[i]] == 0)
                        m.erase(s[i]);
                    i++;
                    windowSize = j - i + 1;
                }
                if (m.size() == windowSize) {
                    ans = max(ans, windowSize);
                }
                j++;
            }
        }
        return ans;
    }
};
```

## Practice Problems

### Fixed Window Size
1. [Substrings of size three with distinct characters](https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/)
2. [Substring with concatenation of all words](https://leetcode.com/problems/substring-with-concatenation-of-all-words/)
3. [Maximum number of vowels in a substring of given length](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/)
4. [Maximum number of occurrences of a substring](https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/)
5. [Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/)
6. [Maximum Points You Can Obtain from Cards](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/)
7. [Find all anagrams in a string](https://leetcode.com/problems/find-all-anagrams-in-a-string/)
8. [K Radius Subarray Averages](https://leetcode.com/problems/k-radius-subarray-averages/)
9. [Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold](https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/)

### Variable Window Size
1. [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
2. [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/)
3. [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)
4. [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)
5. [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/)
6. [Minimum Consecutive Cards to Pick Up](https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/)
7. [Maximum Erasure Value](https://leetcode.com/problems/maximum-erasure-value/)
8. [Fruit Into Baskets](https://leetcode.com/problems/fruit-into-baskets/)
9. [Count Number of Nice Subarrays](https://leetcode.com/problems/count-number-of-nice-subarrays/)
10. [Arithmetic Slices](https://leetcode.com/problems/arithmetic-slices/)
11. [Subarrays with k different integers](https://leetcode.com/problems/subarrays-with-k-different-integers/)

