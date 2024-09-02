/* # Problem Statement
Given n integer ranges, the task is to find the integer that occurs most frequently in all these ranges.
Example
Given ranges: 
[2,5], [1,3], [3,9]

We need to find the number that appears most frequently across all these ranges.


# Solution Approach
1. Brute Force Approach
Steps:
1. Create an array: Initialize an array `count` to keep track of the occurrences of each number in the given ranges. The size of this array should be large enough to cover the maximum possible value in the ranges.
2. Iterate over each range: For each range [L, R], increment the count for every number from L to R.
3. Find the maximum occurring number: Traverse the `count` array to find the number with the highest count.

### Example:
Given ranges: [2, 5], [1, 3], [3, 9]

1. Create an array `count` of size large enough (let's assume max value is 10):
   count = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
   

2. Iterate over each range and update the `count` array:
   - For range [2, 5]:
     count = [0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0]
     
   - For range [1, 3]:
     count = [0, 1, 2, 2, 1, 1, 0, 0, 0, 0, 0]

   - For range [3, 9]:
     count = [0, 1, 2, 3, 2, 2, 1, 1, 1, 1, 0]
     

3. Find the maximum occurring number- by traversing the `count` array:
   The maximum value in the `count` array is 3 at index 3.
   So, the maximum occurring number is 3.
   

## Time Complexity: 
- For each range, we update counts for all numbers in that range: O(n×(R−L+1))
- Finding the maximum in the `count` array: O(m)
- Overall complexity:  O(n×(R−L+1))+O(m), where (n) is the number of ranges and (m) is the maximum value in the ranges.







## Optimized Approach (Prefix Sum Method)
Steps:
Initialize a difference array: Create an array arr of size max_value+2. This array will be used to mark the increments at the start of each range and decrements right after the end of each range.

Update the difference array for each range [L,R]:
Increment arr[L] by 1.
Decrement arr[R + 1] by 1.

Compute the prefix sum to get the count of each number:
Convert the arr array into a prefix sum array to get the actual counts of each number.

Find the maximum occurring number by traversing the prefix sum array.

Example:
Given ranges: 
[2,5], [1,3], [3,9]

Initialize the difference array arr:
arr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

Update the difference array:
For range 
[2,5]:
arr = [0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 0, 0]
  
For range 
[1,3]:
arr = [0, 1, 1, 0, -1, 0, -1, 0, 0, 0, 0, 0]

For range 
[3,9]:
arr = [0, 1, 1, 1, -1, 0, -1, 0, 0, 0, -1, 0]

Compute the prefix sum:
prefix_sum = [0, 1, 2, 3, 2, 2, 1, 1, 1, 1, 0]

Find the maximum occurring number:
The maximum value in the `prefix_sum` array is 3 at index 3.
So, the maximum occurring number is 3.

Time Complexity:
Updating the difference array: O(n)

Computing the prefix sum: O(m)

Finding the maximum in the prefix sum array: O(m)

Overall complexity: O(n)+O(m)

Code Implementation
*/
int maxOccured(int n, int l[], int r[], int maxx) {
        // Step 1: Initialize a difference array of size maxx + 2
        vector<int> arr(maxx + 2, 0);

        // Step 2: Update the difference array for each range [l[i], r[i]]
        for (int i = 0; i < n; i++) {
            arr[l[i]]++;
            if (r[i] + 1 <= maxx) {
                arr[r[i] + 1]--;
            }
        }

        // Step 3: Compute the prefix sum to get the count of each number
        int maxCount = 0, result = 0, currentSum = 0;
        for (int i = 0; i <= maxx; i++) {
            currentSum += arr[i];
            if (currentSum > maxCount) {
                maxCount = currentSum;
                result = i;
            }
        }

        // Step 4: Return the maximum occurring number
        return result;
    }

/*
### Summary
- **Brute Force Approach**:
  - Simple but inefficient for large ranges.
  - Time complexity can be high due to nested loops.

- **Optimized Approach (Prefix Sum Method)**:
  - Efficient for large ranges.
  - Time complexity is linear with respect to the number of ranges and the maximum value in the ranges.

The optimized approach is generally preferred due to its efficiency in handling large input sizes.

*/
