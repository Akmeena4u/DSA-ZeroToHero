string reverseWords(string str) {
        // code here
        int j=0;
        for(int i=0;i<str.length();i++){
            if(str[i]=='.'){
                reverse(str.begin()+j,str.begin()+i);
                j=i+1;
            }
            else if(i==str.length()-1)reverse(str.begin()+j,str.end());
        }
        reverse(str.begin(),str.end());
        return str;
    }
