/*Approch:-
  Create a temp string and store concatenation of str1 to str1 in temp, i.e temp = str1.str1
  If str2 is a substring of temp then str1 and str2 are rotations of each other.
  */

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string str1,string str2)
    {
        // Your code here
    if (str1.length() != str2.length())
        return false;
 
    string temp = str1 + str1;
        return (temp.find(str2) != string::npos);
    }
};
