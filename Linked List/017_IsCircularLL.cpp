


//using slow and fast pointerss

bool isCircular(Node *head)
{
   // Your code here
    if (head == NULL)
        return false;

    Node* tortoise = head;
    Node* hare = head;

    while (hare != NULL && hare->next != NULL) {
        tortoise = tortoise->next;
        hare = hare->next->next;

        if (tortoise == hare)
            return true;
    }

    return false;
}
