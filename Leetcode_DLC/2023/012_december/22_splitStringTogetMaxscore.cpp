/*1422. Maximum Score After Splitting a String
Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).

The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

 

Example 1:

Input: s = "011101"
Output: 5 
Explanation: 
All possible ways of splitting s into two non-empty substrings are:
left = "0" and right = "11101", score = 1 + 4 = 5 
left = "01" and right = "1101", score = 1 + 3 = 4 
left = "011" and right = "101", score = 1 + 2 = 3 
left = "0111" and right = "01", score = 1 + 1 = 2 
left = "01110" and right = "1", score = 2 + 1 = 3


*/

class Solution {
public:
    int maxScore(string str) {
        int result = 0;
        for (int i = 0; i < str.size() - 1; i++) {
            int currentScore = 0;
            for (int j = 0; j <= i; j++) {
                if (str[j] == '0') {
                    currentScore++;
                }
            }
            
            for (int j = i + 1; j < str.size(); j++) {
                if (str[j] == '1') {
                    currentScore++;
                }
            }
            
            result = max(result, currentScore);
        }
        
        return result;
    }
};