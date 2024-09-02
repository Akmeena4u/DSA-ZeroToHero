/*

Problem Statement -
The problem statement determines if there is a way to swap one element from each of two given arrays such that the sums of the arrays become equal after the swap. If such a swap is possible, return 1; otherwise, return -1.


### Brute Force Approach

#### Logic
1. Calculate the sum of both arrays `sumA` and `sumB`.
2. Determine the target difference: `(sumA - sumB) / 2`.
3. Use nested loops to check all pairs (x from A, y from B) to see if `x - y` equals the target difference.
4. Return `1` if such a pair is found, otherwise return `-1`.

*/
//Code



int findSwapValues(vector<int>& A, vector<int>& B) {
    int sumA = 0, sumB = 0;
    for (int num : A) sumA += num;
    for (int num : B) sumB += num;

    if ((sumA - sumB) % 2 != 0) return -1;
    int target = (sumA - sumB) / 2;

    for (int x : A) {
        for (int y : B) {
            if (x - y == target) {
                return 1;
            }
        }
    }
    return -1;
}

/*
Problem with Brute force- The brute force approach has a significant drawback in terms of efficiency. Specifically, it has a time complexity of 
𝑂(𝑛×𝑚) O(n×m), where n is the length of array A and  m is the length of array B. This is because it involves nested loops that iterate over all possible pairs of elements from the two arrays, making it very slow for larger arrays.

*/

/* ### Optimized Approach

#### Logic
1. Calculate the sum of both arrays `sumA` and `sumB`.
2. Determine the target difference: `(sumA - sumB) / 2`.
3. Sort both arrays.
4. Use two pointers to find a pair (x, y) such that `x - y` equals the target difference.
5. Return `1` if such a pair is found, otherwise return `-1`.
*/

// Code



int findSwapValues(vector<int>& A, vector<int>& B) {
    int sumA = 0, sumB = 0;
    for (int num : A) sumA += num;
    for (int num : B) sumB += num;

    if ((sumA - sumB) % 2 != 0) return -1;
    int target = (sumA - sumB) / 2;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int i = 0, j = 0;
    while (i < A.size() && j < B.size()) {
        int difference = A[i] - B[j];
        if (difference == target) {
            return 1;
        } else if (difference < target) {
            i++;
        } else {
            j++;
        }
    }
    return -1;
}


/*

### Explanation:

1. **Initialization and Sum Calculation**:
   - Calculate `sumA` and `sumB` as the sums of arrays `A` and `B`.
   - Check if the difference between sums is even; if not, return `-1`.

2. **Target Calculation**:
   - Compute the target difference `target = (sumA - sumB) / 2`.

3. **Sorting**:
   - Sort both arrays `A` and `B`.

4. **Two-Pointer Technique**:
   - Initialize two pointers, `i` and `j`, to traverse arrays `A` and `B`.
   - Calculate the difference `A[i] - B[j]`.
   - Adjust pointers based on the difference to find the target.

5. **Return Result**:
   - Return `1` if a valid pair is found, otherwise return `-1`.

These approaches help find the solution to swapping elements in two arrays to make their sums equal, with the optimized approach improving efficiency using sorting and two pointers.

Conclusion
The brute force approach is simple but inefficient for larger datasets. The optimized approach, with sorting and two-pointer technique, significantly improves performance and handles larger arrays much more effectively.

 */
