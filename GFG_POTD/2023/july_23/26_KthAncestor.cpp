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
