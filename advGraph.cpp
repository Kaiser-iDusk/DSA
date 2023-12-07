#include<bits/stdc++.h>
#include "disjointSet.cpp"
#include "synchMinHeap.cpp"
using namespace std;

class Graph{
    //code here
    int** matrix;
    int size;

    void sortTriple(vector<tuple<int>>& v){
        //cout << "Sorting:" << endl;
        int n = v.size();
        if(n==1 || n==0){
            return;
        }
        int mid = n/2;
        mergeSort(0, mid, v);
        mergeSort(mid+1, n-1, v);
        merge(0, mid, mid+1, n-1, v);
    }
    void mergeSort(int s, int e, vector<tuple<int>>& v){
        //cout << "MergeSorting on "<<s<<" and "<<e<<" index."<<endl;
        if(s>=e){
            return;
        }
        int mid = s + (e-s)/2;
        mergeSort(s, mid, v);
        mergeSort(mid+1, e, v);
        merge(s, mid, mid+1, e, v);
    }
    void merge(int s1, int e1, int s2, int e2, vector<tuple<int>>& v){
        vector<tuple<int>> temp;
        int i1 = s1, i2 = s2, j1 = e1, j2 = e2;
        //cout<<"Merging: " <<s1<< "-"<<e1<<" and "<<s2<<"-"<<e2<<endl;
        while((s1 <= e1) || (s2 <= e2)){
            //cout << s1 << " " << s2 << endl;
            if(s1 > e1){
                temp.push_back(v[s2]);
                s2++;
            }
            if(s2 > e2){
                temp.push_back(v[s1]);
                s1++;
            }
            if(s1 > e1 && s2 > e2){
                break;
            }
            if((s1<=e1 && s2<=e2) && (v[s1].element(1) <= v[s2].element(1))){
                //cout << "Selecting 1 over 2"<< endl;
                temp.push_back(v[s1]);
                s1++;
            }
            else if((s1<=e1 && s2<=e2) && (v[s1].element(1) > v[s2].element(1))){
                //cout << "Selecting 2 over 1"<< endl;
                temp.push_back(v[s2]);
                s2++;
            }
        }
        int j = 0;
        for(int i = i1; i<=j1; i++){
            v[i] = temp[j];
            j++;
        }
        for(int k = i2; k<=j2; k++){
            v[k] = temp[j];
            j++;
        }
        return;
    }

