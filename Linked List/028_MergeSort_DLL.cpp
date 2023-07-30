/Function to sort the given doubly linked list using Merge Sort.
// Node* mergeTwoLists(Node* list1, Node* list2) {
//     if (list1 == nullptr) return list2;
//     if (list2 == nullptr) return list1;

//     Node* ans = new Node(-1);
//     Node* temp = ans;

//     while (list1 && list2) {
//         if (list1->data <= list2->data) {
//             temp->next = list1;
//             list1->prev = temp;
//             temp = list1;
//             list1 = list1->next;
//         } else {
//             temp->next = list2;
//             list2->prev = temp;
//             temp = list2;
//             list2 = list2->next;
//         }
//     }

//     if (list1) {
//         temp->next = list1;
//         list1->prev = temp;
//     }

//     if (list2) {
//         temp->next = list2;
//         list2->prev = temp;
//     }

//     return ans->next;
// }
Node* mergeTwoLists(Node* list1, Node* list2) {
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;

    Node* ans = nullptr;
    Node* temp = nullptr;

    while (list1 && list2) {
        if (list1->data <= list2->data) {
            if (!ans) {
                ans = temp = list1;
            } else {
                temp->next = list1;
                list1->prev = temp;
                temp = list1;
            }
            list1 = list1->next;
        } else {
            if (!ans) {
                ans = temp = list2;
            } else {
                temp->next = list2;
                list2->prev = temp;
                temp = list2;
            }
            list2 = list2->next;
        }
    }

    if (list1) {
        if (!ans) {
            ans = list1;
        } else {
            temp->next = list1;
            list1->prev = temp;
        }
    }

    if (list2) {
        if (!ans) {
            ans = list2;
        } else {
            temp->next = list2;
            list2->prev = temp;
        }
    }

    return ans;
}

Node* middleNode(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next;
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}


struct Node *sortDoubly(struct Node *head)
{
	// Your code here
	 if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* mid = middleNode(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = nullptr;
    if (right) {
        right->prev = nullptr;
    }

    left = sortDoubly(left);
    right = sortDoubly(right);

    return mergeTwoLists(left, right);
}
