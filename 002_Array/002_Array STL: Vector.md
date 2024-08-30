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

#### **6. 2D Vectors**

- **Definition**: A 2D vector is a vector of vectors, allowing you to represent a matrix or table-like structure.

- **Initialization**:
  ```cpp
  std::vector<std::vector<int>> matrix(3, std::vector<int>(4)); // 3 rows, 4 columns, default-initialized to 0
  std::vector<std::vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; // 2D vector with specific values
  ```

- **Accessing Elements**:
  ```cpp
  int value = matrix[1][2]; // Access element at row 1, column 2
  ```

- **Modifying Elements**:
  ```cpp
  matrix[0][1] = 10; // Set element at row 0, column 1 to 10
  ```

- **Getting Dimensions**:
  ```cpp
  size_t numRows = matrix.size();          // Number of rows
  size_t numCols = matrix[0].size();       // Number of columns (assuming all rows have the same number of columns)
  ```

- **Iterating Over 2D Vectors**:
  ```cpp
  for (size_t i = 0; i < matrix.size(); ++i) {
      for (size_t j = 0; j < matrix[i].size(); ++j) {
          std::cout << matrix[i][j] << " "; // Access elements in row-major order
      }
      std::cout << std::endl;
  }
  ```

- **Resizing 2D Vectors**:
  ```cpp
  matrix.resize(4, std::vector<int>(5, 0)); // Resize to 4 rows and 5 columns, initialized to 0
  ```

#### **7. Use Cases in Interviews**

- **Dynamic Arrays**: When the size of the array is not known in advance or changes during runtime.
- **2D Matrices**: For problems involving grid-based data or matrix operations.
- **Algorithmic Problems**: Frequently used in problems involving sorting, searching, and manipulation of sequences.

#### **8. Practical Examples**

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

#### **9. Array v/s Vector**

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
| **Default Initialization**   | Elements default-initialized
