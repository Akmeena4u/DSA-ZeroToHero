
### Problem Description:
- **Objective**: Sort the array based on the frequency of elements. Elements with higher frequency should come first. If two elements have the same frequency, the smaller number should come first.
  
- **Example**:
  - **Input**: `arr[] = [5, 5, 4, 6, 4]`
  - **Output**: `[4, 4, 5, 5, 6]`
  - **Explanation**: 
    - The element `4` appears twice, `5` also appears twice, and `6` appears once.
    - Since `4` and `5` have the same frequency, the smaller element `4` comes first, followed by `5`.
    - Finally, `6` appears once, so it comes last.

### Steps to Solve:

1. **Frequency Calculation**:
   - The first step is to count the frequency of each element in the array. This can be done using a map (or unordered_map) where the key is the element and the value is its frequency.

2. **Storing in a Vector of Pairs**:
   - Store each element and its corresponding frequency as a pair in a vector. This will allow us to sort the elements based on both frequency and value.

3. **Custom Sorting**:
   - The pairs are sorted in descending order of frequency.
   - If two elements have the same frequency, they are sorted in ascending order of their values (to ensure the smaller element comes first).

4. **Generating the Result**:
   - After sorting, generate the result array by repeating each element according to its frequency.

### Solution Explanation:

The provided solution is written in C++ and follows the above steps. Let's break it down:

```cpp
class Solution {
  public:
    // Custom comparison function for sorting.
    static bool condition(pair<int,int>& p1, pair<int,int>& p2) {
        // If frequencies are the same, compare elements
        return (p1.second == p2.second) ? p1.first < p2.first : p1.second > p2.second;
    }

    // Function to sort the array according to the frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        map<int,int> mp;

        // Step 1: Calculate frequency of each element.
        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
        }

        // Step 2: Store elements and their frequencies as pairs in a vector.
        vector<pair<int,int>> p(mp.begin(), mp.end());

        // Step 3: Sort the vector based on frequency and then value.
        sort(p.begin(), p.end(), condition);

        // Step 4: Generate the sorted array.
        vector<int> ans;
        for(pair<int,int>& temp : p) {
            while(temp.second--) {
                ans.push_back(temp.first);
            }
        }

        return ans;
    }
};
```

### Detailed Breakdown:

1. **Custom Comparison Function**:
   - The `condition` function is used to sort the pairs. 
   - **Condition**:
     - If the frequencies (`p1.second` and `p2.second`) are the same, the smaller element (`p1.first < p2.first`) comes first.
     - Otherwise, the element with a higher frequency (`p1.second > p2.second`) comes first.

2. **Frequency Calculation**:
   - `map<int,int> mp;` initializes a map to store the frequency of each element.
   - The loop `for(int i=0;i<arr.size();i++) mp[arr[i]]++;` iterates over the array, counting the occurrences of each element.

3. **Storing and Sorting**:
   - `vector<pair<int,int>> p(mp.begin(),mp.end());` converts the map into a vector of pairs, where each pair consists of an element and its frequency.
   - `sort(p.begin(), p.end(), condition);` sorts the vector based on the custom condition defined.

4. **Generating the Output Array**:
   - The sorted pairs are iterated over to generate the final array.
   - The loop `while(temp.second--) ans.push_back(temp.first);` adds each element to the result array `ans`, according to its frequency.

### Final Output:
- The function returns a vector `ans` that is sorted according to the frequency of elements as required.

This solution is efficient with a time complexity dominated by the sorting step, which is `O(nlog n)`, where `n` is the number of unique elements in the array. The overall space complexity is `O(n)` for storing the frequency map and the sorted result.
