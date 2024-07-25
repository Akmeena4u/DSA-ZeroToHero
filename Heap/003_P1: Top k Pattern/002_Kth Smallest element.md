###  Finding the Kth Smallest Element

This problem involves finding the `Kth` smallest element in an array. We use a max heap (priority queue) to efficiently manage and retrieve the smallest elements.

### Problem Statement

Given an array of integers and an integer `K`, find the `Kth` smallest element in the array.

### Approach

To solve this problem, we use a max heap to keep track of the smallest `K` elements encountered so far. The steps are:

1. **Use a Max Heap**:
   - A max heap is used to store the smallest `K` elements from the array. In C++, the `priority_queue` is used to create a max heap by default.

2. **Initialize the Heap**:
   - Insert the first `K` elements of the array into the max heap.

3. **Process Remaining Elements**:
   - For each subsequent element in the array, compare it with the root of the heap (the largest element in the heap).
   - If the current element is smaller than the root of the heap, replace the root with this element and reheapify.

4. **Retrieve the Kth Smallest Element**:
   - After processing all elements, the root of the heap will be the `Kth` smallest element.

### Code Explanation

Here's a breakdown of the code:

```cpp
#include <iostream>
#include <queue>
using namespace std;

int findKthSmallest(int arr[], int n, int k) {
    // Create a max heap
    priority_queue<int> pq;

    // Insert the first k elements of the array into the max heap
    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    // For remaining elements, insert into heap if the element is smaller than the max element in the heap
    for (int i = k; i < n; i++) {
        if (pq.top() > arr[i]) {
            pq.pop(); // Remove the largest element
            pq.push(arr[i]); // Insert the new element
        }
    }

    // The top of the heap is the Kth smallest element
    return pq.top();
}

int main() {
    int arr[] = {10, 5, 20, 4, 15};
    int n = 5;
    int k = 2;
    int ans = findKthSmallest(arr, n, k);
    cout << "Ans = " << ans;
    return 0;
}
```


5. **Complexity**:
   - **Time Complexity**: O(N log K), where `N` is the number of elements in the array and `K` is the size of the heap. This is because each element may be inserted or removed from the heap.
   - **Space Complexity**: O(K) due to the storage required for the heap.

This method is efficient for finding the `Kth` smallest element in an array when `K` is much smaller than `N`, leveraging the heap to maintain only the necessary elements.
