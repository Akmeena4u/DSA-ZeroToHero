 // moris traversal
    vector<int> inOrder(Node* root)
    {
        //code here
        
        vector<int> ans;
        Node* curr=root; 
        while(curr){
            
            //left is null then visit it mean push into ans and go on curr->right
            if(curr->left==NULL){
                ans.push_back(curr->data);
                curr=curr->right;
            }
            
            //if left is not null
            
            else{
                //find inordeer predecsor
                
                Node* pred=curr->left;
                while(pred->right && pred->right!=curr){  //to avoid infinte loop
                    pred=pred->right;
                }
                
                //if pred->right is null then go left after establishing link from pred to curr
                
                if(pred->right==NULL){
                    pred->right=curr;
                    curr=curr->left;
                }
                
                //else  left is already visited and pred->right is not null , go right after visiting curr node while removing the link
                
                else{
                    
                    pred->right=NULL;
                    ans.push_back(curr->data);
                    curr=curr->right;
                    
                }
            }
        }
        
        return ans;
        
    }
