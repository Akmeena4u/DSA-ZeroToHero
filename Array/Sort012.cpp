void sort012(int a[], int n)
    {
        // code here 
        
        int zeros , ones , twos;
        
        zeros=ones=twos=0;
        
        for(int i=0 ;i<n;i++){
              
              if(a[i]==0)   zeros++;
              
              else if(a[i]==1)    ones++;
              
              else  twos++;
            
        }
        
        int i=0;
        while(zeros--){
            a[i]=0;
            i++;
        }
        
        while(ones--){
            a[i]=1;
            i++;
        }
        
        while(twos--){
            a[i]=2;
            i++;
        }
        
        
    }
