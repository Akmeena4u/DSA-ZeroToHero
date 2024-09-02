
### Problem Explanation
Given an array of integers and a target value, you need to find three integers in the array such that their sum is closest to the target. If there are multiple solutions with the same closest sum, return the maximum one.

### Solution Approach
1. **Sort the Array**: Sorting helps in efficiently finding the closest sum using the two-pointer technique.
2. **Two-Pointer Technique**: For each element in the array, treat it as the first element of the triplet and use two pointers to find the other two elements such that their sum is closest to the target.
3. **Track Closest Sum**: Keep track of the closest sum and the smallest difference between the sum and the target.

### Detailed Steps and Code Explanation

```cpp
int threeSumClosest(vector<int> arr, int target) {
    // Initialize variables to store the smallest difference and the closest sum found
    int dif = INT_MAX, ans = INT_MAX;

    // Sort the array to facilitate the two-pointer approach
    sort(arr.begin(), arr.end());

    // Iterate through each element of the array, treating it as the first element of the triplet
    for (int i = 0; i < arr.size(); i++) {
        // Initialize two pointers, start (s) and end (e)
        int s = i + 1, e = arr.size() - 1;

        // Use the two-pointer approach to find the closest sum
        while (s < e) {
            // Calculate the sum of the current triplet
            int sum = arr[i] + arr[s] + arr[e];

            // If the sum equals the target, return the sum immediately
            if (sum == target) {
                return sum;
            } 
            // If the sum is greater than the target, decrement the end pointer to reduce the sum
            else if (sum > target) {
                e--;
            } 
            // If the sum is less than the target, increment the start pointer to increase the sum
            else {
                s++;
            }

            // Update the closest sum and the smallest difference if a closer sum is found
            if (abs(sum - target) < dif) {
                dif = abs(sum - target);
                ans = sum;
            } 
            // If the difference is the same but the sum is greater, update the closest sum
            else if (abs(sum - target) == dif) {
                ans = max(ans, sum);
            }
        }
    }

    // Return the closest sum found
    return ans;
}
```

### Explanation of Each Step
1. **Initialize Variables**:
   - `dif`: Stores the smallest difference between the triplet sum and the target.
   - `ans`: Stores the closest sum found.

2. **Sort the Array**:
   - Sorting the array helps in using the two-pointer technique efficiently.

3. **Iterate Through the Array**:
   - Treat each element as the first element of the triplet.
   - Use two pointers `s` (start) and `e` (end) to find the other two elements.

4. **Two-Pointer Technique**:
   - **Sum Calculation**: Calculate the sum of the triplet `arr[i] + arr[s] + arr[e]`.
   - **Check Sum**:
     - If the sum equals the target, return it immediately.
     - If the sum is greater than the target, decrement the end pointer to reduce the sum.
     - If the sum is less than the target, increment the start pointer to increase the sum.

5. **Update Closest Sum**:
   - If the absolute difference between the current sum and the target is smaller than the smallest difference (`dif`), update `dif` and `ans`.
   - If the difference is the same but the current sum is greater, update `ans`.

6. **Return the Closest Sum**:
   - After iterating through the array, return the closest sum found.

This approach ensures that the solution is both efficient and easy to understand, leveraging the two-pointer technique to find the closest sum in \(O(n^2)\) time complexity.
