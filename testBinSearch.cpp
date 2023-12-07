#include<bits/stdc++.h>
#include "BinarySearch.cpp"
using namespace std;

int main(){
    BinarySearch bs;
    vector<int> v;
    int n, target;
    cin >> n;
    for(int i = 0; i< n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    cin >> target;
    cout << bs.firstOccur(v, target) << endl;
    cout << bs.lastOccur(v, target) << endl;
    cout << bs.rotSortArr(v, target) << endl;
}
