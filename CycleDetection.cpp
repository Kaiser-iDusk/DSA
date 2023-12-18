//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    vector<int> parent;
    int size;
    
public: 
    DisjointSet(int n){
        vector<int> temp(n, -1);
        parent = temp;
        size = n;
    }
    int find(int x){
        //cout << "Finding " << x << ": " << endl;
        if(parent[x] < 0){
            //cout << "Answer: " << x << endl;
            return x;
        }
        return find(parent[x]);
    }
    void unite(int x, int y){
        int fx = find(x), fy = find(y);
        //cout << "Parent of " << x << " : " << fx << " Parent of " << y << " : " <<fy << endl;
        if(parent[fx] < parent[fy]){
            parent[fx] = parent[fx] + parent[fy];
            parent[fy] = fx;
            parent[y] = fx;
        }
        else{
            parent[fy] = parent[fx] + parent[fy];
            parent[fx] = fy;
            parent[x] = fy;
        }
    }
};
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        DisjointSet ds(V);
        vector<bool> vis(V, false);
        for(int i = 0; i< V; i++){
            //cout << "Standing at : " << i << endl;
            vis[i] = true;
            for(int j = 0; j< adj[i].size(); j++){
                //cout << adj[i][j] << " is visited? " << vis[adj[i][j]] << endl;
                if(!vis[adj[i][j]]){
                    if(ds.find(i) != ds.find(adj[i][j])){
                        ds.unite(i, adj[i][j]);
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}