/*
    Example 1: Input: nums = [1,1,2] Output: 2, nums = [1,2,_]
    Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
    It does not matter what you leave beyond the returned k (hence they are underscores).
    Company Tags                : Facebook, Google, Amazon, Microsoft, Expedia, LinkedIn
    Leetcode Link               : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

/**************************************************************** C++ ****************************************************************/
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int i = 0, j = 1;
        
        while(j < n) {
            if(nums[i] != nums[j]) nums[++i] = nums[j];
            j++;
        }
        
        return i+1;
    }
};
