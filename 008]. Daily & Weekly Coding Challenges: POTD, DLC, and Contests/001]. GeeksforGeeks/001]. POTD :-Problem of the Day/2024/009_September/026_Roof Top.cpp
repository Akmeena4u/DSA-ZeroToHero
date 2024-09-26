int maxStep(vector<int>& arr) {
    // Initialize variables:
    // 'ans' will store the maximum number of consecutive increasing steps.
    // 'increaseCount' will count the current sequence of increasing steps.
    int ans = 0, increaseCount = 0;

    // Loop through the array starting from the second element (i = 1)
    for(int i = 1; i < arr.size(); i++) {
        // If the current element is greater than the previous one, increment the count of consecutive increases.
        if(arr[i] > arr[i - 1]) 
            increaseCount++;
        else {
            // If the current element is not greater than the previous one, update 'ans' with the maximum of 'ans' and 'increaseCount'.
            // Reset 'increaseCount' to 0 for the next potential sequence.
            ans = max(ans, increaseCount);
            increaseCount = 0;
        }
    }

    // After the loop, check if the last sequence of increases was the longest.
    ans = max(ans, increaseCount);

    // Return the maximum number of consecutive increasing steps found.
    return ans;
}
