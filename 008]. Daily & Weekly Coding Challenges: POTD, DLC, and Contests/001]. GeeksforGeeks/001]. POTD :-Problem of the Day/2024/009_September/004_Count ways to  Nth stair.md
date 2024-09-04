### Count Ways to N'th Stair (Order Does Not Matter)

#### Problem Overview:
- **Objective**: Given `n` stairs, determine the number of distinct ways a person can reach the top if they can either climb 1 stair or 2 stairs at a time, with the order of steps not mattering.
- **Constraints**:
  - For `n = 4`, the combinations `{1, 2, 1}`, `{2, 1, 1}`, `{1, 1, 2}` are considered the same.
  - The goal is to count distinct combinations rather than permutations.

#### Examples:
1. **Input**: `n = 4`
   - **Output**: 3
   - **Explanation**: The distinct ways to reach the 4th stair are:
     - `{1, 1, 1, 1}`
     - `{1, 1, 2}`
     - `{2, 2}`

#### Key Observations:
- The problem reduces to counting the distinct combinations of 1s and 2s that sum up to `n`.
- Unlike the traditional staircase problem where order matters, this problem focuses on distinct sets where the order of steps does not matter.

#### Approach 1: Dynamic Programming (Recursive with Memoization)
- **Idea**: Use a recursive function with memoization to explore the number of ways to reach the nth stair, but simplify the count by considering only distinct sets.
- **Key Insight**: For any given `n`, the number of ways to reach the top is determined by the sum of:
  - The number of ways to reach `n-1` stairs plus
  - The number of ways to reach `n-2` stairs.
  
- **Recurrence Relation**:
  f(n) = 1 + min(f(n-1), f(n-2))

  - Here, `f(n)` represents the distinct ways to reach the nth stair.
  - The `+1` accounts for the additional step from the base cases.

- **Base Cases**:
  - `f(0) = 1` (One way to stay at the start)
  - `f(1) = 1` (Only one way to climb one stair)

- **Implementation**:
```cpp
int f(int n, vector<int> &dp) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    
    if (dp[n] != -1) return dp[n];
    
    return dp[n] = 1 + min(f(n-1, dp), f(n-2, dp));
}

int nthStair(int n) {
    vector<int> dp(n+1, -1);
    return f(n, dp);
}
```

#### Approach 2: Direct Mathematical Observation
- **Key Insight**: Since the order does not matter, each set of steps can be thought of as a combination of 1s and 2s that sum to `n`.
  - Count the number of 2-steps you can take, starting from 0 up to the maximum possible 2-steps (`n/2`).
  - The formula simplifies to counting how many distinct combinations of 2-steps can be made for a given `n`.

- **Mathematical Approach**:
  - If you can take `k` 2-steps, the remaining steps are all 1s.
  - The number of distinct ways to reach the top is simply `1 + (n / 2)`.
    - The `+1` accounts for the case where you take all 1-steps.

- **Implementation**:
```cpp
int nthStair(int n) {
    return 1 + (n / 2);
}
```

#### Conclusion:
- **Recursive Approach with Memoization**:
  - Provides a flexible and intuitive understanding, especially for learners.
  - Suitable when understanding the transition from one step to the next is crucial.
  
- **Mathematical Observation**:
  - Provides a quick and efficient solution.
  - Ideal for scenarios where speed and simplicity are key, especially in competitive programming.

- **Key Learning**:
  - Recognize when the problem requires combinations rather than permutations.
  - Understand how to simplify a problem using direct mathematical insights, which can lead to more efficient solutions.
