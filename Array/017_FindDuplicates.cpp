class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        vector<int> ans;
        sort(arr,arr+n);
        for(int i=1;i<n;i++)
        {
            if(arr[i]==arr[i-1] && arr[i]!=arr[i+1])
            {
                ans.push_back(arr[i]);
            }
        }
        if(ans.empty())
        {
            return {-1};
        }
        return ans;
    }
};
