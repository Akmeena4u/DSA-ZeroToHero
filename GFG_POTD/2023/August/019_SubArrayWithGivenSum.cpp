//Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
         int left = 0;
        int right = 0;
        long long currentSum = 0;
        
         if(s==0)return {-1};

        while (right < n)
        {
            currentSum += arr[right];

            while (currentSum >= s) // Handle the case when the sum becomes equal to or greater than s.
            {
                if (currentSum == s)
                {
                    return vector<int>{left + 1, right + 1}; // Adding 1 to convert to 1-based index.
                }
                currentSum -= arr[left];
                left++;
            }

            right++;
        }

        return vector<int>{-1}; // Subarray not found
    
    }
