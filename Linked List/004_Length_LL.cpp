int findLength(Node* &head){
    int len = 1;
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
        len++;
    }
    return len;
}
