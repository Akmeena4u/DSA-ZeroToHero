// Given an array of positive integers nums and a positive integer target, return the minimal length of a 
// subarray
//  whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.



class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
         int i = 0;
        int j = 0;
        int sum = 0;
        int len = INT_MAX;
        while(j<nums.size()){
            // include current number
            sum = sum + nums[j];
            // Sum of one window is ready
            while(sum>=target){
                len = min(len,j-i+1);
                sum = sum - nums[i];
                i++;
            }
            j++;
        }
        if(len == INT_MAX){
            return 0;
        }
        return len;
    }
};
