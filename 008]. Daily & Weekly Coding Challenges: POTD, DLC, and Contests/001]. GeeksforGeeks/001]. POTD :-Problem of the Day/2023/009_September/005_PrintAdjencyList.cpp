/*V = 5, E = 7
edges = {(0,1),(0,4),(4,1),(4,3),(1,3),(1,2),(3,2)}

Output: 
{{1,4}, 
 {0,2,3,4}, 
 {1,3},
 {1,2,4},
 {0,1,3}}
Explanation:
Node 0 is connected to 1 and 4.
Node 1 is connected to 0,2,3 and 4.
Node 2 is connected to 1 and 3.
Node 3 is connected to 1,2 and 4.
Node 4 is connected to 0,1 and 3.
*/

vector<vector<int>>res(V);
       for (auto edge : edges) 
       {
        int u = edge.first;
        int v = edge.second;
        res[u].push_back(v);
        res[v].push_back(u);  
       }

        return res;
