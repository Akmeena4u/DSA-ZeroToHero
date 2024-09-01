

/*
Varient 1- 
Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Leetcode Problem link- https://leetcode.com/problems/reverse-words-in-a-string-iii/
*/
string reverseWords(string s) {
        
   
        int i = 0;
        //hero honge hamare l and r jo revrese karenge words ko
        int l = 0, r = 0;
        
        int n = s.length();
        
        while(i < n) {
            while(i < n && s[i] != ' ') { //i ko agar char dikha to r ko dega and i++ and r++
                s[r++] = s[i++];
            }
            
            if(l < r) { //l     r
                reverse(s.begin()+l, s.begin()+r);
                
                s[r] = ' ';
                r++;
                
                l = r;
            }
            
            i++; //y eto badhta rahega
        }
        
        s = s.substr(0 , r-1);
        
        return s;
    }

/*

Variant 2 - GFG - Reverse each word in a given string
Example 1:

Input:
S = "i.like.this.program.very.much"
Output: 
i.ekil.siht.margorp.yrev.hcum
Explanation: 
The words are reversed as
follows:"i" -> "i","like"->"ekil",
"this"->"siht","program" -> "margorp",
"very" -> "yrev","much" -> "hcum".

Problem Link - https://www.geeksforgeeks.org/problems/reverse-each-word-in-a-given-string1001/1



*/
string reverseWords (string s)
    {
        //code here.
         int i = 0;
        int l = 0, r = 0;
        int n = s.length();

        while (i < n) {
            // Move r to the next period or end of string
            while (i < n && s[i] != '.') {
                s[r++] = s[i++];
            }

            // Reverse the current word
            if (l < r) {
                std::reverse(s.begin() + l, s.begin() + r);
                l = r;  // Update l to r's position
            }

            // Copy periods directly and update r and l accordingly
            while (i < n && s[i] == '.') {
                s[r++] = s[i++];
            }
            l = r;  // Update l to r's position after copying periods
        }

        // Trim the result if there are trailing characters beyond the processed string
        s = s.substr(0, r);

        return s;
    }
