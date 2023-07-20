pair<bool,int>  solve(Node* root){
      
      if(root->left==NULL && root->right==NULL){
          //leaf node
         pair<bool ,int> p=make_pair(true, root->data);
         return p;
      }
      
      if(root==NULL){
         pair<bool ,int> p=make_pair(true,INT_MIN);
         return p;
      }
      
      pair<bool , int> leftans=solve(root->left);
      pair<bool , int> rightans =solve(root->right);
      
      if(leftans.first ==true && rightans.first==true && root->data> leftans.second && root->data > rightans.second){
          pair<bool, int> p=make_pair(true ,root->data);
          return p;
      }
      
      else{
          pair<bool, int> p=make_pair(false ,root->data);
          return p;
      }
      
      
      
  }
    bool isHeap(struct Node* tree) {
        // code here
        
        pair<bool,int> ans =solve(tree);
        
        if(ans.first==true)  return true;
        else return false;
    }
