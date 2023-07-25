int peakIndexInMountainArray(vector<int>& arr) {
          // Your code here
          int n=arr.size();
         if (n == 1) return 0;
                 
       int s=0;
       int e=n-1;
       
       while(s<e){
           
           int mid=s+(e-s)/2;
           
           
           if(arr[mid]<arr[mid+1]   && mid+1<=e )    s=mid+1;
           
           else      e=mid; //important
       }
       
       return s;
       
    }