    public:
    Graph(int n){
        size = n;
        matrix = new int*[size];
        for(int i = 0; i< size; i++){
            matrix[i] = new int[size];
            for(int j = 0; j< size; j++){
                matrix[i][j] = 0;
            }
        }
    }
    void takeInput(int n){
        while(n--){
            int x, y, wt;
            cout << "Enter the two vertices to be connected: ";
            cin >> x >> y;
            cout << endl;
            if(x >= size || y >= size){
                cout << "Error: Index out of bounds" << endl;
                break;
            }
            cout << "Enter the weight of edge <" << x << ", " << y << "> : ";
            cin >> wt;
            cout << endl;
            matrix[x][y] = wt;
            matrix[y][x] = wt;
        }
        return;
    }
    void display(){
        for(int i = 0; i< size; i++){
            for(int j = 0; j< size; j++){
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }
    vector<tuple<int>> KruskalMST(){
        int nVertices = size;
        vector<tuple<int>> edgeData;
        vector<tuple<int>> ans;
        disjointSet* ds = new disjointSet(nVertices);
        for(int i = 0; i< size; i++){
            for(int j = i; j< size; j++){
                if(matrix[i][j]!=0){
                    tuple<int> tup(3);
                    tup.insert(matrix[i][j]);
                    tup.insert(i);
                    tup.insert(j);
                    edgeData.push_back(tup);
                }
            }
        }
        int nEdges = edgeData.size();
        sortTriple(edgeData);
        for(int i = 0; i< nEdges; i++){
            int x = edgeData[i].element(2);
            int y = edgeData[i].element(3);

            int fx = ds->find(x), fy = ds->find(y);
            if((fx==-1 && fy==-1) || (fx != fy)){
                ds->unite(x, y);
                tuple<int> tup(3);
                tup.insert(edgeData[i].element(1));
                tup.insert(x);
                tup.insert(y);
                ans.push_back(tup);
            }
            else{
                cout << "Cycle forming edges: "<< x << " <--> " << y << endl;
            }
        }
        return ans;
    }
    int PrimMST(int src, int* P, int* W){
        vector<bool> visited(size, false);
        int mstWt = 0;

        P[src] = -1;
        W[src] = 0;
        visited[src] = true;
        
        tuple<int> t(3);
        t.insert(src);
        t.insert(0);
        t.insert(-1);

        SMinHeap spq(size, 2);
        spq.push(t);
        
        // cout << "Min Heap after push: " << endl;
        // spq.display();

        while(!spq.isEmpty()){
            tuple<int> fnt = spq.front();
            spq.pop_front();
            int currV = fnt.element(1);
            
            // cout << "Front element: " << endl;
            // fnt.disptup();

            W[currV] = fnt.element(2);
            P[currV] = fnt.element(3);
            visited[currV] = true;
            
            mstWt += W[currV];

            // cout << "---Curr Index = " << currV << "---" << endl;

            for(int i = 0; i< size; i++){
                if(matrix[currV][i]!=0 && !visited[i]){
                    int f = spq.find(i, 1);
                    if(f!=-1){
                        // cout << "Index " << i << " exists in Min Heap at " << f << endl;
                        if(spq.elem(f).element(2) > matrix[currV][i]){
                            // cout << "Updating weight from " << spq.elem(f).element(2) << " to weight "<< matrix[currV][i] << endl;
                            spq.change(f, matrix[currV][i], 2);
                        }
                        spq.change(f, currV, 3);
                        // cout << "After changes in " << i << " the PQ: " << endl;
                        // spq.display();
                    }
                    else{
                        tuple<int> tup(3);
                        tup.insert(i);
                        tup.insert(matrix[currV][i]);
                        tup.insert(currV);
                        spq.push(tup);
                        
                        // cout << "The PQ after pushing new tuple : " << endl;
                        // spq.display();
                    }
                }
            }
        }
        return mstWt;
    }

    //For public access and debugging this function was specifically made:
    void SortAlg(vector<tuple<int>>& v){
        sortTriple(v);
        return;
    }

    void dispPrim(int n, int* P, int* W){
        for(int i = 0; i< size; i++){
            cout << "Vertex: " << i << " || Parent: " << P[i] << " || Weight: " << W[i] << endl;
        }
        return;
    }
};
 
int main(){
    //complete main here
    int n;
    cout << "Enter number of vertices: " << endl;
    cin >> n;
    Graph* gph = new Graph(n);
    int nI;
    cout << "Enter number of edges to connect: ";
    cin >> nI;
    cout << endl;
    gph->takeInput(nI);
    cout << "Matrix Repr. of Graph ADT:"<< endl;
    gph->display();
    cout << endl;

    int min_wt = 0;
    vector<tuple<int>> ans = gph->KruskalMST();
    cout << "Weight || Vertex1 || Vertex2" << endl;
    for(int i = 0; i< ans.size(); i++){
        min_wt += ans[i].element(1);
        ans[i].disptup();
    }
    cout << "Minimum weight of MST is: "<< min_wt << endl;

    // Prims' Algo
    int* P = new int[n];
    int* W = new int[n];
    int source = 0;
    cout << "Enter source vertex: ";
    cin >> source;
    cout << endl;

    cout << "Prim's MST weight: " << endl;
    cout << gph->PrimMST(source, P, W) << endl;
    cout << "------------------" << endl;
    cout << "Prims's MST: " << endl;
    gph->dispPrim(n, P, W);
    delete W;
    delete P;
    return 0;
}