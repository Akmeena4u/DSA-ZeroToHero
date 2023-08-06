 //Complete this function
    void sol(string s,vector<string>&ans,int ind){
        
        if(ind==s.length())
          {
              ans.push_back(s);
              return;
          }
        
        for(int i=ind;i<s.length();i++){
            swap(s[i],s[ind]);
            sol(s,ans,ind+1);
            swap(s[i],s[ind]);
        }
        
        
        
        
    }
    
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string> ans;
        sol(S,ans,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
