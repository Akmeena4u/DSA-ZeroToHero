
### 1. Sliding Window Technique

**Explanation:**
The sliding window technique is used to find a subarray or substring of a certain length or with specific properties. It maintains a window that can expand or contract based on certain conditions, which helps in optimizing the solution by avoiding redundant computations.

**Problem:** Find the length of the longest substring without repeating characters.

**Code Example:**

```cpp
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Function to find the length of the longest substring without repeating characters
int length_of_longest_substring(const string& s) {
    unordered_map<char, int> char_index;  // Map to store the last index of each character
    int start = 0;  // Start index of the sliding window
    int max_length = 0;  // Maximum length of the substring found

    // Iterate over the string
    for (int end = 0; end < s.length(); ++end) {
        // If the character is already in the map, move the start index
        if (char_index.find(s[end]) != char_index.end()) {
            start = max(start, char_index[s[end]] + 1);
        }
        char_index[s[end]] = end;  // Update the last index of the character
        max_length = max(max_length, end - start + 1);  // Update the maximum length
    }

    return max_length;
}

int main() {
    string s = "abcabcbb";
    cout << length_of_longest_substring(s) << endl;  // Output: 3
    return 0;
}
```

**Explanation:**
- **`unordered_map<char, int> char_index;`**: Maps characters to their most recent index in the string.
- **`start`**: Represents the start of the current window.
- **`max_length`**: Stores the length of the longest substring found.
- As you iterate through the string with `end`, adjust `start` if a repeating character is found to ensure all characters in the window are unique.

---

### 2. Prefix and Postfix Sums

**Explanation:**
Prefix and postfix sums are useful for problems where you need to perform operations involving the sum or product of subarrays. Prefix sums store the cumulative sum up to each index, while postfix sums store the cumulative sum from each index to the end of the array.

**Problem:** Calculate the product of an array except self.

