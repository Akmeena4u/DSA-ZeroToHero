//app 1== use postordertraversal and after completing left and right traversal just swap left and right pointers

//approch-2-- in mirror leftsubtree becomes right and rightsubtree becomes left so we can do it by swap function  after mirroring indivisual left and right subtree
// Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        if(node==NULL)  return;
        
        mirror(node->left);
        mirror(node->right);
        swap(node->left,node->right);
        
    }
