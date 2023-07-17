//You are given array nums of n length and an integer k .return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

int longestOnes(int n, vector<int>& nums, int k) {
        // Code here
          int cnt = 0;
        int maxi = 0;
        int left = 0; // Left pointer for the sliding window
        int zeros = 0; // Count of zeros in the current window

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {
                zeros++;
            }

            while (zeros > k) {
                if (nums[left] == 0) {
                    zeros--;
                }
                left++;
            }

            maxi = max(maxi, right - left + 1);
        }

        return maxi;
    }
