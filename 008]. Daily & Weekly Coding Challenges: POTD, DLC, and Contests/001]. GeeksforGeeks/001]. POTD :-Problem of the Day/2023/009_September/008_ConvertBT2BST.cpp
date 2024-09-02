//Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.



class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node* binaryTreeToBST(Node* root) {
        vector<int> values;
        getNodes(root, values);
        sort(values.begin(), values.end());
        int index = 0;
        return inorder(root, values, index);
    }

private:
    void getNodes(Node* root, vector<int>& values) {
        if (root == NULL) return;
        values.push_back(root->data);
        getNodes(root->left, values);
        getNodes(root->right, values);
    }

    Node* inorder(Node* root, const vector<int>& values, int& index) {
        if (root == NULL) return NULL;
        Node* left = inorder(root->left, values, index);
        root->data = values[index++];
        Node* right = inorder(root->right, values, index);
        return root;
    }
    
};
