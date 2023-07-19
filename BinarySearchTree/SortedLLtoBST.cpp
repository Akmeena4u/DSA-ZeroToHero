Node* sortedLLIntoBST(Node* &head,int n){
    // Base case
    if(head == NULL || n <= 0 ){ // BST not possible
        return NULL;
    }
    // Getting left subtree
    // Node* leftSubtree = sortedLLIntoBST(head,n-1-n/2);
    Node* leftSubtree = sortedLLIntoBST(head,n/2);
    // Now we can create root as head node now points to the mid node
    Node* root = head;
    // Attach root to left subtree
    root->left = leftSubtree;
    head = head->right;
    // Getting right subtree
    // Head points to one node ahead of mid and hence is updated head
    // root->right = sortedLLIntoBST(head,n/2);
    root -> right = sortedLLIntoBST(head,n-1-n/2);
    return root;
}
