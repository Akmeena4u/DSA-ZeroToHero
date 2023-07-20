  //values of both the BST in a sorted order.
    void Inorder(Node* root, vector<int>& in) {
    if (root == NULL)
        return;
    Inorder(root->left, in);
    in.push_back(root->data);
    Inorder(root->right, in);
}

vector<int> MergeArray(const vector<int>& a, const vector<int>& b) {
    std::vector<int> ans(a.size() + b.size());

    int i = 0, j = 0, k = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j])
            ans[k++] = a[i++]; 
        else
            ans[k++] = b[j++];
    }

    while (i < a.size())
        ans[k++] = a[i++];
    while (j < b.size())
        ans[k++] = b[j++];
    
    return ans;
}

Node* InorderToBST(int s, int e, const vector<int>& in) {
    if (s > e)
        return NULL;
    int mid = (s + e) / 2;
    Node* root = new Node(in[mid]);

    root->left = InorderToBST(s, mid - 1, in);
    root->right = InorderToBST(mid + 1, e, in);
    
    return root;
}

vector<int> merge(Node* root1, Node* root2) {
    std::vector<int> bst1, bst2;
    Inorder(root1, bst1);
    Inorder(root2, bst2);

    vector<int> mergedArray = MergeArray(bst1, bst2);

    int s = 0, e = mergedArray.size() - 1;
    Node* mergedBST = InorderToBST(s, e, mergedArray);

    vector<int> result;
    Inorder(mergedBST, result);

    delete mergedBST;
    
    return result;
}
