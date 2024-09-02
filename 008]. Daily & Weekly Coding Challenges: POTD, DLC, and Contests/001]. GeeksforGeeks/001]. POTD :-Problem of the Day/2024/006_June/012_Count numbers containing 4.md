


## Problem Statement
Given a positive integer 'n', determine the count of numbers from 1 to 'n' (inclusive) that contain the digit '4' in their decimal representation.

### Example
- If 'n' is 50, the numbers containing '4' from 1 to 50 are 4, 14, 24, 34, 40, 41, 42, 43, 44, and 45, totaling 10 numbers.

---

## Approach 1: Iterative Checking of Digits
- **Code**:
```cpp
int answer = 0;
for (int i = 4; i <= n; i++) {
    int j = i;
    while (j != 0) {
        int digit = j % 10;
        if (digit == 4) {
            answer++;
            break;
        }
        j = j / 10;
    }
}
```
- **Time Complexity**: O(n * log10(n))
- **Explanation**:
  - The code iterates from 4 to 'n' and for each number, iterates through its digits.
  - It uses modular arithmetic (`j % 10`) to extract the rightmost digit of 'j'.
  - If the extracted digit is '4', it increments the count and breaks out of the inner loop.
  - The outer loop continues until 'n' is reached.

---

## Approach 2: String Conversion and Search
- **Code**:
```cpp
#include <iostream>
#include <string>

int countNumbersContainingFour(int n) {
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        std::string s = std::to_string(i);
        for (char c : s) {
            if (c == '4') {
                ++count;
                break;
            }
        }
    }
    return count;
}
```
- **Time Complexity**: O(n * log10(n))
- **Explanation**:
  - This approach converts each number from 1 to 'n' into a string using `std::to_string`.
  - It then checks each character of the string to see if it's '4'.
  - If '4' is found, it increments the count and breaks out of the inner loop.
  - The outer loop continues until 'n' is processed.

---

Both approaches solve the problem by checking each number's digits but differ in implementation details. Approach 1 directly operates on digits using arithmetic, while Approach 2 converts numbers to strings for easier digit checking. The time complexity is the same for both due to the loop structures and digit processing.
