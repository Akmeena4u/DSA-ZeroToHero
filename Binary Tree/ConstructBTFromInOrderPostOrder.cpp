//Function to return a tree created from postorder and inoreder traversals.
int findPosition(int inorder[], int n, int element) {
    for (int i = 0; i < n; i++) {
        if (inorder[i] == element) {
            return i;
        }
    }
    return -1;
}

Node* buildTreeFromPostOrderInOrder(int inorder[], int postorder[], int& postIndex, int size,
                                    int inorderStart, int inorderEnd) {
    if (postIndex < 0 || inorderStart > inorderEnd) {
        return NULL;
    }

    int element = postorder[postIndex];
    postIndex--;
    Node* root = new Node(element);

    int pos = findPosition(inorder, size, element);
    root->right = buildTreeFromPostOrderInOrder(inorder, postorder, postIndex, size, pos + 1, inorderEnd);
    root->left = buildTreeFromPostOrderInOrder(inorder, postorder, postIndex, size, inorderStart, pos - 1);

    return root;
}

Node* buildTree(int in[], int post[], int n) {
    int postIndex = n - 1;
    Node* ans = buildTreeFromPostOrderInOrder(in, post, postIndex, n, 0, n - 1);
    return ans;
}
