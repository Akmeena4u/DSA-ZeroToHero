//You are given an array A (distinct integers) of size N, and you are also given a sum. You need to find if two numbers in A exists that have sum equal to the given sum.

//Method 1
int sumExists(int arr[], int n, int sum){
    
    
    //code here
     int match = 0;
    int ans = 0;
    for(int i = 0; i<n ; i++){
        match = arr[i];
        for(int j = i + 1; j<n; j++){
            if((match + arr[j]) == sum){
                ans = 1;
            }
        }
    }
    
    return ans;
    
}


//Method 2

int sumExists(int arr[], int n, int sum){
    
    
    //code here
    sort(arr, arr + n);
    int low = 0;
    int high = n - 1;

    while (low < high)
    {
        int s = arr[low] + arr[high];
        if (s == sum)
        {
            return 1;
        }
        else if (s > sum)
        {
            high--;
        }
        else
        {
            low++;
        }
    }
    return 0;
    
    
    
}
