// Input:
// N = 8, M = 5
// A = {3, 4, 1, 9, 56, 7, 9, 12}
// Output: 6
// Explanation: The minimum difference between maximum chocolates and minimum chocolates is 9 - 3 = 6 by choosing following M packets :{3, 4, 9, 7, 9}.


long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
       // Sort the input array
        sort(a.begin(), a.end());

        // Check differences in m-size window
        long long i = 0;
        long long j = m - 1;
        long long diff = LLONG_MAX; // Initialize diff with the maximum value of long long
        while (j < n) {
            long long newDiff = a[j] - a[i];
            diff = min(diff, newDiff);
            j++;
            i++;
        }
        return diff;
    
    }   
