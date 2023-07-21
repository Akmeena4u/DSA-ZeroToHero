/*
20/7/23
   S = hello
Output: h
Explanation: In the given string, the
first character which is non-repeating
is h, as it appears first and there is
no other 'h' in the string.
  */

//Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       //Your code here
        unordered_map<char,int>map;
        
       for(int i=0;i<S.length();i++) map[S[i]]++;
       
       for(int i=0;i<S.length();i++){
           if(map[S[i]]==1)return S[i];
       }
       return '$';
       
    }
