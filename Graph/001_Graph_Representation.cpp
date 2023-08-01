//Adjency list 


#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class Graph{
    public:
        unordered_map<int,list<int>>adjList;
        void addEdge(int u,int v,bool direction){
            // direction = 0 -> undirected
            // direction = 1 -> directed 
            // Create an edge from u to v
            adjList[u].push_back(v);
            // if undirected 
            if(direction == 0)
                adjList[v].push_back(u); // edge created from v to u    
        }
        void printAdjList(){
            for(auto node : adjList){
                cout<<node.first<<"-> ";
                for(auto neighbours : node.second){
                    cout<<neighbours<<", ";
                }
                cout<<endl;
            }
        }
};
int main(){
    Graph g;
    // undirected graph
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(0,2,0);

    // directed graph
    g.addEdge(1,2,1);
    g.addEdge(0,1,1);
    g.addEdge(0,2,1);
    g.printAdjList();
    return 0;
}



//Adjency list with weighted

#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class Graph{
    public:
        unordered_map<int,list<pair<int,int>>>adjList;
        void addEdge(int u,int v,int weight,bool direction){
            // direction = 0 -> undirected
            // direction = 1 -> directed 
            // Create an edge from u to v
            adjList[u].push_back({v,weight});
            // if undirected 
            if(direction == 0)
                adjList[v].push_back({u,weight}); // edge created from v to u    
        }
        void printAdjList(){
            for(auto node : adjList){
                cout<<node.first<<"-> ";
                for(auto neighbours : node.second){
                    cout<<"("<<neighbours.first<<", "<<neighbours.second<<")"<<",";
                }
                cout<<endl;
            }
        }
};
int main(){
    Graph g;
    // undirected graph
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(0,2,0);

    // directed graph
    g.addEdge(1,2,8,1);
    g.addEdge(0,1,5,1);
    g.addEdge(0,2,6,1);
    g.printAdjList();
    return 0;
}


//Adjency matrix
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of nodes "<<endl;
    cin>>n;
    vector<vector<int>>adj(n,vector<int>(n,0));
    int e;
    cout<<"Enter the number of edges"<<endl;
    cin>>e;

    for(int i = 0;i<e;i++){
        int u,v;
        cin>>u>>v;
        // mark 1
        adj[u][v] = 1;
    }
    // Printing the adjacency matrix
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
