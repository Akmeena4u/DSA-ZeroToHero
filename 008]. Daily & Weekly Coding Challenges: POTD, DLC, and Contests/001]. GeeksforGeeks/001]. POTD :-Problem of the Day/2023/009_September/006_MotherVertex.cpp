/*A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.
  Expected Time Complexity: O(V + E)
Expected Space Compelxity: O(V)

  logic:--The idea behind this algorithm is to perform two DFS traversals. The first DFS traversal identifies a potential mother vertex, 
         and the second DFS traversal checks if the potential mother vertex is indeed a mother vertex by verifying if it can reach all other vertices in the graph. 
         If it can, it is a mother vertex; otherwise, there is no mother vertex in the graph.*/


class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
   void dfs(int i,vector<int>& vis, vector<int> adj[]){
        vis[i]=1;
        for(auto it: adj[i])
            if(!vis[it])
                dfs(it,vis,adj);
        return;
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    int ans=0; //mother vertex
	    vector<int> vis(V,0);
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            ans=i;
	            dfs(i,vis,adj);
	        }
	    }
	    vis = vector<int>(V,0);
	    dfs(ans,vis,adj);
	    for(int x:vis)
	        if(!x) return -1;
 
	   return ans;
	}



};
