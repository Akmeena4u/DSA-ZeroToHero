//Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element.


//App-1--Hashing method
class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {
        // Your code goes here
        int hash[n + 1] = {0}; //hash array

    // storing the frequencies:
    for (int i = 0; i < n - 1; i++)
        hash[array[i]]++;

    //checking the freqencies for numbers 1 to N:
    for (int i = 1; i <= n; i++) {
        if (hash[i] == 0) {
            return i;
        }
    }

    // The following line will never execute.
    // It is just to avoid warnings.
    return -1;
    }
};

//Time Complexity: O(N) + O(N) ~ O(2*N)
//Space Complexity: O(N),



//App-2--Summition method
int missingNumber(vector<int>&a, int N) {

    //Summation of first N numbers:
    int sum = (N * (N + 1)) / 2;

    //Summation of all array elements:
    int s2 = 0;
    for (int i = 0; i < N - 1; i++) {
        s2 += a[i];
    }

    int missingNum = sum - s2;
    return missingNum;
}

//Time Complexity: O(N)
//Space Complexity: O(1)


//App3-XOR method

int missingNumber(vector<int>&a, int N) {

    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < N - 1; i++) {
        xor2 = xor2 ^ a[i]; // XOR of array elements
        xor1 = xor1 ^ (i + 1); //XOR up to [1...N-1]
    }
    xor1 = xor1 ^ N; //XOR up to [1...N]

    return (xor1 ^ xor2); // the missing number
}

