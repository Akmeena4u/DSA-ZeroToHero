// Given a number N, check if a number is perfect or not. A number is said to be perfect if sum of all its factors excluding the number itself is equal to the number. Return 1 if the number is Perfect otherwise return 0.

// Example 1:

// Input:
// N = 6
// Output:
// 1 
// Explanation:
// Factors of 6 are 1, 2, 3 and 6.
// Excluding 6 their sum is 6 which
// is equal to N itself. So, it's a
// Perfect Number.





class Solution {
  public:
    int isPerfectNumber(long long N) {
        // code here
           long sum=1;
        if (N==1) return 0;
        for(long long i=2;i<=sqrt(N);i++)
        {
            if(N%i==0)
          {
            sum+=i;
            sum+=N/i;
          }
        }
        if(sum==N) return 1;
        else return 0;
    }
};
