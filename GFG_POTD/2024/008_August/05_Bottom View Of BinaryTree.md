## Problem Understanding

The problem requires us to determine the bottom view of a binary tree. The bottom view consists of the nodes that are visible when the tree is viewed from the bottom. Nodes are considered from left to right according to their horizontal distance from the root.

### Example Explanation

Given the tree:

```
       1
     /   \
    3     2
```

The bottom view is `[3, 1, 2]`.

Given the tree:

```
                      20
                    /    \
                  8       22
                /   \     /   \
              5      3  4     25
                     /    \      
                 10       14
```

The bottom view is `[5, 10, 4, 14, 25]`.

## Intuition

To solve this problem, we need to consider the horizontal distance (hd) from the root:
- Nodes to the left of the root have negative horizontal distances.
- Nodes to the right of the root have positive horizontal distances.

We can use a breadth-first traversal to explore the nodes level by level while keeping track of the horizontal distance for each node. We store the node data corresponding to each horizontal distance in a map. If multiple nodes share the same horizontal distance, we overwrite the value in the map, as the later node in the level traversal will be the bottom-most one for that distance.

## Algorithm

1. Initialize an empty result vector `ans`.
2. If the root is `NULL`, return the empty vector `ans`.
3. Use a `map<int, int>` to store the bottom-most node's data for each horizontal distance.
4. Use a `queue<pair<Node*, int>>` for level-order traversal, where each pair contains a node and its horizontal distance.
5. Push the root node with a horizontal distance of 0 onto the queue.
6. Perform a level-order traversal:
    - For each node, update the map with the node's data for its horizontal distance.
    - Push the left child with a horizontal distance of `hd-1`.
    - Push the right child with a horizontal distance of `hd+1`.
7. Extract the values from the map in order of increasing horizontal distances and add them to the result vector `ans`.
8. Return the result vector `ans`.

## Code

```cpp
#include <vector>
#include <map>
#include <queue>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

vector<int> bottomView(Node* root) {
    vector<int> ans;
    if (root == NULL) {
        return ans;
    }
    
    map<int, int> bottomNode;
    queue<pair<Node*, int>> q;
    
    q.push(make_pair(root, 0));
    
    while (!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;
        
        // Overwrite the data at hd with the current node's data
        bottomNode[hd] = frontNode->data;
        
        if (frontNode->left) {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right) {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }
    
    for (auto i : bottomNode) {
        ans.push_back(i.second);
    }
    
    return ans;
}
```


### Complexity Analysis
- **Time Complexity**: (O(N) - Each node is processed once in the level-order traversal.
- **Space Complexity**: O(N) - The space needed for the map and the queue is proportional to the number of nodes.

## Problem Pattern
This problem falls under the category of tree traversal with additional constraints on how nodes are viewed and represented. The key idea is to use level-order traversal to explore nodes in a controlled manner, keeping track of the horizontal distances to achieve the desired view of the tree.
