
## Problem Overview

Given two sorted arrays `arr1` and `arr2`, and an integer `k`, the task is to find the element that would be at the k-th position of the combined sorted array.

## Example

### Input
- `k = 5`
- `arr1 = [2, 3, 6, 7, 9]`
- `arr2 = [1, 4, 8, 10]`

### Output
- The combined sorted array would be `[1, 2, 3, 4, 6, 7, 8, 9, 10]`.
- The 5th element in this array is `6`.

## Approach

### Key Points:
1. **Merging Two Sorted Arrays:**
   - Since both arrays are already sorted, the problem can be tackled using the merge step of the merge sort algorithm.
   - We maintain two pointers, one for each array, and compare elements to build the combined sorted array until we reach the k-th element.

2. **Complexity:**
   - Time complexity is O(n + m), where n and m are the lengths of `arr1` and `arr2`, respectively.
   - Space complexity is O(n + m) due to the additional array used to store the combined elements.

### Detailed Steps:

1. **Initialization:**
   - Create a combined array `comb` to store the merged elements.
   - Use pointers `i` and `j` to traverse `arr1` and `arr2`, respectively.

2. **Merge Arrays:**
   - Compare elements from `arr1` and `arr2`.
   - Append the smaller element to `comb` and increment the respective pointer.
   - Continue until one of the arrays is exhausted.

3. **Append Remaining Elements:**
   - Append remaining elements from `arr1` or `arr2` to `comb`.

4. **Retrieve k-th Element:**
   - Return the (k-1)-th element from `comb` (since array indices are 0-based).

### Code Implementation:

```cpp
class Solution {
public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int tot = arr1.size() + arr2.size();
        vector<int> comb(tot, 0);

        int i = 0, j = 0;
        int x = 0;
        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i] < arr2[j]) {
                comb[x++] = arr1[i];
                i++;
            } else {
                comb[x++] = arr2[j];
                j++;
            }
        }

        while (i < arr1.size()) {
            comb[x++] = arr1[i];
            i++;
        }

        while (j < arr2.size()) {
            comb[x++] = arr2[j];
            j++;
        }

        int tmp = comb[k-1];
        long ans = (long)tmp;
        return ans;
    }
};

```

## Explanation of Code

 **Solution Class:**
   - Contains the `kthElement` function which takes `k`, `arr1`, and `arr2` as parameters.
   - Combines the arrays into `comb` using two pointers.


By following these steps and understanding the logic, one can easily solve the problem of finding the k-th element in the combined sorted array of two given sorted arrays.
