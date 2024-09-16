 int maxLength(string& S) {
        // code here
         stack<int> st;
        st.push(-1);
        int maxlen=0;
        
        for(int i=0;i<S.length();i++){
            char ch=S[i];
            
            if(ch=='('){
                st.push(i);
            }
            else{
                
                st.pop();
                
                if(st.empty()){
                    st.push(i);
                    
                }
                else{
                    int len=i-st.top();
                    maxlen=max(maxlen,len);
                }
            }
        }
        return maxlen;
    }
