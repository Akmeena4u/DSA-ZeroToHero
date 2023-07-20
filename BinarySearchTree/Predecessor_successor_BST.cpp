void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        // Base case
    if (root == NULL)
        return;

    // If the key is found at the current node
    if (root->key == key) {
        // Find the predecessor (rightmost node in the left subtree)
        if (root->left != NULL) {
            Node* tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp;
        }
        
        // Find the successor (leftmost node in the right subtree)
        if (root->right != NULL) {
            Node* tmp = root->right;
            while (tmp->left)
                tmp = tmp->left;
            suc = tmp;
        }
        
        return;
    }

    // If the key is smaller than the current node, go to the left subtree
    if (root->key > key) {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    // If the key is greater than the current node, go to the right subtree
    else {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }

    }
