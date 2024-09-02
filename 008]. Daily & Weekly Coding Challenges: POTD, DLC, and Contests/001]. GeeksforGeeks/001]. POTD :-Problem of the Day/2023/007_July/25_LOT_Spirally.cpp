//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    //Your code here
    std::vector<int> result;
    if (root == nullptr)
        return result;

    std::stack<Node*> stackEven; // Stack for even levels (right to left)
    std::stack<Node*> stackOdd;  // Stack for odd levels (left to right)

    stackOdd.push(root);

    while (!stackEven.empty() || !stackOdd.empty()) {
        while (!stackOdd.empty()) {
            Node* current = stackOdd.top();
            stackOdd.pop();
            result.push_back(current->data);

            // Push the children in reverse order (right to left)
            if (current->right)
                stackEven.push(current->right);
            if (current->left)
                stackEven.push(current->left);
        }

        while (!stackEven.empty()) {
            Node* current = stackEven.top();
            stackEven.pop();
            result.push_back(current->data);

            // Push the children in the normal order (left to right)
            if (current->left)
                stackOdd.push(current->left);
            if (current->right)
                stackOdd.push(current->right);
        }
    }

    return result;
}
