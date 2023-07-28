/*
 leetcode 2390
 Remove the closest non-star character to its left, as well as remove the star itself.
 Input: s = "leet**cod*e"
Output: "lecoe"
*/

//Approach-1 (Using Stack)
class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        
        for(char &ch : s) {
            
            if(ch == '*') {
                st.pop();
            } else {
                st.push(ch);
            }
            
        }
        
        string result = "";
        
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        
        reverse(begin(result), end(result));
        return result;
    }
};

//Approach-2 (using string as stack)
class Solution {
public:
    string removeStars(string s) {
        string result = "";
        
        for(char &ch : s) {
            
            if(ch == '*') {
                result.pop_back();
            } else {
                result.push_back(ch);
            }
            
        }
        
        return result;
    }
};
