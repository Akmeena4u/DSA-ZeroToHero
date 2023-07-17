//in mirrror or symm tree there would be slight change --- left will look like right and right will look like left
//root->left |mirror|   root->right
//root->left->right    |mirror|   root->right->left

 bool checkSymmetry(Node *r1,  Node* r2) {
         
        if (r1==NULL && r2==NULL)  return true;
        if (r1==NULL && r2!=NULL)  return false;
        if (r1!=NULL && r2==NULL)  return false;
      
        
        return (r1->data == r2->data) && checkSymmetry(r1->left, r2->right) && checkSymmetry(r1->right, r2->left);
    }
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    if(root==NULL) return true;
        return checkSymmetry(root->left, root->right);
    }
