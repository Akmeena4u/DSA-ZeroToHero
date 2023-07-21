/*
21/7/23
   Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5 
Explanation: 
The first 4 elements 1,2,2,4 are reversed first 
and then the next 4 elements 5,6,7,8. Hence, the 
resultant linked list is 4->2->2->1->8->7->6->5.
  */

struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        node* next;
        node* prev=NULL;
        int c=0;
        
        node* curr=head;
        while(curr!=NULL && c<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            c++;
        }
        
        if(next!=NULL){
            head->next=reverse(next,k);
            //return prev;
        }

      return prev;
    }
