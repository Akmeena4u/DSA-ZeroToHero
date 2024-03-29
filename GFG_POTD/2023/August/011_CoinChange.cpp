 // Recursive code
    int solveRec(vector<int> &coins, int amount)
    {
        // Base case
        if (amount == 0)
        {
            return 0;
        }
        if (amount < 0)
        {
            // Simply mark the value that here answer won't come
            return INT_MAX;
        }
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int ans = solveRec(coins, amount - coins[i]);
            if (ans != INT_MAX)
            {
                // Update mini as we have got valid answer
                // Adding 1 so as to consider previous coin which was included
                mini = min(mini, 1 + ans);
            }
        }
        return mini == INT_MAX ? INT_MAX : mini; // Handle INT_MAX case separately
    }

    // Top down approach
    int solveTopDown(vector<int>& coins, int amount, vector<int>& dp)
    {
        // Base case
        if (amount == 0)
        {
            return 0;
        }
        if (amount < 0)
        {
            // Simply mark the value that here answer won't come
            return INT_MAX;
        }
        // Step - 3 : Check if answer already exists?
        if (dp[amount] != -1){
            return dp[amount];
        }
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int ans = solveTopDown(coins, amount - coins[i], dp);
            if (ans != INT_MAX)
            {
                // Update mini as we have got valid answer
                // Adding 1 so as to consider previous coin which was included
                mini = min(mini, 1 + ans);
            }
        }
        // Step 2 : Update in the dp array
        dp[amount] = mini == INT_MAX ? INT_MAX : mini; // Handle INT_MAX case separately
        return dp[amount];
    }

    // Bottom up approach
    int solveTab(vector<int>& coins, int amount)
    {
        // Step 1 : Create dp array 
        vector<int>dp(amount+1,INT_MAX);
        // Step 2 : Observe base case of top down approach
        dp[0] = 0;
        // Step 3 : Reverse the flow in top down approach
        for(int i = 1;i<=amount;i++){
            for(int j = 0;j<coins.size();j++){
                if(i-coins[j]>=0 && dp[i-coins[j]] != INT_MAX){
                    int ans = dp[i-coins[j]];
                    dp[i] = min(dp[i],1+ans);
                }
            }
        }
        return dp[amount];
    }

    int coinChange(vector<int> &coins, int amount)
    {
        // Recursive code
        // int ans = solveRec(coins, amount);
        // if (ans == INT_MAX)
        // {
        //     // Directed by question
        //     return -1;
        // }
        // return ans;

        // Top down approach
        // Step 1 : Create dp array
        // vector<int> dp(amount + 1, -1);
        // int ans = solveTopDown(coins, amount, dp);
        // if (ans == INT_MAX) 
        //     return -1;
        // return ans;

        // Bottom up approach
        int ans = solveTab(coins, amount);
        if (ans == INT_MAX)
            return -1;
        return ans;
    }

    // Count number of ways to make 'sum' using 'coins'
    long long int count(int coins[], int N, int sum) {
        vector<long long int> dp(sum + 1, 0);
        dp[0] = 1; // Base case, there is one way to make sum=0 (by not selecting any coin)

        for (int i = 0; i < N; i++) {
            for (int j = coins[i]; j <= sum; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }

        return dp[sum];
    }
