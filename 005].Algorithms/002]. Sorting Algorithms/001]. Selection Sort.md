### Selection Sort: Overview, Use Cases, Interview Questions, and Facts

#### Overview

**Selection Sort** is a simple and intuitive sorting algorithm that works by repeatedly finding the minimum element from the unsorted part of the array and placing it at the beginning. The algorithm divides the array into two parts: a sorted part and an unsorted part. Initially, the sorted part is empty, and the unsorted part consists of the entire array.

#### Basic Idea of the Selection Sort Algorithm:

1. **Start with the first element** as the minimum (assuming it's the smallest).
2. **Iterate through the unsorted part** of the array to find the minimum element.
3. **Swap** the minimum element with the first element of the unsorted part.
4. **Move the boundary** between the sorted and unsorted parts one element to the right.
5. **Repeat** the above steps until the entire array is sorted.

#### Code Implementation:

```cpp
#include<vector>
using namespace std;

void selectionSort(vector<int>& arr, int n)
{   
    for(int i = 0; i < n-1; i++ ) {
        int minIndex = i;
        
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minIndex]) 
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
}
```

#### Time Complexity:

- **Best Case**: `O(n^2)`
- **Average Case**: `O(n^2)`
- **Worst Case**: `O(n^2)`

**Space Complexity**: `(O(1)` (In-place sorting algorithm)

#### Characteristics:

- **In-place Sorting**: Selection Sort does not require any extra storage, making it an in-place sorting algorithm.
- **Not Stable**: Selection Sort is not a stable sort, meaning that the relative order of equal elements might not be preserved.
- **Comparison-based**: The algorithm is based on comparison and swapping of elements.

### Use Cases for Selection Sort:

- **Small Arrays**: Suitable for small datasets where the overhead of more complex algorithms is not justified.
- **Memory Constraints**: Selection Sort's in-place nature makes it ideal for situations with limited memory.
- **Learning**: Often used as an introductory example for sorting algorithms due to its simplicity.
- **Partially Sorted Data**: If the array is already partially sorted, Selection Sort can be used to sort the remaining unsorted part efficiently.

### Interview Questions Related to Selection Sort:

1. **Explain the Selection Sort Algorithm.**
   - **Answer**: Selection Sort works by dividing the array into a sorted and an unsorted part, repeatedly selecting the minimum element from the unsorted part, and placing it at the beginning of the sorted part.

2. **What is the time complexity of Selection Sort?**
   - **Answer**: The time complexity of Selection Sort is \(O(n^2)\) in the best, average, and worst cases.

3. **Why is Selection Sort not stable?**
   - **Answer**: Selection Sort is not stable because it swaps elements without considering their relative order. For instance, if two elements have the same value, their order might be changed.

4. **Can Selection Sort be used on linked lists?**
   - **Answer**: Selection Sort can be used on linked lists, but it is less efficient than other sorting algorithms like Merge Sort due to the need for frequent node traversals.

5. **How does Selection Sort compare with Bubble Sort?**
   - **Answer**: Both algorithms have the same time complexity of \(O(n^2)\), but Selection Sort generally performs fewer swaps than Bubble Sort, making it slightly more efficient in practice.

6. **Describe a real-world scenario where Selection Sort might be used.**
   - **Answer**: Selection Sort could be used in situations where memory is very limited and the dataset is small, such as sorting a list of items in an embedded system.


### Related Problems Solvable by Selection Sort:

1. **Sorting Small Arrays**: Simple tasks where performance is not a concern.
2. **Finding the k-th smallest/largest element**: Modify the Selection Sort algorithm to stop after finding the k-th element.
3. **Rearranging Array Elements**: Use Selection Sort to rearrange elements according to specific criteria.

Selection Sort is a fundamental algorithm that serves as a stepping stone to understanding more complex sorting algorithms. Despite its limitations in performance, its clarity and simplicity make it an essential tool in the early stages of learning computer science.
