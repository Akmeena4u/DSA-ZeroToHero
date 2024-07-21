

## Problem: Maximum Product of a Subset 🌟

### What's the Challenge?

Given an array of numbers, we want to find the maximum product that we can get by multiplying some (or all) of these numbers together. Sounds like a math puzzle, right? Let's dive in!

### Example

Imagine we have this array:

```
arr = [-1, 0, -2, 4, 3]
```

Our goal is to find the maximum product we can get from these numbers. In this case, the answer is 24. How did we get that? Let's break it down:

1. Multiply all the non-zero numbers: (-1) * (-2) * 4 * 3 = 24.
2. We ignore the zero because any product multiplied by zero is zero.
3. We also consider negative numbers. In this case, we have two negatives: -1 and -2. Since we're multiplying, we want to include the larger negative number (which is -1).

### How Do We Solve It?

1. Initialize three variables:
   - `prod` to keep track of the product of non-zero elements (start with 1).
   - `maxi` to keep track of the maximum negative element (start with negative infinity).
   - `zero` to count the number of zeros (start with 0).
2. Go through each number in the array:
   - If the number is not zero:
     - Update `prod` by multiplying it with the current number.
     - If the number is negative, update `maxi` with the larger negative value.
   - If the number is zero, increment `zero`.
3. If all elements are zero, return 0 (because the product will be zero).
4. If `prod` is negative, divide it by `maxi` (to remove the effect of the maximum negative value).
5. Finally, return `prod` modulo 10^9 + 7 (to handle large numbers).

```cpp
long long int findMaxProduct(vector<int>& arr) {
    // Initialize variables:
    long long prod = 1; // To keep track of the product of non-zero elements
    long long maxi = INT_MIN; // To keep track of the maximum negative element
    int zero = 0; // To count the number of zeros in the array

    // Iterate through the array:
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            // Update the product by multiplying it with the current element
            prod = (1LL * prod * arr[i]) % 1000000007;

            // If the current element is negative, update maxi with the larger negative value
            if (arr[i] < 0) {
                maxi = max(maxi, 1LL * arr[i]);
            }
        } else {
            // If the current element is zero, increment the zero count
            zero++;
        }
    }

    // If all elements are zero, return 0 (product will be zero)
    if (zero == arr.size()) {
        return 0;
    }

    // If the product is negative, divide it by maxi (to remove the effect of the maximum negative value)
    if (prod < 0) {
        prod /= maxi;
    }

    // Return the product modulo 10^9 + 7
    return (1LL * prod) % 1000000007;
}
```

### Complexity

- Time Complexity: O(n) (where n is the size of the array)
- Space Complexity: O(1)


