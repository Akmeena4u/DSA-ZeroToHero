 //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        // code here
         vector<vector<int>> result;
        int mini = A[0];

        for (int i = 1; i < n; i++) {
            if (A[i] > A[i - 1]) {
                vector<int> transaction = {mini, A[i]};
                result.push_back(transaction);
            }
            mini = min(mini, A[i]);
        }

        return result;
    }
