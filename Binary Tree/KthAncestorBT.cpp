int kthAncestor(Node *root, int k, int node)
{
    // Code here
     if (root == NULL)
        return -1;

    if(root->data == node){
        return 1;
    }    

    // If k becomes 0, it means we have found the kth ancestor
    if (k == 0)
        return root->data;

    int leftAns = kthAncestor(root->left, k, node);
    int rightAns = kthAncestor(root->right, k, node);

    // Check if the kth ancestor is found in the left subtree
    if (leftAns != -1)
        return leftAns;

    // Check if the kth ancestor is found in the right subtree
    if (rightAns != -1)
        return rightAns;

    // If the key node is not found in the subtrees, return -1
    return -1;
}
