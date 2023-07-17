#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    Node* root = new Node(data);

    cout << "Enter data for the left part of " << data << " node " << endl;
    root->left = buildTree();

    cout << "Enter data for the right part of " << data << " node " << endl;
    root->right = buildTree();

    return root;
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

int main() {
    Node* root = NULL;

    root = buildTree();

    cout << "Level-order traversal: ";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}

/*

Enter the data: 
20
Enter data for the left part of 20 node 
Enter the data: 
30
Enter data for the left part of 30 node 
Enter the data: 
50
Enter data for the left part of 50 node 
Enter the data: 
-1
Enter data for the right part of 50 node 
Enter the data: 
60
Enter data for the left part of 60 node 
Enter the data: 
-1
Enter data for the right part of 60 node 
Enter the data: 
-1
Enter data for the right part of 30 node 
Enter the data: 
40
Enter data for the left part of 40 node 
Enter the data: 
-1
Enter data for the right part of 40 node 
Enter the data: 
-1
Enter data for the right part of 20 node 
Enter the data: 
100
Enter data for the left part of 100 node 
Enter the data: 
-1
Enter data for the right part of 100 node 
Enter the data: 
-1
Level-order traversal: 20 
30 100 
50 40 
60 

*/
