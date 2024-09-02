
/*
## Problem Statement:
Given a string representing a binary number, you need to find the binary representation of the next integer. The challenge is to perform this operation efficiently without converting the entire string to an integer because the string can be very large.
Example:
Input: "1011" (which is 11 in decimal)
Output: "1100" (which is 12 in decimal)

## Intuition: To find the next integer in binary representation:
Traverse the string from right to left.
Find the first '0' and change it to '1'.
Change all '1's before this '0' to '0'.
This approach handles the conversion without converting the entire string to an integer, thus avoiding potential overflow issues with large numbers.

*/
 
        string binaryNextNumber(string s) {
        // code here.
        bool indication=true;  // // Assume initially the string is all '1's
        for(int i=s.length();i>=0;i--){
            if(s[i]=='0'){
                indication=false; //// Not all '1's
                s[i]='1';   // Change the rightmost '0' to '1
                break;
            }
            else s[i]='0';  // Change '1' to '0'
        }
        if(indication){ 
            s='1'+s;   // If all '1's, prepend '1'
        }
        else{
            while(s[0]=='0')s.erase(s.begin());   // Remove leading zeros
        }
        return s;
    }


/*

Explanation:
# Indication Initialization:
The indication flag is set to true to assume the string consists of all '1's initially.

# Traversal and Conversion:
Traverse from the last character to the first.
If a '0' is found, it’s changed to '1', and indication is set to false to indicate the presence of a '0'. The loop then breaks.
If a '1' is found, it’s changed to '0'.

# Handling All '1's Case:
After the loop, if indication is still true, the original string was all '1's. In this case, prepend '1' to the string.

# Removing Leading Zeros:
Use s.erase(0, s.find_first_not_of('0')) to remove any leading zeros.

*/

