// Input: n = 5, arr[] = [1,2,3,5]
// Output: 4
// Explanation : All the numbers from 1 to 5 are present except 4.

int missingNumber(int n, vector<int>& array) {

        // Your code goes here
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
