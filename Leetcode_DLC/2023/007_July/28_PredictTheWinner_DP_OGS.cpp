/*
  Input: nums = [1,5,2]
Output: false
Explanation: Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
Hence, player 1 will never be the winner and you need to return false.

//Approach-1 (Using same as Optimal Code Strategy

OGS--when its your turn do best mean choose max
and when its your oponenet turn expect worse from result mean he will also take max and for next your turn he will give min to u

  */

class Solution {
public:

int solve(vector<int>& nums, int l, int r) {
        
        if(l > r)
            return 0;
        
        if(l == r)
            return nums[l];
        
        
        int take_left  = nums[l] + min(solve(nums, l+2, r), solve(nums, l+1, r-1));
        
        int take_right = nums[r] + min(solve(nums, l, r-2), solve(nums, l+1, r-1));
        
        
        return max(take_left, take_right);
        
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        
        
      int  n = nums.size();
        
        
        int total = accumulate(begin(nums), end(nums), 0);
        
        int player1 = solve(nums, 0, n-1);
        int player2 = total - player1;
        
        return player1 >= player2;
    }
    
};
