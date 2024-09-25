 
/*
The approach to check whether a linked list is a palindrome consists of the following steps:

1. **Find the Middle**: Use the two-pointer technique (slow and fast pointers) to find the middle of the linked list. The slow pointer moves one step at a time, while the fast pointer moves two steps.
   
2. **Reverse the Second Half**: Reverse the second half of the linked list starting from the node after the middle.

3. **Compare the Halves**: Compare the first half of the list with the reversed second half. If all corresponding elements match, the linked list is a palindrome.

4. **Return Result**: If all comparisons are equal, return `true`. Otherwise, return `false`.

This approach has a time complexity of **O(n)**, where `n` is the number of nodes in the list, and a space complexity of **O(1)** since it modifies the list in place.
*/

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
