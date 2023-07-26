int kthAncestor(Node *root, int k, int node)
{
    // Code here
     if (root == NULL)
        return -1;

    if(root->data == node){
        return 1;
    }    

    // If k becomes 0, it means we have found the kth ancestor
    if (k == 0)
        return root->data;

    int leftAns = kthAncestor(root->left, k, node);
    int rightAns = kthAncestor(root->right, k, node);

    // Check if the kth ancestor is found in the left subtree
    if (leftAns != -1)
        return leftAns;

    // Check if the kth ancestor is found in the right subtree
    if (rightAns != -1)
        return rightAns;

    // If the key node is not found in the subtrees, return -1
    return -1;
}

----------------------------------------------------------------------------------

    // your task is to complete this function
vector<int>temp;

bool solve(Node* root, int val){
    
    if(root==NULL)   return false;
    
    if(root->data == val)   return true;
    
    bool left = solve(root->left, val);
    
    bool right = solve(root->right, val);
    
    if(left || right)   {
        
        temp.push_back(root->data); //node mil chuka h or waps jate time all ansestor ko temp me dalte jayenge
        
        return true;
    }
    
    return false;
    
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    
    temp.clear();
    
    bool call = solve(root, node);
    
    if(temp.size() < k) return -1;  //means there are not enough ancestors to find the k-th ancestor, 
    
    return temp[k - 1];
}

