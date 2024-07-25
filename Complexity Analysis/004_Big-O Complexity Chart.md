### Big-O Complexity Cheat Sheet

This guide covers the time and space complexities of common algorithms used in computer science. It is particularly useful for technical interview preparation. Below is a comprehensive summary, including common data structures and sorting algorithms.

---

### **Big-O Complexity Chart**

| Performance | Time Complexity          |
|-------------|--------------------------|
| Excellent   | O(1), O(log n)           |
| Good        | O(n)                     |
| Fair        | O(n log n)               |
| Bad         | O(n^2)                   |
| Horrible    | O(2^n), O(n!)            |

![image](https://github.com/user-attachments/assets/7272c4e7-eb5c-4d90-a0ba-50b788ed4b1e)


---



### **Common Data Structure Operations**

| Data Structure        | Time Complexity (Average) | Time Complexity (Worst)  | Space Complexity (Worst) |
|-----------------------|---------------------------|--------------------------|--------------------------|
|                       | Access | Search | Insert | Delete | Access | Search | Insert | Delete |
| **Array**             | Θ(1)   | Θ(n)   | Θ(n)   | Θ(n)   | O(1)   | O(n)   | O(n)   | O(n)   | O(n) |
| **Stack**             | Θ(n)   | Θ(n)   | Θ(1)   | Θ(1)   | O(n)   | O(n)   | O(1)   | O(1)   | O(n) |
| **Queue**             | Θ(n)   | Θ(n)   | Θ(1)   | Θ(1)   | O(n)   | O(n)   | O(1)   | O(1)   | O(n) |
| **Singly-Linked List**| Θ(n)   | Θ(n)   | Θ(1)   | Θ(1)   | O(n)   | O(n)   | O(1)   | O(1)   | O(n) |
| **Doubly-Linked List**| Θ(n)   | Θ(n)   | Θ(1)   | Θ(1)   | O(n)   | O(n)   | O(1)   | O(1)   | O(n) |
| **Skip List**         | Θ(log(n)) | Θ(log(n)) | Θ(log(n)) | Θ(log(n)) | O(n) | O(n) | O(n) | O(n) | O(n log(n)) |
| **Hash Table**        | N/A    | Θ(1)   | Θ(1)   | Θ(1)   | N/A    | O(n)   | O(n)   | O(n)   | O(n) |
| **Binary Search Tree**| Θ(log(n)) | Θ(log(n)) | Θ(log(n)) | Θ(log(n)) | O(n) | O(n) | O(n) | O(n) | O(n) |
| **Cartesian Tree**    | N/A    | Θ(log(n)) | Θ(log(n)) | Θ(log(n)) | N/A    | O(n) | O(n) | O(n) | O(n) |
| **B-Tree**            | Θ(log(n)) | Θ(log(n)) | Θ(log(n)) | Θ(log(n)) | O(log(n)) | O(log(n)) | O(log(n)) | O(log(n)) | O(n) |
| **Red-Black Tree**    | Θ(log(n)) | Θ(log(n)) | Θ(log(n)) | Θ(log(n)) | O(log(n)) | O(log(n)) | O(log(n)) | O(log(n)) | O(n) |
| **Splay Tree**        | N/A    | Θ(log(n)) | Θ(log(n)) | Θ(log(n)) | N/A    | O(log(n)) | O(log(n)) | O(log(n)) | O(n) |
| **AVL Tree**          | Θ(log(n)) | Θ(log(n)) | Θ(log(n)) | Θ(log(n)) | O(log(n)) | O(log(n)) | O(log(n)) | O(log(n)) | O(n) |
| **KD Tree**           | Θ(log(n)) | Θ(log(n)) | Θ(log(n)) | Θ(log(n)) | O(n) | O(n) | O(n) | O(n) | O(n) |

![image](https://github.com/user-attachments/assets/1df00818-8a47-49fb-a925-acd820550b6e)


---

### **Array Sorting Algorithms**

| Algorithm        | Time Complexity (Best) | Time Complexity (Average) | Time Complexity (Worst) | Space Complexity (Worst) |
|------------------|------------------------|---------------------------|-------------------------|--------------------------|
| **Quicksort**    | Ω(n log(n))            | Θ(n log(n))               | O(n^2)                  | O(log(n))                |
| **Mergesort**    | Ω(n log(n))            | Θ(n log(n))               | O(n log(n))             | O(n)                     |
| **Timsort**      | Ω(n)                   | Θ(n log(n))               | O(n log(n))             | O(n)                     |
| **Heapsort**     | Ω(n log(n))            | Θ(n log(n))               | O(n log(n))             | O(1)                     |
| **Bubble Sort**  | Ω(n)                   | Θ(n^2)                    | O(n^2)                  | O(1)                     |
| **Insertion Sort**| Ω(n)                  | Θ(n^2)                    | O(n^2)                  | O(1)                     |
| **Selection Sort**| Ω(n^2)                | Θ(n^2)                    | O(n^2)                  | O(1)                     |
| **Tree Sort**    | Ω(n log(n))            | Θ(n log(n))               | O(n^2)                  | O(n)                     |
| **Shell Sort**   | Ω(n log(n))            | Θ(n(log(n))^2)            | O(n(log(n))^2)          | O(1)                     |
| **Bucket Sort**  | Ω(n+k)                 | Θ(n+k)                    | O(n^2)                  | O(n)                     |
| **Radix Sort**   | Ω(nk)                  | Θ(nk)                     | O(nk)                   | O(n+k)                   |
| **Counting Sort**| Ω(n+k)                 | Θ(n+k)                    | O(n+k)                  | O(k)                     |
| **Cubesort**     | Ω(n)                   | Θ(n log(n))               | O(n log(n))             | O(n)                     |

![image](https://github.com/user-attachments/assets/f7e6a88c-c61f-4f1d-ad5d-107dd5a7fc21)


---



### **Conclusion**

This guide serves as a quick reference for the time and space complexities of common algorithms and data structures, aiding in technical interview preparation and improving algorithmic understanding.
