### **Problem: Split Linked List in Parts**

#### **Problem Statement:**
Given the head of a singly linked list and an integer `k`, split the linked list into `k` consecutive linked list parts. The length of each part should be as equal as possible. No two parts should have a size differing by more than one. Some parts may be `null` if the number of parts `k` is greater than the number of nodes in the list.

The parts should be in the order of occurrence in the input list, and earlier parts should have a size greater than or equal to later parts. Return an array of the `k` parts.

#### **Example:**
- **Input:** `head = [1, 2, 3]`, `k = 5`
- **Output:** `[[1], [2], [3], [], []]`
- **Explanation:**
  - The first three parts contain one element each.
  - The remaining two parts are `null` since there are no more elements in the list.

#### **Approach:**

1. **Calculate the Length of the Linked List:**
   - Traverse the linked list to determine its total length `L`.
   - Initialize `L` to `0` and use a pointer (`curr`) to traverse the list while incrementing `L` with each node.

2. **Determine the Size of Each Part:**
   - Calculate the size of each part as `eachBucketNodes = L / k`.
   - Calculate the remainder nodes that cannot be evenly distributed as `remainderNodes = L % k`.

3. **Split the Linked List:**
   - Use a vector `result` of size `k` initialized with `NULL` to store the head of each split part.
   - Traverse the linked list again, this time splitting it into `k` parts:
     - For each part `i`, assign the current node (`curr`) as the head of the `i-th` part.
     - Traverse `eachBucketNodes` nodes, plus one extra node if `remainderNodes > 0` (to evenly distribute the remainder nodes).
     - After traversing the nodes for the current part, set the `next` pointer of the last node to `NULL` to terminate the current part.
     - Decrement `remainderNodes` after distributing an extra node.

4. **Return the Result:**
   - Return the vector `result` containing the heads of the `k` parts.

#### **Code Implementation:**

```cpp
vector<ListNode*> splitListToParts(ListNode* head, int k) {
    // Calculate the length of the linked list
    ListNode* curr = head;
    int L = 0;
    while (curr) {
        L++;
        curr = curr->next;
    }
    
    // Determine the size of each part
    int eachBucketNodes = L / k;      // Base size of each part
    int remainderNodes  = L % k;      // Extra nodes to distribute
    
    vector<ListNode*> result(k, NULL);  // Result vector to store heads of the parts
    curr = head;
    ListNode* prev = NULL;
    
    for (int i = 0; curr && i < k; i++) {
        result[i] = curr;  // Assign the current node as the head of the i-th part
        
        // Traverse the current part size and an extra node if remainderNodes > 0
        for (int count = 1; count <= eachBucketNodes + (remainderNodes > 0 ? 1 : 0); count++) {
            prev = curr;
            curr = curr->next;
        }
        
        prev->next = NULL;  // Terminate the current part
        remainderNodes--;   // Decrement remainder nodes after distributing one
    }
    
    return result;  // Return the array of split parts
}
```

### **Key Points:**
- **Time Complexity:** The approach works in `O(n)` time complexity, where `n` is the number of nodes in the linked list, as it involves traversing the list twice (once for length calculation and once for splitting).
- **Space Complexity:** The space complexity is `O(k)` due to the additional vector of size `k`.
- **Edge Cases:**
  - When `k` is greater than the number of nodes in the list, some parts will be `null`.
  - When `k` is equal to the number of nodes, each part will contain exactly one node.
  - When `k` is less than the number of nodes, each part will have more than one node, with the earlier parts possibly containing one more node than the later parts to account for any remainder nodes.

### **Explanation:**
- The algorithm ensures that the linked list is split into `k` parts where each part is as equal as possible in size. The use of `remainderNodes` ensures that any extra nodes are evenly distributed among the earlier parts. This approach is efficient and handles various edge cases, making it suitable for practical use cases.
