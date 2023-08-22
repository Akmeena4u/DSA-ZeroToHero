// Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

// For example:
// A -> 1
  
// Input: columnNumber = 28
// Output: "AB"

class Solution {
public:
    string convertToTitle(int columnNumber) {
         string s;
        
        while(columnNumber) {
            columnNumber--;
            
            int remain = columnNumber%26;
            char ch    = remain + 'A';
            s.push_back(ch);
            
            columnNumber /= 26;
            
        }
        
        reverse(begin(s), end(s));
        return s;  
    }
};
