
### Priority Queue in C++

A priority queue is a type of container adapter in C++ that allows for the storage of elements such that the element with the highest (or lowest) priority is always at the front and can be accessed in constant time. The `std::priority_queue` class template provides a way to implement such a container.

#### Characteristics of `std::priority_queue`

- **Ordering**: By default, the `std::priority_queue` is implemented as a max-heap, meaning the largest element is always at the top. However, it can be customized to work as a min-heap.
- **Underlying Container**: Typically implemented using a vector (`std::vector`) as the underlying container.
- **Efficiency**: Insertion and deletion operations are logarithmic in complexity, i.e., O(log n).

#### Syntax and Usage

Here is a detailed explanation of how to use `std::priority_queue` in C++:

##### Include Header
To use `std::priority_queue`, you need to include the `<queue>` header.

```cpp
#include <queue>
```

##### Basic Operations
- **Push**: Adds an element to the priority queue.
- **Pop**: Removes the highest-priority element.
- **Top**: Accesses the highest-priority element without removing it.
- **Empty**: Checks if the priority queue is empty.
- **Size**: Returns the number of elements in the priority queue.

##### Example: Max-Heap (Default Behavior)
```cpp
#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> pq;

    // Insert elements
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(1);

    // Access the top element
    std::cout << "Top element: " << pq.top() << std::endl; // Output: 30

    // Remove elements
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    // Output: 30 20 10 5 1

    return 0;
}
```

##### Custom Comparator: Min-Heap
To implement a min-heap, you can use `std::greater` as the comparison function.

```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <functional> // for std::greater

int main() {
    // Min-heap using priority_queue
    std::priority_queue<int, std::vector<int>, std::greater<int>> minPq;

    // Insert elements
    minPq.push(10);
    minPq.push(30);
    minPq.push(20);
    minPq.push(5);
    minPq.push(1);

    // Access the top element
    std::cout << "Top element: " << minPq.top() << std::endl; // Output: 1

    // Remove elements
    while (!minPq.empty()) {
        std::cout << minPq.top() << " ";
        minPq.pop();
    }
    // Output: 1 5 10 20 30

    return 0;
}
```

##### Using Custom Comparator
You can also define a custom comparator for more complex priority rules.
```cpp
#include <iostream>
#include <queue>
#include <vector>

// Custom comparator
struct CustomCompare {
    bool operator()(const int& lhs, const int& rhs) {
        return lhs > rhs; // Min-heap
    }
};

int main() {
    std::priority_queue<int, std::vector<int>, CustomCompare> customPq;

    // Insert elements
    customPq.push(10);
    customPq.push(30);
    customPq.push(20);
    customPq.push(5);
    customPq.push(1);

    // Access the top element
    std::cout << "Top element: " << customPq.top() << std::endl; // Output: 1

    // Remove elements
    while (!customPq.empty()) {
        std::cout << customPq.top() << " ";
        customPq.pop();
    }
    // Output: 1 5 10 20 30

    return 0;
}
```

#### Key Points
- `std::priority_queue` is a convenient way to manage a collection of elements where the highest (or lowest) priority element is always accessible.
- By default, it functions as a max-heap, but you can customize it to behave as a min-heap using `std::greater` or a custom comparator.
- Common operations like insertion, deletion, and access to the top element are efficient, with logarithmic time complexity.

Using `std::priority_queue` in C++ allows you to leverage the power of heap data structures for managing prioritized elements efficiently.
