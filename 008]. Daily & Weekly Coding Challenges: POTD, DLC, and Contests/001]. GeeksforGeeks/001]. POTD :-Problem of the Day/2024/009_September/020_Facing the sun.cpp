 int countBuildings(vector<int> &height) {
        // code here
         int ans = 1, mx = height[0];
        for(auto x:height){
            if(x>mx){
                mx=x;
                ans++;
            }
        }
        return ans;
    }
