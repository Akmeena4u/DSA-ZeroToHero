 void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node* slow = head;
    Node* fast = head;
    bool loopExists = false;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            loopExists = true;
            break;
        }
    }
    if (loopExists) {
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        while (fast->next != slow) {
            fast = fast->next;
        }
        fast->next = NULL;
    }
    }
