 int getMinDiff(vector<int> &arr, int k) {
        // code here
         // Get the size of the array
    int n = arr.size();

    // If the array contains only one element, the difference is 0 (no height difference)
    if(n == 1) return 0;

    // Sort the array in ascending order to handle heights efficiently
    sort(arr.begin(), arr.end());

    // Initialize `ans` to the maximum possible difference between the largest and smallest elements
    int ans = arr[n-1] - arr[0], mn = 0, mx = 0;

    // Iterate through the array to adjust each element based on the given value of `k`
    for(int i = 1; i < n; i++) {
        // If subtracting `k` makes the height negative, skip this element
        if(arr[i] - k < 0) continue;

        // Calculate the minimum height between either increasing the smallest height by `k`
        // or decreasing the current height by `k`
        mn = min(arr[0] + k, arr[i] - k);

        // Calculate the maximum height between either decreasing the largest height by `k`
        // or increasing the previous element by `k`
        mx = max(arr[n-1] - k, arr[i-1] + k);

        // Update the result with the minimum difference obtained so far
        ans = min(ans, mx - mn);
    }

    // Return the final minimum difference
    return ans;
    }
