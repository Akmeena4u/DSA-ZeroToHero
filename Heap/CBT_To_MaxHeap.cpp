void inorder(Node* root, vector<int>&in)
    {
        if(root==NULL)
            return;
        
        inorder(root->left,in);
        in.push_back(root->data);
        inorder(root->right,in);
    }
    void postorder(Node* root, vector<int>&in,int &index)
    {
        if(root==NULL)
            return;
        
        postorder(root->left,in,index);
        postorder(root->right,in,index);
        
        root->data=in[index++];
    }
    void convertToMaxHeapUtil(Node* root)
    {
        // Your code goes here
        vector<int>in;
        inorder(root,in);
        int index=0;
        postorder(root,in,index);
    }   
