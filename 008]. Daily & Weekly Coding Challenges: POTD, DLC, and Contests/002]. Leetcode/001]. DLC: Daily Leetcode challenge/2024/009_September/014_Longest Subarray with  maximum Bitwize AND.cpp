int longestSubarray(vector<int>& nums) {
    int maxVal = 0;  // Variable to store the maximum value encountered
    int result = 0;  // Variable to store the length of the longest subarray with max values
    int streak = 0;  // Variable to keep track of the current streak of max values

    // Iterate through each number in the input array
    for (int num : nums) {
        // If current number is greater than the previously encountered max value
        if (num > maxVal) {
            maxVal = num;    // Update maxVal to the new maximum number
            result = 0;      // Reset the result (length of longest subarray) since a new max is found
            streak = 0;      // Reset the current streak of max numbers
        }

        // If the current number matches the max value
        if (maxVal == num) {
            streak++;  // Increment the streak since the max value continues
        } else {
            streak = 0;  // Reset the streak if the number is not equal to the max value
        }

        // Update the result with the longest streak found so far
        result = max(result, streak);
    }

    return result;  // Return the length of the longest subarray of maximum values
}
