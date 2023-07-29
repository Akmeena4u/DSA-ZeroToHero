
void removeLoop(Node* &head){
    if(head == NULL){
        return;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        // loop is present
        if(slow == fast){
            // Move slow to head
            slow = head;
            break;
        }
    }
    Node *prev = fast;
    while(slow!=fast){
        // Move both by 1 step
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }
    // Removal step
    prev->next = NULL;
}
