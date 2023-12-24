/*
You are given an integer array nums that may contain duplicates. Your task is to return all possible subsets. Return only unique subsets and they can be in any order.

Note: The individual subsets should be sorted.

Example:

Input: 
nums = [1,2,2] 
Output: 
[[],[1],[1,2],[1,2,2],[2],[2,2]]
Explanation: 
We can have subsets ranging from length 0 to 3. which are listed above. Also the subset [1,2] appears twice but is printed only once as we require only unique subsets.


  */




class Solution {

  public:
  
   void findSubsets(int ind, vector < int > & nums, vector < int > & ds, vector < vector < int >> & ans) {
         ans.push_back(ds);
         for (int i = ind; i < nums.size(); i++) {
            if (i != ind && nums[i] == nums[i - 1]) continue;
            ds.push_back(nums[i]);
            findSubsets(i + 1, nums, ds, ans);
            ds.pop_back();
         }
      }
 
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        // Write your code here
         vector < vector < int >> ans;
         vector < int > ds;
         sort(nums.begin(), nums.end());
         findSubsets(0, nums, ds, ans);
         return ans;
    }
};
