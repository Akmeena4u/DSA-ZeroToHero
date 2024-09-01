// You are given an array A (distinct integers) of size N, and 
// you are also given a sum. You need to find if two numbers in A exists that have sum equal to the given sum.
//   Examples:
// Input:
// 1
// 10
// 1 2 3 4 5 6 7 8 9 10
// 14
// Output:
// 1


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
