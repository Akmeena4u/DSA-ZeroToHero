/*
   N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6

  */


int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      if(N == 0 ){
            return 0;
        }
        
        sort(arr,arr+N);
        
        int ans = 1;
        int prev = arr[0];
        int cur = 1;
        
        for(int i = 1;i < N;i++){
            if(arr[i] == prev+1){
                cur++;
            }
            else if(arr[i] != prev){
                cur = 1;
            }
            prev = arr[i];
            ans = max(ans, cur);
        }
        return ans;
    }
