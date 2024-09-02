// Input:
// s1 = "0033"
// s2 = "2"
// Output:
// 66

/* This function multiplies two input strings representing integers and returns the result as a string. */
string multiplyStrings(string s1, string s2) {
    bool neg = 0; // Initialize a boolean to check if the result should be negative.

    // Check if the first input string is negative and remove the '-' sign if present.
    if (s1[0] == '-') {
        neg ^= 1; // Toggle the 'neg' flag.
        s1 = s1.substr(1); // Remove the '-' sign.
    }

    // Check if the second input string is negative and remove the '-' sign if present.
    if (s2[0] == '-') {
        neg ^= 1; // Toggle the 'neg' flag.
        s2 = s2.substr(1); // Remove the '-' sign.
    }

    // Reverse the input strings to simplify multiplication from right to left.
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    int n = s1.size(); // Length of the first input string.
    int m = s2.size(); // Length of the second input string.

    vector<int> res(n + m + 20, 0); // Initialize a vector to store the result with extra space.

    // Perform multiplication digit by digit.
    for (int i = 0; i < m; i++) {
        int pos = i; // Initialize the position for the current multiplication.
        int x = s2[i] - '0'; // Get the digit from the second input string.
        for (int j = 0; j < n; j++) {
            int y = s1[j] - '0'; // Get the digit from the first input string.

            // Multiply the digits and add to the result at the appropriate position.
            res[pos] += x * y;

            // If the result at the current position is greater than 9, carry over to the next position.
            if (res[pos] > 9) {
                res[pos + 1] += res[pos] / 10;
                res[pos] = res[pos] % 10;
            }

            ++pos; // Move to the next position for the next digit.
        }
    }

    bool found = 0; // Flag to track if non-zero digits have been encountered.
    string ans = ""; // Initialize the final answer as an empty string.

    // Build the final answer by iterating through the result vector.
    for (int i = res.size() - 1; i > -1; i--) {
        if (res[i])
            found = 1; // Set the 'found' flag when a non-zero digit is encountered.

        if (found)
            ans += (char)(res[i] + '0'); // Append non-zero digits to the answer as characters.
    }

    if (neg)
        ans = '-' + ans; // If the result is negative, add a '-' sign to the answer.

    return ans; // Return the multiplied string as a string.
}

