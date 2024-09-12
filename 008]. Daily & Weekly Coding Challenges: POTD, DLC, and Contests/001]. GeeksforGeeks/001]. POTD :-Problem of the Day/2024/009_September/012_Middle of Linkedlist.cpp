 int getMiddle(Node* head) {
       
    if(head == NULL){
        cout<<"Linked List is empty";
        return head->data;
    }
    // Only one node in the linked list
    if(head -> next == NULL){
        return head->data;
    }
    Node* slow = head;
    Node* fast = head; // n/2 + 1 will be the answer
    // Node* fast = head->next;  // If we want n/2 as the answer
    // slow and fast are valid
    while(slow!=NULL && fast!=NULL){
        fast = fast->next; // move 1 step
        if(fast!=NULL){ // check if fast becomes null
            fast = fast->next; // if not null, then simply move 1 step more and hence in total 2 steps
            slow = slow->next; // move 1 step
        }
    }
    return slow->data; // return slow which will be the middle node
    }
