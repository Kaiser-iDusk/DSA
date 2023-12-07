#include<bits/stdc++.h>
using namespace std;
 
class Graph{
    //code here
    bool** matrix;
    int sz;

    void DFS(int sv, vector<bool>& visited){
        if(!visited[sv]){
            visited[sv] = true;
        }
        for(int i = 0; i< sz; i++){
            if(matrix[sv][i] && !visited[i]){
                DFS(i, visited);
            }
        }
    }

    void BFPrint(int sv, vector<bool>& visited, queue<int>& q){
        cout << sv << " ";
        visited[sv] = true;
        for(int i = 0; i< sz; i++){
            if(matrix[sv][i] && !visited[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            sv = q.front();
            q.pop();
            if(!visited[sv])
                BFPrint(sv, visited, q);
        }
    }
public:
    Graph(int n){
        sz = n;
        matrix = new bool*[n];
        for(int i = 0; i< n; i++){
            matrix[i] = new bool[n];
        }
        for(int i = 0; i< n; i++){
            for(int j = 0; j< n; j++){
                matrix[i][j] = false;
            }
        }
    }
    void printMatrix(){
        for(int i = 0; i< sz; i++){
            for(int j = 0; j< sz; j++){
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    void insertNode(int e){
        for(int i = 1; i<= e; i++){
            int fv, sv;
            cout << "Enter 1st and 2nd vertex: " << endl;
            cin >> fv >> sv;
            matrix[fv][sv] = true;
            matrix[sv][fv] = true;
        }
    }
    void printGraph(int sv, int set){
        vector<bool> v(sz, false);
        if(set)
            DFS(sv, v);
        else{
            queue<int> q;
            BFPrint(sv, v, q);
        }
        return;
    }
    int nComponents(){
        vector<bool> visited(sz, false);
        int cnt = 0;
        for(int i = 0; i< sz; i++){
            if(!visited[i]){
                DFS(i, visited);
                cnt++;
            }
        }
        return cnt;
    }
};
 
int main(){
    //complete main here
    int n;
    cin >> n;
    Graph* grp = new Graph(n);
    int e;
    cin >> e;
    grp->insertNode(e);
    //grp->printMatrix();
    //grp->printGraph(2, 0);
    cout << grp->nComponents() << endl;
    return 0;
}