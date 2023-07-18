// An element of array is leader if it is greater than or equal to all the elements to its right side.
vector<int> leaders(int a[], int n){

        vector<int> ans;
  
 // Last element of an array is always a leader,
 // push into ans array.
 int max = a[n - 1];
ans.push_back(a[n-1]);

  // Start checking from the end whether a number is greater
  // than max no. from right, hence leader.
  for (int i = n-2; i >= 0; i--)
    if (a[i] >= max) {
      ans.push_back(a[i]);
      max = a[i];
    }


reverse(ans.begin(),ans.end());
  
  return ans;
        
    }
