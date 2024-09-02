
// Given a singly linked list and an integer x.Delete xth node from the singly linked list.

// Example 1:

// Input: 1 -> 3 -> 4 
//        x = 3
// Output: 1 -> 3
// Explanation:
// After deleting the node at 3rd
// position (1-base indexing), the
// linked list is as 1 -> 3. 



/*You are required to complete below method*/
Node* deleteNode(Node *head,int x)
{
    //Your code here//Your code here
    if(head==NULL){
        return NULL;
    }
    
    // If there is single node, delete that and make head point to null // first node
       if(x==1){
           
           Node* temp=head;
           
           head=head->next;
           
           delete temp;
          
           return head;
       }
       
       
       //delete last node
       
       
       
       
       
      int i=1;  
        
        Node*prev =head;
        
        while(i<x-1 ){
            
            prev=prev->next;
            i++;
        }
        
        Node* curr= prev->next;
        
        
        prev->next=curr->next;
        
        curr->next=NULL;
        
        delete curr;
        
        return head;
        
}