**Code Example:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the product of an array except self
vector<int> product_except_self(const vector<int>& nums) {
    int n = nums.size();  // Number of elements in the array
    vector<int> result(n, 1);  // Result array to store the product

    // Calculate prefix products
    int prefix = 1;  // Prefix product initialized to 1
    for (int i = 0; i < n; ++i) {
        result[i] = prefix;  // Set the prefix product for the current index
        prefix *= nums[i];  // Update the prefix product
    }

    // Calculate postfix products
    int postfix = 1;  // Postfix product initialized to 1
    for (int i = n - 1; i >= 0; --i) {
        result[i] *= postfix;  // Update the result array with the postfix product
        postfix *= nums[i];  // Update the postfix product
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = product_except_self(nums);
    for (int num : result) {
        cout << num << " ";  // Output: 24 12 8 6
    }
    cout << endl;
    return 0;
}
```

**Explanation:**
- **Prefix Calculation:** Iterate from the start and compute the product of all elements before each index.
- **Postfix Calculation:** Iterate from the end and compute the product of all elements after each index.
- **Result Calculation:** Multiply the prefix and postfix values to get the product for each index, excluding the element itself.

---

### 3. Matrix as a Bookkeeper

**Explanation:**
When additional space is limited, you can use existing rows and columns in a matrix to keep track of information. This avoids the need for extra storage by modifying the matrix itself.

**Problem:** Set matrix zeroes.

**Code Example:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Function to set matrix zeroes
void set_zeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();  // Number of rows
    int n = matrix[0].size();  // Number of columns
    bool row_zero = false;  // Flag to check if the first row has zero
    bool col_zero = false;  // Flag to check if the first column has zero

    // Check if the first row has any zeroes
    for (int j = 0; j < n; ++j) {
        if (matrix[0][j] == 0) {
            row_zero = true;
            break;
        }
    }

    // Check if the first column has any zeroes
    for (int i = 0; i < m; ++i) {
        if (matrix[i][0] == 0) {
            col_zero = true;
            break;
        }
    }

    // Use the first row and column to mark zero rows and columns
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Zero out cells based on the markers in the first row and column
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Zero out the first row and column if needed
    if (row_zero) {
        for (int j = 0; j < n; ++j) {
            matrix[0][j] = 0;
        }
    }
    if (col_zero) {
        for (int i = 0; i < m; ++i) {
            matrix[i][0] = 0;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };
    set_zeroes(matrix);
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
```

**Explanation:**
- **Row and Column Checks:** Determine if the first row or column contains zeroes.
- **Mark Zeroes:** Use the first row and column to mark which rows and columns need to be zeroed.
- **Update Matrix:** Set cells to zero based on the markers.
- **Handle First Row and Column:** Set the entire first row and column to zero if required.

---

### 4. Kadane’s Algorithm

**Explanation:**
Kadane's Algorithm is used to find the maximum sum subarray in a linear array. It efficiently solves the problem by maintaining a running maximum sum and updating it as you iterate through the array.

**Problem:** Find the maximum subarray sum.

**Code Example:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Function to find the maximum subarray sum
int max_subarray_sum(const vector<int>& nums) {
    int max_sum = nums[0];  // Initialize with the first element
    int current_sum = nums[0];  // Initialize with the first element

    // Iterate through the array starting from the second element
    for (size_t i = 1; i < nums.size(); ++i) {
        current_sum = max(nums[i], current_sum + nums[i]);  // Update the current sum
        max_sum = max(max_sum, current_sum);  // Update the maximum sum
    }

    return max_sum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << max_subarray_sum(nums) << endl;  // Output: 6
    return 0;
}
```

**Explanation:**
- **`current_sum`**: Keeps track of the maximum sum of the subarray ending at the current index.
- **`max_sum`**: Keeps track of the maximum sum found so far.
- Update `current_sum` with the maximum of the current element or the sum of `current_sum` and the current element.

---

### 5. Two-Pointer Technique

**Explanation:**
The two-pointer technique is used when you need to find a pair of elements that satisfy a condition. It involves using two pointers, usually starting at the ends of a sorted array, and moving them towards each other based on certain conditions.

**Problem:** Find the container with the most water.

**Code Example:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Function to find the container with the most water
int max_area(const vector<int>& height) {
    int left = 0;  // Left pointer
    int right = height.size() - 1;  // Right pointer
    int max_area = 0;  // Maximum area found

    while (left < right) {
        int width = right - left;  // Width of the container
        int h = min(height[left], height[right]);  // Height of the container
        max_area = max(max_area, width * h);  // Update the maximum area

        // Move the pointer pointing to the shorter line
        if (height[left] < height[right]) {
            ++left;
        } else {
            --right;
        }
    }

    return max_area;
}

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << max_area(height) << endl;  // Output: 49
    return 0;
}
```

**Explanation:**
- **`left` and `right`**: Pointers starting at the two ends of the array.
- **Width**: Distance between the two pointers.
- **Height**: Minimum height between the two pointers.
- Move the pointer pointing to the shorter line to potentially find a taller line that might increase the area.

These examples and explanations should provide a clear understanding of each pattern and its implementation in C++.


---



### 6. Merging Intervals

**Explanation:**
The merging intervals problem involves combining overlapping intervals from a set of intervals. The goal is to merge all overlapping intervals into one and return a list of non-overlapping intervals that cover all the intervals in the input.

**Steps to Solve:**
1. **Sort Intervals:** First, sort the intervals based on their start times. This ensures that when you iterate through the intervals, any overlap will be contiguous.
2. **Merge Overlapping Intervals:** Initialize a list with the first interval. For each subsequent interval, check if it overlaps with the last interval in the merged list. If it does, update the end time of the last interval in the merged list. Otherwise, add the current interval to the merged list.

**Code Example:**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to merge overlapping intervals
vector<vector<int>> merge_intervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};

    // Sort intervals based on the start time
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged = {intervals[0]};  // Start with the first interval

    // Iterate through the intervals
    for (const auto& interval : intervals) {
        // Check if there is an overlap with the last interval in merged
        if (interval[0] <= merged.back()[1]) {
            // Merge the intervals by updating the end time
            merged.back()[1] = max(merged.back()[1], interval[1]);
        } else {
            // No overlap, add the interval to the merged list
            merged.push_back(interval);
        }
    }

    return merged;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = merge_intervals(intervals);

    // Output the merged intervals
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}
```

**Explanation:**
- **Sorting:** The `sort` function orders the intervals by their start times.
- **Merging:** After sorting, iterate through each interval and merge overlapping intervals by updating the end time of the last interval in the merged list.
- **Output:** Print the merged intervals, which now represent the non-overlapping intervals that cover all the input intervals.

---

### 7. Circular Array Handling

**Explanation:**
The problem of finding the maximum sum of a circular subarray can be approached by leveraging Kadane’s Algorithm and some additional calculations. Kadane’s Algorithm finds the maximum sum subarray for a non-circular array, and by modifying this approach, we can handle circular arrays.

**Steps to Solve:**
1. **Kadane’s Algorithm:** First, apply Kadane’s Algorithm to find the maximum sum subarray for the non-circular case.
2. **Circular Subarray:** To find the maximum sum for a circular subarray, compute the total sum of the array and then find the minimum sum subarray using Kadane’s Algorithm on the inverted array (where each element is negated). The maximum circular sum is the total sum minus this minimum sum.
3. **Compare Results:** Compare the result from the non-circular Kadane’s Algorithm and the circular case to determine the maximum sum.

**Code Example:**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function to find the maximum subarray sum using Kadane's Algorithm
int kadane(const vector<int>& arr) {
    int max_sum = arr[0];  // Initialize max_sum with the first element
    int current_sum = arr[0];  // Initialize current_sum with the first element

    // Iterate through the array starting from the second element
    for (size_t i = 1; i < arr.size(); ++i) {
        current_sum = max(arr[i], current_sum + arr[i]);  // Update current_sum
        max_sum = max(max_sum, current_sum);  // Update max_sum
    }

    return max_sum;
}

// Function to find the maximum sum of a circular subarray
int max_circular_subarray_sum(const vector<int>& nums) {
    int max_sum = kadane(nums);  // Maximum subarray sum for the non-circular case

    int total_sum = 0;  // Total sum of the array
    vector<int> inverted_nums;  // Array to store the negated values

    // Compute total_sum and prepare inverted_nums
    for (int num : nums) {
        total_sum += num;
        inverted_nums.push_back(-num);
    }

    // Find the minimum subarray sum using Kadane's Algorithm on inverted_nums
    int min_sum = kadane(inverted_nums);
    int max_circular_sum = total_sum + min_sum;  // Maximum circular sum

    // Return the maximum of the non-circular and circular sums
    return max(max_sum, max_circular_sum);
}

int main() {
    vector<int> nums = {8, -8, 9, -9, 10, -11, 12};
    cout << max_circular_subarray_sum(nums) << endl;  // Output: 22
    return 0;
}
```

**Explanation:**
- **Kadane’s Algorithm:** Finds the maximum sum subarray for the non-circular case.
- **Circular Subarray Calculation:** Calculate the total sum of the array and find the minimum subarray sum by applying Kadane’s Algorithm to the negated values. The maximum circular sum is the total sum minus this minimum sum.
- **Result Comparison:** Return the maximum value between the non-circular maximum sum and the circular maximum sum.

These detailed explanations and code examples should help you understand how to approach and solve these problems effectively using C++.
