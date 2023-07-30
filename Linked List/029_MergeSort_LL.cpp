ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)  return list2;
        if (list2==NULL)  return list1;

        ListNode* ans= new ListNode(-1);
        ListNode* temp=ans;
        while(list1 && list2){
            if(list1->val <=list2->val){
                   temp->next=list1;
                   temp=list1;
                   list1=list1->next;
            }
            else{
                temp->next=list2;
                temp=list2;
                list2=list2->next;
            }
        }

        if(list1){
            temp->next=list1;

        }
        if(list2){
            temp->next=list2;
        }

        return ans->next;
    }

    ListNode* middleNode(ListNode* head) {
    // If empty linked list
    if (head == NULL) {
      //  cout << "Linked List is empty";
        return head;
    }

    // Only one node in the linked list
    if (head->next == NULL) {
        return head;
    }

    ListNode* slow = head;
    ListNode* fast = head->next; // Update this line

    // slow and fast are valid
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next; // move 1 step
        fast = fast->next; // move 1 step more and hence in total 2 steps
        slow = slow->next; // move 1 step
    }

    return slow; // return slow which will be the middle node
}



    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)  return head;
        
        //break ll into two halves using mid node
        ListNode* mid= middleNode(head);
        ListNode* left=head;
        ListNode* right =mid->next;
        mid->next=NULL;

        //rec call for both halves to further breaks
        left=sortList(left);
        right=sortList(right);

        //merge two left and right sorted ll
        ListNode* mergedList=mergeTwoLists(left,right);

        return mergedList;
    }
