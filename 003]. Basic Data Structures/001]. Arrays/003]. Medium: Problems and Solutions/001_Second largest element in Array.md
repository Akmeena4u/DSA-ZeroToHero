

### Brute Force Approach

**Algorithm:**
1. **Sort** the array in ascending order.
2. The second smallest element is at index 1.
3. The second largest element is at index `n-2`.

**Code:**
```cpp
#include <bits/stdc++.h>
using namespace std;

void getElements(int arr[], int n) {
    if (n <= 1) {
        cout << -1 << " " << -1 << endl;
        return;
    }
    sort(arr, arr + n);
    int second_small = arr[1];
    int second_large = arr[n - 2];
    cout << "Second smallest is " << second_small << endl;
    cout << "Second largest is " << second_large << endl;
}
```

**Complexity:**
- **Time Complexity:** \(O(N \log N)\) (due to sorting)
- **Space Complexity:** \(O(1)\) (if sorting in-place)

---

### Better Approach

**Algorithm:**
1. Traverse the array to find the smallest and largest elements.
2. Traverse again to find the second smallest and second largest elements.

**Code:**
```cpp
#include <bits/stdc++.h>
using namespace std;

void getElements(int arr[], int n) {
    if (n <= 1) {
        cout << -1 << " " << -1 << endl;
        return;
    }
    int small = INT_MAX, second_small = INT_MAX;
    int large = INT_MIN, second_large = INT_MIN;

    for (int i = 0; i < n; i++) {
        small = min(small, arr[i]);
        large = max(large, arr[i]);
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] < second_small && arr[i] != small)
            second_small = arr[i];
        if (arr[i] > second_large && arr[i] != large)
            second_large = arr[i];
    }

    cout << "Second smallest is " << second_small << endl;
    cout << "Second largest is " << second_large << endl;
}
```

**Complexity:**
- **Time Complexity:** \(O(N)\) (two linear traversals)
- **Space Complexity:** \(O(1)\)

---

### Optimal Approach

**Algorithm:**
1. Traverse the array once to find the smallest and largest elements.
2. During the same traversal, update the second smallest and second largest elements based on comparisons.

**Code:**
```cpp
#include <bits/stdc++.h>
using namespace std;

int secondSmallest(int arr[], int n) {
    if (n < 2) return -1;
    int small = INT_MAX;
    int second_small = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (arr[i] < small) {
            second_small = small;
            small = arr[i];
        } else if (arr[i] < second_small && arr[i] != small) {
            second_small = arr[i];
        }
    }
    return second_small;
}

int secondLargest(int arr[], int n) {
    if (n < 2) return -1;
    int large = INT_MIN;
    int second_large = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > large) {
            second_large = large;
            large = arr[i];
        } else if (arr[i] > second_large && arr[i] != large) {
            second_large = arr[i];
        }
    }
    return second_large;
}
```

**Complexity:**
- **Time Complexity:** \(O(N)\) (single pass for both smallest and largest)
- **Space Complexity:** \(O(1)\)

---
