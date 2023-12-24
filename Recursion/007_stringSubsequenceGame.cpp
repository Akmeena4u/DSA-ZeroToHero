/*
Given a string return all unique possible subsequences which start with vowel and end with consonant. A String is a subsequence of a given String, 
that is generated by deleting some character of a given string without changing its order.
NOTE: Return all the unique subsequences in lexicographically sorted order. 

Example 1:

Input: S = "abc"
Output: "ab", "ac", "abc" 

  */





class Solution {
  public:
  
  
       bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    bool isConsonant(char c) {
        return !isVowel(c);
    }

    void solve(int i, string s, string &f, set<string> &result) {
        if (i == s.length()) {
            if (f.length() > 0 && isVowel(f[0]) && isConsonant(f.back())) {
                result.insert(f);
            }
            return;
        }
        // picking 
        f += s[i];
        solve(i + 1, s, f, result);
        // popping out while backtracking
        f.pop_back();
        solve(i + 1, s, f, result);
    }

    set<string> allPossibleSubsequences(string S) {
        set<string> result;
        string f = "";   //f= currently formed subsequnce 
        solve(0, S, f, result);
        return result;
    }
};
