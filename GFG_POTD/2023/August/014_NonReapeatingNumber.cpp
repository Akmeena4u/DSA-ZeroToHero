// Input: 
// N = 2
// arr[] = {1, 2, 3, 2, 1, 4}
// Output:
// 3 4 
// Explanation:
// 3 and 4 occur exactly once.

 class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        unordered_map<int,int>m;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        m[nums[i]]++;
         for(int i=0;i<nums.size();i++)
         if(m[nums[i]]==1)
             ans.push_back(nums[i]);
    sort(ans.begin(),ans.end());
    return ans;
    }
};
