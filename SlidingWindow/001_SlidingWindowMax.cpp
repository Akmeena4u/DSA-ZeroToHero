// Input:
// N = 9, K = 3
// arr[] = 1 2 3 1 4 5 2 3 6
// Output: 
// 3 3 4 5 5 5 6 


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        // process first k sized window
        for(int i = 0;i<k;i++){
            // Remove smaller elements
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            // Insert element
            dq.push_back(i);
        }
        // Store answer for 1st window
        ans.push_back(nums[dq.front()]);
        // Process remaining windows
        for(int i = k;i<nums.size();i++){
            // removal
            if(!dq.empty() && i-k>=dq.front())
                dq.pop_front();
            // addition
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            // Insert element
            dq.push_back(i);
            // ans store
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
