#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int maxProfit = 0;
	int mini = prices[0];
	
	for(int i=1;i<prices.size();i++){
        int curProfit = prices[i] - mini;
        maxProfit = max(maxProfit,curProfit);
        mini = min(mini,prices[i]);
        }
	return maxProfit;
}
