// Given a Binary Search Tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.
//For details handwritten notes and explanation checkout just  next file 

class Solution {
    int count = 0;
    int ans = 0;

public:
    int kthLargest(Node* root, int K) {
        revInorder(root, K);
        return ans;
    }

private:
    void revInorder(Node* root, int k) {
        if (root == nullptr) return;
        revInorder(root->right, k);
        count++;
        if (count == k) {
            ans = root->data;
            return;
        }
        revInorder(root->left, k);
    }
};
