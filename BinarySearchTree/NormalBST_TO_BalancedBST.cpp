// function should return root of the modified BST
vector<Node*> inOrder;

void inorderTraversal(Node* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);      // Traverse left subtree
    inOrder.push_back(root);           // Visit the current node
    inorderTraversal(root->right);     // Traverse right subtree
}

Node* solve(int start, int end) {
    if (start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;

    Node* root = inOrder[mid];
    root->left = solve(start, mid - 1);
    root->right = solve(mid + 1, end);

    return root;
}

Node* buildBalancedTree(Node* root) {
    inOrder.clear(); // Clear the inOrder vector before each test case
    inorderTraversal(root);
    int s = 0, e = inOrder.size() - 1;
    Node* ans = solve(s, e);
    return ans;
}
