#include <iostream>
using namespace std;

class Node{
public:
int data;
Node* Left;
Node* right;

Node*(int data){
  this->data=data;
Left=NULL;
right=NULL;

}

}

Node* BuildTree(){
int data ;
cin>>data;

if(data==-1)  return NULL;

//step a , b ,c
Node* root= new Node(data);
root->left=BuildTree();
root->right=BuildTree();
return root;
}

int main() {
    Node* root = NULL;

    root = buildTree();

    // Perform operations on the binary tree as needed

    return 0;
}

