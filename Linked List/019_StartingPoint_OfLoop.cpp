Node* findStart(Node* &head){
    if(head == NULL){
        return head;
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
    while(slow!=fast){
        // Move both by 1 step
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
