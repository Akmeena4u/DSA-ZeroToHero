/*
S = hello
Output: h
  */

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
