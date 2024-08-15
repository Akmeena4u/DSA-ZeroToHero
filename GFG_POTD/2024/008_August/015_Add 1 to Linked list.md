### Problem: Add One to a Number Represented as a Linked List

We are given a **singly linked list**, where each node contains a single digit of a number. The digits are stored in reverse order, meaning the head of the list holds the least significant digit of the number. We need to **add 1** to this number and return the updated linked list.

### Example:

- Input: `1 -> 9 -> 9`
- Output: `2 -> 0 -> 0`

Here, the linked list `1 -> 9 -> 9` represents the number 991 in reverse order. When we add 1 to 991, the result is 992, so the linked list should become `2 -> 0 -> 0`.

### Approach to Solve the Problem:

1. **Reverse the Linked List**:  
   We need to start adding from the least significant digit (which is the last node in the list), so we reverse the linked list to bring the last digit to the front.

2. **Add One**:  
   After reversing, we add 1 to the first node (which represents the last digit of the number). If that node is a 9, we set it to 0 and carry over 1 to the next node.

3. **Handle the Carry**:  
   If adding 1 causes a carry (for example, when a node's value becomes 10), we set the current node to 0 and pass the carry to the next node. This continues until there’s no carry left or we reach the end of the list.

4. **Extra Carry**:  
   If there’s still a carry after processing all the nodes (e.g., when adding 1 to 999), we need to add a new node with value 1 at the end of the list.

5. **Reverse the List Again**:  
   Finally, we reverse the list back to its original order. The linked list now represents the updated number after adding 1.

---

### Code Implementation:

```cpp


// Function to reverse the linked list
Node* reverse(Node* head) {
    Node *prev = nullptr, *cur = head, *next = nullptr;
    while (cur) {
        next = cur->next;  // Store the next node
        cur->next = prev;  // Reverse the link
        prev = cur;        // Move prev to current node
        cur = next;        // Move to next node
    }
    return prev;           // Return new head (which was last node)
}

// Function to add one to the number
Node* addOne(Node* head) {
    // Step 1: Reverse the list
    head = reverse(head);
    
    // Step 2: Initialize carry as 1 (since we are adding 1)
    int carry = 1;
    Node* temp = head;
    Node* tail = nullptr;
    
    // Step 3: Traverse the list and add the carry
    while (temp && carry) {
        if (temp->data == 9) {
            temp->data = 0;  // If it's 9, set to 0 and keep the carry
        } else {
            temp->data += 1; // Add 1 to current node
            carry = 0;       // No more carry
        }
        tail = temp;         // Keep track of the last node
        temp = temp->next;   // Move to next node
    }
    
    // Step 4: If carry is still 1, add a new node with value 1
    if (carry) {
        tail->next = new Node(1);
    }
    
    // Step 5: Reverse the list again to restore original order
    head = reverse(head);
    
    return head;  // Return the modified list
}


```

### Explanation of Code:

1. **Reverse the List**:  
   The function `reverse()` reverses the linked list by changing the direction of the pointers between nodes. It takes the current list and returns the head of the reversed list.

2. **Add One to the Number**:  
   The function `addOne()` does the following:
   - Reverses the list to start adding from the least significant digit.
   - Initializes a carry of 1 because we are adding 1 to the number.
   - If a node's value is 9, it sets it to 0 and carries 1 to the next node. Otherwise, it adds 1 to the node and sets the carry to 0.
   - If we reach the end of the list and still have a carry, a new node with value 1 is added.
   - The list is reversed again to restore the original order.

3. **Printing the List**:  
   The function `printList()` prints the linked list in a human-readable format for easy understanding.

4. **Example**:  
   In the example, we start with the list `9 -> 9 -> 9`, which represents the number 999. After adding 1, the list becomes `1 -> 0 -> 0 -> 0`, representing the number 1000.

---

### Time Complexity:

- **Reversing the Linked List**: O(n) where n is the number of nodes in the list.
- **Adding the Carry**: O(n) because we might need to visit all nodes to propagate the carry.
- **Reversing Again**: O(n).
- **Total Time Complexity**: O(n), where n is the number of nodes.

### Space Complexity:

- **Space Complexity**: O(1) because we only use a few extra pointers to reverse and traverse the list.

---

### Conclusion:

This approach efficiently handles the problem of adding one to a number represented as a linked list. By reversing the list, we can add from the least significant digit, handle any carries, and finally restore the list to its correct order. The time complexity is O(n), making the solution efficient for large lists.
