#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int pt, int ln, int n, vector<int>& obstacles){
        if(pt == n-1)
            return 0;
        if(obstacles[pt] == ln)
            return INT_MAX;
        //cout << "Pt: " << pt << " ln: " << ln << endl;
        int straight = solve(pt+1, ln, n, obstacles);
        //cout << "Straight--> " << ((straight == INT_MAX) ? 0 : 1) << endl; 
        int jump1 = INT_MAX, jump2 = INT_MAX;
        if(ln == 1 && straight == INT_MAX){
            if(obstacles[pt] != 2)
                jump1 = solve(pt, 2, n, obstacles);
            if(obstacles[pt] != 3)
                jump2 = solve(pt, 3, n, obstacles);
        }
        else if(ln == 2 && straight == INT_MAX){
            if(obstacles[pt] != 1)
                jump1 = solve(pt, 1, n, obstacles);
            if(obstacles[pt] != 3)
                jump2 = solve(pt, 3, n, obstacles);
        }
        else if(ln == 3 && straight == INT_MAX){
            if(obstacles[pt] != 2)
                jump1 = solve(pt, 2, n, obstacles);
            if(obstacles[pt] != 1)
                jump2 = solve(pt, 1, n, obstacles);
        }
        if(jump1 != INT_MAX)
            jump1++;
        if(jump2 != INT_MAX)
            jump2++;
        //cout << "Jump1: " << jump1 << " || Jump2: " << jump2 << endl;
        return min(straight, min(jump1, jump2));
    }
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        long int ans = solve(0, 2, n, obstacles);
        return (int)ans;
    }
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        Solution ob;
        int n; 
        cin >> n;
        vector<int> obstacles(n, 0);
        for(int i = 0; i< n; i++){
            cin >> obstacles[i];
        }
        cout << "MinJumps = " << ob.minSideJumps(obstacles) << endl;
    }
    return 0;
}