#Given an array of size n which contains all elements occurring in multiples of K, except one element which doesn't occur in multiple of K. Find that unique element.

class Solution{
  public:
    int findUnique(int a[], int n, int k) {
          sort(a , a+n);
          
          for(int i=0; i<n; i=i+k){
              if(a[i] != a[i+k-1]){
                  return a[i];
              }
          }
          return -1;
    }

};
