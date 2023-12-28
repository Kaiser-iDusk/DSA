#include<bits/stdc++.h>
using namespace std;
 
void make_adj(vector<pair<int, int>>& edges, int M, unordered_map<int, list<int>>& adj){
	for(int i = 0; i< M; i++){
		int u = edges[i].first, v = edges[i].second;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	vector<int> ans;
	vector<int> vis(n+1, 0);
	vector<int> parent(n+1);
	unordered_map<int, list<int>> adj;
	make_adj(edges, m, adj);

	parent[s] = -1;
	queue<int> q;
	q.push(s);
    vis[s] = 1;
	
	while(!q.empty()){
		int vtx = q.front();
		q.pop();

		for(auto i: adj[vtx]){
			if(!vis[i]){
				q.push(i);
				parent[i] = vtx;
                vis[i] = 1;
			}
		}
	}
	int vtx = t;
	while(parent[vtx] != -1){
		ans.push_back(vtx);
		vtx = parent[vtx];
	}
	ans.push_back(s);
	reverse(ans.begin(), ans.end());
	
	return ans;
}

int main(){
    //complete main here
    int n, m, s, t;
    vector<pair<int, int>> edges;
    cout << "Enter number of edges and vertices: " << endl;
    cin >> m >> n;
    for(int i = 0; i< m; i++){
        int x, y;
        cout << "Enter pair of edges to connect: " << endl;
        cin >> x >> y;
        edges.push_back(make_pair(x, y));
    }
    cout << "Enter the src and destn vertices: " << endl;
    cin >> s >> t;
    vector<int> path;
    path = shortestPath(edges, n, m, s, t);
    cout << "Answer: ";
    for(auto i: path){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}