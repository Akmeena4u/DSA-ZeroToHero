//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        // Create a max heap to store the pairs of absolute
    // differences and negative values
    priority_queue<pair<int, int> > maxH;
   
      int m = arr.size();
 
    for (int i = 0; i < m; i++) {
        // Skip if the element is equal to x
        if (arr[i] == x)
            continue;
 
        // Calculate the absolute difference and add the
        // pair to the max heap
        maxH.push({ abs(arr[i] - x), -arr[i] });
 
        // If the size of the max heap exceeds k, remove the
        // element with the maximum absolute difference
        if (maxH.size() > k)
            maxH.pop();
    }
 
    // Store the result in a vector
    vector<int> result;
 
    // Retrieve the top k elements from the max heap
    while (!maxH.empty()) {
        // Get the top element from the max heap
        auto p = maxH.top();
        maxH.pop();
 
        // Add the negative value to the result vector
        result.push_back(-p.second);
    }
 
    // Reverse the result vector to get the closest numbers
    // in ascending order
    reverse(result.begin(), result.end());
 
    return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
