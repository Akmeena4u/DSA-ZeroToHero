

### Problem:
Given an array `nums[]` of length `n`, construct an output array such that `product[i]` is equal to the product of all the elements of `nums[]` except `nums[i]`. You must solve it **without using division** because it will give incorrect ans when you will divide by zero and in **O(n)** time.

---

### 1. **Naive Approach (Using Nested Loops)**

#### Idea:
For each element at index `i`, calculate the product of all other elements by iterating over the array and multiplying them.

#### Time Complexity:
- **O(n^2)** due to the nested loops.

#### Space Complexity:
- **O(1)**, excluding the space used for the result.

#### C++ Code:

```cpp
vector<int> productExceptSelfNaive(vector<int>& nums) {
    int n = nums.size();
    vector<int> product(n, 1);
    
    // For each element, calculate the product of all other elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                product[i] *= nums[j];
            }
        }
    }
    
    return product;
}
```

---

### 2. **Approach Using Left and Right Arrays**

#### Idea:
We can improve the solution by calculating two auxiliary arrays:
- **Left Product Array**: Stores the product of all elements to the left of `nums[i]`.
- **Right Product Array**: Stores the product of all elements to the right of `nums[i]`.

We then combine the two arrays to get the final result.

#### Time Complexity:
- **O(n)** due to two passes through the array.

#### Space Complexity:
- **O(n)** for storing the left and right product arrays.

#### C++ Code:

```cpp
vector<int> productExceptSelfWithLeftRight(vector<int>& nums) {
    int n = nums.size();
    vector<int> left(n, 1);
    vector<int> right(n, 1);
    vector<int> product(n, 1);
    
    // Step 1: Calculate the left products
    for (int i = 1; i < n; i++) {
        left[i] = left[i - 1] * nums[i - 1];
    }
    
    // Step 2: Calculate the right products
    for (int i = n - 2; i >= 0; i--) {
        right[i] = right[i + 1] * nums[i + 1];
    }
    
    // Step 3: Calculate the final product array
    for (int i = 0; i < n; i++) {
        product[i] = left[i] * right[i];
    }
    
    return product;
}
```

---

### 3. **Optimized Approach (O(1) Space, Excluding Output Array)**

#### Idea:
Instead of using separate left and right arrays, we can store the cumulative left products in the result array and update it with the right products in a second pass.

#### Time Complexity:
- **O(n)** due to two passes through the array.

#### Space Complexity:
- **O(n)** for the result array. No extra space is used for left and right products (apart from the result array).

#### C++ Code:

```cpp
vector<int> productExceptSelfOptimized(vector<int>& nums) {
    int n = nums.size();
    
    // Step 1: Initialize the result array
    vector<int> product(n, 1);
    
    // Step 2: Calculate the left products and store in product[]
    int left = 1;
    for (int i = 0; i < n; i++) {
        product[i] = left;
        left *= nums[i];
    }
    
    // Step 3: Calculate the right products and update product[]
    int right = 1;
    for (int i = n - 1; i >= 0; i--) {
        product[i] *= right;
        right *= nums[i];
    }
    
    return product;
}
```

---

### Comparison of Approaches:

| Approach                             | Time Complexity | Space Complexity |
|--------------------------------------|-----------------|------------------|
| Naive Approach                       | O(n^2)          | O(1)             |
| Left and Right Arrays                | O(n)            | O(n)             |
| Optimized Approach (without division)| O(n)            | O(n) (for result)|

---

### Example Walkthrough:

Consider the input `nums = {1, 2, 3, 4}`.

#### 1. **Naive Approach**:
- For each element, we loop through the array to compute the product of all elements except itself.
  - For `nums[0]`: Product is `2 * 3 * 4 = 24`.
  - For `nums[1]`: Product is `1 * 3 * 4 = 12`.
  - For `nums[2]`: Product is `1 * 2 * 4 = 8`.
  - For `nums[3]`: Product is `1 * 2 * 3 = 6`.

  Result: `24 12 8 6`.

#### 2. **Left and Right Arrays**:
- **Left Array**: Calculate products of all elements to the left of each index.
  - `left[] = {1, 1, 2, 6}`.
  
- **Right Array**: Calculate products of all elements to the right of each index.
  - `right[] = {24, 12, 4, 1}`.
  
- Final result is the product of `left[]` and `right[]` at each index.
  
  Result: `24 12 8 6`.

#### 3. **Optimized Approach**:
- **Left Products**: Compute cumulative product and store in `product[]` array.
  - After first pass: `product[] = {1, 1, 2, 6}`.
  
- **Right Products**: Update `product[]` with the right products.
  - After second pass: `product[] = {24, 12, 8, 6}`.

---

### Conclusion:
The optimized approach achieves the desired result in **O(n)** time and **O(n)** space (for the result array), making it efficient and optimal for the problem.
