### Square Root of a Number

**Problem Explanation:**
Given an integer `n`, find the square root of `n`. If `n` is not a perfect square, return the floor value of the square root. The floor value of any number is the greatest integer that is less than or equal to that number.

**Example:**
- **Input:** `n = 5`
- **Output:** `2`
- **Explanation:** Since `5` is not a perfect square, the floor of the square root of `5` is `2`.

### Intuition:
The problem requires us to compute the square root of a given number and return its floor value. The most straightforward approach is to use a brute force method by checking each number starting from `1` up to `n`. However, this approach is not efficient, especially for large values of `n`. 

A better approach leverages the properties of binary search to efficiently find the square root in a logarithmic time complexity. By narrowing down the possible range with each comparison, binary search quickly homes in on the floor value of the square root.

### Pattern: Binary Search
Binary Search is a classic algorithm used to efficiently find an element or a value within a sorted array or a search space. In this problem, binary search can be applied because the possible square roots are ordered and we can systematically eliminate half of the remaining possibilities in each step.

### Algorithm:
1. **Initialization:**
   - Start with two pointers: `s` (start) initialized to `0` and `e` (end) initialized to `x` (the input number).
   - Use a variable `ans` to store the floor value of the square root. Initialize it to `-1`.
   
2. **Binary Search Loop:**
   - Calculate the middle of the current search space using `mid = s + (e - s) / 2`.
   - If `mid * mid` equals `x`, then `mid` is the square root, and you return `mid`.
   - If `mid * mid` is greater than `x`, the square root must be smaller, so update the end pointer `e` to `mid - 1`.
   - If `mid * mid` is less than `x`, update `ans` to `mid` (since this is a possible floor value) and move the start pointer `s` to `mid + 1` to search the higher half.

3. **Return:**
   - After the loop ends, return `ans`, which holds the floor value of the square root.

### Code Implementation:

```cpp
long long int floorSqrt(long long int x) 
{
    long long s = 0;
    long long e = x;
    
    long long ans = -1;  // Variable to store the floor value of sqrt(x)
    
    while (s <= e) {
        long long mid = s + (e - s) / 2;
        
        // Check if mid*mid is equal to x
        if (mid * mid == x) {
            return mid;  // Found exact square root
        }
        
        // If mid*mid is greater than x, move to the left half
        if (mid * mid > x) {
            e = mid - 1;
        }
        // If mid*mid is less than x, move to the right half
        else {
            ans = mid;  // mid could be the floor value of sqrt(x)
            s = mid + 1;
        }
    }
    
    return ans;  // Return the calculated floor value
}
```

### Time Complexity:
- **O(log n)**: The binary search reduces the search space by half with each step, making it very efficient.

### Space Complexity:
- **O(1)**: The algorithm uses a constant amount of extra space.

### Explanation:
The binary search is well-suited to this problem because the range of possible values for the square root is continuous and ordered. By iteratively adjusting the search range based on the middle value, we quickly converge on the correct floor value of the square root, ensuring efficiency even for large inputs. 

### Edge Cases:
- For `n = 0`, the function should return `0`.
- For `n = 1`, the function should return `1`.
- The function correctly handles large values of `n` due to the efficiency of binary search.
