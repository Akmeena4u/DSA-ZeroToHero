class Solution {
public:
    // Memoization array to store intermediate results
    int t[51]; 

    // Recursive function to calculate the minimum extra characters
    int solve(int i, string& s, unordered_set<string>& st, int &n) {
        // Base case: If we reach or go past the end of the string, no more extra characters are needed
        if(i >= n) {
            return 0;
        }

        // Check if the current index 'i' is already solved and stored in the memoization array
        if(t[i] != -1) {
            return t[i];
        }

        // Case 1: Skip the current character and add 1 to the result, considering it as an extra character
        int result = 1 + solve(i+1, s, st, n);

        // Case 2: Try to form valid substrings from index 'i' and check in the dictionary
        for(int j = i; j < n; j++) {
            string curr = s.substr(i, j-i+1);  // Extract substring from 'i' to 'j'
            if(st.count(curr)) {
                // If the current substring is valid (exists in the dictionary), solve for the next part of the string
                result = min(result, solve(j+1, s, st, n));  // Take the minimum result between skipping and forming valid substring
            }
        }

        // Store the result for the current index 'i' in the memoization array and return it
        return t[i] = result;
    }

    // Main function to find the minimum number of extra characters needed
    int minExtraChar(string s, vector<string>& dict) {
        int n = s.length();  // Length of the input string

        // Initialize the memoization array with -1 (indicating unsolved states)
        memset(t, -1, sizeof(t)); 

        // Store dictionary words in an unordered_set for fast lookup
        unordered_set<string> st(begin(dict), end(dict));

        // Start solving from index 0
        return solve(0, s, st, n);
    }
};
