### Problem: Nth Natural Number

#### Problem Statement
Given a positive integer `n`, the task is to find the `n`th natural number after removing all numbers that contain the digit `9`.

#### Explanation with Example:
- **Input:** `n = 8`
- **Output:** `8`
  
  **Explanation:** 
  - Natural numbers without the digit `9` are: 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13, ...
  - The first 8 numbers are `1, 2, 3, 4, 5, 6, 7, 8`, so the 8th number is `8`.

#### Concept:
- The problem is essentially about counting natural numbers in a modified numbering system where any number containing the digit `9` is excluded.
- Notice that if you take a natural number and express it in base 9, it effectively skips over the numbers that would have had a '9' in them in base 10.
- This means the problem can be reduced to converting `n` to a number in base 9.

#### Approach:

1. **Base Conversion:**
   - Convert the given number `n` into its equivalent in base 9.
   - This conversion will effectively "skip" all numbers that contain the digit `9` when represented in base 10.
   
2. **Detailed Steps:**
   - Start with `n`, and repeatedly divide it by `9`, storing the remainders.
   - The remainders are then used to form the digits of the base-9 number.
   - Multiply each digit by its positional value (1, 10, 100, etc.) to get the result.

#### Code Implementation:
```cpp
long long findNth(long long n) {
    long long ans = 0;
    long long p = 1;

    // Convert the number n to its base 9 equivalent
    while (n > 0) {
        ans += p * (n % 9);  // Add the last digit in base 9 to the answer
        n /= 9;              // Reduce n by dividing by 9
        p *= 10;             // Increase positional multiplier (powers of 10)
    }

    return ans;
}
```

#### Explanation of the Code:
- **Initialization:**
  - `ans` is initialized to `0` to store the final result.
  - `p` is initialized to `1` to keep track of the positional value (units, tens, hundreds, etc.) as we build the result.

- **Conversion Process:**
  - We use a `while` loop that continues until `n` becomes `0`.
  - In each iteration:
    - `(n % 9)` gives the last digit in base 9, which is then multiplied by `p` (the positional multiplier) and added to `ans`.
    - `n` is divided by `9` to move to the next digit.
    - `p` is multiplied by `10` to shift the position to the next place value.

- **Return the Result:**
  - After the loop, `ans` contains the equivalent of `n` in the modified base-9 system, which is the desired nth natural number after removing all numbers containing the digit `9`.

#### Complexity Analysis:
- **Time Complexity:** O(log₉(n))
  - The number of iterations is proportional to the number of digits in the base-9 representation of `n`.
- **Space Complexity:** O(1)
  - Only a constant amount of space is used for variables.

#### Summary:
This problem is elegantly solved by interpreting the number `n` in base 9. This conversion effectively skips over numbers that contain the digit `9` in base 10, providing the correct `n`th number in a sequence where such numbers are omitted.
