
//Approch -1


class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    int SecondL=-1;
	    std::sort(arr,arr+n);
    int largest =arr[n-1];
	    for(int i=n-2;i>=0;i--)
	    {
	        if(arr[i]!=largest)
	        {
	            SecondL=arr[i];
	            break;
	            
	        }
	    }
	    return SecondL;
	}
};




//Apprroch 2

#include <bits/stdc++.h> 
int findSecondLargest(int n, vector<int> &arr)
{
    // Write your code here.
    if(n<2)  return -1;
    
    int largest=INT_MIN;
    int secondlargest=INT_MIN;
    
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            secondlargest=largest;
            largest=arr[i];
        }

        //if arr[i] is in inbetween largets and secondlargets
        
        else if(arr[i]>secondlargest && arr[i]!=largest){
            secondlargest=arr[i];
        }
    }
    
    if(secondlargest==INT_MIN){
        return -1;
    }

    return secondlargest;
}
