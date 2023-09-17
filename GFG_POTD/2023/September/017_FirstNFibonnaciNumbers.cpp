class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
        //code here
          vector<long long> dup(n, 0);
        dup[0] = 1; dup[1] = 1;
        for(int i=2; i<n; i++) 
        {
            dup[i] = dup[i-1] + dup[i-2];
        }
        return dup;
    }
};
