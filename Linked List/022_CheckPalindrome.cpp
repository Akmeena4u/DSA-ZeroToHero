Node* findMid(Node* head) {
        // Check if the head is NULL or the list has only one node.
        if (head == NULL || head->next == NULL)
            return head;

        Node* slow = head;
        Node* fast = head;

        // Move slow by one step and fast by two steps until fast reaches the end.
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow; // Return the mid-point of the linked list.
    }

    // Function to reverse the linked list.
    Node* reverseList(Node* head) {
        // Check if the list is empty or has only one node.
        if (head == NULL || head->next == NULL)
            return head;

        Node* current = head;
        Node* previous = NULL;
        Node* forward = NULL;

        // Reverse the linked list using three pointers approach.
        while (current != NULL) {
            forward = current->next;
            current->next = previous;
            previous = current;
            current = forward;
        }

        return previous; // Return the new head of the reversed linked list.
    }

    // Function to check whether the linked list is palindrome.
    bool isPalindrome(Node *head) {
        // Check if the list is empty or has only one node (base case).
        if (head == NULL || head->next == NULL)
            return true;

        Node* mid = findMid(head); // Find the mid-point of the linked list.
        Node* secondHalf = mid->next; // Head of the second half of the linked list.
        mid->next = NULL; // Split the list into two halves.
        Node* firstHalf = head; // Head of the first half of the linked list.
        secondHalf = reverseList(secondHalf); // Reverse the second half.

        // Compare the first half and the reversed second half for palindrome check.
        while (secondHalf != NULL) {
            if (firstHalf->data != secondHalf->data)
                return false;
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true; // The linked list is palindrome.
    }
