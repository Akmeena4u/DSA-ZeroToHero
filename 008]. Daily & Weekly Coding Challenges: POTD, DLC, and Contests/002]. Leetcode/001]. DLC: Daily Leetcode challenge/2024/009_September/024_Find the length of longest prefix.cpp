  int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;

// Loop through each value in the first array (arr1)
for(int val : arr1) {
    // Check if the current value or any of its prefixes (obtained by dividing by 10)
    // is not already in the set and is greater than 0
    while(!st.count(val) && val > 0) {
        // Insert the current value into the unordered_set
        st.insert(val);

        // Divide the current value by 10 to get its prefix
        val = val / 10;
    }
}

int result = 0; // To store the longest common prefix (LCP) result

// Loop through each value in the second array (arr2)
for(int num : arr2) {
    // Keep dividing the current number by 10 until we find a prefix that exists in the set
    // or until the number becomes 0
    while(!st.count(num) && num > 0) {
        num /= 10;
    }

    // If the number is greater than 0, it means a prefix was found in the set
    if(num > 0) {
        // Calculate the number of digits in the found prefix using log10
        // and update the result with the maximum length of the prefix
        result = max(result, static_cast<int>(log10(num)) + 1);
    }
}

return result; // Return the length of the longest common prefix

    }
