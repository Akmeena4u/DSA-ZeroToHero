class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    // Function to perform DFS traversal from a given source vertex.
    void dfs(int src, vector<int> adj[], vector<bool>& visited, vector<int>& result) {
        visited[src] = true;
        result.push_back(src);

        for (int neighbour : adj[src]) {
            if (!visited[neighbour]) {
                dfs(neighbour, adj, visited, result);
            }
        }
    }

    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> result;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, result);
            }
        }

        return result;
    }
};
