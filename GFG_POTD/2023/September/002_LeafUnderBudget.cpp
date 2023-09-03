// Given a binary tree and a budget. Assume you are at the root of the tree(level 1), you need to maximise the count of leaf nodes you can visit in your budget
// if the cost of visiting a leaf node is equal to the level of that leaf node.

class Solution
{
public:
    int getCount(Node *root, int k)
    {
        //code here 
        int ans = 0;
        
        queue<pair<Node *, int>> q;
        q.push({root, 1});
        
        while(!q.empty()){
            Node * cur;
            int level;
            
            tie(cur, level) = q.front();
            q.pop();
            
            if(cur -> left != nullptr)
                q.push({cur -> left, level + 1});
            if(cur -> right != nullptr)
                q.push({cur -> right, level + 1});
                
            if(!cur -> left and !cur -> right){
                if(level <= k){
                    k -= level;
                    ++ans;
                }
            }
        }
        
        return ans;
    }
};
