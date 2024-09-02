### Problem Description

The task is to construct a binary tree from a given parent array representation. The parent array `parent` uses indices (0-based indexing) as the values of the tree nodes, and `parent[i]` denotes the parent node of a particular node `i`. The root node will have `parent[i] = -1` since it has no parent. The goal is to return the root node of the constructed tree.

### Example

**Input:**
```
parent[] = [-1, 0, 0, 1, 1, 3, 5]
```

**Output (Level Order Traversal):**
```
0 1 2 3 4 5 6
```

**Explanation:**
The tree structure will be:
```
          0
        /   \
       1     2
      / \
     3   4
    /
   5
 /
6
```

### Intuition

1. **Node Creation**: Each index in the parent array represents a node. We first create all nodes.
2. **Tree Construction**: We then iterate through the parent array and use the parent-child relationships to construct the tree:
   - The root node is identified by `parent[i] = -1`.
   - For other nodes, we attach them to their parent nodes as left or right children.
   - If two nodes have the same parent, the first one becomes the left child, and the second one becomes the right child.

### Algorithm

1. **Initialize Nodes**: Create an array of node pointers where each index corresponds to a node.
2. **Identify Root**: Traverse the parent array to identify the root node (`parent[i] = -1`).
3. **Attach Children**: For each node, attach it to its parent node as a left or right child based on availability.
4. **Return Root**: After constructing the tree, return the root node.

### Code Implementation

```cpp
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node *createTree(vector<int> parent) {
    // Get the size of the parent array
    int n = parent.size();
    
    // Array to store node pointers
    Node* nodes[n], *root;
    
    // Create all nodes with values equal to their indices
    for(int i = 0; i < n; i++) {
        nodes[i] = new Node(i);
    }
    
    // Set up the tree structure
    for(int i = 0; i < n; i++) {
        // If parent[i] is -1, then nodes[i] is the root node
        if(parent[i] == -1) {
            root = nodes[i];
        } else {
            // If the left child is null, assign the current node as the left child
            if(nodes[parent[i]]->left == NULL) {
                nodes[parent[i]]->left = nodes[i];
            }
            // Otherwise, assign the current node as the right child
            else {
                nodes[parent[i]]->right = nodes[i];
            }
        }
    }
    
    // Return the root node of the constructed tree
    return root;
}
```

### Complexity Analysis

- **Time Complexity**: O(n)
  - We traverse the parent array twice:
    - Once for creating nodes.
    - Once for attaching nodes to their parents.
- **Space Complexity**: O(n)
  - We use an additional array to store the pointers to the nodes.

This approach ensures efficient construction of the binary tree from the given parent array representation.