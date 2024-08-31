### Solution 1: Sorting

**Algorithm:**
1. Sort the array in ascending order.
2. Return the last element of the sorted array.

**Code:**
```cpp
#include <bits/stdc++.h>
using namespace std;

int sortArr(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    return arr[arr.size() - 1];
}

int main() {
    vector<int> arr1 = {2, 5, 1, 3, 0};
    vector<int> arr2 = {8, 10, 5, 7, 9};

    cout << "The Largest element in the array is: " << sortArr(arr1) << endl;
    cout << "The Largest element in the array is: " << sortArr(arr2) << endl;

    return 0;
}
```

**Complexity:**
- **Time Complexity:** \(O(n \log n)\) (due to sorting)
- **Space Complexity:** \(O(1)\) (if sorting in-place)

---

### Solution 2: Using a Max Variable

**Algorithm:**
1. Initialize a max variable with the first element of the array.
2. Iterate through the array, updating the max variable whenever a larger element is found.
3. Return the max variable.

**Code:**
```cpp
#include <bits/stdc++.h>
using namespace std;

int findLargestElement(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr1[] = {2, 5, 1, 3, 0};
    int arr2[] = {8, 10, 5, 7, 9};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "The Largest element in the array is: " << findLargestElement(arr1, size1) << endl;
    cout << "The Largest element in the array is: " << findLargestElement(arr2, size2) << endl;

    return 0;
}
```

**Complexity:**
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)
