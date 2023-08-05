class Solution {
public:
// n-> represents the index of current house
    int solveRec(vector<int>&nums,int n){
        // Base Case
        if(n < 0){
            return 0;
        }
        if(n == 0){
            return nums[0];
        }
        // Include case
        int include = nums[n] + solveRec(nums,n-2);
        // Exclude case
        int exclude = 0 + solveRec(nums,n-1);
        return max(include,exclude);
    }   
    // Top down approach
    int solveTopDown(vector<int>&nums,int n,vector<int>&dp){
        // Base Case
        if(n < 0){
            return 0;
        }
        if(n == 0){
            return nums[0];
        }
        // Step 3 : Check if answer exists already
        if(dp[n] != -1)
            return dp[n];
        // Include case
        int include = nums[n] + solveTopDown(nums,n-2,dp);
        // Exclude case
        int exclude = 0 + solveTopDown(nums,n-1,dp);
        // Step 2 : Include in dp array
        dp[n] = max(include,exclude);
        return dp[n];
    }
    // Bottom up approach
    int solveTab(vector<int>&nums,int n){
        // Step 1 : Create dp array
        vector<int>dp(n+1,0);
        // Step 2 : Observe base case of top down
        dp[0] = nums[0];
        // Step 3 : Reverse flow of top down 
        for(int i = 1;i<=n;i++){
            int temp = 0;
            if(i-2>=0){
                temp = dp[i-2];
            }
            int include = temp + nums[i];
            int exclude = dp[i-1] + 0;
            dp[i] = max(include,exclude);
        }
        return dp[n];
    }
   // Space optimization
int spaceOpt(vector<int>& nums, int n) {
    int prev2 = 0;
    int prev1 = nums[0];
    int curr = 0;
    for (int i = 1; i < n; i++) { // Changed the loop condition to "< n" instead of "<= n"
        int temp = 0;
        if (i - 2 >= 0) {
            temp = prev2;
        }
        int include = temp + nums[i];
        int exclude = 0 + prev1;
        curr = max(include, exclude);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1)
        return nums[0];

    vector<int> arr1(nums.begin(), nums.end() - 1); // Corrected the range for arr1
    vector<int> arr2(nums.begin() + 1, nums.end()); // Corrected the range for arr2

    int ans1 = spaceOpt(arr1, n - 1); // Changed n to n - 1
    int ans2 = spaceOpt(arr2, n - 1); // Changed n to n - 1

    return max(ans1, ans2);
}

};
