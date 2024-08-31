
// Input:
// N = 12
// Arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}
// Output: 3
// Explanation: There are 3 0's in the given array.

class Solution{   
public:
    int countZeroes(int arr[], int n) {
        // code here
        
        int count=0;
        for(int i = 0; i < n; i++){
            if(arr[i] == 0){
                count++;
            }
        }
        return count;
    }
};
