// Given three integers n, k, target, and an array of coins of size n. Find if it is possible to make a change of target cents by using
// an infinite supply of each coin but the total number of coins used must be exactly equal to k.

// Example 1:

// Input:
// n = 5, k = 3, target = 11
// coins = {1, 10, 5, 8, 6}

// Output: 
// 1

// Explanation: 
// 2 coins of 5 and 1 coins of 1 can be used 
// to make change of 11 i.e. 11 => 5+5+1.


class Solution {
  public:
  bool canMakeChangeUtil(int target, int k, vector<int>& coins, int n, vector<vector<vector<int>>>& dp) {
    if (k == 0 && target == 0) {
        return true;
    }

    if (k < 0 || target < 0 || n == 0) {
        return false;
    }

    if (dp[n][k][target] != -1) {
        return dp[n][k][target];
    }

    // Exclude the current coin.
    bool excludeCoin = canMakeChangeUtil(target, k, coins, n - 1, dp);

    // Include the current coin if it doesn't exceed the target and k.
    bool includeCoin = false;
    if (coins[n - 1] <= target && k > 0) {
        includeCoin = canMakeChangeUtil(target - coins[n - 1], k - 1, coins, n, dp);
    }

    dp[n][k][target] = excludeCoin || includeCoin;
    return dp[n][k][target];
}



    bool makeChanges(int N, int k, int target, vector<int> &coins) {
        // code here
        int n = coins.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(target + 1, -1)));

    return canMakeChangeUtil(target, k, coins, n, dp);
    }
};
