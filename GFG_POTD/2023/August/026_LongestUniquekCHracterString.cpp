class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
       int l, r;
        int n = s.size();
        
        l = r = 0;
        
        int ans = -1;
        map<char,int> f;
        
        while(r < n){
            ++f[s[r]];
            
            while(f.size() > k){
                --f[s[l]];
                if(f[s[l]] == 0)
                    f.erase(s[l]);
                    
                ++l;
            }
             
            if(f.size() == k)
                ans = max(ans, r - l + 1);
                
            ++r;
        }
        
        return ans;
    }
};
