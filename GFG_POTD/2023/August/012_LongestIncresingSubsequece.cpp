// Input:
// N = 16
// A = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15}
// Output: 
// 6
// Explanation:
// There are more than one LIS in this array. One such Longest increasing subsequence is {0,2,6,9,13,15}.

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<int> dp{a[0]};
        
        for (int i = 0; i < n; i++){
            if(a[i] > dp.back()) dp.push_back(a[i]);
            else {
                auto it = lower_bound(dp.begin(), dp.end(), a[i]);
                *it= a[i];
            }
        }
        return dp.size();
    }

};
