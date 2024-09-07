### Problem: Delete Nodes From Linked List Present in Array

#### Problem Statement
You are given an array of integers `nums` and the head of a linked list. The task is to return the head of the modified linked list after removing all nodes from the linked list that have a value present in the array `nums`.

#### Example

- **Input:** 
  - `nums = [1, 2, 3]`
  - `head = [1, 2, 3, 4, 5]`
  
- **Output:** 
  - `[4, 5]`

  **Explanation:** 
  - Nodes with values `1`, `2`, and `3` exist in `nums`, so these nodes are removed from the linked list. The resulting linked list is `[4, 5]`.

#### Approach

1. **Create a Boolean Set:**
   - Create a boolean array `set` to store which values from `nums` exist, allowing for quick look-up. The size of this array can be sufficiently large to handle the range of potential values in the linked list nodes.

2. **Populate the Set:**
   - Iterate through the `nums` array, and for each value, mark it as `true` in the `set`. This step allows you to efficiently check if a node's value exists in `nums` during the list traversal.

3. **Traverse the Linked List:**
   - Use two pointers:
     - `cur` to traverse the linked list.
     - `prev` to keep track of the previous node.
   - For each node in the linked list, check if its value is present in the `set`:
     - If it is, remove the node from the linked list.
     - If it is not, move both pointers forward.

4. **Handle Edge Cases:**
   - Ensure that if the head of the linked list itself needs to be removed, the head is updated to the next node.

5. **Return the Modified List:**
   - After the traversal, return the new head of the linked list.

#### Code Implementation
```cpp
ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    // Create a boolean array 'set' to mark values that need to be removed
    vector<bool> set(1e5 + 1, false);

    // Populate the 'set' with values from nums
    for(int num : nums) {
        set[num] = true;
    }

    // Initialize pointers for traversal
    ListNode* prev = nullptr;
    ListNode* cur = head;

    // Traverse the linked list
    while(cur != nullptr) {
        if(set[cur->val]) {  // If current node's value is in 'nums'
            if(prev == nullptr) {  // If node to delete is the head
                head = head->next; // Update head to the next node
                cur->next = nullptr; // Disconnect current node
                cur = head; // Move cur to the new head
            } else { // If node to delete is not the head
                prev->next = cur->next; // Skip the current node
                cur->next = nullptr; // Disconnect current node
                cur = prev->next; // Move cur to the next node
            }
        } else {
            // Move both pointers forward if no deletion occurs
            prev = cur;
            cur = cur->next;
        }
    }

    return head; // Return the modified linked list
}
```

#### Explanation of the Code

1. **Set Creation:**
   - A boolean array `set` of size `1e5 + 1` is initialized with `false`. This size is assumed to cover the range of potential node values.
   - The `set` array is populated such that each value in `nums` is marked as `true`.

2. **List Traversal:**
   - The traversal begins with `cur` at the head and `prev` as `nullptr`.
   - For each node:
     - If the node's value is found in `set`, it is removed from the linked list.
     - If the node is the head (`prev == nullptr`), the head is updated.
     - Otherwise, the node is skipped by updating `prev->next`.
   - If the node's value is not in `set`, both `prev` and `cur` are moved to the next nodes.

3. **Returning the Result:**
   - The modified linked list with the nodes removed is returned as the result.

#### Complexity Analysis

- **Time Complexity:** O(n + m)
  - `n` is the number of nodes in the linked list.
  - `m` is the number of elements in `nums`.
  - Populating the `set` array takes O(m) time, and traversing the linked list takes O(n) time.

- **Space Complexity:** O(1)
  - The space complexity is constant, O(1), excluding the space used for the boolean `set` array, which is fixed in size.

#### Summary
This problem is efficiently solved by using a boolean array to store the elements that need to be removed, followed by a traversal of the linked list to remove the nodes. The approach ensures that the solution is both time-efficient and space-efficient, handling edge cases like deletion of the head node seamlessly.
