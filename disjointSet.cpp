#include<bits/stdc++.h>
using namespace std;

class disjointSet{
    //code here
    int size = 10;
    vector<int> parent;

    public:
    disjointSet(){
        for(int i = 0; i< size; i++){
            parent.push_back(-1);
        }
    }
    disjointSet(int n){
        size = n;
        for(int i = 0; i< size; i++){
            parent.push_back(-1);
        }
    }
    int find(int x){
        if(x >= size){
            return -1;
        }
        if(parent[x]<0){
            return x;
        }
        int pt = find(parent[x]);
        parent[x] = pt;
        return pt;
    }
    void unite(int x, int y){
        if(x >= size || y >= size){
            cout << "Error: Invalid unite operation; element out of set universe" << endl;
            return;
        }
        int fx = find(x), fy = find(y);
        // cout << "Parent of " << x << " is : " << fx << endl;
        // cout << "Parent of " << y << " is : " << fy << endl;
        if(parent[fx] < parent[fy]){
            parent[fy] = fx;
            parent[y] = fx;
            return;
        }
        else{
            parent[fy] += parent[fx];
            parent[fx] = fy;
            return;
        }
        return;
    }
    void dispParent(){
        for(int i = 0; i< size; i++){
            cout << parent[i] << " ";
        }
        cout << endl;
    }
};
