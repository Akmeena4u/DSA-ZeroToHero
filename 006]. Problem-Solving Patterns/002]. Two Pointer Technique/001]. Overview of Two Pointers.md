### Two Pointer Approach: Comprehensive Notes

---

#### **Introduction**
The Two Pointer Approach is a technique used to solve problems efficiently by utilizing two pointers to traverse or process data in linear structures like arrays, vectors, or linked lists. This method often helps in reducing both time and space complexity compared to other approaches.

---

#### **What is the Two Pointer Approach?**
- **Definition:** A technique where two pointers are used to solve a problem in linear time by traversing the data structure. The pointers typically start at different positions, and their movement depends on the specific problem requirements.
- **Applications:** Useful for problems involving linear data structures where you want to process or compare two elements at a time. It helps in reducing space complexity to constant while optimizing time complexity.

---

#### **When to Use the Two Pointer Approach**
- When you need to process two elements in a single iteration.
- When the data is sorted, the two-pointer technique can efficiently find pairs or other properties.
- Useful for searching in arrays, strings, and linked lists.Cycle Detection: Efficient in detecting cycles in linked lists.
- Reduces time complexity from O(N^2) to O(N) in many cases.
- Detecting loops in linked lists, checking palindromes, reversing arrays or linked lists, solving the Two Sum problem, and finding the middle of a linked list.

---

#### **Special Cases and Edge Cases**
- **Empty Arrays:** Ensure that the algorithm handles cases where the array size is zero.
- **Single Element Arrays:** Must handle cases where the array has only one element.
- **Arrays with Duplicate Elements:** Ensure that the solution accounts for duplicates if required.

---

#### **Benefits of Two Pointer Approach**
- **Efficiency:** Reduces time complexity compared to nested loops.
- **Space Savings:** Minimizes space usage by avoiding extra data structures.
- **Versatility:** Applicable to a range of problems involving linear data structures.

---

### Main Approaches

1. **Both Pointers Starting from the Beginning (Same Direction)**
2. **Both Pointers Moving in the Same Direction with a Fixed Difference (Sliding Window)**
3. **Both Pointers Starting from Opposite Ends (Moving Towards Each Other)**
4. **Two or More Pointers on Separate Arrays**

### 1. Two Pointers Starting from the Beginning

#### Problem 1: Reversing an Array In-Place

**Approach with Extra Space**:
```cpp
#include <iostream>
using namespace std;

void reverseArray(int A[], int n) {
    int* reverse = new int[n];
    int j = n - 1;
    for (int i = 0; i < n; i++) {
        reverse[j--] = A[i];
    }
    for (int i = 0; i < n; i++) {
        A[i] = reverse[i];
    }
    delete[] reverse;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    reverseArray(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
```

**In-Place Approach**:
```cpp
void reverseArray(int A[], int n) {
    int i = 0;
    int j = n - 1;
    while (i < j) {
        swap(A[i], A[j]);
        i++;
        j--;
    }
}
```

#### Problem 2: Removing Duplicates from a Sorted Array

**Approach with Extra Space**:
```cpp
#include <iostream>
using namespace std;

int removeDuplicates(int A[], int n) {
    int* unique = new int[n];
    int j = 0;
    for (int i = 0; i < n - 1; i++) {
        if (A[i] != A[i + 1]) {
            unique[j++] = A[i];
        }
    }
    unique[j++] = A[n - 1];
    for (int i = 0; i < j; i++) {
        A[i] = unique[i];
    }
    delete[] unique;
    return j;
}

int main() {
    int arr[] = {1, 1, 2, 3, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int newSize = removeDuplicates(arr, n);
    for (int i = 0; i < newSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
```

**In-Place Approach**:
```cpp
int removeDuplicates(int A[], int n) {
    if (n == 0) return 0;
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (A[i] != A[j]) {
            A[++j] = A[i];
        }
    }
    return j + 1;
}
```

### 2. Two Pointers Moving in the Same Direction with Fixed Difference (Sliding Window)

#### Problem: Find the Sum of All Subarrays of Size `k`

**Brute-Force Approach**:
```cpp
#include <iostream>
using namespace std;

int* subarraySumSizeK(int A[], int n, int k, int &size) {
    size = n - k + 1;
    int* sums = new int[size];
    for (int i = 0; i < size; i++) {
        int sum = 0;
        for (int j = 0; j < k; j++) {
            sum += A[i + j];
        }
        sums[i] = sum;
    }
    return sums;
}

int main() {
    int arr[] = {3, 5, 6, 2, 4, 7, 8};
    int k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    int size;
    int* result = subarraySumSizeK(arr, n, k, size);
    for (int i = 0; i < size; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    delete[] result;
    return 0;
}
```

**Optimized Sliding Window Approach**:
```cpp
int* subarraySumSizeK(int A[], int n, int k, int &size) {
    size = n - k + 1;
    int* sums = new int[size];
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += A[i];
    }
    sums[0] = sum;
    for (int i = k; i < n; i++) {
        sum += A[i] - A[i - k];
        sums[i - k + 1] = sum;
    }
    return sums;
}
```

### 3. Two Pointers Starting from Opposite Ends (Moving Towards Each Other)

#### Problem: Find Two Numbers in a Sorted Array that Sum to Zero

**Brute-Force Approach**:
```cpp
#include <iostream>
using namespace std;

bool hasTwoSumZero(int A[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] + A[j] == 0) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int arr[] = {-3, -1, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (hasTwoSumZero(arr, n))
        cout << "Two numbers found" << endl;
    else
        cout << "No such numbers" << endl;
    return 0;
}
```

**Optimized Approach with Two Pointers**:
```cpp
bool hasTwoSumZero(int A[], int n) {
    int i = 0;
    int j = n - 1;
    while (i < j) {
        int sum = A[i] + A[j];
        if (sum == 0)
            return true;
        else if (sum < 0)
            i++;
        else
            j--;
    }
    return false;
}
```

### 4. Two Pointers on Separate Arrays

#### Problem: Merging Two Sorted Arrays

**Brute-Force Approach**:
```cpp
#include <iostream>
using namespace std;

void mergeArrays(int A[], int B[], int m, int n, int result[]) {
    for (int i = 0; i < m; i++) {
        result[i] = A[i];
    }
    for (int i = 0; i < n; i++) {
        result[m + i] = B[i];
    }
    sort(result, result + m + n);
}

int main() {
    int A[] = {1, 3, 5, 7};
    int B[] = {2

, 4, 6, 8};
    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0]);
    int result[m + n];
    mergeArrays(A, B, m, n, result);
    for (int i = 0; i < m + n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
```

**Optimized Approach with Two Pointers**:
```cpp
void mergeArrays(int A[], int m, int B[], int n, int result[]) {
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < m && j < n) {
        if (A[i] < B[j]) {
            result[k++] = A[i++];
        } else {
            result[k++] = B[j++];
        }
    }
    while (i < m) {
        result[k++] = A[i++];
    }
    while (j < n) {
        result[k++] = B[j++];
    }
}
```

### Summary
- **Two Pointer Technique**: Effective for problems involving arrays or lists where two pointers can traverse from different ends or in the same direction with a fixed difference.
- **Sliding Window Technique**: Often a specific case of the Two Pointer Technique where one pointer represents the start of a window, and the other represents the end.

This approach helps optimize solutions to problems that would otherwise require nested loops, reducing time complexity significantly.

By mastering the Two Pointer Approach, you can efficiently solve a variety of problems with reduced time and space complexity.
