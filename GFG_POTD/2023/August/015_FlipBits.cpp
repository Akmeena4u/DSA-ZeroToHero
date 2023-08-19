// Input:
// N = 5
// A[] = {1, 0, 0, 1, 0} 
// Output:
// 4
// Explanation:
// We can perform a flip operation in the range [1,2]
// After flip operation array is : [ 1 1 1 1 0 ]
// Count of one after fliping is : 4
// [Note: the subarray marked in bold is the flipped subarray]

class Solution{
    public:
int maxOnes(int a[], int n)
    {
        int maxi=0,initial=0,cnt=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==1)initial++;
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]==1)
            {
                if(cnt>0)
                {
                    cnt--;
                }
                else
                {
                    cnt=0;
                }
            }
            else
            {
                cnt++;
                
            }
            maxi=max(maxi,cnt);
        }
        return initial+maxi;
    }
};
