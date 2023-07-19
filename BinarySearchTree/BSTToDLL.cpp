void convertToDLL(Node* root,Node* &head){
    // Base case
    if(root == NULL){
        return;
    }
    // Convert right subtree to linked list
    convertToDLL(root->right,head);
    // Attach the root node to right linked list
    root->right = head;
    // Attaching previous pointer
    if(head!=NULL)
        // To avoid NULL pointer exception
        head->left = root;
    // Update head
    head = root;
    // Convert left subtree to linked list
    convertToDLL(root->left,head);
}
