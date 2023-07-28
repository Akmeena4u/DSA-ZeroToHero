 string minRemoveToMakeValid(string s) {
          string ans;
        stack<int> st; // Use a stack to store the indices of opening brackets
        
        // Mark indices of invalid closing brackets
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    s[i] = '*'; // Mark invalid closing bracket with '*'
                }
            }
        }
        
        // Mark remaining unmatched opening brackets with '*'
        while (!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }
        
        // Construct the valid string without '*' characters
        for (char ch : s) {
            if (ch != '*') {
                ans += ch;
            }
        }
        
        return ans;
    }
