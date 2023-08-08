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
