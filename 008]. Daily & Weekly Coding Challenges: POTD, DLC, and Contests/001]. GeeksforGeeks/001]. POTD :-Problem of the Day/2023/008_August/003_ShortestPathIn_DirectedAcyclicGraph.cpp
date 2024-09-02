// User function Template for C++
class Solution {
  public:
      vector<vector<pair<int, int>>> adjList;

    vector<int> topoSortBfs(int n) {
        vector<int> indegree(n, 0);
        for (int src = 0; src < n; src++) {
            for (auto nbr : adjList[src]) {
                int dest = nbr.first;
                indegree[dest]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();
            topo.push_back(frontNode);
            for (auto nbr : adjList[frontNode]) {
                int dest = nbr.first;
                indegree[dest]--;
                if (indegree[dest] == 0) {
                    q.push(dest);
                }
            }
        }
        return topo;
    }

    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        adjList.resize(N);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adjList[u].push_back({v, wt});
        }

        vector<int> topoOrder = topoSortBfs(N);

        vector<int> dist(N, INT_MAX);
        dist[0] = 0;

        for (int i = 0; i < N; i++) {
            int node = topoOrder[i];
            if (dist[node] != INT_MAX) {
                for (auto nbr : adjList[node]) {
                    int dest = nbr.first;
                    if (dist[node] + nbr.second < dist[dest]) {
                        dist[dest] = dist[node] + nbr.second;
                    }
                }
            }
        }

        for (int i = 0; i < N; i++) {
            if (dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};
