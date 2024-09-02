
### Rotate a Linked List

**Problem Statement:**

Given the head of a singly linked list and a positive integer `k`, rotate the linked list clockwise by `k` nodes. This is equivalent to left-shifting the linked list by `k` nodes. 

**Examples:**

- **Input:** Linked List: `2 -> 4 -> 7 -> 8 -> 9`, `k = 3`
- **Output:** `8 -> 9 -> 2 -> 4 -> 7`

**Explanation:** 
To rotate the list by 3 positions:
1. After 1 rotation: `4 -> 7 -> 8 -> 9 -> 2`
2. After 2 rotations: `7 -> 8 -> 9 -> 2 -> 4`
3. After 3 rotations: `8 -> 9 -> 2 -> 4 -> 7`

**Problem Pattern:**

This problem involves circular linked list manipulation. The key idea is to:
1. Connect the end of the list to the start to form a circular list.
2. Traverse `k` nodes to find the new head.
3. Break the circular link to form the new rotated list.


**Algorithm:**

1. **Handle Edge Cases:**
   - If the list is empty (`head` is `NULL`), return `NULL`.
   - If `k` is 0, no rotation is needed, return the head.

2. **Connect the Last Node to the Head:**
   - Traverse to the end of the list.
   - Connect the last node’s `next` pointer to the head.

3. **Find the New Head:**
   - Traverse `k` nodes to find the new head.
   - Adjust the `head` pointer accordingly.

4. **Break the Circular Link:**
   - Set the `next` pointer of the new last node (which was the old `head`) to `NULL` to break the circular connection.

**Code:**

```cpp
Node* rotate(Node* head, int k) {
    // Edge case: if the list is empty
    if (!head) return NULL;
    
    // Edge case: if k is 0, no rotation needed
    if (k == 0) return head;
    
    // Step 1: Connect the last node to the head
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = head;  // Form a circular linked list
    
    // Step 2: Move the head by k nodes
    while (--k) {
        head = head->next;
    }
    
    // Step 3: Break the circle
    Node* newHead = head->next;
    head->next = NULL;  // Break the circular link
    
    return newHead;
}
```

**Dry Run:**

Let's dry run the algorithm with the example:

- **Input:** Linked List: `2 -> 4 -> 7 -> 8 -> 9`, `k = 3`

1. **Initial List:** `2 -> 4 -> 7 -> 8 -> 9`
2. **Connect End to Head:** `2 -> 4 -> 7 -> 8 -> 9 -> 2` (circular)
3. **Move the Head by k Nodes:**
   - After first move: `head = 4 -> 7 -> 8 -> 9 -> 2`
   - After second move: `head = 7 -> 8 -> 9 -> 2 -> 4`
   - After third move: `head = 8 -> 9 -> 2 -> 4 -> 7`
4. **Break Circular Link:** The list is now `8 -> 9 -> 2 -> 4 -> 7`.

**Complexity Analysis:**

- **Time Complexity:** O(n) where n is the number of nodes in the linked list. This is because we need to traverse the entire list to find the end, make the connection, and then find the new head.
- **Space Complexity:** O(1) because we are using a constant amount of extra space.

**Similar Problems:**

1. **Reverse a Linked List:** Reverse the entire linked list in-place.
2. **Rotate List:** Given a list and an integer `k`, rotate the list to the right by `k` places.
3. **Merge Two Sorted Lists:** Merge two sorted linked lists into one sorted linked list.
4. **Remove Nth Node From End:** Remove the nth node from the end of the list.
5. **Detect Cycle in a Linked List:** Determine if there is a cycle in a linked list.
