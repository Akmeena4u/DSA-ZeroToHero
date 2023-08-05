void insertAtBottom(stack<int> &St, int target){
       
       if(St.empty()){
           St.push(target);
           return;
       }
       
       int topElement= St.top();
       St.pop();
       
       insertAtBottom(St, target);
        //BT
        St.push(topElement);

       
   }
   
   
    void Reverse(stack<int> &St){
        // bc
        
        if(St.empty()){
            return;
        }
        
        //find top most element 
        
        int target= St.top();
        St.pop();
        
        //reverse remaining elements of stack by recurssion
        
        Reverse(St);
        
        //push top element at bottom
        
        insertAtBottom(St,target);
    }
