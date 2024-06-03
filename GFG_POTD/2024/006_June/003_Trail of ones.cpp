/*

### Problem Understanding
We need to count the number of binary strings of length n that contain at least one pair of consecutive 1s.

### Brute Force Approach:
- Initial idea: Generate all permutations of binary strings of length `n` using 1s and 0s.
- For each permutation, traverse the string and count occurrences of consecutive 1s.
- Realization: Generating all permutations takes time complexity O(2^n), since each position can be either 0 or 1.

### Transition to Optimized Approach:
- Instead of generating all binary strings, look for a more efficient way to count strings with consecutive ones.
- Observation: Count strings for small values of `n` and gradually increase `n` to detect patterns.
- Noticed: The problem aligns with a modified Fibonacci series pattern.

### Optimized Approach:
- For `n = 2`, directly return 1 since "11" is the only valid string.
- For larger `n`, use dynamic programming principles to calculate the number of valid strings:
  - Define `a` as the number of valid strings of length `n-2` and `b` for `n-1`.
  - Use the relation: `c = (a + b) % mod` for next value, and `ans = ((ans * 2) % mod + c) % mod` to update the count.
- Use modulo operation to keep numbers manageable and prevent overflow.



*/



//--------------------------------------------------------------------- Brute force Solution-----------------------------------------------------------------------------
  
//  Helper function to count strings with at least one consecutive ones
int countWithConsecutiveOnes(string s, int n) {
    // Base case: if the string length is n, check for consecutive ones
    if (s.length() == n) {
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == '1' && s[i + 1] == '1') {
                return 1;
            }
        }
        return 0;
    }

    // Recur by adding '0' or '1' to the current string
    return countWithConsecutiveOnes(s + "0", n) + countWithConsecutiveOnes(s + "1", n);
}

    int numberOfConsecutiveOnes(int n) {
        // code here
           return countWithConsecutiveOnes("", n);
    }


//---------------------------------------------------------------------------------Optimized Approch-------------------------------------------------------------

 int numberOfConsecutiveOnes(int n) {
        // code here          
        if(n==2)return 1;
        int a=0,b=1,ans=1,mod=1e9+7;
        for(int i=3;i<=n;i++){
            int c = (a+b)%mod;
            a=b;
            b=c;
            ans=((ans*2)%mod+c)%mod;
        }
        return ans;
          

    }
