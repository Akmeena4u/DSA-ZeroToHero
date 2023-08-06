// Input:
// n = 5
// m = 4
// arr = {1, 2, 3, 4, 5}
// Output: 
// 4
// Explanation: 
// Maximum difference can be achieved by making these two sets {1, 2, 3, 4} and {2, 3, 4, 5} of m=4 students.
// Difference of sum of numbers of these two sets will be | (1+2+3+4) -  (2+3+4+5) | = 4.


class Solution{
public:
    int diffSum(int n,int m,int arr[])
    {
        //write your code here
        sort(arr,arr+n);
        int maxSum = 0;
        for (int i = n - 1; i >= n - m; i--) {
            maxSum += arr[i];
        }

        int minSum = 0;
        for (int i = 0; i < m; i++) {
            minSum += arr[i];
        }

        return maxSum - minSum;
        
    }
};
