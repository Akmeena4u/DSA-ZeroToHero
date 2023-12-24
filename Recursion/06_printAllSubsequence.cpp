//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Solution{
	public:
		 void solve(const string& s, int ind, string& str, vector<string>& result) {
		     
        if (ind >= s.size()) {
            result.push_back(str);
            return;
        }

        solve(s, ind + 1, str, result); //take 
        str.push_back(s[ind]);
        solve(s, ind + 1, str, result); //not take 
        str.pop_back(); // Backtrack to remove the last character
    }

    std::vector<std::string> AllPossibleStrings(const std::string& s) {
        int i = 0;
        string str = "";
        vector<string> result;
        solve(s, i, str, result);

        sort(result.begin(), result.end());

        return result;
    }
};

