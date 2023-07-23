bool isFullTree(Node* root) {
    if (root == nullptr)
        return true;

    if (root->left == nullptr && root->right == nullptr)
        return true;

    if (root->left != nullptr && root->right != nullptr)
        return isFullTree(root->left) && isFullTree(root->right);

    return false;
}
