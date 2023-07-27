class Solution {
public:
    typedef long long ll;
    
    bool possible(vector<int>& batteries, ll mid_time, int n) {
        
        ll target = n*mid_time; //each computer will run mid_time minutes
        
        ll sum = 0;
        
        for(int i = 0; i<batteries.size(); i++) {
            
            target -= min((ll)batteries[i], mid_time);
            
            if(target <= 0)
                return true;
            
        }
        return target <= 0;
    }
    
    long long maxRunTime(int n, vector<int>& batteries) {
        
        ll l = *min_element(begin(batteries), end(batteries));
        
        long long sum_total_minutes = 0;
        
        for(auto &mints : batteries){
            sum_total_minutes += mints;
        }
        
        ll r = sum_total_minutes/n;
        
        ll result = 0;
        
        while(l <= r) {
            
            ll mid_time = l + (r-l)/2;
            
            if(possible(batteries, mid_time, n)) {
                result = mid_time;
                l = mid_time+1;
            } else {
                r = mid_time-1;
            }
        }
        
        return result;
    }
};
