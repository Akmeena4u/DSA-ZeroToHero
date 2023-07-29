/*You are required to complete below method*/
Node* deleteNode(Node *head, int x)
{
    //Your code here
    if (head == NULL)
    {
        //  cout << "Cannot delete, LL is empty";
        return head;
    }

    // deleting first node
    if (head->data == x)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return head;
    }

    Node *prev = head;
    Node *curr = head->next;

    while (curr != NULL)
    {
        if (curr->data == x)
        {
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
            return head;
        }
        prev = curr;
        curr = curr->next;
    }

    // If node with value x is not found in the linked list, return head as it is.
    return head;
}
