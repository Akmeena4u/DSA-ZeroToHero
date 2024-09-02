// Given a singly linked list, remove all the nodes in the list which have any node on their right whose value is greater.
//   (Not just immidiate Right , but entire List on the Right)

 

// Example 1:

// Input:
// LinkedList = 12->15->10->11->5->6->2->3
// Output: 15 11 6 3
// Explanation: Since, 12, 10, 5 and 2 are
// the elements which have greater elements
// on the following nodes. So, after deleting
// them, the linked list would like be 15,
// 11, 6, 3.



class Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
             head = rev(head);
            Node* node = head;
            
            while (node != nullptr && node->next != nullptr) {
                if (node->data > node->next->data) {
                    node->next = node->next->next;
                } else {
                    node = node->next;
                }
            }
            
            return rev(head);
        }
        
    Node* rev(Node* head) {
        Node* prev = nullptr;
        Node* next = nullptr;
        
        while (head != nullptr) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    
    }
    
};
   
