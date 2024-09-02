
### Problem Breakdown:
1. **Find Nearest Smaller to Left (NSL)**: For each element in the array, find the nearest smaller element to its left.
2. **Find Nearest Smaller to Right (NSR)**: For each element in the array, find the nearest smaller element to its right.
3. **Calculate Absolute Difference**: For each element, compute the absolute difference between its nearest left smaller and nearest right smaller.
4. **Return the Maximum Difference**: Among all the computed absolute differences, return the maximum value.

### Efficient Approach:
To avoid the `O(n^2)` time complexity, we can utilize stacks to find the nearest smaller elements in linear time `O(n)`.

### Steps:

1. **NSL Array Construction**:
   - Traverse the array from left to right.
   - Use a stack to keep track of elements as you find the nearest smaller elements on the left.

2. **NSR Array Construction**:
   - Traverse the array from right to left.
   - Similarly, use a stack to track elements to find the nearest smaller elements on the right.

3. **Calculate Maximum Absolute Difference**:
   - After constructing the NSL and NSR arrays, iterate through the array and compute the absolute difference between corresponding elements in NSL and NSR.
   - Keep track of the maximum difference.

### Example:
Let's say the input array is `[2, 1, 8]`.

- NSL: For each element, find the nearest smaller element on the left:
  - For `2`, there is no smaller element on the left, so NSL[0] = 0.
  - For `1`, there is no smaller element on the left, so NSL[1] = 0.
  - For `8`, the nearest smaller element on the left is `1`, so NSL[2] = 1.
  - NSL = `[0, 0, 1]`.

- NSR: For each element, find the nearest smaller element on the right:
  - For `2`, the nearest smaller element on the right is `1`, so NSR[0] = 1.
  - For `1`, there is no smaller element on the right, so NSR[1] = 0.
  - For `8`, there is no smaller element on the right, so NSR[2] = 0.
  - NSR = `[1, 0, 0]`.

- Compute the differences:
  - For index 0: `|NSL[0] - NSR[0]| = |0 - 1| = 1`.
  - For index 1: `|NSL[1] - NSR[1]| = |0 - 0| = 0`.
  - For index 2: `|NSL[2] - NSR[2]| = |1 - 0| = 1`.

- The maximum difference is `1`.

### C++ Code Implementation:
```cpp
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int findMaxDifference(vector<int>& arr) {
    int n = arr.size();
    vector<int> NSL(n, 0), NSR(n, 0);
    stack<int> s;

    // Finding Nearest Smaller to Left (NSL)
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            NSL[i] = s.top();
        }
        s.push(arr[i]);
    }

    // Clear the stack for the next pass
    while (!s.empty()) {
        s.pop();
    }

    // Finding Nearest Smaller to Right (NSR)
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            NSR[i] = s.top();
        }
        s.push(arr[i]);
    }

    // Finding the maximum absolute difference
    int maxDiff = 0;
    for (int i = 0; i < n; ++i) {
        int diff = abs(NSL[i] - NSR[i]);
        maxDiff = max(maxDiff, diff);
    }

    return maxDiff;
}

int main() {
    vector<int> arr = {2, 1, 8};
    cout << "Maximum Difference: " << findMaxDifference(arr) << endl;
    return 0;
}
```

### Explanation:
- **NSL and NSR Arrays**: These arrays store the nearest smaller elements to the left and right of each element, respectively.
- **Stack Usage**: The stack helps efficiently find the nearest smaller elements by maintaining a dynamic set of potential candidates.
- **Final Calculation**: We calculate the absolute differences and determine the maximum among them.

This approach ensures the solution runs in linear time `O(n)`, making it efficient even for large input arrays.
