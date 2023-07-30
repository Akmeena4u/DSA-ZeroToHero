 //Function to add two numbers represented by linked list.
    Node* reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;
    while(curr!=NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
         if (first == NULL)
        return second;
    if (second == NULL)
        return first;

    // Step 1: Reverse both the linked lists
    first = reverse(first);
    second = reverse(second);

    // Step 2: Add both the linked lists
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    int carry = 0;
    while (first != NULL && second != NULL) {
        // Find sum
        int sum = carry + first->data + second->data;
        // Find digit
        int digit = sum % 10;
        // Find carry
        carry = sum / 10;
        Node* newNode = new Node(digit);
        if (ansHead == NULL) {
            // First node insert
            ansHead = newNode;
            ansTail = newNode;
        } else {
            ansTail->next = newNode;
            ansTail = newNode;
        }
        first = first->next;
        second = second->next;
    }
    while (first != NULL) {
        int sum = carry + first->data;
        int digit = sum % 10;
        carry = sum / 10;
        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
        first = first->next;
    }
    while (second != NULL) {
        int sum = carry + second->data;
        int digit = sum % 10;
        carry = sum / 10;
        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
        second = second->next;
    }
    // Handle the carry
    while (carry != 0) {
        int sum = carry;
        int digit = sum % 10;
        carry = sum / 10;
        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
    }
    // Step 3: Reverse the Linked List
    ansHead = reverse(ansHead);
    return ansHead;
    }
