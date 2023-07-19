// Function should return median of the BST
void inorderTraversal(Node* root, vector<int>& values) {
    if (root == NULL)
        return;

    inorderTraversal(root->left, values);
    values.push_back(root->data);
    inorderTraversal(root->right, values);
}

float findMedianOfBST(vector<int>& values) {
    int n = values.size();
    if (n % 2 == 1) {
        return static_cast<float>(values[n / 2]);
    } else {
        int mid = n / 2;
        return static_cast<float>(values[mid - 1] + values[mid]) / 2.0;
    }
}


float findMedian(struct Node *root)
{
      //Code here
     vector<int> values;
    inorderTraversal(root, values);
    return findMedianOfBST(values);
}
