//simply use the BST  property that For each node in the tree:
//All nodes in its left subtree have values less than the node's value.
//All nodes in its right subtree have values greater than the node's value.

// and keeping in mind above conditions i have inserted new node in bst


class Solution
{
    public:
        Node* insert(Node* root, int Key) {
        
            // Your code goes here
      if (root == NULL) {
        root = new Node(Key);
        return root;
    }

    if (root->data > Key) {
        root->left = insert(root->left, Key);
    } else if (root->data < Key) {
        root->right = insert(root->right, Key);
    }

    return root;
    }

};
