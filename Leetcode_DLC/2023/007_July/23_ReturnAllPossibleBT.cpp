/*
  Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.

Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.

A full binary tree is a binary tree where each node has exactly 0 or 2 children.
*/

vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> result;
        if (n % 2 == 0) {
            // For a full binary tree, the number of nodes must be odd.
            return result;
        }

        if (n == 1) {
            // Base case: Create a single node tree.
            TreeNode* root = new TreeNode(0);
            result.push_back(root);
            return result;
        }

        // For each number of left nodes from 1 to n-1, create all possible subtrees on the left and right.
        for (int leftNodes = 1; leftNodes < n; leftNodes += 2) {
            int rightNodes = n - 1 - leftNodes;

            vector<TreeNode*> leftSubtrees = allPossibleFBT(leftNodes);
            vector<TreeNode*> rightSubtrees = allPossibleFBT(rightNodes);

            // Connect the left and right subtrees to the root node.
            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }

        return result;
    }
