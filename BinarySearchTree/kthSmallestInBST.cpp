int kthSmallest(TreeNode* root, int &k) {
        // Base case
        if(root == NULL){
            return -1;
        }
        // Inorder traversal
        // root ke left me milega smallest 
        int leftAns = kthSmallest(root->left,k);
        // Valid answer
        if(leftAns != -1){
            return leftAns;  //left me mil gya to right me jaane ki jarurat hi nahu h
        }
        // Node
        k--;
        if(k == 0){
            return root->val;
        }
        // Right
        int rightAns = kthSmallest(root->right,k);
        return rightAns;
    }
