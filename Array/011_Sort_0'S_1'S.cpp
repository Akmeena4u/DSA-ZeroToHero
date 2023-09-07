// Input:
// N = 5
// arr[] = {0, 0, 1, 1, 0}
// Output: 0 0 0 1 1

void segregate0and1(int arr[], int n) {
        // code here
        int i=0;
        int start=0;
        int end=n-1;
        while(i != end){
            if(arr[i]==0){
                swap(arr[start],arr[i]);
                i++;
                start++;
            }
            else{
                swap(arr[i],arr[end]);
                end--;
            }
        }
    }
