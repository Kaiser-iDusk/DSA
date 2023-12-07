#include<bits/stdc++.h>
#include "Josephus.cpp"
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    Josephus j(n, k);
    j.execute();
}