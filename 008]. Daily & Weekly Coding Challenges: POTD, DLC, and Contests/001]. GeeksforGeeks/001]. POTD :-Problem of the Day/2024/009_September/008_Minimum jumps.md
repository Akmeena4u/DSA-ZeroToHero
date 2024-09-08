### **Problem: Minimum Jumps**

#### **Problem Statement:**
Given an array `arr[]` of non-negative integers, where each element represents the maximum length of the jump that can be made forward from that element. You need to find the minimum number of jumps required to reach the end of the array starting from the first element. If an element is `0`, it means you cannot move through that element.

**Note:** Return `-1` if it is impossible to reach the end of the array.

#### **Example:**
- **Input:** `arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}`
- **Output:** `3`
- **Explanation:**
  - First jump from the 1st element (value `1`) to the 2nd element (value `3`).
  - From here, jump to the 5th element (value `9`).
  - Finally, jump to the last element.

#### **Approach:**

1. **Initial Check:**
   - If the first element of the array is `0`, it means you can't make any jumps, hence return `-1`.

2. **Variables to Track:**
   - `ans`: Stores the minimum number of jumps required (initially set to `1` because at least one jump is required if the array is not trivial).
   - `jump`: Tracks the number of steps we can still take (initialized to `arr[0]`).
   - `mx`: Tracks the maximum number of steps we can take in the current jump range.

3. **Iterate Through the Array:**
   - Start from the second element (`i = 1`).
   - Decrement `mx` and `jump` with each step.
   - Update `mx` with the maximum jump possible from the current position.
   - If `jump` becomes `0` and we haven't reached the end of the array, it means we need to make a new jump:
     - Check if `mx` is greater than `0` to ensure a valid jump is possible. If not, return `-1` as it is impossible to proceed further.
     - Update `jump` with `mx`, reset `mx` to `0`, and increment the jump count (`ans`).

4. **Return the Result:**
   - After completing the loop, return the total number of jumps stored in `ans`.

#### **Code Implementation:**

```cpp
int minJumps(vector<int>& arr) {
    // If the first element is 0, we can't make any jump
    if (!arr[0]) return -1;
    
    int ans = 1;        // At least one jump is required if the array is non-trivial
    int jump = arr[0];  // Initial jump capability
    int mx = 0;         // Maximum reach within the current jump
    
    for (int i = 1; i < arr.size(); i++) {
        mx--;           // Decrement the max reach for each step
        jump--;         // Decrement the jump count
        
        mx = max(mx, arr[i]);  // Update max reach for the current position
        
        if (!jump && i != arr.size() - 1) {  // If no more jumps left and not at the last element
            if (mx <= 0) return -1;  // If no further jump is possible, return -1
            jump = mx;  // Update jump with the maximum reach from the current range
            mx = 0;     // Reset mx for the next range
            ans++;      // Increment the jump count
        }
    }
    
    return ans;  // Return the total number of jumps required
}
```

### **Key Points:**
- **Time Complexity:** The approach works in `O(n)` time complexity, where `n` is the number of elements in the array, as it involves a single pass through the array.
- **Space Complexity:** The space complexity is `O(1)` as it uses a constant amount of extra space.
- **Edge Cases:** 
  - When the array has only one element (`arr[] = {0}`), it should directly return `0` as no jump is needed.
  - Handle cases where large jumps can be made early in the array, as well as cases where the maximum jumps only cover a small distance.

This approach effectively balances checking how far you can go with each jump while minimizing the total number of jumps required to reach the end.
