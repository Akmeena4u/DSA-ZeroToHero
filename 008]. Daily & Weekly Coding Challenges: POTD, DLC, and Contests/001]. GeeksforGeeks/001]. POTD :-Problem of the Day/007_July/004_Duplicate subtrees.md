To solve the problem of finding duplicate subtrees in a binary tree, we can use a recursive approach combined with hashing to keep track of the structure and values of the subtrees. Here's a step-by-step explanation of the solution:

### Approach:

1. **Serialize Subtrees**:
   - For each subtree, create a unique string representation that includes the structure and node values.
   - Use the string serialization to detect duplicate subtrees.

2. **Hashing**:
   - Use an unordered map (hash map) to count the occurrences of each serialized subtree.
   - When a serialized subtree appears for the second time, add the root of that subtree to the result list.

3. **Recursive Traversal**:
   - Perform a post-order traversal (left-right-root) to serialize each subtree and update the hash map.

4. **Result Compilation**:
   - Collect all roots of the duplicate subtrees and return them as the result.

### Implementation Details:

- **Base Case**: If the node is null, return a special character (e.g., "N") to denote null in the serialization.
- **Recursive Case**: For each node, serialize the subtree rooted at that node by combining the node's value, the serialization of the left subtree, and the serialization of the right subtree.
- **Hash Map Update**: Update the count of the serialized string in the hash map.
- **Duplicate Detection**: If the count of a serialized string becomes 2, add the root node of that subtree to the result list.

### Time and Space Complexity:

- **Time Complexity**: O(n) - where n is the number of nodes in the tree. Each node is visited once.
- **Space Complexity**: O(n) - for the hash map to store the serialized strings and for the recursion stack.

### Code:

```cpp
#include <unordered_map>
#include <vector>
#include <string>

struct Node {
    int data;
    Node* left;
    Node* right;
};

std::string serializeSubtree(Node* root, std::unordered_map<std::string, int>& subtreeMap, std::vector<Node*>& duplicates) {
    if (!root) {
        return "N"; // Null representation
    }
    
    // Serialize current subtree
    std::string serialized = std::to_string(root->data) + "," + 
                             serializeSubtree(root->left, subtreeMap, duplicates) + "," + 
                             serializeSubtree(root->right, subtreeMap, duplicates);
    
    // Increment the count of the serialized subtree in the map
    subtreeMap[serialized]++;
    
    // If the serialized subtree appears exactly twice, add to duplicates
    if (subtreeMap[serialized] == 2) {
        duplicates.push_back(root);
    }
    
    return serialized;
}

std::vector<Node*> printAllDups(Node* root) {
    std::unordered_map<std::string, int> subtreeMap;
    std::vector<Node*> duplicates;
    serializeSubtree(root, subtreeMap, duplicates);
    return duplicates;
}

// Function to print the tree nodes in pre-order traversal
void printPreOrder(Node* node) {
    if (!node) return;
    std::cout << node->data << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}
```

### Explanation of Example:

For the given binary tree:
```
    1
   / \
  2   3
 /   / \
4   2   4
   /
  4
```

- The subtree rooted at node with value 2 (`2,4,N,N,N`) and the subtree rooted at another node with value 2 (`2,4,N,N,N`) are duplicates.
- The subtree rooted at node with value 4 (`4,N,N`) appears multiple times.

The output would be the roots of these subtrees:
```
2 4
4
```

### Notes:

- Use a string serialization to uniquely identify the structure and values of subtrees.
- Ensure that the hash map correctly counts occurrences to detect duplicates efficiently.
- This approach leverages post-order traversal to build the serialization from the leaves up to the root, ensuring that subtrees are fully constructed before comparison.
