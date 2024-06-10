/*

### Problem Statement
You are given an array containing distinct elements. You need to rearrange the array such that it follows a zigzag pattern where:
- The element at index 0 is less than the element at index 1.
- The element at index 1 is greater than the element at index 2.
- The element at index 2 is less than the element at index 3.
- And so on...

### Approach
1. Traverse the array.
2. For every element at index `i`, check the following:
   - If `i` is even, ensure `arr[i] < arr[i + 1]`. If not, swap them.
   - If `i` is odd, ensure `arr[i] > arr[i + 1]`. If not, swap them.
3. Continue this process until the end of the array is reached.

### Example
For the array `[4, 3, 7, 8, 6, 2, 1]`, the steps are:
1. Check indices 0 and 1: 4 > 3, so swap to get `[3, 4, 7, 8, 6, 2, 1]`.
2. Check indices 1 and 2: 4 < 7, no swap needed.
3. Check indices 2 and 3: 7 > 8, so swap to get `[3, 4, 8, 7, 6, 2, 1]`.
4. Check indices 3 and 4: 7 < 6, no swap needed.
5. Check indices 4 and 5: 6 > 2, so swap to get `[3, 4, 8, 7, 2, 6, 1]`.
6. Check indices 5 and 6: 6 < 1, no swap needed.

*/

// ### Code Implementation

 void zigZag(int n, vector<int> &arr) {
        // code here
          for(int i=0;i<n-1;i++){
            if(i%2==0){
                if(arr[i] > arr[i+1]){
                    swap(arr[i], arr[i+1]);
                }
            }
            else{
                if(arr[i] < arr[i+1]){
                    swap(arr[i], arr[i+1]);
                }
            }
        }
        return;
    
    }

/*

### Time and Space Complexity
- Time Complexity: O(n), as we only need to traverse the array once.
- Space Complexity: O(1), as no extra space is used.

### Key Points
- When the index `i` is even, ensure `arr[i] < arr[i + 1]`.
- When the index `i` is odd, ensure `arr[i] > arr[i + 1]`.
- The solution uses a single loop and a constant amount of extra space.

### Explanation
- The problem ensures that the array elements are distinct, so no need to handle equality.
- Swapping elements in-place maintains the requirement without using additional space.
- The approach leverages simple conditional checks and swaps, making it efficient.

By following these steps and understanding the code, you can convert any given array into a zigzag pattern efficiently.

*/
