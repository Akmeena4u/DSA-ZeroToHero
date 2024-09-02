//problem
// Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

// Example 1:

// Input: N = 4
// arr = {1, 5, 11, 5}
// Output: YES
// Explanation: 
// The two parts are {1, 5, 5} and {11}


//algorithmm
// if it's possible to partition an array into two equal-sum subsets.

// The equalPartition function calculates the total sum of the input array.
// If the total sum is odd, it's not possible to have equal-sum subsets, so it returns 0 ("NO").
// Otherwise, it computes the sum k required for each subset.
// It initializes a DP table and calls the subsetSumUtil function to check if there exists a subset that sums up to k.
// The subsetSumUtil function is a recursive function with memoization (using the dp table) to determine if it's possible to achieve a target sum using elements from the array.
// It checks if it can achieve a target sum by either not taking the current element or taking it.
// The result is returned as 1 ("YES") if it's possible to partition into equal sums, and 0 ("NO") otherwise.



class Solution{
public:
     bool subsetSumUtil(int ind, int target, int arr[], vector<vector<int>> &dp){
        if(target == 0)
            return true;

        if(ind == 0)
            return arr[0] == target;

        if(dp[ind][target] != -1)
            return dp[ind][target];

        bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

        bool taken = false;
        if(arr[ind] <= target)
            taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

        return dp[ind][target] = notTaken || taken;
    }

    int equalPartition(int N, int arr[])
    {
        int totSum = 0;

        for(int i = 0; i < N; i++){
            totSum += arr[i];
        }

        if (totSum % 2 == 1) return 0; // If the total sum is odd, it's not possible to partition into equal sums.

        else{
            int k = totSum / 2;
            vector<vector<int>> dp(N, vector<int>(k + 1, -1));
            return subsetSumUtil(N - 1, k, arr, dp) ? 1 : 0; // Return 1 for "YES" and 0 for "NO".
        } 
    }
};
