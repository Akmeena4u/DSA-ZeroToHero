/*

# Problem Description:

- Given an array `arr1` representing a sequence of numbers.
- Create an exact replica of `arr1`, but with one extra element inserted at any position.
- Determine the index of the extra element in the replicated array.
- The possible positions for the extra element are at indices 1 to n+1, where n is the size of the original array `arr1`.

# Approach 1 :

1. Front Case (Index 0):
   - Start looping from index 0 to n-1.
   - If `arr2[i]` (replicated array) does not match `arr1[i]` (original array) at any index, return that index as the answer.

2. Middle Case (Indices 1 to n):
   - Loop from index 0 to n-1 as before.
   - If a mismatch is found, return the index as the answer.

3. End Case (Index n+1):
   - If no mismatch is found in the loops, return n as the answer because the extra element is at the end.  */

//# Code Implementation:  

 int findExtra(int n, int arr1[], int arr2[]) {
        // add code here.
           //Ans could be at start or middle 
        for(int i=0;i<n-1;i++){
            if(arr1[i]!=arr2[i]){
                return i;
            }
        }
        return n-1;   // if ans not found in start or middle it will be at last index
    }
    

//This code will correctly identify the index of the extra element in the replicated array based on the provided logic.

---

/*

Approach 2: Binary Search Approach:
   - Since the arrays are sorted, we can efficiently use binary search to find the extra element.
   - We compare corresponding elements of both arrays.
   - When we find the first mismatch, the element at that position in `arr1` is the extra element.  */

//Code with Explanation: 



int findExtra(int arr1[], int arr2[], int n) {
    int left = 0, right = n - 2; // arr2 has one element less than arr1

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Compare elements of arr1 and arr2
        if (arr1[mid] == arr2[mid]) {
            // Move right if elements are same, meaning extra element is further in arr1
            left = mid + 1;
        } else {
            // Move left if elements are different, meaning extra element is at or before mid
            right = mid - 1;
        }
    }

    // When the loop ends, left is pointing to the extra element in arr1
    return left;
}


/* Explanation:
- The `findExtra` function takes three parameters: the two arrays `arr1` and `arr2`, and the size `n`.
- It initializes `left` to 0 and `right` to `n - 2` because `arr2` has one element less than `arr1`.
- Using a while loop, it performs binary search to compare elements of `arr1` and `arr2`.
- If the elements at the mid index are the same, it means the extra element is further in `arr1`, so it moves `left` to `mid + 1`.
- If the elements are different, it means the extra element is at or before the mid index, so it moves `right` to `mid - 1`.
- When the loop ends, `left` points to the index of the extra element in `arr1`, which is returned as the result.

This code efficiently finds the index of the extra element in the replicated array using binary search.  */
