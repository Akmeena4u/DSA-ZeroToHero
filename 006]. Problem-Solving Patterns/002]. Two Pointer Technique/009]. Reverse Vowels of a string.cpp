/*
  345. Reverse Vowels of a String
    
    Given a string s, reverse only all the vowels in the string and return it.
    The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
    Example 1:
    Input: s = "hello"
    Output: "holle"

    Company Tags                : Google, Zoho, Flipkart, 
    Leetcode Link               : https://leetcode.com/problems/reverse-vowels-of-a-string/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/reversing-the-vowels5304/1
*/

//Simply using  Two pointer technique
class Solution {
public:
    bool isVowel(char &ch) {
        return ch =='a' || ch == 'e' ||
               ch =='i' || ch == 'o' ||
               ch == 'u' ||
               ch =='A' || ch == 'E' ||
               ch =='I' || ch == 'O' ||
               ch == 'U';
    }
    string reverseVowels(string s) {
        int n = s.length();
        int i = 0;
        int j = n-1;
        
        while(i < j) {
            if(!isVowel(s[i])) i++;
            
            else if(!isVowel(s[j])) j--;
            
            else {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        
        return s;
    }
};
