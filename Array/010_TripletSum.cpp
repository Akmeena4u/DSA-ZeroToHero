// Input:
// n = 6, X = 13
// arr[] = [1 4 45 6 10 8]
// Output:
// 1
// Explanation:
// The triplet {1, 4, 8} in 
// the array sums up to 13.

class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int arr[], int n, int X)
    {
        //Your Code Here
           sort(arr,arr+n);
        for(int i=0; i<n-2; i++){
            int low =i+1, high=n-1;
            
            while(low<high){
                if(arr[low]+arr[high] == X-arr[i])
                  return true;
                
                else if (arr[low]+arr[high] < X-arr[i])
                  low++;
                
                else{
                    high--;
                }  
            }
        }
        return false;
    }

};
