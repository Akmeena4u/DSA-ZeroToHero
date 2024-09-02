 //Print the corner nodes ie- the node at the leftmost and rightmost of each level.

void printCorner(Node *root)
{

// Your code goes here
queue<Node*>q;
    q.push(root);
    
    vector<int>ans;
    while(!q.empty())
    {
        
        int size=q.size();
     
            int count=1;
            
            while(count<=size)
            {
                Node *temp=q.front();
                q.pop();
                if(count==1 || count==size)
                {
                    ans.push_back(temp->data);
                    
                }
                
                if(temp->left!= NULL)
                    {
                        q.push(temp->left);
                    }
                    
                    if(temp->right!=NULL)
                    {
                        q.push(temp->right);
                    }
                    count++;
                
            }
            
        }
        
        for(auto it: ans)
        {
            cout<<it<<" ";
        }

}
