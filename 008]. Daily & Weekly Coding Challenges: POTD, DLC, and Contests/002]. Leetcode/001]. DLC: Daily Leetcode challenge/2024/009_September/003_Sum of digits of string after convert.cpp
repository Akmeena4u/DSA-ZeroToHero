/*
Problem: 1945. Sum of Digits of String After Convert
problem link: https://leetcode.com/problems/sum-of-digits-of-string-after-convert/

For example, if s = "zbax" and k = 2, then the resulting integer would be 8 by the following operations:

Convert: "zbax" ➝ "(26)(2)(1)(24)" ➝ "262124" ➝ 262124
Transform #1: 262124 ➝ 2 + 6 + 2 + 1 + 2 + 4 ➝ 17
Transform #2: 17 ➝ 1 + 7 ➝ 8
Return the resulting integer after performing the operations described above.

*/

int getLucky(string s, int k) {
        string num = "";

        for(char &ch : s) {
            int char_int = ch - 'a' + 1; //a : 1, b : 2 and so on...
            num         += to_string(char_int);
        }
        
        int sum = 0;

        while(k--) {
            sum = 0;
            for(char &ch : num) {
                sum += ch - '0';
            }

            num = to_string(sum);
        }

        return stoi(num);
    }
