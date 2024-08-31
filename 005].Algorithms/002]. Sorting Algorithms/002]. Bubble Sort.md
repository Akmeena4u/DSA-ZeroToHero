### Bubble Sort -  
Bubble sort is a simple and intuitive sorting algorithm. The algorithm works by repeatedly stepping through the list, comparing adjacent pairs of elements, and swapping them if they are in the wrong order. This process is repeated until the list is sorted.

#### Key Characteristics:
- **Stable**: Preserves the relative order of equal elements.
- **In-Place**: Requires only a constant amount of additional memory space (O(1) space complexity).
- **Time Complexity**: O(n^2) in the worst and average cases; O(n) in the best case when the list is already sorted.

#### Algorithm Outline:
1. Begin from the start of the list.
2. Compare each pair of adjacent elements.
3. If the elements are out of order, swap them.
4. Continue this process, progressively reducing the number of comparisons with each pass.
5. If during a pass no swaps are made, the list is already sorted, and the algorithm can terminate early.

This implementation includes an optimization to stop the algorithm early if the list becomes
sorted before all passes are complete.

```cpp
void bubbleSort(vector<int>& arr, int n) {   
    // Iterate over the array 'n-1' times
    for (int i = 1; i < n; i++) {
        bool swapped = false; // Track whether any swaps occur in this pass
        
        // Inner loop for comparing adjacent elements up to the (n-i)th element
        for (int j = 0; j < n-i; j++) {
            
            // If the current element is greater than the next element, swap them
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true; // Mark that a swap occurred
            }
        }
        
        // If no swaps occurred, the array is already sorted, so break early
        if (!swapped) {
            break;
        }
    }
}
```

---

#### Interview questions


 1. **What is Bubble Sort?**
   - **Answer**: Bubble Sort is a simple comparison-based sorting algorithm. It repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. This process continues until no more swaps are needed, meaning the list is sorted.

 2. **What is the time complexity of Bubble Sort?**
   - **Answer**: 
     - **Worst-case**: O(n²)
     - **Average-case**: O(n²)
     - **Best-case**: O(n) (when the array is already sorted, and no swaps are needed)

 3. **Is Bubble Sort stable?**
   - **Answer**: Yes, Bubble Sort is a stable sorting algorithm. It preserves the relative order of elements with equal keys.

 4. **Is Bubble Sort an in-place algorithm?**
   - **Answer**: Yes, Bubble Sort is an in-place algorithm as it requires only a constant amount of additional space (O(1) space complexity).

 5. **How can you optimize Bubble Sort?**
   - **Answer**: An optimization can be implemented by introducing a flag (e.g., `swapped`) that tracks whether any swaps were made during a pass. If no swaps were made, the list is already sorted, and the algorithm can terminate early.

 6. **When would you use Bubble Sort over other sorting algorithms?**
   - **Answer**: While Bubble Sort is generally not preferred due to its inefficiency, it might be used in educational contexts to teach sorting concepts or when the dataset is very small and nearly sorted, where its simplicity and early termination optimization can be beneficial.

 7. **Can you explain how Bubble Sort works with an example?**
   - **Answer**: Yes. Consider an array `[5, 2, 9, 1, 5]`. Bubble Sort will compare and swap elements to "bubble" the largest elements to the end of the array. After the first pass, the array becomes `[2, 5, 1, 5, 9]`, and the process continues until the array is sorted.

 8. **What are the advantages and disadvantages of Bubble Sort?**
   - **Answer**:
     - **Advantages**:
       - Simple to understand and implement.
       - Works well on small datasets or nearly sorted data.
       - Stable and in-place.
     - **Disadvantages**:
       - Inefficient on large datasets due to its O(n²) time complexity.
       - Performs unnecessary comparisons even if the array is nearly sorted without the early termination optimization.

 9. **How would Bubble Sort behave with a reverse-sorted array?**
   - **Answer**: In the worst case, such as a reverse-sorted array, Bubble Sort will perform the maximum number of comparisons and swaps, resulting in O(n²) time complexity.

 10. **How does Bubble Sort compare with other O(n²) sorting algorithms like Selection Sort and Insertion Sort?**
   - **Answer**: Bubble Sort generally performs worse than Insertion Sort in practical scenarios, especially for nearly sorted data, where Insertion Sort can be more efficient with O(n) time complexity. Selection Sort, on the other hand, is more efficient in terms of swaps but is still O(n²) in both comparisons and time complexity.

11.  **Why is the inner loop running until n-i?**
    - **Answer**: The inner loop runs until n-i because after each complete pass through the array, the largest unsorted element "bubbles up" to its correct position. Thus, in subsequent passes, there is no need to compare elements beyond the last sorted position, reducing the number of comparisons and swaps needed.


