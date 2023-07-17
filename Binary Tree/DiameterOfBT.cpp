 // Function to return the diameter of a Binary Tree.
     int maxDepth(Node* root) {
        if(root == NULL) 
		return 0;

        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        int ans = max(leftHeight, rightHeight) + 1;
        return ans;
    }
    int diameter(Node* root) {
        // Your code here
        if(root == NULL) 
        return 0;
      //length of the longest path between two nodes =Diameter
      //diameter could include root or may not include(diameter is in rightsubtree or leftsubtre)
        int op1 = diameter(root->left);
        int op2 = diameter(root->right);
        int op3 = maxDepth(root->left) + 1 + maxDepth(root->right);
        int ans = max(op1, max(op2, op3));
        return ans ;
    }
