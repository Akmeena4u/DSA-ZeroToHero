//The cost of stock on each day is given in an array price[] of size n. Each day you may decide to either buy or sell the stock i at price[i], you can even buy and sell the stock on the same day, Find the maximum profit which you can get.

int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
         int maxProfit = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1]) {
                maxProfit += (prices[i] - prices[i - 1]);
            }
        }
        return maxProfit;
    
    }
