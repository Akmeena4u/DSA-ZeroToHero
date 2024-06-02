/*
Problem statement-->
 
Given a string s of lowercase English characters, determine whether the summation of x and y is EVEN or ODD.
where:

x is the count of distinct characters that occupy even positions in the English alphabet and have even frequency. 
y is the count of distinct characters that occupy odd positions in the English alphabet and have odd frequency.


Note: Return "EVEN" if the sum of x & y is even otherwise return "ODD".

Example 1:

Input: 
s = "abbbcc"
Output: 
ODD
Explanation: 
x = 0 and y = 1 so (x + y) is ODD. 'a' occupies 1st place(odd) in english alphabets and its frequency is odd(1), 'b' occupies 2nd place(even) but its frequency is odd(3) so it doesn't get counted and 'c' occupies 3rd place(odd) but its frequency is even(2) so it also doesn't get counted.

*/

class Solution {
  public:
    string oddEven(string S) {
        unordered_map<char, int> m;
        for (int i = 0; i < S.size(); i++) {
            m[S[i]]++;
        }

        int ans = 0;
        for (auto x : m) {
            char ch = x.first;
            if ((ch - 'a'+1) % 2 != 0 && x.second % 2 != 0) { // Odd position in alphabet with odd frequency
                ans++;
            } else if ((ch - 'a'+1) % 2 == 0 && x.second % 2 == 0) { // Even position in alphabet with even frequency
                ans++;
            } else {
                continue;
            }
        }

        return (ans % 2 == 0) ? "EVEN" : "ODD";
        
    }    
};

/*

Algorithm-->

1. Store the frequency of each character in the map 
2. logic- Aceess each character and apply cond and increment ans accordingly and - Adding +1 to (ch - 'a') helps in this adjustment because without it, 'a' would always result in 0 (which is even in 0-based indexing), and 'b' would always result in 1 (odd in 0-based indexing), and so forth. By adding 1, we shift the positions so that 'a' becomes 1 (odd) and 'b' becomes 2 (even), aligning with the expected odd and even positions in the problem statement.

*/


// Driver Code.
