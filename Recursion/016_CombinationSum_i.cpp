/*
Given an array of integers and a sum B, find all unique combinations in the array where the sum is equal to B. The same number may be chosen from the array any number of times to make B.

Note:
        1. All numbers will be positive integers.
        2. Elements in a combination (a1, a2, …, ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
        3. The combinations themselves must be sorted in ascending order.


Example 1:

Input:
N = 4
arr[] = {7,2,6,5}
B = 16
Output:
(2 2 2 2 2 2 2 2)
(2 2 2 2 2 6)
(2 2 2 5 5)
(2 2 5 7)
(2 2 6 6)
(2 7 7)
(5 5 6)

  */



void f(int ind, vector<int>&arr, int target, vector<int>&v, vector<vector<int>>&ans){
        if(ind==arr.size()){
            if(target==0){
                //sort(v.begin(),v.end());
                ans.push_back(v);
            }
            return ;
        }
        
        if(target>=arr[ind]){
            v.push_back(arr[ind]);
            f(ind, arr, target-arr[ind],v,ans);
            v.pop_back();
        }
        
        f(ind+1, arr, target, v,ans);
    }


vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<int>v;
        vector<vector<int>>ans;
        set<int>st(A.begin(),A.end());
        vector<int>arr(st.begin(),st.end());
        f(0,arr,B,v,ans);
        //sort(ans.begin(),ans.end());
        return ans;
        
    }
