### Problem Understanding

You are given an array of `n` integers, and your goal is to rearrange the elements in such a way that the value of the expression `∑arr[i] * i` is maximized, where `i` ranges from `0` to `n-1`. 

Since the value of the expression could be large, you need to return the result modulo \(10^9 + 7\).

### Example

**Input:**  
`arr[] = [5, 3, 2, 4, 1]`  

**Output:**  
`40`

**Explanation:**  
To maximize the value, arrange the array as `[1, 2, 3, 4, 5]`. The resulting sum is:  
\[0*1 + 1*2 + 2*3 + 3*4 + 4*5 = 0 + 2 + 6 + 12 + 20 = 40\]

Since \(40 < 10^9 + 7\), the output is 40.

### Intuition

To maximize the sum `∑arr[i] * i`, you want the smallest elements to be multiplied by the smallest indices and the largest elements to be multiplied by the largest indices. Sorting the array in non-decreasing order achieves this. The element at index `0` is multiplied by `0`, the element at index `1` is multiplied by `1`, and so forth.

### Algorithm

1. **Sort the Array:**  
   Sort the array in ascending order so that the smallest elements are at the smallest indices and the largest elements are at the largest indices.

2. **Calculate the Sum:**  
   Iterate through the sorted array, and for each element `arr[i]`, compute `arr[i] * i` and add it to the result. Keep the result modulo \(10^9 + 7\) to avoid overflow.

3. **Return the Result:**  
   The final result is the maximum sum modulo \(10^9 + 7\).

### Code Implementation

```cpp
#include <vector>
#include <algorithm>

class Solution {
  public:
    int Maximize(std::vector<int> &arr) {
        // Sort the array in ascending order
        std::sort(arr.begin(), arr.end());
        
        long long res = 0;
        int n = arr.size();
        const long long MOD = 1000000007;
        
        // Calculate the sum of arr[i] * i
        for(int i = 0; i < n; ++i) {
            res = (res + i * (long long)arr[i]) % MOD;
        }
        
        return res;
    }
};
```

### Edge Cases

1. **Single Element Array:**  
   If the array has only one element, the sum will always be `0`, as the element will be multiplied by `0`.

2. **Large Numbers:**  
   The array might contain large values, but since we are taking the modulus \(10^9 + 7\) at every step, the solution should handle these correctly.

3. **Negative Numbers:**  
   If the problem statement allows negative numbers, sorting still holds, as negative numbers would minimize the sum when placed at smaller indices.

### Complexity Analysis

- **Time Complexity:**  
  The time complexity of this approach is `O(n log n)` due to the sorting step. The summation loop runs in `O(n)`, but the overall complexity is dominated by the sorting step.

- **Space Complexity:**  
  The space complexity is `O(1)` if we ignore the space used by the sorting algorithm (which is `O(log n)` for most sorting algorithms).

### Summary

The optimal approach to maximize the value `∑arr[i] * i` is to sort the array and multiply each element by its index. By taking advantage of sorting, we ensure that the smallest elements are multiplied by the smallest indices, and the largest elements are multiplied by the largest indices, maximizing the sum. The modulus operation ensures that the solution handles large outputs efficiently.
