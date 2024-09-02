

#### Purpose

The function `removeAllDuplicates` removes all nodes that have duplicate values in a sorted linked list, ensuring that only unique values remain.

#### Steps
1. **Initialize Pointers**:
    - `temp` is used to traverse the list.
    - `prev` tracks the last non-duplicate node.

2. **Traverse the List**:
    - Use a `while` loop to traverse the list with `temp` until `temp` is `NULL`.

3. **Check for Duplicates**:
    - Inside the loop, use another nested `while` loop to check if the current node `temp` has the same value as the next node (`temp->next`).
    - Count the number of consecutive duplicates using `cnt`.

4. **Remove Duplicates**:
    - If duplicates are found (`cnt > 0`), adjust pointers to skip all nodes with the duplicated value.
        - If `prev` is not `NULL`, set `prev->next` to `temp->next`.
        - If `prev` is `NULL`, it means the head node itself was duplicated. Update the head to `temp->next`.

5. **Move to Next Node**:
    - If no duplicates are found, simply move `prev` to `temp` and `temp` to `temp->next`.

6. **Return Modified List**:
    - Finally, return the updated head of the linked list.

### Detailed Dry Run
#### Example List: `23 -> 28 -> 28 -> 35 -> 49 -> 49 -> 53 -> 53`

1. **Initial Pointers**:
    - `temp` at `23`, `prev` is `NULL`.

2. **Step-by-Step Process**:
    - `23`: No duplicates (`prev` moves to `23`).
    - `28`: Duplicates found (`28 -> 28`).
        - Adjust pointers to skip all `28`s.
        - Update `prev->next` to `35` (or head to `35` if `prev` is `NULL`).
    - `35`: No duplicates (`prev` moves to `35`).
    - `49`: Duplicates found (`49 -> 49`).
        - Adjust pointers to skip all `49`s.
        - Update `prev->next` to `53`.
    - `53`: Duplicates found (`53 -> 53`).
        - Adjust pointers to skip all `53`s.
        - Update `prev->next` to `NULL`.

### Code with Comments
Here's the annotated code with comments explaining each part of the process:

```cpp
Node* removeAllDuplicates(struct Node* head) {
    Node *temp = head;
    Node *prev = NULL;
    
    while (temp != NULL) {
        int cnt = 0;
        // Check for duplicates
        while (temp != NULL && temp->next != NULL) {
            if (temp->data == temp->next->data) {
                temp = temp->next;  // Move to the next node
                cnt++;
            } else {
                break;  // Exit if no more duplicates
            }
        }
        
        // If duplicates were found, remove them
        if (cnt > 0) {
            if (prev != NULL) {
                prev->next = temp->next;  // Skip the duplicate nodes
                temp = prev->next;  // Move to the next node
            } else {
                head = temp->next;  // Head was a duplicate
                temp = head;  // Move to the new head
            }
        } else {
            // No duplicates, move prev to temp
            prev = temp;
            temp = temp->next;  // Move to the next node
        }
    }
    
    return head;
}
```

### Key Points
- **Initialization**: Set up pointers `temp` and `prev`.
- **Traversal**: Use `temp` to traverse the list and identify duplicates.
- **Removal**: Adjust pointers to skip over duplicates and update `prev` or `head` as needed.
- **Result**: The modified list only contains unique values, with all duplicates removed.

This function ensures efficient removal of duplicates by leveraging the sorted property of the linked list, making it easier to detect and handle consecutive duplicate values.
