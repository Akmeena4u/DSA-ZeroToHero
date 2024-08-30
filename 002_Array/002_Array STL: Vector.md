### Comprehensive Guide to `std::vector` in C++ STL for Interview Preparation

`std::vector` is a dynamic array provided by the C++ Standard Library (STL). It is one of the most commonly used data structures in C++ due to its versatility and performance. Here’s a detailed guide to understanding and using `std::vector`, focusing on key aspects that are relevant for coding interviews.

---

#### **1. Introduction**

- **Definition**: `std::vector` is a sequence container that encapsulates dynamic size arrays. It allows for automatic resizing and provides fast random access to elements.
- **Header File**: `#include <vector>`

#### **2. Basic Operations**

- **Initialization**:
  ```cpp
  std::vector<int> v1;           // Empty vector of integers
  std::vector<int> v2(5);        // Vector with 5 elements, default-initialized to 0
  std::vector<int> v3(5, 10);    // Vector with 5 elements, each initialized to 10
  std::vector<int> v4{1, 2, 3};  // Vector with 3 elements: 1, 2, 3
  ```

- **Accessing Elements**:
  ```cpp
  int val = v1[0];       // Access element at index 0 (no bounds checking)
  int val = v1.at(0);    // Access element at index 0 (with bounds checking)
  int first = v1.front(); // Access first element
  int last = v1.back();  // Access last element
  ```

- **Modifying Elements**:
  ```cpp
  v1[0] = 5;          // Modify element at index 0
  v1.at(1) = 10;      // Modify element at index 1
  v1.push_back(20);   // Add element at the end
  v1.pop_back();      // Remove the last element
  ```

- **Size and Capacity**:
  ```cpp
  size_t size = v1.size();     // Number of elements
  size_t capacity = v1.capacity(); // Number of elements that can be stored without reallocating
  bool empty = v1.empty();     // Check if the vector is empty
  ```

- **Resizing**:
  ```cpp
  v1.resize(10);     // Resize to 10 elements (new elements are default-initialized)
  v1.resize(5, 1);   // Resize to 5 elements, new elements are initialized to 1
  ```

- **Reserve and Shrink**:
  ```cpp
  v1.reserve(20);    // Reserve space for 20 elements, avoiding multiple reallocations
  v1.shrink_to_fit(); // Shrink capacity to fit the current size
  ```

#### **3. Iterators**

- **Types**:
  - **`begin()`**: Returns an iterator to the first element.
  - **`end()`**: Returns an iterator to one past the last element.
  - **`rbegin()`**: Returns a reverse iterator to the last element.
  - **`rend()`**: Returns a reverse iterator to one before the first element.

- **Usage**:
  ```cpp
  for (auto it = v1.begin(); it != v1.end(); ++it) {
      std::cout << *it << " "; // Access elements through iterators
  }
  ```

#### **4. Common Algorithms**

- **Sorting**:
  ```cpp
  std::sort(v1.begin(), v1.end()); // Sort elements in ascending order
  ```

- **Searching**:
  ```cpp
  auto it = std::find(v1.begin(), v1.end(), 10); // Find first occurrence of 10
  if (it != v1.end()) {
      std::cout << "Found 10 at position: " << std::distance(v1.begin(), it);
  }
  ```

- **Copying**:
  ```cpp
  std::vector<int> v2 = v1; // Copy constructor
  std::vector<int> v3(v1.begin(), v1.end()); // Copy elements from another vector
  ```

- **Filling**:
  ```cpp
  std::fill(v1.begin(), v1.end(), 0); // Fill vector with 0
  ```

#### **5. Performance Considerations**

- **Time Complexity**:
  - **Access**: `O(1)`
  - **Insertion/Deletion at end**: `O(1)` (amortized)
  - **Insertion/Deletion at middle**: `O(n)`
  - **Resize**: `O(n)` (when reallocating)

- **Capacity Management**:
  - `std::vector` automatically manages its capacity but can be controlled using `reserve()` and `shrink_to_fit()`.

#### **6. Use Cases in Interviews**

- **Dynamic Arrays**: When the size of the array is not known in advance or changes during runtime.
- **Algorithmic Problems**: Frequently used in problems involving sorting, searching, and manipulation of sequences.

#### **7. Practical Examples**

- **Reverse a Vector**:
  ```cpp
  std::reverse(v1.begin(), v1.end());
  ```

- **Rotate Elements**:
  ```cpp
  std::rotate(v1.begin(), v1.begin() + 2, v1.end()); // Rotate elements left by 2 positions
  ```

- **Unique Elements**:
  ```cpp
  auto last = std::unique(v1.begin(), v1.end()); // Remove duplicates
  v1.erase(last, v1.end()); // Erase the removed elements
  ```

---

#### **8. Array v/s Vector**

Here's a comparative table highlighting the key differences between `std::vector` and raw arrays in C++:

| Feature                      | `std::vector`                                             | Raw Array                                      |
|------------------------------|-----------------------------------------------------------|------------------------------------------------|
| **Definition**               | Dynamic array provided by the C++ Standard Library      | Fixed-size array defined by the language      |
| **Header File**              | `#include <vector>`                                      | No specific header required                    |
| **Size**                     | Dynamic (can grow/shrink)                                | Fixed (size must be known at compile-time)     |
| **Initialization**           | Can be initialized with a size, value, or another vector | Requires size to be specified                  |
| **Memory Management**        | Automatically manages memory                             | Manual management (e.g., `new` and `delete`)   |
| **Access Time Complexity**   | O(1) (constant time)                                     | O(1) (constant time)                           |
| **Insertions/Deletions**      | Fast at the end (O(1) amortized); O(n) elsewhere          | O(n) (requires shifting elements)              |
| **Resizing**                 | `resize()` method available; dynamic resizing            | Not possible; requires creating a new array    |
| **Capacity Management**      | `reserve()` and `shrink_to_fit()` methods available      | Not applicable                                  |
| **Bounds Checking**          | `at()` method with bounds checking; `[]` operator without | No built-in bounds checking                    |
| **Copy/Move Semantics**      | Supports copy and move operations                         | Requires manual copy and move                  |
| **Iterator Support**         | Full support (begin(), end(), rbegin(), rend(), etc.)   | No iterators available                         |
| **Default Initialization**   | Elements default-initialized (or use provided value)     | Elements may be uninitialized (depends on type)|
| **Memory Overhead**          | May have some overhead due to dynamic resizing           | No overhead beyond the fixed size              |
| **Use Case**                 | When dynamic resizing and automatic memory management are needed | When size is fixed and performance is critical |

### Key Points:

- **`std::vector`**: Ideal for scenarios where the size of the container can change dynamically or when automatic memory management is beneficial. It provides more flexibility and functionality but comes with some overhead due to its dynamic nature.

- **Raw Arrays**: Best used when the size of the array is known at compile-time and does not change. They offer a simpler, lower-overhead option but lack the flexibility and safety features provided by `std::vector`.

Understanding these differences will help you choose the appropriate data structure for your specific needs and performance requirements during coding interviews and real-world applications.

This guide covers the essential aspects of `std::vector` and how to use it effectively for coding interviews. Understanding these operations and methods will help you handle various problems involving dynamic arrays in C++.
