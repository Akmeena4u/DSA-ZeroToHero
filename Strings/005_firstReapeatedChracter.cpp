/*

Given a string consisting of lowercase english alphabets. Find the repeated character present first in the string.

Example 1:

Input:
S = "geeksforgeeks"
Output: g
Explanation: g, e, k and s are the repeating
characters. Out of these, g occurs first. 
  */

class Solution
{
  public:
    char firstRep (string s)
    {
        //code here.
         //code here.
        for(int i = 0; i < s.length(); i++)
            for(int j = 1 + i; j <= s.length(); j++)
                if(s[i] == s[j])
                    return s[i];
        return '#';
    }
};
