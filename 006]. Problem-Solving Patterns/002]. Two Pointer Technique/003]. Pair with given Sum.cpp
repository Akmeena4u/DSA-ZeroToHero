// Input:
// n = 7
// arr[] = {1, 2, 3, 4, 5, 6, 7}
// K = 8
// Output:
// 3
// Explanation:
// We find 3 such pairs that
// sum to 8 (1,7) (2,6) (3,5)


class Solution{
  public:
    int Countpair(int arr[], int n, int sum){
        
        // Complete the function
    int count=0;
    int i=0;
    int j=n-1;
    
    while(i<j){
        if(arr[i]+arr[j]==sum){
            count++;
            j--;
            i++;
        }else if(arr[i]+arr[j]>sum){
            j--;
        }else{
            i++;
        }
    }
    return count==0?-1:count;
    
        
    }
};
