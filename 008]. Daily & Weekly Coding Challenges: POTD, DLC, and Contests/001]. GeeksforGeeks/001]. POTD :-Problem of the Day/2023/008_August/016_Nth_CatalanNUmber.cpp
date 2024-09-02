
// Catalan Number for N is equal to the number of expressions containing N pairs of
// paranthesis that are correct matched, i.e., 
// for each of the N '(' there exist N ')' on there right and vice versa.
//   Input:
// N = 5
// Output: 42


class Solution
{
    public:
    //Function to find the nth catalan number.
    long long int m = 1000000007;
    int findCatalan(int n) 
    {
        //code here
        int dp[n+1];
        dp[0] = dp[1] = 1;
        
        for(int i=2; i<=n; i++){
            long long int cat = 0;
            
            int k = 0, j = i-1;
            while(k<=j){
                if(k == j){
                    cat = ((cat % m)+((dp[k]% m) * (dp[j]% m)) % m) % m ;
                }else{
                    cat = ((cat % m)+ (((dp[k]% m) * (dp[j]% m)) + ((dp[j]% m) * (dp[k]% m))) % m)% m;
                }
                k++;
                j--;
            }
            dp[i] = cat;
        }
        return dp[n];
    }
};
