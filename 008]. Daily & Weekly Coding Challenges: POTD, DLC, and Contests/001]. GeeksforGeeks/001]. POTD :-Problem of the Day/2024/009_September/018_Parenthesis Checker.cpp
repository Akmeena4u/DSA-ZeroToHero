 bool ispar(string x)
    {
        // Your code here
        unordered_map<char,char> mm;
        mm[')']='(';
        mm[']']='[';
        mm['}']='{';
        stack<char> st;
        for(auto c:x){
            if(c=='(' or c=='[' or c=='{')st.push(c);
            else if(st.empty())return false;
            else{
                if(st.top()!=mm[c])return false;
                st.pop();
            }
        }
        return st.empty();
    }
