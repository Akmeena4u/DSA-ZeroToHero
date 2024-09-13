 void mirror(Node* node) {
        // code here
         if(node==NULL)  return;
        
        mirror(node->left);
        mirror(node->right);
        swap(node->left,node->right);
    }
