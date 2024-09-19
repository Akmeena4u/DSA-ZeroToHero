### Problem: **Different Ways to Add Parentheses**

#### Problem Overview:
You are given a string `expression` of numbers and operators (`+`, `-`, `*`). You need to compute all the different possible results from computing all the possible ways to group the numbers and operators using parentheses. The operators are applied in the usual order of arithmetic precedence.

For example:
- Input: `"2*3-4*5"`
- Output: `[-34, -14, -10, -10, 10]`

This problem can be broken down into smaller subproblems using recursion and dividing the expression based on where the operators (`+`, `-`, `*`) appear.

### Approach:
The idea is to split the input expression around every operator and solve the left and right sub-expressions recursively. We can then apply the operator to combine the results from both sub-expressions. The results from all combinations are collected and returned.

### Steps to Solve:
1. **Base Case**: 
   If the string is purely numeric (i.e., it doesn't contain any operators), convert it into an integer and return it as the only possible result.
   
2. **Recursive Case**: 
   If the string contains an operator (`+`, `-`, `*`), recursively compute all possible results for the left and right parts of the string (before and after the operator), and then combine the results from both parts using the operator.

3. **Combine Results**: 
   For each operator in the string, we:
   - Solve the left part of the string.
   - Solve the right part of the string.
   - Combine the results from both parts using the current operator.

4. **Return Final Results**: 
   After iterating through all the operators in the string and combining the results, we return all the possible results.

### Code Implementation in C++:

```cpp
class Solution {
public:
    // Function to compute all possible results for the given expression
    vector<int> solve(string s) {
        vector<int> result;

        // Traverse the string to find operators
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '+' || s[i] == '-' || s[i] == '*') {
                // Recursively solve the left and right parts of the expression
                vector<int> left_results  = solve(s.substr(0, i));
                vector<int> right_results = solve(s.substr(i+1));

                // Combine the results from left and right using the current operator
                for(int &x : left_results) {
                    for(int &y : right_results) {
                        if(s[i] == '+') {
                            result.push_back(x + y);
                        } else if(s[i] == '-') {
                            result.push_back(x - y);
                        } else if(s[i] == '*') {
                            result.push_back(x * y);
                        }
                    }
                }
            }
        }

        // If no operators were found, the string is a number, so convert and return it
        if(result.empty()) {
            result.push_back(stoi(s));
        }

        return result;
    }

    // The main function that starts the recursive computation
    vector<int> diffWaysToCompute(string s) {
        return solve(s);
    }
};
```

### Explanation of Code:

- **`solve` Function**:
   - This function takes a string `s` and returns all possible results of evaluating the expression represented by `s`.
   - It loops through each character in the string. When it finds an operator (`+`, `-`, `*`), it splits the string into two parts:
     - `left_results`: Results from solving the part of the string before the operator.
     - `right_results`: Results from solving the part of the string after the operator.
   - It then combines the results from the left and right parts using the operator and adds the results to the `result` vector.
   - If no operators are found, it means the string is purely a number, so it converts it to an integer and returns it.

- **`diffWaysToCompute` Function**:
   - This is the main function that users call with the expression string. It simply calls the `solve` function and returns the result.

### Example Walkthrough:
Let's take the input string `"2*3-4*5"` and break it down step by step.

1. **Initial Step**:
   - The string is `"2*3-4*5"`.
   - First operator found is `*` at index 1. We split the string into:
     - Left part: `"2"`
     - Right part: `"3-4*5"`
   - Recursively solve `"3-4*5"`.

2. **Recursive Step (for `"3-4*5"`)**:
   - First operator is `-` at index 1. We split the string into:
     - Left part: `"3"`
     - Right part: `"4*5"`
   - Recursively solve `"4*5"`.

3. **Recursive Step (for `"4*5"`)**:
   - First operator is `*` at index 1. We split into:
     - Left part: `"4"`
     - Right part: `"5"`
   - Both are numbers, so return `[4]` and `[5]`.

4. **Combine Results**:
   - Now that we have the results for `"4*5"`, we combine them using the `*` operator:
     - `4 * 5 = 20`
   - So, the result for `"4*5"` is `[20]`.

5. **Further Combination**:
   - Using the results from `"3"` and `"4*5"`, we combine:
     - `3 - 20 = -17`
   - So, the result for `"3-4*5"` is `[-17]`.

6. **Final Combination**:
   - Now we combine results from `"2"` and `"3-4*5"`:
     - `2 * -17 = -34`

### Time Complexity:
- The problem uses a **divide-and-conquer** approach, which results in splitting the expression at every operator. If there are `n` operators, the complexity will be exponential as each recursive call splits the problem further. Therefore, the time complexity is roughly **O(n \* 2^n)**, where `n` is the number of operators in the expression.

### Conclusion:
This solution uses recursion and dynamic partitioning to compute all possible results for an arithmetic expression by varying the order of operations. It efficiently breaks the problem into smaller subproblems and combines the results using a clean and structured approach.
