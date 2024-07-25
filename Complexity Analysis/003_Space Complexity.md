### Space Complexity Explained

**Space Complexity** is often confused with **Auxiliary Space**, but they are distinct concepts. Here are the precise definitions:

- **Auxiliary Space:** This is the extra space or temporary space used by an algorithm, excluding the space used by the input.
- **Space Complexity:** This is the total space taken by an algorithm with respect to the input size. It includes both the auxiliary space and the space used by the input.

### Key Points

1. **Space Complexity vs. Auxiliary Space:**
   - **Auxiliary Space** focuses on the extra space required by the algorithm, excluding input size.
   - **Space Complexity** is the overall space required, including both auxiliary space and input space.

2. **Example - Sorting Algorithms:**
   - **Merge Sort:** Uses O(n) auxiliary space.
   - **Insertion Sort & Heap Sort:** Use O(1) auxiliary space.
   - **Overall Space Complexity:** For Merge Sort, Insertion Sort, and Heap Sort is O(n).

### Detailed Explanation

Space complexity is a parallel concept to time complexity. It evaluates the memory requirements of an algorithm as a function of the input size.

#### Creating Arrays
- **1D Array:** An array of size `n` requires O(n) space.
- **2D Array:** A two-dimensional array of size `n*n` requires O(n^2) space.

### Recursive Calls and Stack Space

Recursive functions add a level to the call stack for each call. This stack space counts towards space complexity.

**Example:**

```cpp
int add (int n) {
    if (n <= 0) {
        return 0;
    }
    return n + add(n-1);
}
```

**Stack Trace:**

1. add(4)
2.   -> add(3)
3.     -> add(2)
4.       -> add(1)
5.         -> add(0)

Each call adds a level to the stack, taking O(n) space.

### Non-Recursive Function Example

```cpp
int addSequence(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pairSum(i, i+1);
    }
    return sum;
}

int pairSum(int x, int y) {
    return x + y;
}
```

- There are O(n) calls to `pairSum`.
- However, these calls do not exist simultaneously on the call stack.
- Thus, the space complexity is O(1).

### Important Considerations

- Space complexity can be influenced by factors such as the programming language, the compiler, or the machine running the algorithm.

### Summary

Understanding space complexity helps in evaluating the efficiency of algorithms, especially when memory usage is a critical factor. By distinguishing between auxiliary space and overall space complexity, we can better compare different algorithms in terms of their memory requirements.

---

### Additional Notes

- **Recursive calls** significantly impact space complexity due to the call stack.
- **Iterative algorithms** often have lower space complexity as they do not add multiple levels to the stack.
- When analyzing space complexity, always consider the overall memory usage, including both input and auxiliary space.

---

By comprehending these concepts, you will be better equipped to evaluate and compare algorithms based on their memory efficiency, which is crucial for technical interviews and real-world applications.
