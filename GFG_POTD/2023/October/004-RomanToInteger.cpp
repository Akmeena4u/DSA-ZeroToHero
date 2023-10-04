/*Given a string in roman no format (s)  your task is to convert it to an integer . Various symbols and their values are given below.
I 1
V 5
X 10
L 50
C 100
D 500
M 1000

Example 1:

Input:
s = V
Output: 5*/



#include <string>

class Solution {
public:
    int romanToDecimal(std::string &s) {
        // Create a map to associate Roman numerals with decimal values.
        std::unordered_map<char, int> mymap {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int value = 0;
        for (int i = 0; i < s.size(); ++i) {
            // Check if the current Roman numeral is smaller than the next one.
            // If yes, subtract its value; otherwise, add its value.
            if (i + 1 < s.size() && mymap[s[i]] < mymap[s[i + 1]]) {
                value -= mymap[s[i]];
            } else {
                value += mymap[s[i]];
            }
        }
        return value;
    }
};
