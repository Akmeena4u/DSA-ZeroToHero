int changeUtil(int amount, vector<int>& coins, int n, vector<vector<int>>& dp) {
    // If the amount is 0, there's one way (no coins).
    if (amount == 0) {
        return 1;
    }

    // If either the amount or the number of coin types becomes negative, there's no way to make change.
    if (amount < 0 || n <= 0) {
        return 0;
    }

    // If we have already calculated the result for this amount and number of coins, return it.
    if (dp[n][amount] != -1) {
        return dp[n][amount];
    }

    // Try two options: including the current coin and excluding it.
    int includeCoin = changeUtil(amount - coins[n - 1], coins, n, dp);
    int excludeCoin = changeUtil(amount, coins, n - 1, dp);

    // Store the result in the memoization table and return it.
    dp[n][amount] = includeCoin + excludeCoin;
    return dp[n][amount];
}

int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

    return changeUtil(amount, coins, n, dp);
}
