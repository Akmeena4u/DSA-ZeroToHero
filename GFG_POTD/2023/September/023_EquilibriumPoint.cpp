/*
problem-Given an array A of n positive numbers. The task is to find the first equilibrium point in an array. Equilibrium point in an array is a position such that the sum 
of elements before it is equal to the sum of elements after it.
Note: Return equilibrium point in 1-based indexing. Return -1 if no such point exists. 
*/



class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here

    long long totalSum = 0;
    long long leftSum = 0;

    // Calculating the total sum of the array
    if (n==1) {
    return 1;
}

    for (int i = 0; i < n; i++) {
        totalSum += a[i];
    }

    // Finding the equilibrium index
    for (int i = 0; i < n; i++) {
        // Subtract the current element from the total sum
        totalSum -= a[i];

        // If the left sum is equal to the total sum, return the current index
        if (leftSum == totalSum) {
            return i+1;
        }

        // Add the current element to the left sum for the next iteration
        leftSum += a[i];
    }

    // No equilibrium index found
    return -1;
    }

};
