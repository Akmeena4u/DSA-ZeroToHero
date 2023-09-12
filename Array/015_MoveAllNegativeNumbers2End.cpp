// Given an unsorted array arr[] of size N having both negative and positive integers. The task is place all negative element at the end of array without changing the order of positive element and negative element.

 

// Example 1:

// Input : 
// N = 8
// arr[] = {1, -1, 3, 2, -7, -5, 11, 6 }
// Output : 
// 1  3  2  11  6  -1  -7  -5

void segregateElements(int arr[],int n)
    {
        // Your code goes here
      
      int a[n];
      
      int i=0;
      
      for(int x=0;x<n;x++){
          if(arr[x]>0){
              a[i]=arr[x];
               i++;
      } 
              
              
  }
  
  
  for(int x=0;x<n;x++){
          if(arr[x]<0){
              a[i]=arr[x];
               i++;
      } 
              
              
  }
  
  
  for(int x=0;x<n;x++){
          
              arr[x]=a[x];
               
      } 
}
};
