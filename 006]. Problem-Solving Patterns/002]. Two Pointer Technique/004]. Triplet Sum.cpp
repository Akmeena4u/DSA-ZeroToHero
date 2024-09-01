
bool findTriplet(int arr[], int n, int X) {
    // Sort the array first to use the two-pointer technique
    std::sort(arr, arr + n);

    // Traverse each element and fix it as the first element of the triplet
    for (int i = 0; i < n - 2; ++i) {
        // Initialize two pointers
        int low = i + 1;  // Start right after the fixed element
        int high = n - 1; // Start from the end of the array

        // Use the two-pointer approach to find if there exists a pair
        // such that arr[low] + arr[high] + arr[i] == X
        while (low < high) {
            int currentSum = arr[i] + arr[low] + arr[high];

            if (currentSum == X) {
                return true; // Triplet found
            } 
            else if (currentSum < X) {
                ++low; // Increase the lower pointer to get a larger sum
            } 
            else {
                --high; // Decrease the upper pointer to get a smaller sum
            }
        }
    }

    return false; // No triplet found
}
