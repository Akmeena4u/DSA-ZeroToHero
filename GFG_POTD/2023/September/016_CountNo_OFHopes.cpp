//problem
// A frog jumps either 1, 2, or 3 steps to go to the top. In how many ways can it reach the top of Nth step. As the answer will be large find the answer modulo 1000000007.

// Example 1:

// Input:
// N = 1
// Output: 1




// Algorithm-----
//  the number of ways a frog can reach the top of a staircase with n steps. It uses dynamic programming with memoization.

// The solve function is a recursive function that computes the number of ways for the frog to reach step i.
// If i is zero, there's one way (the frog is already at the top).
// If i is negative, there are zero ways (an invalid step).
// Memoization (dp array) stores and reuses previously computed results to avoid redundant calculations.
// The result for step i is the sum of the number of ways to reach steps i-1, i-2, and i-3.
// The function returns the total number of ways for the frog to reach the top, modulo 1e9+7.
// The countWays function initializes the dp array and calls solve to compute and return the final result.




  





class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
     

long long mod=1e9+7;
    long long solve(int i,vector<int>& dp)
    {
        if(i==0) return 1;
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];        
        return dp[i]=(solve(i-1,dp)+solve(i-2,dp)+solve(i-3,dp))%mod;
    }
    long long countWays(int n)
    {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};
