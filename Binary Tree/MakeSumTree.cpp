//sumtree==== mean replace each node with--currNodeVal+leftsubtreeval+rightsubtreeval


int toSumTree(Node* root) {
        if (root == NULL)
            return 0;

        int leftSum = toSumTree(root->left);
        int rightSum = toSumTree(root->right);
        root->data += leftSum + rightSum;
        return root->data;
    }
