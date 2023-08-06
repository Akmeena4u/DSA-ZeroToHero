// Given a string s, you choose some substring s[l...r] (1 ≤ l ≤ r ≤ |s|) exactly once and reverse it. For example, in the string geeks, select the substring s[2...4], after performing the mentioned operation, the new string will be gkees.

// Count the number of unique strings that can be obtained by doing this operation exactly once.

// Example 1:

// Input:
// s = "abaaa"
// Output: 
// 5
// Explanation: 
// Take every possible substring and operate on it.
// Possible strings after doing the operation are:
// "baaaa", "abaaa", "aabaa", "aaaba" and "aaaab".


//tle problem

//User function Template for C++

class Solution{
public:
    long long int countStrings(string s){
        // Your code goes here
        //unique means ------set
        
        //findout all substrings
        
        unordered_set<string> uniqueString;
        for(int i=0;i<s.length();i++){
            
            for(int j=i+1;j<=s.length();j++){
                string substring=s.substr(i,j-i);
                
                //reverse these substreings
                string reversed=substring;
                reverse(reversed.begin(),reversed.end());
                
                string newstr=s.substr(0,i)+reversed+s.substr(j);
                
                uniqueString.insert(newstr);
            }
        }
        return uniqueString.size();
    }
};
