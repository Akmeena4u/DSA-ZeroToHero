 Node* deleteNode(Node* head, int x) {
        // Your code here
    int pos = 1;                 // Initialize position counter
    Node *curr = head;           // Start from the head of the list
    
    if (x == 1) return head->next; // If the node to delete is the head, return the next node as the new head
    
    while (pos != x) {           // Traverse the list to reach the node at position x
        pos++;
        curr = curr->next;       // Move to the next node
    }
    
    if (curr->next != NULL) {    // If the node to delete is not the last node
        curr->next->prev = curr->prev; // Set the next node's previous pointer to skip the current node
    }
    
    if (curr->prev != NULL) {    // If the node to delete is not the first node
        curr->prev->next = curr->next; // Set the previous node's next pointer to skip the current node
    }
    
    return head;                 // Return the head of the list
    }
