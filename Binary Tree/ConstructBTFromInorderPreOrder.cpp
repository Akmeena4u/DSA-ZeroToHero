 int findPosition(int inorder[], int n, int element, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == element) {
                return i;
            }
        }
        return -1;
    }

    Node* buildTreeFromPreOrderInOrder(int inorder[], int preorder[], int size, int& preIndex, int inorderStart,
                                       int inorderEnd) {
        if (preIndex >= size || inorderStart > inorderEnd) {
            return NULL;
        }

        int element = preorder[preIndex++];
        Node* root = new Node(element);
        int pos = findPosition(inorder, size, element, inorderStart, inorderEnd);

        root->left = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, inorderStart, pos - 1);
        root->right = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, pos + 1, inorderEnd);

        return root;
    }

    Node* buildTree(int in[], int pre[], int n) {
        int preIndex = 0;
        Node* ans = buildTreeFromPreOrderInOrder(in, pre, n, preIndex, 0, n - 1);
        return ans;
    }
