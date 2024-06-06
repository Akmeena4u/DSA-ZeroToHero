/*
The logic behind the solution for the "Max Sum in the Configuration" problem is to find the maximum possible value of a special sum obtained by rotating the array. The sum is defined as the sum of each element multiplied by its index. The challenge is to determine the maximum sum by rotating the array in different ways.

Steps and Logic:
1. Initial Calculations:
Calculate the initial special sum, temp, for the given array configuration.
Calculate the sum of all elements in the array, sum.

2. Iterative Calculation:
Use a mathematical formula to compute the new special sum after each rotation, rather than recalculating it from scratch. This formula is derived from the relationship between the sums of consecutive rotations.

*/


/*
## BruteForce Approach
An alternative approach would be to calculate the sum for each rotation from scratch, which would involve rotating the array and recalculating the sum for each rotation. This approach, however, would have a time complexity of  𝑂(𝑛^2), making it less efficient than the current approach.
*/

//## Optimized Approach

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long maxSumAfterRotation(vector<int> &arr) {
    int n = arr.size();
    long long temp = 0, sum = 0, ans = 0;

    // Calculate initial temp (Σ i * arr[i]) and sum (Σ arr[i])
    for (int i = 0; i < n; ++i) {
        temp += (long long)i * arr[i];
        sum += arr[i];
    }

    // Initialize ans with the initial temp value
    ans = temp;

    // Calculate temp for each rotation and update ans with the maximum temp
    for (int i = 1; i < n; ++i) {
        // Update temp using the formula:
        // temp = temp - sum + n * arr[i - 1]
        temp = temp - sum + (long long)n * arr[i - 1];
        ans = max(ans, temp);
    }

    return ans;
}

int main() {
    vector<int> arr = {8, 3, 1, 2};
    cout << "Maximum sum after rotation is: " << maxSumAfterRotation(arr) << endl;
    return 0;
}


/*

Explanation:

1. Initialization:
We initialize three variables: temp, sum, and ans as 0.
temp stores the initial sum calculated as Σ (i * arr[i]).
sum stores the sum of all elements in the array (Σ arr[i]).

2. First Loop:
We iterate over the array to calculate the initial temp and sum.

3. Initialize ans:
We initialize ans with the value of temp to keep track of the maximum sum encountered.

4. Second Loop:
For each rotation, we update temp using the formula:
temp = temp - sum + n * arr[i - 1]

We update ans to be the maximum of the current temp and the previous ans.

5. Return the Result:
Finally, we return ans which contains the maximum sum after all rotations.

By following this approach, we efficiently calculate the maximum sum achievable after rotating the array using mathematical insights, thus optimizing the solution.

Time and Space Complexity
Time Complexity: The time complexity is 𝑂(𝑛)  because we make a single pass to compute the initial values and then another pass to compute the maximum value for all rotations.
Space Complexity: The space complexity is 𝑂(1) because we use a constant amount of extra space.

*/

