**Pedovain Sequence Problem Explanation and Solution:**

### Overview:
" This is a straightforward problem where the answer is almost entirely given in the problem statement itself. The task is to find the n-th element of the Pedovain sequence. the code will be  
  almost same as the code of to find  nth Fibbonacci number but game is over how to manage lagrge number , and thats why there is need to use mudulus operation .

  Dynamic programming is a method used to solve problems by breaking them down into simpler subproblems and storing the results of these subproblems to avoid redundant computations.
  In this code, we use an dp array to store the values of the Padovan sequence as we compute them.

### Key Points:
1. **Pedovain Sequence Definition:**
   - The Pedovain sequence is similar to the Fibonacci sequence.
   - Each element is the sum of the previous two and the one before the previous two elements.
   - Formula: P(n) = P(n-2) + P(n-3) .

2. **Initial Values:**
   - The first three elements of the Pedovain sequence are always 1.
   - P(0) = 1, P(1) = 1, P(2) = 1.

3. **Objective:**
   - Given a number n, find the  n-th element of the Pedovain sequence.

4. **Example:**
   - If n = 3, the value is the sum of P(1) and P(0), both of which are 1.
   - P(3) = P(1) + P(0) = 1 + 1 = 2.

## Approach:
 **Dynamic Programming:**
   - Use an array to store the values of the sequence up to n .
   - Initialize the first three values as 1.
   - Use a loop to calculate subsequent values based on the formula P(n) = P(n-2) + P(n-3).
   - Take modulo 10^9 + 7 to prevent integer overflow.

### Code:
```cpp
 int padovanSequence(int n)
    {
       //code here
       int dp[n+1];
       int mod=1e9+7;
       // base case
       dp[0]=1;
       dp[1]=1;
       dp[2]=1;
       for(int i=3;i<=n;i++){
           //recursive code
           dp[i]=(dp[i-2]+dp[i-3])% mod;
           
       }
       return dp[n] % mod;
    }

```

### Explanation:
- **Initialization:** 
  - Define the modulo constant 10^9 + 7.
  - Initialize the DP array with zeros.
  - Set the base cases for P(0), P(1), and P(2).

- **Dynamic Programming Loop:**
  - Iterate from 3 to n.
  - Calculate dp[i] using the formula dp[i] = dp[i-2] + dp[i-3].
  - Take modulo 10^9 + 7 to avoid overflow.

- **Return Value:**
  - Return dp[n] as the result.

### Complexity Analysis :
Time Complexity: O(n)
Space Complexity: O(n)

### Summary:
This problem demonstrates a simple yet effective use of dynamic programming to solve sequence-based problems. The use of the modulo operation ensures that the solution handles large numbers without overflow, making it efficient and practical for a wide range of input values.

---

## Approach 2 - Optimized space o(1)


### Overview:
The optimized solution reduces the space complexity by using only a few variables instead of an entire array to store the sequence values. This is done by keeping track of only the necessary previous values to compute the next value in the sequence.

### Code in Java:
```cpp
 int padovanSequence(int n) {
        if (n <= 2)
            return 1;

        int a = 1, b = 1, c = 1, d = 0;

        for (int i = 3; i <= n; i++) {
            d = (a + b) % MOD;
            a = b;
            b = c;
            c = d;
        }

        return d;
    }
```

### Explanation:
- **Initialization:** 
  - Define the modulo constant 10^9 + 7.
  - Initialize the variables  a, b, and c to 1, representing the first three elements of the sequence.

- **Iteration:**
  - Start the loop from 3 to n.
  - Compute d as (a + b)% mod m.
  - Update the values of a, b, and c for the next iteration.

- **Return Value:**
  - Return d , which holds the n-th value of the Pedovain sequence.

### Time and Space Complexity:
- **Time Complexity:** O(n) because the loop runs from 3 to n.
- **Space Complexity:** O(1)since only a constant amount of space is used to store variables a, b, c, and d .

This optimized solution efficiently computes the n-th element of the Pedovain sequence while minimizing space usage.


