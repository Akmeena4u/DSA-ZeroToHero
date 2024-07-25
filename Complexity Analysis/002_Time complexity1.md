### Time Complexity

**Definition**: 
The time complexity of an algorithm is the amount of time taken by an algorithm to run as a function of the length of the input. It is a measure of the algorithm's performance, independent of machine-specific constants and factors.

---

### **How is Time Complexity Computed?**

To estimate time complexity, consider the cost of each fundamental instruction and the number of times each instruction is executed.

#### **Basic Operations**:
Basic operations like comparisons, return statements, assignments, and reading a variable are assumed to take constant time, denoted as O(1).

**Example Statements**:
1. `int a = 5;` // Reading a variable
2. `if (a == 5) return true;` // Return statement
3. `int x = 4 > 5 ? 1 : 0;` // Comparison
4. `bool flag = true;` // Assignment

**Overall Time Complexity**:
`T(n) = t(statement1) + t(statement2) + ... + t(statementN)`
Assuming each statement takes constant time: `T(n) = O(1)`
Thus, the overall time complexity is O(1), which means constant complexity.

---

### **Loops and Time Complexity**

For loops, the time complexity is determined by the runtime of the block inside the loop multiplied by the number of times the loop executes.

**Example**:
```cpp
for (int i = 0; i < n; i++) {
   cout << "GeeksForGeeks" << endl;
}
```
The loop executes `n` times, printing "GeeksForGeeks" each time.

**Time Complexity**:
`T(n) = n* t(cout statement)`
Since `t(cout statement) = O(1)`: `T(n) = n O(1)` : `T(n) = O(n)`
This represents linear complexity.

---

### **Nested Loops and Time Complexity**

For nested loops, multiply the runtime of the block inside the innermost loop by the number of times all enclosing loops execute.

**Example**:
```cpp
for (int i = 0; i < n; i++) {
   for (int j = 0; j < m; j++) {
       cout << "GeeksForGeeks" << endl;
   }
}
```
The `cout` statement executes `n * m` times.

**Time Complexity**:
`T(n) = n*m *t(cout statement)`
Since `t(cout statement) = O(1)`:
`T(n) = n*m O(1)`
`T(n) = O(n*m)`
This represents quadratic complexity.

---

### **Summary of Time Complexity Calculation**

1. **Constant Time (O(1))**:
   - Individual statements or simple operations.
   - Example: `int a = 5;`

2. **Linear Time (O(n))**:
   - Single loops where the number of iterations is proportional to the input size.
   - Example: 
     ```cpp
     for (int i = 0; i < n; i++) {
         // O(1) operations
     }
     ```

3. **Quadratic Time (O(n * m))**:
   - Nested loops where the number of iterations is a product of two variables.
   - Example: 
     ```cpp
     for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
             // O(1) operations
         }
     }
     ```

---

Understanding time complexity is crucial for analyzing and optimizing algorithms, ensuring efficient performance for large inputs.

---
