  Node* LCA(Node *root, int n1, int n2)
        {
            // code here
            //Your code here
    //bc
        if(root==NULL){
            return NULL;
        }


        //case1
        if(n1 <root->data && n2 < root->data){
            return LCA(root->left ,n1,n2);
        }
          //case 2
         if(n1 >root->data && n2 > root->data){
            return LCA(root->right ,n1,n2);
        }

        //case 3 and 4
        return root;
        }
