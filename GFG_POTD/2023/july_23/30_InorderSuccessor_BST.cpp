 // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here//Your code here
        
        Node* successor = NULL;
        
        while (root != NULL) {
            
            if (x->data >= root->data) {
                root = root->right;
            } else {
                successor = root;
                root = root->left;
            }
        }
        
        return successor;
    }
