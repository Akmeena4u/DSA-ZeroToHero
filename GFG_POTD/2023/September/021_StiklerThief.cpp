/*
   According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots
   
   Input:
n = 5
a[] = {6,5,5,7,4}
Output: 
15
Explanation: 
Maximum amount he can get by looting 1st, 3rd and 5th house. Which is 6+5+4=15.*/



class Solution
{
    public:
    //Function to find the maximum money the thief can get.
     // Top down approach
    int solveTopDown(int arr[], int n, vector<int>& dp) {
        // Base Cases
        if (n <= 0) {
            return 0;
        }
        if (n == 1) {
            return arr[0];
        }
        // Step 3: Check if answer exists already
        if (dp[n] != -1)
            return dp[n];
        // Include case
        int include = arr[n - 1] + solveTopDown(arr, n - 2, dp);
        // Exclude case
        int exclude = solveTopDown(arr, n - 1, dp);
        // Step 2: Include in dp array
        dp[n] = max(include, exclude);
        return dp[n];
    }

    // Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n) {
        // Top down approach
        // Step 1: Create dp array
        vector<int> dp(n + 1, -1);
        int ans = solveTopDown(arr, n, dp);
        return ans;
    }
};
