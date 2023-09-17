// Given an array arr[] of non-negative integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

// Note: Answer can be very large, so, output answer modulo 109+7

// Example 1:

// Input: N = 6, arr[] = {2, 3, 5, 6, 8, 10}
//        sum = 10
// Output: 3
// Explanation: {2, 3, 5}, {2, 8}, {10} are 
// possible subsets.



//Algorithm:--
// Here the number of ways to achieve a target sum using elements from an array. It uses dynamic programming (DP) with memoization.

// The perfectSum function initializes a DP table and calls a helper function.
// The helper function is recursive and computes ways to reach the sum.
// Base cases handle when the index is 0.
// Memoization (dp table) avoids redundant calculations.
// The result is returned as the total number of ways to reach the target sum.




class Solution{

	public:
	int mod=1e9+7;
	int helper(int arr[],int index,int sum, vector<vector<int>> &dp)
	{
	    if(index==0)
	    {
	        if(arr[0]==0 and sum==0) return 2;
	        if(sum==0 or sum==arr[0]) return 1;
	        return 0;
	    }
	    if(dp[index][sum]!=-1) return dp[index][sum];
	    int notpick=helper(arr,index-1,sum,dp)%mod;
	    int pick=0;
	    if(arr[index]<=sum)
	    {
	        pick=helper(arr,index-1,sum-arr[index],dp)%mod;
	    }
	    return dp[index][sum]=((pick)%mod+(notpick)%mod)%mod;
	}
	
	
	int perfectSum(int arr[], int n, int sum)
	{
	  vector<vector<int>>dp(n,vector<int>(sum+1,-1));
      return helper(arr,n-1,sum,dp);
	}
	  
};
