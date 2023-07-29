bool checkLoop(Node* &head){
    if(head == NULL){
        return false;
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
            return true;
        }
    }
    // loop is not present
    return false;
}
